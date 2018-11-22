/*
* File Name: mainMaster.c
* Author:    sunowsir
* Mail:      sunowsir@protonmail.com
* GitHub:    github.com/sunowsir
* Created Time: 2018年11月13日 星期二 20时33分34秒
*/

#include "./include/mainMaster.h"

int main() {
    // int startSock;
    if (masterConnect()) {
        perror("masterConnect error!");
        exit(1);
    }
/*
    if (close(startSock)) {
        perror("Close error!");
        exit(1);
    }
*/  
    return 0;
}
