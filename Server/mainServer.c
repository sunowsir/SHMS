/*
 * File Name:    mainServer.c
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * GitHub:       github.com/sunowsir
 * Created Time: 2018年11月22日 星期四 15时02分57秒
 */

#include "./include/mainServer.h"

int main() {
    if (ServerConnect()) {
        printf("ServerConnect \033[1;31merror\033[0m\n");
    }
    return 0;
}
