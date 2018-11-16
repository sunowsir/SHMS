/*
* File Name: mainMaster.h
* Author:    sunowsir
* Mail:      sunowsir@protonmail.com
* GitHub:    github.com/sunowsir
* Created Time: 2018年11月13日 星期二 21时39分57秒
*/

#ifndef _MAINMASTER_H
#define _MAINMASTER_H

#include "./getAllIP.h"
#include "./LinkList.h"
#include "./dataTransmission.h"
#include "../../includeShare/needHead.h"
#include "../../includeShare/Get_conf.h"
#include "../../includeShare/StrtoInt.h"
#include "../../includeShare/socketCreate.h"

int masterConnect();
int masterCommunication(int /* start socket. */);
int masterClose(int /* start socket. */);

#endif

