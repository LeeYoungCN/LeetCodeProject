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

buildcache_root_dir="${root_path}/out/build"
install_root_dir="${root_path}/out/install"

toolchain_file_dir="${root_path}/cmake"
build_type="Debug"

google_test_case=""
ctest_case=""
enable_clean=1
enable_install=1
preset="linux_gnu_debug"
cmake_preset_file="${root_path}/CMakePresets.json"
prefix=$(grep "PROBLEM_PREFIX" "${cmake_preset_file}" | awk -F'"' '{print$4}')

if ! ARGS=$(getopt -o ct:s:p: --long clean,gtest:,pre_set:,prefix:,ctest:,install -n "$0" -- "$@"); then
    echo "Terminating..." >&2
    exit 1
fi

eval set -- "$ARGS"

while true; do
    case "$1" in
    -c | --clean)
        enable_clean=0
        shift 1
        ;;
    -s | --pre_set)
        preset="$2"
        shift 2
        ;;
    -p | --prefix)
        prefix="$2"
        shift 2
        ;;
    -t | --gtest)
        google_test_case="$2"
        shift 2
        ;;
    --ctest)
        ctest_case="$2"
        shift 2
        ;;
    --install)
        enable_install=0
        shift 1
        ;;
    --)
        shift 1
        break
        ;;
    *)
        print_log "Internal error!"
        exit 1
        ;;
    esac
done

os=$(uname -s)

if echo "${os}" | grep -q "MINGW"; then
    os="MINGW"
    preset="mingw_debug"
elif [ "${os}" = "Darwin" ]; then
    preset="darwin_clang_debug"
fi

case "$preset" in
linux_gnu_debug)
    toolchain_file=${toolchain_file_dir}/linux_gnu.cmake
    generator="Unix Makefiles"
    build_type="Debug"
    ;;
linux_gnu_release)
    toolchain_file=${toolchain_file_dir}/linux_gnu.cmake
    generator="Unix Makefiles"
    build_type="Release"
    ;;
linux_clang_debug)
    toolchain_file=${toolchain_file_dir}/linux_clang.cmake
    generator="Unix Makefiles"
    build_type="Debug"
    ;;
linux_clang_release)
    toolchain_file=${toolchain_file_dir}/linux_clang.cmake
    generator="Unix Makefiles"
    build_type="Release"
    ;;
mingw_debug)
    toolchain_file=${toolchain_file_dir}/mingw.cmake
    generator="MinGW Makefiles"
    build_type="Debug"
    ;;
mingw_release)
    toolchain_file=${toolchain_file_dir}/mingw.cmake
    generator="MinGW Makefiles"
    build_type="Release"
    ;;
darwin_clang_debug)
    toolchain_file=${toolchain_file_dir}/drawin_clang.cmake
    generator="Unix Makefiles"
    build_type="Debug"
    ;;
darwin_clang_release)
    toolchain_file=${toolchain_file_dir}/drawin_clang.cmake
    generator="Unix Makefiles"
    build_type="Release"
    ;;
*)
    print_log "Preset error!"
    exit 1
    ;;
esac

buildcache_dir="${buildcache_root_dir}"
install_dir="${install_root_dir}/${preset}"
bin_dir="${buildcache_dir}/bin"

if [ ${enable_clean} -eq 0 ]; then
    rm_dir "${buildcache_dir}"
    rm_dir "${install_dir}"
fi

if [ ! -d "${buildcache_dir}" ]; then
    if cmake -S "${root_path}" \
        -B "${buildcache_dir}" \
        -G "${generator}" \
        --toolchain="${toolchain_file}" \
        -DCMAKE_BUILD_TYPE="${build_type}" \
        -DCMAKE_INSTALL_PREFIX="${install_dir}" \
        -DPROBLEM_PREFIX="${prefix}"; then
        print_log "CMake configuration OK."
    else
        print_log "CMake configuration failed."
        exit 1
    fi
fi

if cmake --build "${buildcache_dir}" -j4; then
    print_log "CMake build OK."
else
    print_log "CMake build failed."
    exit 1
fi

if [ ${enable_install} -eq 0 ]; then
    if cmake --install "${buildcache_dir}"; then
        print_log "CMake install OK."
    else
        print_log "CMake install failed."
        exit 1
    fi
fi

if [ -n "${google_test_case}" ]; then
    pushd "${bin_dir}" || exit 1
    ./leetcode_test --gtest_filter="${google_test_case}"
    popd || exit 1
fi

if [ -n "${ctest_case}" ]; then
    if [ "${ctest_case}" == "*" ]; then
        ctest --rerun-failed --output-on-failure --test-dir "${buildcache_dir}"
    else
        ctest --output-on-failure --test-dir "${buildcache_dir}" -R "${ctest_case}"
    fi
fi
