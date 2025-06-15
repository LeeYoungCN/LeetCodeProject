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

cd ${ROOT_DIR} || exit 1

readonly BUILDCACHE_ROOT_DIR="${ROOT_DIR}/out/build"
readonly INSTALL_ROOT_DIR="${ROOT_DIR}/out/install"
readonly TOOLCHAIN_FILE_DIR="${ROOT_DIR}/cmake"

arg_enable_clean=0
arg_enable_build=0
arg_enable_configure=0
arg_enable_install=0
arg_enable_gtest=0
arg_enable_ctest=0

arg_preset=""
arg_prefix=""
arg_target="all"
arg_component="all"
arg_gtest_case="*"
arg_ctest_case=""

cmake_source_dir=""
cmake_build_dir=""
cmake_install_dir=""
cmake_build_type=""
cmake_toolchain_file=""
cmake_generator=""
cmake_preset=""
cmake_problem_prefix=""
cmake_build_target=""
cmake_install_target=""
cmake_configure_param_cfg=""

function print_help() {
    echo "$(basename "$0") [options]"
    echo "Options:"
    echo "    -c | --clean                    Remove cmake build direction and cmake install direction."
    echo "    -p | --prefix=<problem-pefix>   Set problem prefix. problem-pefix: ALL(default), lc0012, lc0017 ..."
    echo "    -s | --preset=<preset-name>     CMake configure preset."
    echo "                                    Windows: mingw_debug(default), mingw_release"
    echo "                                    Linux:   linux_clang_debug(default), linux_clang_releas, linux_gnu_debug, linux_gnu_release"
    echo "                                    Darwin:  darwin_clang_debug(default), darwin_clang_releas"
    echo "    --configure                     Run CMake configure"
    echo "    --build[=<target-name>]         Run cmake --build <cmake-build-dir> [--target <target-name>] -j4"
    echo "                                    List all target name: --build=list"
    echo "    --install[=<component>]         Run install cmake --install <cmake-build-dir> [--component <component>]."
    echo "                                    List all component: --install=list"
    echo "    --gtest[=<gtest-case>]          Run all gtest test case:      --gtest"
    echo "                                    Run target gtest test case:   --gtestr=<gtest-case>."
    echo "                                    Get gtest case list:          --gtest=list."
    echo "    --ctest[=<ctest-case>]          Rerun ctest case TEST_ALL:    --ctest or --ctest=all."
    echo "                                    Run target ctest case:        --ctest=<ctest-case>."
    echo "                                    Run last failed ctest case:   --ctest=rerun."
    echo "                                    Get gtest case list:          --ctest=list."
    echo "    --help                          Get help info."
}

function init_cmake_configure_param() {
    if [ -n "${arg_preset}" ]; then
        cmake_preset="${arg_preset}"
    else
        os=$(uname -s)
        if echo "${os}" | grep -q "MINGW"; then
            os="Windows"
        fi

        case ${os} in
        Windows)
            cmake_preset="mingw_debug"
            ;;
        Linux)
            cmake_preset="linux_clang_debug"
            ;;
        Darwin)
            cmake_preset="darwin_clang_debug"
            ;;
        *)
            print_log "os: ${os} error!"
            exit 1
            ;;
        esac
    fi

    case "$cmake_preset" in
    linux_gnu_debug)
        cmake_toolchain_file=${TOOLCHAIN_FILE_DIR}/linux_gnu.cmake
        cmake_generator="Unix Makefiles"
        cmake_build_type="Debug"
        ;;
    linux_gnu_release)
        cmake_toolchain_file=${TOOLCHAIN_FILE_DIR}/linux_gnu.cmake
        cmake_generator="Unix Makefiles"
        cmake_build_type="Release"
        ;;
    linux_clang_debug)
        cmake_toolchain_file=${TOOLCHAIN_FILE_DIR}/linux_clang.cmake
        cmake_generator="Unix Makefiles"
        cmake_build_type="Debug"
        ;;
    linux_clang_release)
        cmake_toolchain_file=${TOOLCHAIN_FILE_DIR}/linux_clang.cmake
        cmake_generator="Unix Makefiles"
        cmake_build_type="Release"
        ;;
    mingw_debug)
        cmake_toolchain_file=${TOOLCHAIN_FILE_DIR}/mingw.cmake
        cmake_generator="MinGW Makefiles"
        cmake_build_type="Debug"
        ;;
    mingw_release)
        cmake_toolchain_file=${TOOLCHAIN_FILE_DIR}/mingw.cmake
        cmake_generator="MinGW Makefiles"
        cmake_build_type="Release"
        ;;
    darwin_clang_debug)
        cmake_toolchain_file=${TOOLCHAIN_FILE_DIR}/drawin_clang.cmake
        cmake_generator="Unix Makefiles"
        cmake_build_type="Debug"
        ;;
    darwin_clang_release)
        cmake_toolchain_file=${TOOLCHAIN_FILE_DIR}/drawin_clang.cmake
        cmake_generator="Unix Makefiles"
        cmake_build_type="Release"
        ;;
    *)
        print_log "Preset: ${arg_preset} error!" error
        exit 1
        ;;
    esac

    if [ -z "${arg_prefix}" ]; then
        cmake_problem_prefix="ALL"
    else
        cmake_problem_prefix="${arg_prefix}"
    fi

    cmake_install_dir="${INSTALL_ROOT_DIR}/${arg_preset}"

    print_log "Init CMake configure param success." info
}

