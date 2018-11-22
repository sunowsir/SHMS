/*
* File Name: StrtoInt.c
* Author:    sunowsir
* Mail:      sunowsir@protonmail.com
* GitHub:    github.com/sunowsir
* Created Time: 2018年11月13日 星期二 23时15分14秒
*/

#include "./StrtoInt.h" 

int StrtoInt(char *str) {
    if (!strcmp(str, "")) {
        return -1;
    }
    int ret = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9') {
            continue;
        }
        ret = ret * 10 + (str[i] - '0');
    }
    return ret;
}

