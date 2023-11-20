#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 20
#define LARGE_STATE_COUNT 7
#define SYMBOL_COUNT 13
#define ALIAS_COUNT 0
#define TOKEN_COUNT 5
#define EXTERNAL_TOKEN_COUNT 1
#define FIELD_COUNT 1
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define PRODUCTION_ID_COUNT 6

enum {
  sym_hidden_node_definition = 1,
  aux_sym_file_node_definition_token1 = 2,
  anon_sym_SLASH = 3,
  sym_newline = 4,
  sym_file_tree = 5,
  sym__node_definition = 6,
  sym_file_node_definition = 7,
  sym__inline_directory = 8,
  sym_directory_node_definition = 9,
  sym_title = 10,
  sym__nested = 11,
  aux_sym_file_tree_repeat1 = 12,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_hidden_node_definition] = "hidden_node_definition",
  [aux_sym_file_node_definition_token1] = "file_node_definition_token1",
  [anon_sym_SLASH] = "/",
  [sym_newline] = "newline",
  [sym_file_tree] = "file_tree",
  [sym__node_definition] = "_node_definition",
  [sym_file_node_definition] = "file_node_definition",
  [sym__inline_directory] = "_inline_directory",
  [sym_directory_node_definition] = "directory_node_definition",
  [sym_title] = "title",
  [sym__nested] = "_nested",
  [aux_sym_file_tree_repeat1] = "file_tree_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_hidden_node_definition] = sym_hidden_node_definition,
  [aux_sym_file_node_definition_token1] = aux_sym_file_node_definition_token1,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [sym_newline] = sym_newline,
  [sym_file_tree] = sym_file_tree,
  [sym__node_definition] = sym__node_definition,
  [sym_file_node_definition] = sym_file_node_definition,
  [sym__inline_directory] = sym__inline_directory,
  [sym_directory_node_definition] = sym_directory_node_definition,
  [sym_title] = sym_title,
  [sym__nested] = sym__nested,
  [aux_sym_file_tree_repeat1] = aux_sym_file_tree_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_hidden_node_definition] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_file_node_definition_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_SLASH] = {
    .visible = true,
    .named = false,
  },
  [sym_newline] = {
    .visible = true,
    .named = true,
  },
  [sym_file_tree] = {
    .visible = true,
    .named = true,
  },
  [sym__node_definition] = {
    .visible = false,
    .named = true,
  },
  [sym_file_node_definition] = {
    .visible = true,
    .named = true,
  },
  [sym__inline_directory] = {
    .visible = false,
    .named = true,
  },
  [sym_directory_node_definition] = {
    .visible = true,
    .named = true,
  },
  [sym_title] = {
    .visible = true,
    .named = true,
  },
  [sym__nested] = {
    .visible = false,
    .named = true,
  },
  [aux_sym_file_tree_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum {
  field_nested = 1,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_nested] = "nested",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
  [3] = {.index = 2, .length = 1},
  [4] = {.index = 3, .length = 1},
  [5] = {.index = 4, .length = 1},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_nested, 0, .inherited = true},
  [1] =
    {field_nested, 0},
  [2] =
    {field_nested, 1, .inherited = true},
  [3] =
    {field_nested, 2, .inherited = true},
  [4] =
    {field_nested, 3, .inherited = true},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(3);
      if (lookahead == '\n') SKIP(0)
      if (lookahead == '.') ADVANCE(4);
      if (lookahead == '/') ADVANCE(8);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(5);
      if (lookahead != 0 &&
          lookahead != '^') ADVANCE(7);
      END_STATE();
    case 1:
      if (lookahead == '\n') SKIP(1)
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(6);
      if (lookahead != 0 &&
          lookahead != '/' &&
          lookahead != '^') ADVANCE(7);
      END_STATE();
    case 2:
      if (lookahead == '/') ADVANCE(8);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(2)
      END_STATE();
    case 3:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 4:
      ACCEPT_TOKEN(sym_hidden_node_definition);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '/' &&
          lookahead != '^') ADVANCE(7);
      END_STATE();
    case 5:
      ACCEPT_TOKEN(aux_sym_file_node_definition_token1);
      if (lookahead == '.') ADVANCE(4);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(5);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '/' &&
          lookahead != '^') ADVANCE(7);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(aux_sym_file_node_definition_token1);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(6);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '/' &&
          lookahead != '^') ADVANCE(7);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(aux_sym_file_node_definition_token1);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '/' &&
          lookahead != '^') ADVANCE(7);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0, .external_lex_state = 1},
  [5] = {.lex_state = 0, .external_lex_state = 1},
  [6] = {.lex_state = 0, .external_lex_state = 1},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 1},
  [9] = {.lex_state = 2, .external_lex_state = 1},
  [10] = {.lex_state = 2, .external_lex_state = 1},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0, .external_lex_state = 1},
  [13] = {.lex_state = 0, .external_lex_state = 1},
  [14] = {.lex_state = 2},
  [15] = {.lex_state = 2},
  [16] = {.lex_state = 0, .external_lex_state = 1},
  [17] = {.lex_state = 0, .external_lex_state = 1},
  [18] = {.lex_state = 0, .external_lex_state = 1},
  [19] = {.lex_state = 0, .external_lex_state = 1},
};