function print_cmake_configure_info() {
    print_log "cmake_preset:                ${cmake_preset}" info
    print_log "cmake_problem_prefix:        ${cmake_problem_prefix}" info
    print_log "cmake_build_type:            ${cmake_build_type}" info
    print_log "cmake_generator:             ${cmake_generator}" info
    print_log "cmake_toolchain_file:        ${cmake_toolchain_file}" info
    print_log "cmake_source_dir:            ${cmake_source_dir}" info
    print_log "cmake_build_dir:             ${cmake_build_dir}" info
    print_log "cmake_install_dir:           ${cmake_install_dir}" info
    print_log "cmake_configure_param_cfg:   ${cmake_configure_param_cfg}" info
}

function record_cmake_configure_param() {
    mkdir -p "${cmake_build_dir}"
    wright_kv_to_file "cmake_preset" "${cmake_preset}" "${cmake_configure_param_cfg}"
    wright_kv_to_file "cmake_problem_prefix" "${cmake_problem_prefix}" "${cmake_configure_param_cfg}"
    wright_kv_to_file "cmake_build_type" "${cmake_build_type}" "${cmake_configure_param_cfg}"
    wright_kv_to_file "cmake_generator" "${cmake_generator}" "${cmake_configure_param_cfg}"
    wright_kv_to_file "cmake_toolchain_file" "${cmake_toolchain_file}" "${cmake_configure_param_cfg}"
    wright_kv_to_file "cmake_source_dir" "${cmake_source_dir}" "${cmake_configure_param_cfg}"
    wright_kv_to_file "cmake_build_dir" "${cmake_build_dir}" "${cmake_configure_param_cfg}"
    wright_kv_to_file "cmake_install_dir" "${cmake_install_dir}" "${cmake_configure_param_cfg}"
}

function cmake_configure() {
    rm_dir "${cmake_build_dir}"

    init_cmake_configure_param
    record_cmake_configure_param
    print_cmake_configure_info

    if cmake -S "${cmake_source_dir}" \
        -B "${cmake_build_dir}" \
        -G "${cmake_generator}" \
        -DCMAKE_TOOLCHAIN_FILE="${cmake_toolchain_file}" \
        -DCMAKE_BUILD_TYPE="${cmake_build_type}" \
        -DCMAKE_INSTALL_PREFIX="${cmake_install_dir}" \
        -DPROBLEM_PREFIX="${cmake_problem_prefix}"; then
        print_log "CMake configuration success." info
    else
        print_log "CMake configuration failed." error
        exit 1
    fi
}

function cmake_build() {
    if [ ! -d "${cmake_build_dir}" ]; then
        print_log "CMake not confiure." error
        exit 1
    fi

    cmake_build_target="${arg_target}"
    # shellcheck disable=SC1090
    source "${cmake_configure_param_cfg}"
    print_cmake_configure_info

    case ${cmake_build_target} in
    list)
        cmake --build "${cmake_build_dir}" --target "help"
        ;;
    *)
        if cmake --build "${cmake_build_dir}" --target "${cmake_build_target}" -j4; then
            print_log "CMake build success." info
        else
            print_log "CMake build failed." error
            exit 1
        fi
        ;;
    esac
}

