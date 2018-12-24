#!/bin/bash

# ${1} : log path and file name.

# retStr: return string
retStr="";

function getString() {
    local _logFile=${1};
    local _line="$(cat "${_logFile}" | wc -l)";
    local needRetLine="1";
    local _remainLine="$((${_line} - 1))";
    local _retWord="$(cat "${_logFile}" | head -${needRetLine})";
    
    echo "$(cat ${_logFile} | tail -${_remainLine})" > ${_logFile};
    retStr="${_retWord}";
    
    if [[ "${retStr}x" == "x" ]];
    then
        return -1;
    fi
    return 0;
}

function main() {
    logFile=${1};
    while [[ ! -e ${logFile} ]];
    do
        sleep 0.5;
    done
    
    getString ${logFile};
    if [[ ${?} -eq -1 ]];
    then
        echo "ERROR";
        return 1;
    fi
    
    echo "${retStr}";
    return 0;
}

main $@;
exit ${?};

