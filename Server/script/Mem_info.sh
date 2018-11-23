#!/bin/bash

free -m | grep "^Mem" | awk -v last_per=$1 -v nowdate=$(date +"%Y-%m-%d_%H:%M:%S") '
{
    printf("%s %sM %sM %.1f%% %.1f%%\n", nowdate, $2, $7, $3 / $2 * 100, 0.3 * last_per + 0.7 * ($3 / $2 * 100));
}'

