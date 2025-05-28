#!/bin/bash
file_path=$(cd $(dirname $0); pwd)
root_path=$(cd ${file_path}/..; pwd)

source "${root_path}/script/common_func.sh"

buildcache_root_dir="${root_path}/out/build"
install_root_dir="${root_path}/out/install"
toolchain_file_dir="${root_path}/cmake"
build_type="Debug"

target=""
test_case=""
enable_clean=1
preset="Linux_gnu_debug"

ARGS=$(getopt -o c,t:p: --long clean,test:,pre_set: -n "$0" -- "$@")

if [ $? != 0 ]; then
    echo "Terminating..." >&2 ;
    exit 1;
fi

eval set -- "$ARGS"

while true; do
    case "$1" in
        -c|--clean) enable_clean=0; shift 1;;
        -t|--test)  test_case="$2"; shift 2;;
        -p|--pre_set) preset="$2"; shift 2;;
        --) shift 1; break;;
        *) print_log "Internal error!";  exit 1;;
    esac
done

os=$(uname -s)

if echo "${os}" | grep -q "MINGW" ; then
    os="MINGW"
    preset="mingw_debug"
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
    *) print_log "Pre set error!";  exit 1;;
esac


buildcache_dir="${buildcache_root_dir}"
install_dir="${install_root_dir}/${preset}"
bin_dir="${buildcache_dir}/bin"

if [ ${enable_clean} -eq 0 ]; then
    if [ -d "${buildcache_dir}" ]; then
        rm -rf "${buildcache_dir}"
    fi

    if [ -d "${install_dir}" ]; then
        rm -rf "${install_dir}"
    fi
fi

if [ ! -d "${buildcache_dir}" ]; then
    mkdir -p "${buildcache_dir}"
    cmake -S "${root_path}" -B "${buildcache_dir}" -DCMAKE_BUILD_TYPE="${build_type}" -DCMAKE_INSTALL_PREFIX="${install_dir}" -DCMAKE_TOOLCHAIN_FILE="${toolchain_file}" -G "${generator}"

    if [ $? -ne 0 ]; then
        print_log "CMake configuration failed."
        exit 1
    fi
fi

if [ -z "${target}" ]; then
    cmake --build "${buildcache_dir}"  -j4
else
    cmake --build "${buildcache_dir}" --target "${target}" -j4
fi

if [ $? -ne 0 ]; then
    print_log "CMake build failed."
    exit 1
fi

print_log "CMake build OK."

cmake --install "${buildcache_dir}"

cd "${bin_dir}" || exit 1
if [ -n "${test_case}" ]; then
    ./${target_name}* --gtest_filter=${test_case}
fi
