/*
* File Name: masterClose.c
* Author:    sunowsir
* Mail:      sunowsir@protonmail.com
* GitHub:    github.com/sunowsir
* Created Time: 2018年11月13日 星期二 23时48分08秒
*/

#include "./mainMaster.h"

int masterClose(int sockFd) {
    return (close(sockFd) == 0 ? 0 : 1);
}


