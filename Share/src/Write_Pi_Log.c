/*************************************************************************
	> File Name:    Write_Pi_Log.c
	> Author:       sunowsir
	> Mail:         sunowsir@protonmail.com
	> Created Time: 2018年09月30日 星期日 16时36分33秒
 ************************************************************************/

#include "../include/Write_Pi_Log.h"

int writePiLog(const char *logFile, char *logInfo) {
    FILE *fp = fopen(logFile, "a");

    if (fp == NULL)  {
        printf("logFile:%s, ", logFile);
        perror("Write_Pi_Log(): ");
        return -1;
    }
    if (fseek(fp, 0, SEEK_END) < 0) {
        fclose(fp);
        return -1;
    }
    if (fwrite(logInfo, sizeof(char), strlen(logInfo), fp) <= 0) {
        fclose(fp);
        return -1;
    }
    fclose(fp);
    return 0;
}
