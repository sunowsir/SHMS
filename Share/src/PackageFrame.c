/*
 * File Name:    PackageFrame.c
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * GitHub:       github.com/sunowsir
 * Created Time: 2018年11月20日 星期二 20时36分20秒
 */

#include "../include/PackageFrame.h"

Package *PackageInit() {
    Package *p = (Package *)malloc(sizeof(Package));
    p->IP = (char *)malloc(sizeof(char) * 20);
    p->dataType = 0;
    p->dataSize = 0;
    return p;
}

Package *PackageCreate(char *IP, int dataType, int dataSize) {
    Package *pack = PackageInit();
    pack->dataSize = dataSize;
    pack->dataType = dataType;
    // pack->IP = strdup(IP);
    strcpy(pack->IP, IP);
    free(IP);
    return pack;
}    

void PackageClear(Package *pack) {
    if (pack == NULL) {
        return ;
    }
    free(pack->IP);
    free(pack);
    return ;
}
