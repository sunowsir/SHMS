#!/bin/bash

# retStr: return string

function retString() {
    local logPath=${1};
    local _retWord="$(cat "${logPath}" | head -1)";
    local line="$(cat "${logPath}" | wc -l)";
    local _remainLog="$(cat ${logPath} | tail -$[${line} - 1])";
    echo "${_remainLog}" > ${logPath};
    retStr="${_retWord}";
    
    if [[ "${retStr}x" == "x" ]];
    then
        return -1;
    fi
    return 0;
}

function getArchive() {
    ArchPath=${1};
    cd ${ArchPath};
    
    ArchName="$(ls ./*.tar 2> /dev/null)";
    if [[ "${ArchName}x" == "x" ]];
    then
        return -1;
    fi
    tar –xvf ./${ArchName};
    return 0;
}

function getString() {
    local logPath=${1};
    cd ./Archive/;
    logFileName="$(ls ./*.log 2> /dev/null)";
    if [[ "${logFileName}x" == "x" ]];
    then
        # Archive 文件夹没有已解压的日志文件
        local arg="${logPath}/Archive";
        arg="$(echo "${arg}" | tr -s "/")";
        getArchive() ${arg};
        if [[ ${?} -eq -1 ]];
        then
            # Archive 文件夹为空，没有压缩包。
            retString ${logPath};
            return ${?};
        else
            # Aichive　文件夹有压缩包，并且已经解压
            logFileName="$(ls ./*.log 2> /dev/null)";
            local arg="${logPath}/Archive/${logFileName}";
            arg="$(echo "${arg}" | tr -s "/")";
            retString ${arg};
            return ${?};
        fi
    else 
        # 有之前解压出来的日志文件
        local arg="${logPath}/Archive/${logFileName}";
        arg="$(echo "${arg}" | tr -s "/")";
        retString ${arg};
        return ${?};
    fi
    return 0;
}

function main() {
    cd ${1};
    
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

