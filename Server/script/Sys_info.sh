#!/bin/bash

# 现在时间
nowdate=`date +"%Y-%m-%d__%H:%M:%S"`
# 系统版本
os_v=`cat /etc/issue | awk '{printf("%s_%s", $1, $2);}'`
# 内核版本
ker_v=`uname -r`
# 运行时间和负载信息
run_and_load=`uptime -p | tr -s " " "\n" | awk '{printf("_%s", $1)}'``cat /proc/loadavg | awk '{ printf(" %s %s %s", $1, $2, $3); }'`

# 负载信息
#load_info=`uptime | awk '{printf ("%s %s %s", $(NF - 2), $(NF - 1), $NF)}' | tr -s "," " "`

disk_total=`df -m | grep "^/dev/" | awk 'BEGIN{t_num=0; u_num = 0}{if (NR > 1) {t_num = t_num + $2; u_num += $3 }}END{printf ("%d:%d", t_num, u_num)}'`
disk_used=`echo $disk_total | cut -d ":" -f2`
disk_total=`echo $disk_total | cut -d ":" -f1`

#内存大小
mem_total=`free -m | sed -n "2p" | awk '{printf("%s", $2)}'`

# 磁盘占用百分比
per_disk_used=`echo "$disk_total $disk_used" | awk '{printf("%d", $2/$1 * 100);}'`
# 内存占用百分比
per_memo=`free -m | sed -n "2p" | awk '{printf("%d", $3/$2 * 100);}'`
# CPU温度
cpu_temp=`cat /sys/class/thermal/thermal_zone0/temp | awk '{printf("%d", $1 / 1000);}'`

# 磁盘报警级别

if [[ $per_disk_used -ge 0 && $per_disk_used -le 80  ]];then
    disk_warn="normal"

elif [[ $per_disk_used -ge 81 && $per_disk_used -le 90 ]];then
    disk_warn="note"

else
    disk_warn="warning"

fi

# 内存报警级别

if [[ $per_memo -ge 0 && $per_memo -le 70  ]];then
    memo_warn="normal"

elif [[ $per_memo -ge 71 && $per_memo -le 80 ]];then
    memo_warn="note"

else
    memo_warn="warning"

fi

# CPU温度报警级别


if [[ $cpu_temp -ge 0 && $cpu_temp -le 50  ]];then
    cpu_warn="normal"

elif [[ $cpu_temp -ge 51 && $cpu_temp -le 70 ]];then
    cpu_warn="note"

else
    cpu_warn="warning"

fi

#主机名
hname=`hostname`

echo "$nowdate $hname $os_v $ker_v ${run_and_load} ${disk_total}M ${per_disk_used}% ${mem_total}M ${per_memo}% ${cpu_temp} ${disk_warn} ${memo_warn} ${cpu_warn}"
