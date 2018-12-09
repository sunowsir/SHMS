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
    if (logPath == NULL) {
        printf("server.conf \033[31;merror\033[0m don't have logPath.\n");
        return NULL;
    }
    char *ScriptPath = getConf("ScriptPath", "./server.conf");
    if (ScriptPath == NULL) {
        printf("server.conf \033[31;merror\033[0m don't have ScriptPath.\n");
        return NULL;
    }
    strcpy(ScriptPath, "getLogHeadInfo.sh");
    char tempData[MAXBUFF];
    strcpy(ScriptPath, " ");
    strcpy(ScriptPath, logPath);
    
    FILE *fp = popen(ScriptPath, "r");
    fgets(tempData, sizeof(tempData), fp);
    pclose(fp);
    free(logPath);
    free(ScriptPath);
    
    char *retData = (char *)malloc(sizeof(char) * (int)strlen(tempData));
    strcpy(retData, tempData);
    return retData;
} 
