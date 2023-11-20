"use strict";

const indent = "  "
const title_pattern = /[^\n^\/]+/;

module.exports = grammar({
  name: "lube",
  externals: $ => [
    $.newline
  ],
  rules: {
    file_tree: $ => repeat($._node_definition),
    _node_definition: $ => seq(choice($.file_node_definition, $.directory_node_definition), $.newline),
    hidden_node_definition: $ => ".",
    file_node_definition: $ => seq(optional($.hidden_node_definition), title_pattern),
    _inline_directory: $ => seq(optional(seq(optional($.hidden_node_definition), $.title)), "/", optional($._nested)),
    directory_node_definition: $ => $._inline_directory,
    title: $ => title_pattern,
    _nested: $ => field("nested", choice($.directory_node_definition, $.file_node_definition)),
  },
});
