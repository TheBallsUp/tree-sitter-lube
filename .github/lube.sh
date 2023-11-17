#!/usr/bin/env bash

function validate() {
  if [[ ! -f node_modules/.bin/tree-sitter ]]; then
    if [[ $1 == message ]]; then
      echo ERROR: Dependencies are not installed. Try running lube.sh install
    fi
    return 1
  fi
  return 0
}

for item in $1; do
  case "$item" in
    clean) rm -r bindings src binding.gyp Cargo.toml ;;
    build) validate message && ./node_modules/.bin/tree-sitter generate ;;
    refresh) ./.github/lube.sh clean build ;;
    purge) ./.github/lube.sh clean && rm -rf ./node_modules ;;
    install) npm install --save nan && npm install --save-dev tree-sitter-cli ;;
  esac
done
