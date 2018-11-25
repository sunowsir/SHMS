/*
 * File Name:    PackageFrame.h
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * GitHub:       github.com/sunowsir
 * Created Time: 2018年11月20日 星期二 20时36分15秒
 */

#ifndef _PACKAGEFRAME_H
#define _PACKAGEFRAME_H

#include "./needHead.h"

/* 应约定好数据传输的最大大小。  */
typedef struct Package {
    char *IP;
    int dataSize, dataType;
} Package;

Package *PackageInit();

Package *PackageCreate(char * /* IP */ , int /* dataType */ , int /* dataSize */);

void PackageClear(Package *);

#endif

