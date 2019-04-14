/*
 * File Name:    mainServer.h
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * GitHub:       github.com/sunowsir
 * Created Time: 2018年11月22日 星期四 15时03分14秒
 */

#ifndef _MAINSERVER_H
#define _MAINSERVER_H

#include "heartBeat.h"
#include "runScriptAndSave.h"
#include "needHead.h"


/* return : success(0), false(-1). */

int ServerConnect();

void *getInfo();

#endif

