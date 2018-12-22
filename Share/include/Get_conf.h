/*
* File Name: Get_conf.h
* Author:    sunowsir
* Mail:      sunowsir@protonmail.com
* GitHub:    github.com/sunowsir
* Created Time: 2018年11月12日 星期一 11时58分16秒
*/

#ifndef _GET_CONF_H
#define _GET_CONF_H

#include "./needHead.h"

/* The space pointed to by the pointer returned by this function needs to call free to release. */
char *getConf(const char * /* the name of need varialbe */ , const char * /* path and file name. */);

#endif

