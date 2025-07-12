#!/usr/local/bin/bash
SCRIPT_DIR="$(
    cd "$(dirname "$0")" || exit 1
    pwd
)"
ROOT_DIR="$(
    cd "${SCRIPT_DIR}/.." || exit 1
    pwd
)"

readonly SCRIPT_DIR
readonly ROOT_DIR

# shellcheck disable=SC1091
source "${SCRIPT_DIR}/common_func.sh"

readonly LEETCODE_SRC_DIR="${ROOT_DIR}/code//leetcode/src"
readonly PROBLEM_LIST_FILE="${ROOT_DIR}/code/problem_list"

if [ -e "${PROBLEM_LIST_FILE}" ]; then
    rm "${PROBLEM_LIST_FILE}"
fi


find "${LEETCODE_SRC_DIR}" -type f -exec bash -c '
  for file do
    base=$(basename "${file}")
    echo "${base%.*}"  # 去除最后一个扩展名
  done
' _ {} + | sort >> "${PROBLEM_LIST_FILE}"

print_log "Refresh ${PROBLEM_LIST_FILE} success." info