enum {
  ts_external_token_newline = 0,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token_newline] = sym_newline,
};

static const bool ts_external_scanner_states[2][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token_newline] = true,
  },
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_hidden_node_definition] = ACTIONS(1),
    [aux_sym_file_node_definition_token1] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [sym_newline] = ACTIONS(1),
  },
  [1] = {
    [sym_file_tree] = STATE(11),
    [sym__node_definition] = STATE(2),
    [sym_file_node_definition] = STATE(12),
    [sym__inline_directory] = STATE(13),
    [sym_directory_node_definition] = STATE(12),
    [sym_title] = STATE(14),
    [aux_sym_file_tree_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_hidden_node_definition] = ACTIONS(5),
    [aux_sym_file_node_definition_token1] = ACTIONS(7),
    [anon_sym_SLASH] = ACTIONS(9),
  },
  [2] = {
    [sym__node_definition] = STATE(3),
    [sym_file_node_definition] = STATE(12),
    [sym__inline_directory] = STATE(13),
    [sym_directory_node_definition] = STATE(12),
    [sym_title] = STATE(14),
    [aux_sym_file_tree_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(11),
    [sym_hidden_node_definition] = ACTIONS(5),
    [aux_sym_file_node_definition_token1] = ACTIONS(7),
    [anon_sym_SLASH] = ACTIONS(9),
  },
  [3] = {
    [sym__node_definition] = STATE(3),
    [sym_file_node_definition] = STATE(12),
    [sym__inline_directory] = STATE(13),
    [sym_directory_node_definition] = STATE(12),
    [sym_title] = STATE(14),
    [aux_sym_file_tree_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(13),
    [sym_hidden_node_definition] = ACTIONS(15),
    [aux_sym_file_node_definition_token1] = ACTIONS(18),
    [anon_sym_SLASH] = ACTIONS(21),
  },
  [4] = {
    [sym_file_node_definition] = STATE(16),
    [sym__inline_directory] = STATE(13),
    [sym_directory_node_definition] = STATE(16),
    [sym_title] = STATE(14),
    [sym__nested] = STATE(17),
    [sym_hidden_node_definition] = ACTIONS(5),
    [aux_sym_file_node_definition_token1] = ACTIONS(7),
    [anon_sym_SLASH] = ACTIONS(9),
    [sym_newline] = ACTIONS(24),
  },
  [5] = {
    [sym_file_node_definition] = STATE(16),
    [sym__inline_directory] = STATE(13),
    [sym_directory_node_definition] = STATE(16),
    [sym_title] = STATE(14),
    [sym__nested] = STATE(18),
    [sym_hidden_node_definition] = ACTIONS(5),
    [aux_sym_file_node_definition_token1] = ACTIONS(7),
    [anon_sym_SLASH] = ACTIONS(9),
    [sym_newline] = ACTIONS(26),
  },
  [6] = {
    [sym_file_node_definition] = STATE(16),
    [sym__inline_directory] = STATE(13),
    [sym_directory_node_definition] = STATE(16),
    [sym_title] = STATE(14),
    [sym__nested] = STATE(19),
    [sym_hidden_node_definition] = ACTIONS(5),
    [aux_sym_file_node_definition_token1] = ACTIONS(7),
    [anon_sym_SLASH] = ACTIONS(9),
    [sym_newline] = ACTIONS(28),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 2,
    ACTIONS(30), 1,
      ts_builtin_sym_end,
    ACTIONS(32), 3,
      sym_hidden_node_definition,
      aux_sym_file_node_definition_token1,
      anon_sym_SLASH,
  [9] = 2,
    ACTIONS(34), 1,
      aux_sym_file_node_definition_token1,
    STATE(15), 1,
      sym_title,
  [16] = 2,
    ACTIONS(36), 1,
      anon_sym_SLASH,
    ACTIONS(38), 1,
      sym_newline,
  [23] = 2,
    ACTIONS(36), 1,
      anon_sym_SLASH,
    ACTIONS(40), 1,
      sym_newline,
  [30] = 1,
    ACTIONS(42), 1,
      ts_builtin_sym_end,
  [34] = 1,
    ACTIONS(44), 1,
      sym_newline,
  [38] = 1,
    ACTIONS(46), 1,
      sym_newline,
  [42] = 1,
    ACTIONS(48), 1,
      anon_sym_SLASH,
  [46] = 1,
    ACTIONS(50), 1,
      anon_sym_SLASH,
  [50] = 1,
    ACTIONS(52), 1,
      sym_newline,
  [54] = 1,
    ACTIONS(54), 1,
      sym_newline,
  [58] = 1,
    ACTIONS(56), 1,
      sym_newline,
  [62] = 1,
    ACTIONS(58), 1,
      sym_newline,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(7)] = 0,
  [SMALL_STATE(8)] = 9,
  [SMALL_STATE(9)] = 16,
  [SMALL_STATE(10)] = 23,
  [SMALL_STATE(11)] = 30,
  [SMALL_STATE(12)] = 34,
  [SMALL_STATE(13)] = 38,
  [SMALL_STATE(14)] = 42,
  [SMALL_STATE(15)] = 46,
  [SMALL_STATE(16)] = 50,
  [SMALL_STATE(17)] = 54,
  [SMALL_STATE(18)] = 58,
  [SMALL_STATE(19)] = 62,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_file_tree, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_file_tree, 1),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_file_tree_repeat1, 2),
  [15] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_file_tree_repeat1, 2), SHIFT_REPEAT(8),
  [18] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_file_tree_repeat1, 2), SHIFT_REPEAT(9),
  [21] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_file_tree_repeat1, 2), SHIFT_REPEAT(4),
  [24] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__inline_directory, 1),
  [26] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__inline_directory, 2),
  [28] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__inline_directory, 3),
  [30] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__node_definition, 2),
  [32] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__node_definition, 2),
  [34] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [36] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_title, 1),
  [38] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_file_node_definition, 1),
  [40] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_file_node_definition, 2),
  [42] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [44] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [46] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_directory_node_definition, 1, .production_id = 1),
  [48] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [50] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [52] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__nested, 1, .production_id = 2),
  [54] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__inline_directory, 2, .production_id = 3),
  [56] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__inline_directory, 3, .production_id = 4),
  [58] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__inline_directory, 4, .production_id = 5),
};

#ifdef __cplusplus
extern "C" {
#endif
void *tree_sitter_lube_external_scanner_create(void);
void tree_sitter_lube_external_scanner_destroy(void *);
bool tree_sitter_lube_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_lube_external_scanner_serialize(void *, char *);
void tree_sitter_lube_external_scanner_deserialize(void *, const char *, unsigned);

#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_lube(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .external_scanner = {
      &ts_external_scanner_states[0][0],
      ts_external_scanner_symbol_map,
      tree_sitter_lube_external_scanner_create,
      tree_sitter_lube_external_scanner_destroy,
      tree_sitter_lube_external_scanner_scan,
      tree_sitter_lube_external_scanner_serialize,
      tree_sitter_lube_external_scanner_deserialize,
    },
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
