#!/bin/bash

# ${1} : log path and file name.

# retStr: return string
retStr="";

function getString() {
    local _logFile=${1};
    local _retWord="$(cat "${_logFile}" | head -1)";
    local _line="$(cat "${_logFile}" | wc -l)";
    local _remainLog="$(cat ${_logFile} | tail -$[${_line} - 1])";
    echo "${_remainLog}" > ${_logFile};
    retStr="${_retWord}";
    
    if [[ "${retStr}x" == "x" ]];
    then
        return -1;
    fi
    return 0;
}

function main() {
    getString ${1};
    if [[ ${?} -eq -1 ]];
    then
        echo "ERROR";
        return 1;
    fi
    
    echo -n "${retStr}";
    return 0;
}

main $@;
exit ${?};

