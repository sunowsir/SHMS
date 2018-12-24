#!/bin/bash

# ${1} : log path and file name.

# retStr: return string
retStr="";

function getString() {
    local _logFile=${1};
    local _line="$(cat "${_logFile}" | wc -l)";
    if [[ ${_line} -lt 1 ]];
    then
        return 0;
    fi
    
    local needRetLine="";
    
    if [[ ${_line} -lt 10 ]];
    then
        needRetLine=${_line};
    elif [[ ${_line} -lt 20 ]];
    then
        needRetLine=$((${_line} / 3 * 2));
    fi
    
    local _retWord="$(cat "${_logFile}" | head -${needRetLine})";
    local _remainLine="";
    
    if [[ ${_line} -eq ${needRetLine} ]];
    then
        _remainLine=0
    else
        let "_remainLine=${_line} - ${needRetLine}"
    fi
    echo "needRetLine:${needRetLine}"
    echo "_remainLine:${_remainLine}"
    
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

