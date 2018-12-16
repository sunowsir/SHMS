/*
 * File Name:    dataTransmission.h
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * GitHub:       github.com/sunowsir
 * Created Time: 2018年11月23日 星期五 18时57分22秒
 */

#ifndef _DATATRANSMISSION_H
#define _DATATRANSMISSION_H

#include "./getScriptRunInfo.h"
#include "../../Share/include/needHead.h"
#include "../../Share/include/Get_conf.h"
#include "../../Share/include/PackageFrame.h"

/* return : success(0), false(-1) */

int dataTransmission(int /* sockFd */);

#endif
