/*
 * File Name:    getScriptRunInfo.c
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * GitHub:       github.com/sunowsir
 * Created Time: 2018年11月25日 星期日 16时35分52秒
 */

#include "../include/getScriptRunInfo.h"

/*  读取指定类型日志信息  */

char *getScriptRunInfo(int Signifier) {
    if (Signifier < 100 || Signifier > 105) {
        printf("getScriptRunInfo(): Signifier \033[1;31merror\033[0m\n");
        return NULL;
    }
    
    /* 从配置文件中获取日志文件所在位置 */
    
    char *logPath = getConf("logPath", "./server.conf");
    if (logPath == NULL) {
        printf("server.conf \033[31;merror\033[0m don't have logPath.\n");
        return NULL;
    }
    if (logPath[(int)strlen(logPath) - 1] == '/') {
        logPath[(int)strlen(logPath) - 1] = '\0';
    }
    
    /* 从配置文件中获取脚本所在位置  */
    
    char *ScriptPath = getConf("ScriptPath", "./server.conf");
    if (ScriptPath == NULL) {
        printf("server.conf \033[31;merror\033[0m don't have ScriptPath.\n");
        return NULL;
    }
    if (ScriptPath[(int)strlen(ScriptPath) - 1] == '/') {
        ScriptPath[(int)strlen(ScriptPath) - 1] = '\0';
    }
    
    char Cmd[MAXBUFF] = {'0'};
    char tempData[MAXBUFF];
    
    /* 生成执行命令 */
    
    strcpy(Cmd, ScriptPath);
    strcat(Cmd, "/getLogHeadInfo.sh ");
    strcat(Cmd, logPath);
    switch (Signifier) {
        case 100 : {
            strcat(Cmd, "/cpu.log");
        } break;
        case 101 : {
            strcat(Cmd, "/disk.log");
        } break;
        case 102 : {
            strcat(Cmd, "/malips.log");
        } break;
        case 103 : {
            strcat(Cmd, "/mem.log");
        } break;
        case 104 : {
            strcat(Cmd, "/sys.log");
        } break;
        case 105 : {
            strcat(Cmd, "/user.log");
        } break;
    }
    
    if (logPath != NULL) {
        free(logPath);
    }
    if (ScriptPath != NULL) {
        free(ScriptPath);
    }
    
    /* 调用脚本执行命令 */
    
    FILE *fp = popen(Cmd, "r");
    fgets(tempData, sizeof(char) * MAXBUFF, fp);
    pclose(fp);

    /* 将获得的数据返回 */

    char *retData = NULL;
    if (tempData == NULL || (int)strlen(tempData) == 0 || (((int)strlen(tempData) == 1) && (tempData[0] == '\n'))) {
        retData = strdup("NULL");
    }
    // char *retData = (char *)calloc(sizeof(char), (int)strlen(tempData));
    // strcpy(retData, tempData);
    retData = strdup(tempData);
    
    return retData;
}


