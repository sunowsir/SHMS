/*
* File Name: mainMaster.c
* Author:    sunowsir
* Mail:      sunowsir@protonmail.com
* GitHub:    github.com/sunowsir
* Created Time: 2018年11月13日 星期二 20时33分34秒
*/

#include "./mainMaster.h"

int main() {
    int startSock;
    if (masterConnect(&startSock)) {
        perror("masterConnect error!");
        exit(1);
    }

    if (masterCommunication(startSock)) {
        perror("masterCommunication error!");
        exit(1);
    }

    if (masterClose(startSock)) {
        perror("masterClose error!");
        exit(1);
    }
    
    return 0;
}