function cmake_install() {
    # shellcheck disable=SC1090
    source "${cmake_configure_param_cfg}"
    print_cmake_configure_info

    rm_dir "${cmake_install_dir}"
    cmake_install_target=${arg_component}

    case ${cmake_install_target} in
    list)
        cmake --build "${cmake_build_dir}" --target "list_install_components" -j4
        ;;
    *)
        if cmake --install "${cmake_build_dir}"; then
            print_log "CMake install success." info
        else
            print_log "CMake install failed." error
            exit 1
        fi
        ;;
    esac

}

function run_gtest() {
    case "${arg_gtest_case}" in
    list)
        "${cmake_build_dir}"/bin/leetcode_test --gtest_list_tests
        ;;
    *)
        "${cmake_build_dir}"/bin/leetcode_test --gtest_filter="${arg_gtest_case}"
        ;;
    esac
}

function run_ctest() {
    if [ -z "${arg_ctest_case}" ]; then
        ctest --output-on-failure --test-dir "${cmake_build_dir}" -R "TEST_ALL"
        return 0
    fi

    case "${arg_ctest_case}" in
    list)
        ctest --test-list --test-dir "${cmake_build_dir}"
        ;;
    rerun)
        ctest --rerun-failed --output-on-failure --test-dir "${cmake_build_dir}"
        ;;
    all)
        ctest --output-on-failure --test-dir "${cmake_build_dir}" -R "TEST_ALL"
        ;;
    *)
        ctest --output-on-failure --test-dir "${cmake_build_dir}" -R "${arg_ctest_case}"
        ;;
    esac
}

function main() {

    if ! ARGS=$(getopt -o cp:s: --long clean,install::,preset:,prefix:,configure,build::,gtest::,ctest::,help -n "$0" -- "$@"); then
        print_log "getopt failed." error
        exit 1
    fi

    eval set -- "$ARGS"

    while true; do
        case "$1" in
        -c | --clean)
            arg_enable_clean=1
            shift 1
            ;;
        -p | --prefix)
            arg_prefix=$2
            shift 2
            ;;
        -s | --preset)
            arg_preset=$2
            shift 2
            ;;
        --configure)
            arg_enable_configure=1
            shift 1
            ;;
        --build)
            arg_enable_build=1
            if [ -n "${2}" ]; then
                arg_target=$2
            fi
            shift 2
            ;;
        --install)
            arg_enable_install=1
            if [ -n "${2}" ]; then
                arg_component="${2}"
            fi
            shift 2
            ;;
        -t | --gtest)
            arg_enable_build=1
            arg_enable_gtest=1
            if [ -n "$2" ]; then
                arg_gtest_case="$2"
            fi
            shift 2
            ;;
        --ctest)
            arg_enable_build=1
            arg_enable_ctest=1
            if [ -n "$2" ]; then
                arg_ctest_case="$2"
            fi
            shift 2
            ;;
        --help)
            print_help
            exit 0
            ;;
        --)
            shift 1
            break
            ;;
        *)
            print_log "Invalid param [${1}]." error
            exit 1
            ;;
        esac
    done

    cmake_source_dir="${ROOT_DIR}"
    cmake_build_dir="${BUILDCACHE_ROOT_DIR}"
    cmake_configure_param_cfg="${cmake_build_dir}/cmake_configure.conf"
    readonly cmake_configure_param_cfg

    if [ ${arg_enable_clean} -ne 0 ]; then
        rm_dir "${cmake_build_dir}"
        rm_dir "${cmake_install_dir}"
    fi

    if [ ${arg_enable_configure} -ne 0 ]; then
        cmake_configure
    fi

    if [ ${arg_enable_build} -ne 0 ]; then
        cmake_build
    fi

    if [ ${arg_enable_install} -ne 0 ]; then
        cmake_install
    fi

    if [ ${arg_enable_gtest} -ne 0 ]; then
        run_gtest
    fi

    if [ ${arg_enable_ctest} -ne 0 ]; then
        run_ctest
    fi
}

main "$@"
