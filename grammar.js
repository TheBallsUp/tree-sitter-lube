"use strict";

const title_pattern = /[^\n^\/]+/;

module.exports = grammar({
  name: "lube",
  externals: $ => [
    $.newline,
    $.indent,
    $.dedent,
  ],
  rules: {
    file_tree: $ => repeat($._node_definition),

    _node_definition: $ => seq(choice($.file_node_definition, $.directory_node_definition), $.newline),

    hidden_node_definition: $ => ".",
    file_node_definition: $ => seq(optional($.hidden_node_definition), title_pattern),
    directory_node_definition: $ => seq(optional(seq(optional($.hidden_node_definition), $.title)), "/", optional($._nested)),

    title: $ => title_pattern,
    _nested: $ => field("nested", choice($.directory_node_definition, $.file_node_definition)),
  },
});
