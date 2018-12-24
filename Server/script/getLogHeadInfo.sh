#!/bin/bash

# ${1} : log path and file name.

# retStr: return string
retStr="";

function getString() {
    local _logFile=${1};
    local _line="$(cat "${_logFile}" | wc -l)";
    if [[ ${_line} -lt 10 ]];
    then
        return 0;
    fi
    local needRetLine="$(awk -v line=${_line}'
    {
        if (line < 5) {
            printf("%d", line);
        } else if (line <= 10) {
            printf("%d", 5 + ((line - 5) / 2);
        } else if (line <= 20) {
            printf("%d", line / 3 * 2);
        } else {
            printf("%d", 20);
        }
    }
    ')";
    local _retWord="$(cat "${_logFile}" | head -${needRetLine})";
    local _remainLog="$(cat ${_logFile} | tail -$((${_line} - ${needRetLine})))";
    echo "${_remainLog}" > ${_logFile};
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

