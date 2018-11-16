/*
* File Name: TCP_connect.c
* Author:    sunowsir
* Mail:      sunowsir@protonmail.com
* GitHub:    github.com/sunowsir
* Created Time: 2018年11月12日 星期一 11时59分39秒
*/

#include "./TCP_connect.h"

int tcpConnect(struct sockaddr_in *caddr, char *IP, int Port) {

    struct sockaddr_in _caddr;

       // 初始化sockaddr_in　结构体
    memset(&_caddr, 0, sizeof(_caddr));
    _caddr.sin_family = AF_INET;  
    _caddr.sin_port = htons(Port);  
    
    // 创建新的socket
    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    
    if(inet_pton(AF_INET, IP, &_caddr.sin_addr) <= 0) {
        perror("Inet_pton");
        exit(1);
    }

    if (connect(sock, (struct sockaddr*)&_caddr, sizeof(_caddr)) < 0) {
        perror("Connect");
        exit(1);
    }
    *caddr = _caddr;
    return sock;
}

