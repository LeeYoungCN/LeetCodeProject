#!/usr/local/bin/bash
SCRIPT_DIR="$(
    cd "$(dirname "$0")" || exit 1
    pwd
)"
ROOT_DIR="$(
    cd "${SCRIPT_DIR}/.." || exit 1
    pwd
)"

CODE_DIR="${ROOT_DIR}/code"

readonly FILES=(
    "${CODE_DIR}/utils/inc/*.hpp"
    "${CODE_DIR}/utils/src/*.cpp"
    "${CODE_DIR}/leetcode/inc/*.h"
    "${CODE_DIR}/leetcode/src/*.cpp"
    "${CODE_DIR}/test/*.cpp"
    )

for ELEMENT in "${FILES[@]}"; do
    clang-format -i ${ELEMENT}
done
