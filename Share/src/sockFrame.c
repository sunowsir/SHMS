/*
* File Name: sockFrame.c
* Author:    sunowsir
* Mail:      sunowsir@protonmail.com
* GitHub:    github.com/sunowsir
* Created Time: 2018年11月16日 星期五 16时13分57秒
*/

#include "../include/sockFrame.h"

int sockServer(char *IP, int Port) {
    /* 创建 sockaddr_in 结构体 */
    struct sockaddr_in saddr;

    /* 初始化 socketaddr_in 结构体 */
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = inet_addr(IP);
    saddr.sin_port = htons(Port);

    /* 创建新的socket */
    int sockFd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (bind(sockFd, (struct sockaddr*)&saddr, sizeof(saddr)) < 0) {
        perror("sock Frame(sockServer) : \033[1;31mBind error\033[0m");
        return -1;
    }

    if (listen(sockFd, 20) < 0) {
        perror("sock Frame(sockServer) : \033[1;31mListen error\033[0m");
        return -1;
    }
    return sockFd;
}


int sockClient(char *IP, int Port) {
    /* 创建sockaddr_in　结构体 */
    struct sockaddr_in  caddr;

    /* 初始化sockaddr_in　结构体 */
    memset(&caddr, 0, sizeof(caddr));
    caddr.sin_family = AF_INET;  
    caddr.sin_port = htons(Port);  
    
    /* 创建新的socket */
    int sockFd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    
    if(inet_pton(AF_INET, IP, &caddr.sin_addr) <= 0) {
        perror("sock Frame(sockClient) : \033[1;31mInet_pton error\033[0m");
        return -1;
    }

    if (connect(sockFd, (struct sockaddr*)&caddr, sizeof(caddr)) < 0) {
        perror("sock Frame(sockClient) : \033[1;31mConnect error\033[0m");
        return -1;
    }
    return sockFd;
}

int sockGetFromIP(char *fromIP, struct sockaddr_in *sonaddr) {
    if (inet_ntop(AF_INET, (void *)&(sonaddr->sin_addr), fromIP, 16) == NULL) {
        perror("sock Frame(sockGetFromIP) : \033[1;31minet_ntop error\033[0m");
        return -1;
    }
    return 0;
}

int recData(int sock, char **buf, int bufLen) {
    int status = recv(sock, *buf, bufLen, 0);
    return (status == 0 ? 1 : 0);
}


int sendData(int sock, char *buf) {
    int bufLen = (int)strlen(buf);
    return (send(sock, buf, bufLen, 0) < 0 ? 1 : 0);
}


