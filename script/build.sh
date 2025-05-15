#!/bin/bash

file_path=$(cd $(dirname $0); pwd)
root_path=$(cd ${file_path}/..; pwd)
buildcache_path="${root_path}/buildcache"
install_path="${root_path}/install"
bin_path="${buildcache_path}/bin"

target_name="leetcode_test"
cmake_toolchain_file="${root_path}/cmake/project_toolchain.cmake"
os=$(uname -s)
generator="Unix Makefiles"

if [[ ${os} =~ "MINGW" ]]; then
    os="MINGW"
    generator="MinGW Makefiles"
fi

if [ -d "${buildcache_path}" ]; then
    rm -rf "${buildcache_path}"
fi

if [ -d "${install_path}" ]; then
    rm -rf "${install_path}"
fi

mkdir -p "${buildcache_path}"

cd "${root_path}" || pwd
cmake -S "${root_path}" -B "${buildcache_path}" -G "${generator}"
cmake --build "${buildcache_path}"
cmake --install "${buildcache_path}"

cd "${bin_path}" || pwd
./${target_name}*
