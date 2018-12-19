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
    
    /* 生成执行命令 */
    
    char Cmd[MAXBUFF] = {'0'};
    char tempData[MAXBUFF];
    switch (Signifier) {
        case 100 : {
            strcat(logPath, "/cpu.log");
        } break;
        case 101 : {
            strcat(logPath, "/disk.log");
        } break;
        case 102 : {
            strcat(logPath, "/malips.log");
        } break;
        case 103 : {
            strcat(logPath, "/mem.log");
        } break;
        case 104 : {
            strcat(logPath, "/sys.log");
        } break;
        case 105 : {
            strcat(logPath, "/user.log");
        } break;
    }
    strcpy(Cmd, ScriptPath);
    strcat(Cmd, "/getLogHeadInfo.sh ");
    strcat(Cmd, logPath);
    
    if (logPath != NULL) {
        free(logPath);
    }
    if (ScriptPath != NULL) {
        free(ScriptPath);
    }
    
    /* 调用脚本执行命令 */
    
    FILE *fp = popen(Cmd, "r");
    fgets(tempData, sizeof(tempData), fp);
    pclose(fp);

    /* 将获得的数据返回 */

    if (tempData == NULL || (int)strlen(tempData) == 0 || (((int)strlen(tempData) == 1) && (tempData[0] == '\n'))) {
        return NULL;
    }
    char *retData = (char *)calloc(sizeof(char), (int)strlen(tempData));
    strcpy(retData, tempData);
    return retData;
}


