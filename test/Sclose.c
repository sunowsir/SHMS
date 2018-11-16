/*************************************************************************
	> File Name:    Sclose.c
	> Author:       sunowsir
	> Mail:         sunowsir@protonmail.com
	> Created Time: 2018年09月28日 星期五 17时02分34秒
 ************************************************************************/

#include "head.h"

void Sclose(int *sockfd) {
    if (close(*sockfd) < 0) {
        perror("Close");
        exit(1);
    }

    return;
}
