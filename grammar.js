"use strict";

const name_pattern = /[^\n^\/]+/;
const newline = /\r?\n/;

// TODO: Implement tabbed sub-trees.
module.exports = grammar({
  name: "lube",
  rules: {
    tree: $ => repeat(seq($._node, newline)),
    _node: $ => choice($.file, $.directory),
    file: $ => name_pattern,
    directory: function($) {
      const nested = field("nested", optional(choice($.directory, $.file)))
      const separate = field("separate", "/")
      return seq(optional($.directory_name), separate, nested)
    },
    directory_name: $ => name_pattern,
  },
});
