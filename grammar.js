module.exports = grammar({
  name: "lube",
  rules: {
    tree: $ => repeat($._definition),
    _definition: $ => choice($.file, $.directory, $.link),
    file: $ => /\w/,
    directory: $ => seq(/\w/, "/"),
    link: $ => seq(/\w/, "->", /\w/)
  },
});
