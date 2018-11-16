/*************************************************************************
	> File Name:    Sendw.c
	> Author:       sunowsir
	> Mail:         sunowsir@protonmail.com
	> Created Time: 2018年09月28日 星期五 17时06分20秒
 ************************************************************************/

#include "head.h" 

void Sendw(int *sockfd, char *sword) {
    if (send(*sockfd, sword, strlen(sword), 0) < 0) {
        perror("Send");
        exit(1);
    }
    
    return;
}

