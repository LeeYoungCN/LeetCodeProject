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

find "${CODE_DIR}" -type f \( -name "*.cpp" -o -name "*.hpp" -o -name "*.h" \) -exec clang-format -i {} +
