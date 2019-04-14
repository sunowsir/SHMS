/*
* File Name: CreateConnect.h
* Author:    sunowsir
* Mail:      sunowsir@protonmail.com
* GitHub:    github.com/sunowsir
* Created Time: 2018年11月16日 星期五 16时37分36秒
*/

#ifndef _CREATECONNECT_H
#define _CREATECONNECT_H

#include "LinkList.h"
#include "StrtoInt.h"
#include "Get_conf.h"
#include "needHead.h"
#include "sockFrame.h"

/* return : success(0), false(-1).  */

pthread_t CreateConnect(LinkList **, int);

#endif

