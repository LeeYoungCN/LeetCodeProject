#!/bin/bash
file_path=$(cd $(dirname $0); pwd)
root_path=$(cd ${file_path}/..; pwd)
buildcache_path="${root_path}/buildcache"
bin_path="${buildcache_path}/bin"
target_name="LeetCodePractice"
os=$(uname -s)
generator="Unix Makfiles"
if [[ ${os} =~ "MINGW" ]]; then
    os="MINGW"
    generator="MinGW Makefiles"
fi

if [ -d "${buildcache_path}" ]; then
    rm -rf "${buildcache_path}"
fi

mkdir -p "${buildcache_path}"

cd "${root_path}" || pwd
cmake -S "${root_path}" -B "${buildcache_path}" -G "${generator}"
cmake --build "${buildcache_path}" --target "${target_name}"

cd "${bin_path}" || pwd
./${target_name}*
