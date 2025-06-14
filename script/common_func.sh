#!/usr/bin/bash

function print_log() {
    echo "[$(date "+%Y-%m-%d %H:%M:%S")] ${1}"
}

function replace_text() {
    local old_str="$1"
    local new_str="$2"
    local file_path="$3"
    sed -i "s#${old_str}#${new_str}#g" "${file_path}"
}

function rm_dir() {
    local dir="${1}"
    if [ ! -d "${dir}" ]; then
        return 0
    fi

    if ! rm -rf "${dir}"; then
        print_log "remove ${dir} failed."
    fi
}
