"use strict";

const title_pattern = /[^\n^\/]+/;
const newline = /\r?\n/;
const indent = "  "

module.exports = grammar({
  name: "lube",
  rules: {
    tree: $ => repeat($._node),
    _node: $ => seq(choice($.file, $.directory), newline),

    file: $ => title_pattern,
    _separate: $ => field("separate", "/"),
    directory: $ => seq(optional($._title), $._separate, optional($._nested)),
    _title: $ => field("title", title_pattern),

    _nested: $ => field("nested", choice($.directory, $.file)),
  },
});
