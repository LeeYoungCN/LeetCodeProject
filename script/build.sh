#!/bin/bash

file_path=$(cd $(dirname $0); pwd)
root_path=$(cd ${file_path}/..; pwd)
buildcache_path="${root_path}/buildcache"
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
        *) echo "Internal error!";  exit 1;;
    esac
done

os=$(uname -s)
generator="Unix Makefiles"

if [[ ${os} =~ "MINGW" ]]; then
    os="MINGW"
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
    cmake -S "${root_path}" -B "${buildcache_path}" -G "${generator}"
fi

# cd "${root_path}" || exit 1
if [ -z "${target}" ]; then
    cmake --build "${buildcache_path}"
else
    cmake --build "${buildcache_path}" --target "${target}"
fi
cmake --install "${buildcache_path}"

cd "${bin_path}" || exit 1
if [ -z "${test_case}" ]; then
    ./${target_name}*
else
    ./${target_name}* --gtest_filter=${test_case}
fi
