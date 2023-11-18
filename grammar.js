const name_pattern = /[^\n^/]+/
module.exports = grammar({
  name: "lube",
  rules: {
    tree: $ => repeat($._node),
    _node: $ => choice($.file, $.directory),
    file: $ => name_pattern,
    directory: $ => prec.left(1, seq(name_pattern, "/", optional(choice($.directory, $.file)))),
  }
});
