/*
* File Name: socketCreate.c
* Author:    sunowsir
* Mail:      sunowsir@protonmail.com
* GitHub:    github.com/sunowsir
* Created Time: 2018年11月13日 星期二 20时08分01秒
*/

#include "./socketCreate.h"

int socketCreate(char *IP, int Port, struct sockaddr_in *saddr) {
    
    // 创建新的socket
    int ssock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    // 初始化 socketaddr_in 结构体
    saddr->sin_family = AF_INET;
    saddr->sin_addr.s_addr = inet_addr(IP);
    saddr->sin_port = htons(Port);    
    return ssock;
}

