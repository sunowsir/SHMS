/*
* File Name: TCP_connect.h
* Author:    sunowsir
* Mail:      sunowsir@protonmail.com
* GitHub:    github.com/sunowsir
* Created Time: 2018年11月12日 星期一 12时02分29秒
*/

#ifndef _TCP_CONNECT_H
#define _TCP_CONNECT_H

#include "../../includeShare/needHead.h"

int tcpConnect(struct sockaddr_in *caddr, char *IP, int Port);

#endif
