#!/usr/bin/bash
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

readonly LEETCODE_INC_DIR="${ROOT_DIR}/code/leetcode/inc"
readonly LEETCODE_SRC_DIR="${ROOT_DIR}/code/leetcode/src"
readonly TEST_DIR="${ROOT_DIR}/code/test"

readonly TEMPLATE_FILE_DIR="${ROOT_DIR}/script/template"
readonly TEMPLATE_HEAD_FILE="${TEMPLATE_FILE_DIR}/leetcode_head_file.h.in"
readonly TEMPLATE_SRC_FILE="${TEMPLATE_FILE_DIR}/leetcode_src_file.cpp.in"
readonly TEMPLATE_TEST_FILE="${TEMPLATE_FILE_DIR}/leetcode_test_file.cpp.in"

ARG_PREFIX=""
ARG_URL=""
ARG_CLASS_NAME=""
ARG_FUNC="int LeetCodeFunction(std::vector<int> x, int y)"

g_leetcode_file_name=""
g_leetcode_class_name=""
g_test_class_name=""
g_def_str=""

g_func_name=""
g_func_ret_type=""
g_func_param=""
g_param_names=""

function print_help() {
    echo "$(basename "$0") [options]"
    echo "Options:"
    echo "    -p | --prefix <file-prefix>   = 问题前缀"
    echo "    -u | --url <url>              = 问题网址"
    echo "    -f | --func <function-name>   = 函数名称"
    echo "    -n | --name <class-name>      = 文件和类名称, 如果为空从url中获取"
}

if ! ARGS=$(getopt -o p:u:f:n:? --long prefix:,url:,func:,name:,help -n "$0" -- "$@"); then
    echo "Terminating..." >&2
    exit 1
fi

eval set -- "$ARGS"

while true; do
    case "$1" in
    -p | --prefix)
        ARG_PREFIX="$2"
        readonly ARG_PREFIX
        shift 2
        ;;
    -u | --url)
        ARG_URL="$2"
        readonly ARG_URL
        shift 2
        ;;
    -f | --func)
        ARG_FUNC="$2"
        readonly ARG_FUNC
        shift 2
        ;;
    -n | --name)
        ARG_CLASS_NAME="$2"
        readonly ARG_CLASS_NAME
        shift 2
        ;;
    --help)
        print_help
        exit 0
        ;;
    --)
        shift
        break
        ;;
    *)
        echo "Internal error!"
        exit 1
        ;;
    esac
done

if [ -z "${ARG_PREFIX}" ]; then
    print_log "prefix empty."
    exit 1
fi

if [ -z "${ARG_CLASS_NAME}" ] && [ -z "${ARG_URL}" ]; then
    print_log "name empty."
    exit 1
fi

echo "prefix [${ARG_PREFIX}]"
echo "url    [${ARG_URL}]"

if [ -n "${ARG_FUNC}" ]; then
    echo "func   [${ARG_FUNC}]"
fi

function create_new_file_by_template() {
    local template_file="$1"
    local new_file="$2"
    local time_str
    time_str="$(date "+%Y-%m-%d %H:%M:%S")"

    print_log "create [${new_file}]"

    if [ ! -e "${template_file}" ]; then
        print_log "template file not exist!"
        exit 1
    fi

    if [ -e "${new_file}" ]; then
        print_log "new file already exist!"
        return 0
    fi

    cp "${template_file}" "${new_file}" || exit 1
    replace_text "@URL_STR@" "${ARG_URL}" "${new_file}"
    replace_text "@CLASS_NAME@" "${g_leetcode_class_name}" "${new_file}"
    replace_text "@DEF_STR@" "${g_def_str}" "${new_file}"
    replace_text "@HEAD_FILE_NAME@" "${g_leetcode_file_name}.h" "${new_file}"
    replace_text "@TEST_CLASSNAME@" "${g_test_class_name}" "${new_file}"
    replace_text "@FUNC_RET_TYPE@" "${g_func_ret_type}" "${new_file}"
    replace_text "@FUNC_PARAM@" "${g_func_param}" "${new_file}"
    replace_text "@CLASS_FUNC@" "${g_func_name}" "${new_file}"
    replace_text "@TIME_STR@" "${time_str}" "${new_file}"
    replace_text "@PARAM_NAMES@" "${g_param_names}" "${new_file}"
    print_log "create [${new_file}] success." info
}

function get_function_data() {
    local func_name_with_ret="${ARG_FUNC%(*}"

    g_func_ret_type="${func_name_with_ret% *}"
    g_func_name="${func_name_with_ret##* }"

    g_func_param="${ARG_FUNC##*(}"
    g_func_param="${g_func_param%)}"

    IFS=',' read -r -a array <<<"${g_func_param}"
    local length=${#array[@]}
    local index=0

    for praram in "${array[@]}"; do
        g_param_names="${g_param_names}${praram##* }"
        if [ $index -lt $((length - 1)) ]; then
            g_param_names="${g_param_names}, "
        fi
        index=$((index + 1))
    done
}

function refresh_problem_prefix() {
    local cmake_preset_file=${ROOT_DIR}/CMakePresets.json
    local problem_prefix
    local trimmed
    problem_prefix=$(grep CMAKE_PROBLEM_PREFIX "${cmake_preset_file}")
    trimmed=$(echo "$problem_prefix" | sed -e 's/^[[:space:]]*//' -e 's/[[:space:]]*$//')
    replace_text "${trimmed}" "\"CMAKE_PROBLEM_PREFIX\": \"${g_leetcode_file_name}\"," "${cmake_preset_file}"
}

function get_class_data() {
    local raw_class_name
    local prefix_fmt
    local class_name_fmt

    if [ -z "${ARG_CLASS_NAME}" ]; then
        # https://leetcode.cn/problems-name/
        raw_class_name=$(awk -F / '{print $5}' <<<"${ARG_URL}")
    else
        raw_class_name="${ARG_CLASS_NAME}"
    fi

    raw_class_name="${raw_class_name//-/_}"
    prefix_fmt=$(tr '[:lower:]' '[:upper:]' <<<"${ARG_PREFIX}")
    class_name_fmt=$(sed -r 's/(^|_)(\w)/\U\2/g' <<<"${raw_class_name}")

    g_leetcode_file_name="${ARG_PREFIX}_${raw_class_name}"
    g_leetcode_class_name="${prefix_fmt}_${class_name_fmt}"

    g_test_class_name="TEST_${prefix_fmt}"
    g_def_str="$(tr '[:lower:]' '[:upper:]' <<<"${g_leetcode_file_name}")_H"
}

function create_file() {
    local head_file_path="${LEETCODE_INC_DIR}/${g_leetcode_file_name}.h"
    local src_file_path="${LEETCODE_SRC_DIR}/${g_leetcode_file_name}.cpp"
    local test_file_path="${TEST_DIR}/test_${g_leetcode_file_name}.cpp"

    create_new_file_by_template "${TEMPLATE_HEAD_FILE}" "${head_file_path}"
    create_new_file_by_template "${TEMPLATE_SRC_FILE}" "${src_file_path}"
    create_new_file_by_template "${TEMPLATE_TEST_FILE}" "${test_file_path}"
}

function main() {
    get_function_data
    get_class_data
    create_file
    refresh_problem_prefix
    "${SCRIPT_DIR}/refresh_problem_list.sh"
}

main
