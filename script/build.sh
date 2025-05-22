#!/bin/bash
source common_func.sh

file_path=$(cd $(dirname $0); pwd)
root_path=$(cd ${file_path}/..; pwd)
buildcache_path="${root_path}/build"
install_path="${root_path}/install"
bin_path="${buildcache_path}/bin"
target=""
test_case=""
enable_clean=1

ARGS=$(getopt -o c,t: --long clean,test: -n "$0" -- "$@")

if [ $? != 0 ]; then
    echo "Terminating..." >&2 ;
    exit 1;
fi

eval set -- "$ARGS"

while true; do
    case "$1" in
        -c|--clean) enable_clean=0; shift 1;;
        -t|--test)  test_case="$2"; shift 2;;
        --) shift 1; break;;
        *) print_log "Internal error!";  exit 1;;
    esac
done

os=$(uname -s)
generator="Unix Makefiles"
toolchain_file="${root_path}/cmake/Linux_gnu.cmake"

if echo "${os}" | grep -q "MINGW" ; then
    os="MINGW"
    toolchain_file="${root_path}/cmake/MINGW_gnu.cmake"
    generator="MinGW Makefiles"
fi

if [ ${enable_clean} -eq 0 ]; then
    if [ -d "${buildcache_path}" ]; then
        rm -rf "${buildcache_path}"
    fi

    if [ -d "${install_path}" ]; then
        rm -rf "${install_path}"
    fi
fi

if [ ! -d "${buildcache_path}" ]; then
    mkdir -p "${buildcache_path}"
    cmake -S "${root_path}" -B "${buildcache_path}" -DCMAKE_TOOLCHAIN_FILE="${toolchain_file}" -G "${generator}"

    if [ $? -ne 0 ]; then
        print_log "CMake configuration failed."
        exit 1
    fi
fi

if [ -z "${target}" ]; then
    cmake --build "${buildcache_path}" 
else
    cmake --build "${buildcache_path}" --target "${target}"
fi

if [ $? -ne 0 ]; then
    print_log "CMake build failed."
    exit 1
fi

print_log "CMake build OK."

cmake --install "${buildcache_path}"

cd "${bin_path}" || exit 1
if [ -n "${test_case}" ]; then
    ./${target_name}* --gtest_filter=${test_case}
fi
