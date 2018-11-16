/*
* File Name: sendData.c
* Author:    sunowsir
* Mail:      sunowsir@protonmail.com
* GitHub:    github.com/sunowsir
* Created Time: 2018年11月13日 星期二 21时33分16秒
*/

#include "./sendData.h" 

int sendData(int sock, char *buf) {
    int bufLen = (int)strlen(buf);
    return (send(sock, buf, bufLen, 0) < 0 ? 1 : 0);
}

