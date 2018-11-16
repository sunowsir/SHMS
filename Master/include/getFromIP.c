/*
* File Name: getFromIP.c
* Author:    sunowsir
* Mail:      sunowsir@protonmail.com
* GitHub:    github.com/sunowsir
* Created Time: 2018年11月13日 星期二 20时18分09秒
*/

#include "./getFromIP.h"

int getFromIP(char *fromIP, struct sockaddr_in *sonaddr) {
    if (inet_ntop(AF_INET, (void *)&(sonaddr->sin_addr), fromIP, 16) != NULL) {
        return 1;
    }
    return 0;
}
