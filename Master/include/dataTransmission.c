/*
* File Name: dataTransmission.c
* Author:    sunowsir
* Mail:      sunowsir@protonmail.com
* GitHub:    github.com/sunowsir
* Created Time: 2018年11月14日 星期三 17时35分43秒
*/

#include "./dataTransmission.h" 

void *dataTransmission(void *arg) {
    char *fromIP = (char *)arg;
    printf("Communicating with the server from <%s> \n", fromIP);
    return NULL;
}

