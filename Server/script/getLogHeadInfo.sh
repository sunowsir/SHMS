#!/bin/bash

retWord=""

function getWord() {
    local logPath=${1};
    local _retWord="$(cat "${logPath}" | head -1)";
    local line="$(cat "${logPath}" | wc -l)";
    local _remainLog="$(cat ${logPath} | tail -$[${line} - 1])";
    echo "${_remainLog}" > ${logPath};
    retWord="${_retWord}";
    return 0;
}

function main() {
    getWord ${1};
    echo -n "${retWord}";
}

main $@;
exit 0;

