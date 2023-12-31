#include "tree_sitter/parser.h"

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

#define VEC_RESIZE(vec, _cap)                                                  \
    void *tmp = realloc((vec).data, (_cap) * sizeof((vec).data[0]));           \
    assert(tmp != NULL);                                                       \
    (vec).data = tmp;                                                          \
    (vec).cap = (_cap);

#define VEC_GROW(vec, _cap)                                                    \
    if ((vec).cap < (_cap)) {                                                  \
        VEC_RESIZE((vec), (_cap));                                             \
    }

#define VEC_PUSH(vec, el)                                                      \
    if ((vec).cap == (vec).len) {                                              \
        VEC_RESIZE((vec), MAX(16, (vec).len * 2));                             \
    }                                                                          \
    (vec).data[(vec).len++] = (el);

#define VEC_POP(vec) (vec).len--;

#define VEC_NEW                                                                \
    { .len = 0, .cap = 0, .data = NULL }

#define VEC_BACK(vec) ((vec).data[(vec).len - 1])

#define VEC_FREE(vec)                                                          \
    {                                                                          \
        if ((vec).data != NULL)                                                \
            free((vec).data);                                                  \
    }

#define VEC_CLEAR(vec) (vec).len = 0;

enum TokenType {
    NEWLINE,
    INDENT,
    DEDENT,
};

typedef struct {
    char flags;
} Delimiter;

static inline Delimiter new_delimiter() { return (Delimiter){0}; }

typedef struct {
    uint32_t len;
    uint32_t cap;
    uint16_t *data;
} indent_vec;

static indent_vec indent_vec_new() {
    indent_vec vec = VEC_NEW;
    vec.data = calloc(1, sizeof(uint16_t));
    vec.cap = 1;
    return vec;
}

typedef struct {
    uint32_t len;
    uint32_t cap;
    Delimiter *data;
} delimiter_vec;

static delimiter_vec delimiter_vec_new() {
    delimiter_vec vec = VEC_NEW;
    vec.data = calloc(1, sizeof(Delimiter));
    vec.cap = 1;
    return vec;
}

typedef struct {
    indent_vec indents;
    delimiter_vec delimiters;
    bool inside_f_string;
} Scanner;

bool tree_sitter_lube_external_scanner_scan(void *payload, TSLexer *lexer, const bool *valid_symbols) {
    Scanner *scanner = (Scanner *)payload;

    bool error_recovery_mode = valid_symbols[INDENT];
    lexer->mark_end(lexer);
    bool found_end_of_line = false;
    uint32_t indent_length = 0;

    for (;;) {
        if (lexer->lookahead == '\n') {
            found_end_of_line = true;
            indent_length = 0;
            lexer->advance(lexer, true);
        } else if (lexer->lookahead == ' ') {
            indent_length++;
            lexer->advance(lexer, true);
        } else if (lexer->lookahead == '\r' || lexer->lookahead == '\f') {
            indent_length = 0;
            lexer->advance(lexer, true);
        } else if (lexer->lookahead == '\t') {
            indent_length += 8;
            lexer->advance(lexer, true);
        } else if (lexer->eof(lexer)) {
            indent_length = 0;
            found_end_of_line = true;
            break;
        } else {
            break;
        }
    }

    if (found_end_of_line) {
        if (scanner->indents.len > 0) {
            uint16_t current_indent_length = VEC_BACK(scanner->indents);
            if (valid_symbols[INDENT] && indent_length > current_indent_length) {
                VEC_PUSH(scanner->indents, indent_length);
                lexer->result_symbol = INDENT;
                return true;
            }

            if ((valid_symbols[DEDENT] || !valid_symbols[NEWLINE]) && indent_length < current_indent_length) {
                VEC_POP(scanner->indents);
                lexer->result_symbol = DEDENT;
                return true;
            }
        }

        if (valid_symbols[NEWLINE] && !error_recovery_mode) {
            lexer->result_symbol = NEWLINE;
            return true;
        }
    }
    return false;
}

unsigned tree_sitter_lube_external_scanner_serialize(void *payload, char *buffer) {
    Scanner *scanner = (Scanner *)payload;
    size_t size = 0;
    buffer[size++] = (char)scanner->inside_f_string;

    size_t delimiter_count = scanner->delimiters.len;
    if (delimiter_count > UINT8_MAX) delimiter_count = UINT8_MAX;
    buffer[size++] = (char)delimiter_count;

    if (delimiter_count > 0) memcpy(&buffer[size], scanner->delimiters.data, delimiter_count);
    size += delimiter_count;

    int iter = 1;
    for (; iter < scanner->indents.len && size < TREE_SITTER_SERIALIZATION_BUFFER_SIZE; ++iter)
        buffer[size++] = (char)scanner->indents.data[iter];
    return size;
}

void tree_sitter_lube_external_scanner_deserialize(void *payload, const char *buffer, unsigned length) {
    Scanner *scanner = (Scanner *)payload;

    VEC_CLEAR(scanner->delimiters);
    VEC_CLEAR(scanner->indents);
    VEC_PUSH(scanner->indents, 0);

    if (length > 0) {
        size_t size = 0;
        scanner->inside_f_string = (bool)buffer[size++];
        size_t delimiter_count = (uint8_t)buffer[size++];
        if (delimiter_count > 0) {
            VEC_GROW(scanner->delimiters, delimiter_count);
            scanner->delimiters.len = delimiter_count;
            memcpy(scanner->delimiters.data, &buffer[size], delimiter_count);
            size += delimiter_count;
        }
        for (; size < length; size++) VEC_PUSH(scanner->indents, (unsigned char)buffer[size]);
    }
}

void *tree_sitter_lube_external_scanner_create() {
#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L)
    _Static_assert(sizeof(Delimiter) == sizeof(char), "");
#else
    assert(sizeof(Delimiter) == sizeof(char));
#endif
    Scanner *scanner = calloc(1, sizeof(Scanner));
    scanner->indents = indent_vec_new();
    scanner->delimiters = delimiter_vec_new();
    tree_sitter_lube_external_scanner_deserialize(scanner, NULL, 0);
    return scanner;
}

void tree_sitter_lube_external_scanner_destroy(void *payload) {
    Scanner *scanner = (Scanner *)payload;
    VEC_FREE(scanner->indents);
    VEC_FREE(scanner->delimiters);
    free(scanner);
}
