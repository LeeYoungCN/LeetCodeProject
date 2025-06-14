#!/usr/bin/bash
file_path="$(
    cd "$(dirname "$0")" || exit 1
    pwd
)"
root_path="$(
    cd "${file_path}/.." || exit 1
    pwd
)"

# shellcheck disable=SC1091
source "${file_path}/common_func.sh"

LEETCODE_INC_DIR="${root_path}/leetcode/inc"
LEETCODE_SRC_DIR="${root_path}/leetcode/src"
TEST_DIR="${root_path}/test"

TEMPLATE_FILE_DIR="${root_path}/script/template"
TEMPLATE_HEAD_FILE="${TEMPLATE_FILE_DIR}/leetcode_head_file.template"
TEMPLATE_SRC_FILE="${TEMPLATE_FILE_DIR}/leetcode_src_file.template"
TEMPLATE_TEST_FILE="${TEMPLATE_FILE_DIR}/leetcode_test_file.template"

leetcode_file_name=""
leetcode_class_name=""
test_class_name=""

head_file_path=""
src_file_path=""
test_file_path=""
def_str=""

prefix=""
url=""
class_name=""

lc_func=""
func_name="LeetCodeFunction(std::vector<int> x)"
func_ret_type="int"
func_param="std::vector<int> x"

time_str="$(date "+%Y-%m-%d %H:%M:%S")"

function print_help() {
    basename "$0"
    echo "      -p|--prefix <file-prefix>   = 问题前缀"
    echo "      -u|--url <url>              = 问题网址"
    echo "      -f|--func <function-name>   = 函数名称"
    echo "      -n|--name <class-name>      = 文件和类名称, 如果为空从url中获取"
}

if ! ARGS=$(getopt -o p:u:f:n:? --long prefix:,url:,func:,name:,help -n "$0" -- "$@"); then
    echo "Terminating..." >&2
    exit 1
fi

eval set -- "$ARGS"

while true; do
    case "$1" in
    -p | --prefix)
        prefix="$2"
        shift 2
        ;;
    -u | --url)
        url="$2"
        shift 2
        ;;
    -f | --func)
        lc_func="$2"
        shift 2
        ;;
    -n | --name)
        class_name="$2"
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

if [ -z "${prefix}" ]; then
    print_log "prefix empty."
    exit 1
fi

if [ -z "${class_name}" ] && [ -z "${url}" ]; then
    print_log "name empty."
    exit 1
fi

echo "prefix [${prefix}]"
echo "url    [${url}]"

if [ -n "${lc_func}" ]; then
    echo "func   [${lc_func}]"
fi

function create_new_file_by_template() {
    local template_file="$1"
    local new_file="$2"

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
    replace_text "URL_STR" "${url}" "${new_file}"
    replace_text "CLASS_NAME" "${leetcode_class_name}" "${new_file}"
    replace_text "DEF_STR" "${def_str}" "${new_file}"
    replace_text "HEAD_FILE_NAME" "${leetcode_file_name}.h" "${new_file}"
    replace_text "TEST_CLASSNAME" "${test_class_name}" "${new_file}"
    replace_text "FUNC_RET_TYPE" "${func_ret_type}" "${new_file}"
    replace_text "FUNC_PARAM" "${func_param}" "${new_file}"
    replace_text "CLASS_FUNC" "${func_name}" "${new_file}"
    replace_text "TIME_STR" "${time_str}" "${new_file}"
    replace_text "PARAM_NAMES" "${param_names}" "${new_file}"
}

function main() {
    if [ -n "${lc_func}" ]; then
        func_name="${lc_func%(*}"
        func_ret_type="${func_name% *}"
        func_name="${func_name##* }"

        func_param="${lc_func##*(}"
        func_param="${func_param%)}"
    fi

    IFS=' ' read -r -a array <<<"${func_param}"
    length=${#array[@]}

    index=1
    param_names=""
    while [[ $index -lt $length ]]; do
        param_names="${param_names}${array[$index]}"
        if [ $index -lt $((length - 1)) ]; then
            param_names="${param_names} "
        fi
        index=$((index + 2))
    done

    local problem_name
    local prefix_fmt
    local problem_fmt

    if [ -z "${class_name}" ]; then
        # https://leetcode.cn/problems-name/
        problem_name=$(awk -F / '{print $5}' <<<"${url}")
    else
        problem_name="${class_name}"
    fi

    problem_name="${problem_name//-/_}"
    prefix_fmt=$(tr '[:lower:]' '[:upper:]' <<<"${prefix}")
    problem_fmt=$(sed -r 's/(^|_)(\w)/\U\2/g' <<<"${problem_name}")

    leetcode_file_name="${prefix}_${problem_name}"
    leetcode_class_name="${prefix_fmt}_${problem_fmt}"

    test_class_name="TEST_${prefix_fmt}"

    head_file_path="${LEETCODE_INC_DIR}/${leetcode_file_name}.h"
    src_file_path="${LEETCODE_SRC_DIR}/${leetcode_file_name}.cpp"
    test_file_path="${TEST_DIR}/test_${leetcode_file_name}.cpp"
    def_str="$(tr '[:lower:]' '[:upper:]' <<<"${leetcode_file_name}")_H"

    create_new_file_by_template "${TEMPLATE_HEAD_FILE}" "${head_file_path}"
    create_new_file_by_template "${TEMPLATE_SRC_FILE}" "${src_file_path}"
    create_new_file_by_template "${TEMPLATE_TEST_FILE}" "${test_file_path}"
}

main
