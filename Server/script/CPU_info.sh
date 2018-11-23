#!/bin/bash

time_and_load=`date +"%Y-%m-%d__%H:%M:%S "``uptime | tr -s " " "\n" | tr -s "," " " | awk NF | tail -3 | tr -s "\n" " "`

# 0.5s 前
# 开机后总时间
cpu_local1=`cat /proc/stat | grep  -w "cpu" | awk '{printf("%d", $2 + $3 + $4 + $5 + $6 + $7 + 8);}'`
# 开机后累计空闲
cpu_idle1=`cat /proc/stat | grep  -w "cpu" | awk '{printf("%d", $5);}'`

sleep 0.5s

# 0.5s 后
# 开机后总时间
cpu_local2=`cat /proc/stat | grep  -w "cpu" | awk '{printf("%d", $2 + $3 + $4 + $5 + $6 + $7 + 8);}'`
# 开机后累计空闲
cpu_idle2=`cat /proc/stat | grep  -w "cpu" | awk '{printf("%d", $5);}'`

# 0.5s 内
((cpu_local = $cpu_local2 - $cpu_local1))
((cpu_idle = $cpu_idle2 - $cpu_idle1))

# 计算cpu占用率
cpu_occu=`echo "$cpu_local $cpu_idle" | awk '{printf("%.2f%%", (1 - $2 / $1) * 100);}'`

# CPU温度
cpu_temp_info=`cat /sys/class/thermal/thermal_zone0/temp | awk '{
        if ($1 >= 1000 && $1 < 50000) {
            printf("%.2f normal", $1 / 1000);
        }
        else if ($1 >= 50000 && $1 <= 70000) {
            printf("%.2f note", $1 / 1000);
        }
        else {
            printf("%.2f warning", $1 / 1000);
        }
    }'`


echo "${time_and_load}${cpu_occu} ${cpu_temp_info}"
