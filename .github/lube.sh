#!/usr/bin/env bash

TS="./node_modules/.bin/tree-sitter"

function validate() {
  if [[ ! -f node_modules/.bin/tree-sitter ]]; then
    if [[ $1 == message ]]; then
      echo ERROR: Dependencies are not installed. Try running lube.sh install
    fi
    return 1
  fi
  return 0
}

function commands() {
  echo ./.github/lube.sh '[parse|clean|build|refresh|purge|install|test|help]'
}

for item in "$@"; do
  case "$item" in
    clean) rm -rf bindings src binding.gyp Cargo.toml build &>/dev/null ;;
    build) validate message && $TS generate && node-gyp configure build ;;
    refresh) ./.github/lube.sh clean build ;;
    purge) ./.github/lube.sh clean && rm -rf ./node_modules &>/dev/null ;;
    install) npm install ;;
    test) $TS test ;;
    parse) $TS parse ;;
    help) commands ;;
    *) echo ERROR: No option named "$item" && commands ;;
  esac
done
