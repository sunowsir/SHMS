/*************************************************************************
	> File Name:    Write_Pi_Log.c
	> Author:       sunowsir
	> Mail:         sunowsir@protonmail.com
	> Created Time: 2018年09月30日 星期日 16时36分33秒
 ************************************************************************/

#include "../include/Write_Pi_Log.h"

int writePiLog(const char *logPath, char *logInfo) {
    FILE *fp = fopen(logPath, "a");

    if (fp == NULL)  {
        perror("Write_Pi_Log(): open file error");
        return 1;
    }
    fseek(fp, 0, SEEK_END);
    fwrite(logInfo, sizeof(char), strlen(logInfo), fp);
    fclose(fp);
    return 0;
}
