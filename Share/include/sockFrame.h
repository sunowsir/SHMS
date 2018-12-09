/*
* File Name: sockFrame.h
* Author:    sunowsir
* Mail:      sunowsir@protonmail.com
* GitHub:    github.com/sunowsir
* Created Time: 2018年11月16日 星期五 16时13分21秒
*/

#ifndef _SOCKFRAME_H
#define _SOCKFRAME_H

#include "./needHead.h"

/* return : success (sockFd), false(-1) */

int sockServer(char * /* IP */ , int /* Port */ );

int sockClient(char * /* IP */ ,int /* Port */);

int sockGetFromIP(char * /* save IP */, struct sockaddr_in *);
// 
// /* return : success(0), false(1) */
// 
// int sockRecData(int /* sock */ , char * /* buf */ , int /* bufLen */ );
// 
// /* return : success(0), false(1). */
// 
// int sockSendData(int /* sock */ , char * /* buf */ );
// 
#endif

