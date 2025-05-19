#!/bin/bash
file_path="$(cd $(dirname $0); pwd)"
root_path="$(cd ${file_path}/..; pwd)"

LEETCODE_INC_DIR="${root_path}/leetcode/include"
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

lc_func=""
func_name="LeetCodeFunction(std::vector<int> x)"
func_ret_type="int"

ARGS=$(getopt -o p:u:f: --long prefix:,url:,func: -n "$0" -- "$@")

if [ $? != 0 ]; then
    echo "Terminating..." >&2 ;
    exit 1;
fi

eval set -- "$ARGS"

while true; do
    case "$1" in
        -p|--prefix) prefix="$2"; shift 2;;
        -u|--url)    url="$2";    shift 2;;
        -f|--func)   lc_func="$2"; shift 2;;
        --) shift; break;;
        *) echo "Internal error!"; exit 1;;
    esac
done

if [ -z "${prefix}" ] || [ -z "${url}" ]; then
    echo "error"
fi

echo "prefix [${prefix}]"
echo "url    [${url}]"

if [ -n "${lc_func}" ]; then
    echo "func   [${lc_func}]"
fi

replace_text() {
    local old_str="$1"
    local new_str="$2"
    local file_path="$3"
    sed -i "s#${old_str}#${new_str}#g" "${file_path}"
}

create_new_file_by_template() {
    local template_file="$1"
    local new_file="$2"

    echo "create [${new_file}]"

    if [ ! -e ${template_file} ]; then
        echo "template file not exist!"
        exit 1
    fi

    if [ -e ${new_file} ]; then
        echo "new file already exist!"
        exit 1
    fi

    cp "${template_file}" "${new_file}" || exit 1
    replace_text "URL_STR"          "${url}"                    "${new_file}"
    replace_text "CLASS_NAME"       "${leetcode_class_name}"    "${new_file}"
    replace_text "DEF_STR"          "${def_str}"                "${new_file}"
    replace_text "HEAD_FILE_NAME"   "${leetcode_file_name}.h"   "${new_file}"
    replace_text "TEST_CLASSNAME"   "${test_class_name}"        "${new_file}"
    replace_text "FUNC_RET_TYPE"    "${func_ret_type}"          "${new_file}"
    replace_text "CLASS_FUNC"       "${func_name}"              "${new_file}"
}

main() {
    if [ -n "${lc_func}" ]; then
        func_name="${lc_func#* }"
        echo "func_name=[${func_name}]"
        func_ret_type="${lc_func%% *}"
        echo "func_ret_type=[${func_ret_type}]"
    fi

    # "https://leetcode.cn/problems/"
    local problem_name=$(echo ${url} | awk -F / '{print $5}')
    problem_name=$(echo ${problem_name} | sed  's/-/_/g')

    local prefix_fmt=$(echo ${prefix} | sed -r 's/(^|_)(\w)/\U\2/g')
    local problem_fmt=$(echo ${problem_name} | sed -r 's/(^|_)(\w)/\U\2/g')

    leetcode_file_name="${prefix}_${problem_name}"
    leetcode_class_name="${prefix_fmt}_${problem_fmt}"

    test_class_name="Test_${prefix_fmt}"

    head_file_path="${LEETCODE_INC_DIR}/${leetcode_file_name}.h"
    src_file_path="${LEETCODE_SRC_DIR}/${leetcode_file_name}.cpp"
    test_file_path="${TEST_DIR}/test_${leetcode_file_name}.cpp"
    def_str="$(echo ${leetcode_file_name} | tr 'a-z' 'A-Z')_H"

    create_new_file_by_template "${TEMPLATE_HEAD_FILE}" "${head_file_path}"
    create_new_file_by_template "${TEMPLATE_SRC_FILE}"  "${src_file_path}"
    create_new_file_by_template "${TEMPLATE_TEST_FILE}" "${test_file_path}"
}

main
