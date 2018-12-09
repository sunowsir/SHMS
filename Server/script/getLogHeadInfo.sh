#!/bin/bash

# retString: return string

function retString() {
    local logPath=${1};
    local _retWord="$(cat "${logPath}" | head -1)";
    local line="$(cat "${logPath}" | wc -l)";
    local _remainLog="$(cat ${logPath} | tail -$[${line} - 1])";
    echo "${_remainLog}" > ${logPath};
    retString="${_retWord}";
    
    if [[ "${retString}x" == "x" ]];
    then
        return -1;
    fi
    return 0;
}

function getArchive() {
    
}

function getString() {
    local logPath=${1};
    cd ./Archive/;
    logFileName="$(ls ./*.log 2> /dev/null)";
    if [[ "${logFileName}x" == "x" ]];
    then
        getArchive();
        if [[ ${?} -eq -1 ]];
        then
            # Archive 文件夹为空，没有压缩包和已经解压的日志。
            retString ${logPath};
            return ${?};
        else
            # Aichive　文件夹有压缩包，并且已经解压
        fi
    else 
        # 有之前解压出来的日志文件
    fi
    return 0;
}

function main() {
    cd ${1};
    
    getString ${1};
    echo -n "${retString}";
}

main $@;
exit 0;

