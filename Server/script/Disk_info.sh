#!/bin/bash

df -m | grep "^/dev/" | awk -v ntime=$(date +"%Y-%m-%d__%H:%M:%S") '
BEGIN{
    num = 0; 
    unum = 0; 
    hnum = 0;
} 
{
    num += $2; 
    unum += $3; 
    hnum += $4;
    printf("%s 1 %s %sM %sM %s\n", ntime, $6, $2, $4, $5);
} 
END{
    printf("%s 0 disk %dM %dM %.2f%%\n", ntime, num, hnum, unum / num * 100);
}'

