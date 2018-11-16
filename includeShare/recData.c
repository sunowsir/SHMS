/*
* File Name: recData.c
* Author:    sunowsir
* Mail:      sunowsir@protonmail.com
* GitHub:    github.com/sunowsir
* Created Time: 2018年11月13日 星期二 20时45分10秒
*/

#include "./recData.h"

int recData(int sock, char **buf, int bufLen) {
    int status = recv(sock, *buf, bufLen, 0);
    return (status == 0 ? 1 : 0);
}


