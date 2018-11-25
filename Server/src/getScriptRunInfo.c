/*
 * File Name:    getScriptRunInfo.c
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * GitHub:       github.com/sunowsir
 * Created Time: 2018年11月25日 星期日 16时35分52秒
 */

#include "../include/getScriptRunInfo.h"

/*  从指定路径的日志中读取信息  */

char *getScriptRunInfo(int Signifier) {
    char *logPath = getConf("logPath", "./server.conf");
    char tempData[MAXBUFF];
    char cmd[MAXBUFF];
    strcpy(cmd, "../script/getLogHeadInfo.sh ");
    strcpy(cmd, logPath);
    FILE *fp = popen(logPath, "r");
    fgets(tempData, sizeof(tempData), fp);
    pclose(fp);
    char *retData = (char *)malloc(sizeof(char) * (int)strlen(tempData));
    strcpy(retData, tempData);
    return retData;
}
