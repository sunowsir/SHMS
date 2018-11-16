/*************************************************************************
	> File Name:    Cret_cont.c
	> Author:       sunowsir
	> Mail:         sunowsir@protonmail.com
	> Created Time: 2018年09月28日 星期五 16时49分38秒
 ************************************************************************/

#include "head.h"

void Cret_cont(int *sock, char *IP, int Port) {
    
        
    // 创建sockaddr_in　结构体
    struct sockaddr_in  caddr;

    // 初始化sockaddr_in　结构体
    memset(&caddr, 0, sizeof(caddr));
    caddr.sin_family = AF_INET;  
    caddr.sin_port = htons(Port);  
    
    // 创建新的socket
    *sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    
    // 转化为网络字节序
    if(inet_pton(AF_INET, IP, &caddr.sin_addr) <= 0) {
        perror("Inet_pton");
        exit(1);
    }

    // 连接
    if (connect(*sock, (struct sockaddr*)&caddr, sizeof(caddr)) < 0) {
        perror("Connect");
        exit(1);
    }
    
    return;
}
