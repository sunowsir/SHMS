/*
* File Name: lisenGetIP.h
* Author:    sunowsir
* Mail:      sunowsir@protonmail.com
* GitHub:    github.com/sunowsir
* Created Time: 2018年11月16日 星期五 16时37分36秒
*/

#ifndef _LISENGETIP_H
#define _LISENGETIP_H

#include "./LinkList.h"
#include "../../includeShare/StrtoInt.h"
#include "../../includeShare/Get_conf.h"
#include "../../includeShare/needHead.h"
#include "../../includeShare/sockFrame.h"

/* return : success(0), false(1).  */

pthread_t listenGetIP(LinkList **, int);

#endif
