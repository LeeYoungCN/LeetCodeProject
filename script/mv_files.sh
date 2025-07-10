#!/usr/local/bin/bash
echo "Bash version: $BASH_VERSION"
if [ -z "$BASHRC_LOADED" ]; then
    # shellcheck disable=SC1091
    source "${HOME}/.bashrc"
fi

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

cd "${ROOT_DIR}" || exit 1

CODE_DIR="${ROOT_DIR}/code"

LEETCODE_DIR="${CODE_DIR}/leetcode"
LEETCODE_SRC_DIR="${LEETCODE_DIR}/src"
LEETCODE_INC_DIR="${LEETCODE_DIR}/inc"
TEST_DIR="${CODE_DIR}/test"

function mv_file()
{
    local file=$1
    local dst_dir=$2
    local inc_str="${3}"
    local new_inc_str="${4}"

    if [ ! -e "${file}" ]; then
        ehco "${file} not exit!"
        return
    fi

    if [ ! -d "${dst_dir}" ]; then
        mkdir -p "${dst_dir}"
    fi
    replace_text "${inc_str}" "${new_inc_str}" "${file}"
    mv "${file}" "${dst_dir}"
}

function mv_all_files() {
    find "${LEETCODE_SRC_DIR}" -maxdepth 1 -type f -name 'lc*.cpp' -print0 |
        while IFS= read -r -d '' src_file; do
            local src_file_name
            src_file_name="$(basename "${src_file}")"
            local problem_name="${src_file_name%.cpp}"
            local inc_file="${LEETCODE_INC_DIR}/${problem_name}.h"
            local test_file="${TEST_DIR}/test_${problem_name}.cpp"
            local prefix=${problem_name%%_*}
            local fold_name="${prefix%??}xx"
            local inc_str="${problem_name}.h"
            local new_inc_str="${fold_name}/${problem_name}.h"

            mv_file "${src_file}" "${LEETCODE_SRC_DIR}/${fold_name}" "${inc_str}" "${new_inc_str}"
            mv_file "${inc_file}" "${LEETCODE_INC_DIR}/${fold_name}" "${inc_str}" "${new_inc_str}"
            mv_file "${test_file}" "${TEST_DIR}/test_${fold_name}" "${inc_str}" "${new_inc_str}"
        done
}

mv_all_files
