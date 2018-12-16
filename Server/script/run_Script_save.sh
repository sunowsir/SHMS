#!/bin/bash

# ${1} : logPath

logPath="${1}/ | tr -s '/'";
scriptPath="$(dirname ${0})";

while true;
do
    cpuLogPath="$(echo "${logPath}cpu/cpu.log" | tr -s '/')";
    ${scriptPath}/CPU_info.sh > ${cpuLogPath};
    
    memLogPath="$(echo "${logPath}mem/mem.log" | tr -s '/')";
    ${scriptPath}/Mem_info.sh > ${memLogPath};

    sleep 5;

done &

while true;
do
    diskLogPath="$(echo "${logPath}disk/disk.log" | tr -s '/')";
    ${scriptPath}/Disk_info.sh > ${diskLogPath};

    sleep 60;
done & 

while true;
do
    sysLogPath="$(echo "${logPath}sys/sys.log" | tr -s '/')";
    sysRunRes="$(${scriptPath}/Sys_info.sh)";
    cpuWInfo="$(echo "${sysRunRes}" | tr -s ' ' '\n' | tail -1)";
    memWInfo="$(echo "${sysRunRes}" | tr -s ' ' '\n' | tail -2 | head -1)";
    diskWInfo="$(echo "${sysRunRes}" | tr -s ' ' '\n' | tail -3 | head -1)";

    if [[ "${diskWInfo}" == "warning" ]];
    then
        echo -e "Disk warning ! ";
    elif [[ "4{memWInfo}" == "warning" ]];
    then
        echo -e "MEM warning ! ";
    elif [[ "${cpuWInfo}" == "warning" ]];
    then
        echo -e "CPU warning ! ";
    fi
    
    userLogPath="$(echo "${logPath}user/user.log" | tr -s '/')";
    ${scriptPath}/User_info.sh > ${userLogPath};

    sleep 5;

done &

while true;
do
    malipsLogPath="$(echo "${logPath}malips/malips.log" | tr -s '/')";
    ${scriptPath}/Malicious_ps_info.sh > ${malipsLogPath};

done &



