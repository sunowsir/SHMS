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
    if (logPath[(int)strlen(logPath) - 1] != '/') {
        logPath = addTailChar(logPath);
    }
    
    /* 从配置文件中获取脚本所在位置  */
    
    char *ScriptPath = getConf("ScriptPath", "./server.conf");
    if (ScriptPath == NULL) {
        printf("server.conf \033[31;merror\033[0m don't have ScriptPath.\n");
        return NULL;
    }
    if (ScriptPath[(int)strlen(ScriptPath) - 1] != '/') {
        ScriptPath = addTailChar(ScriptPath);
    }
    
    /* 生成执行命令 */
    
    strcpy(ScriptPath, "getLogHeadInfo.sh");
    char tempData[MAXBUFF];
    strcpy(ScriptPath, " ");
    switch (Signifier) {
        case 100 : {
            strcpy(logPath, "cpu/");
            
        } break;
        case 101 : {
            strcpy(logPath, "disk/");
            
        } break;
        case 102 : {
            strcpy(logPath, "malips/");
            
        } break;
        case 103 : {
            strcpy(logPath, "mem/");
            
        } break;
        case 104 : {
            strcpy(logPath, "sys/");
            
        } break;
        case 105 : {
            strcpy(logPath, "user/");
            
        } break;
    }
    strcpy(ScriptPath, logPath);
    
    /* 调用脚本执行命令 */
    
    FILE *fp = popen(ScriptPath, "r");
    fgets(tempData, sizeof(tempData), fp);
    pclose(fp);
    free(logPath);
    free(ScriptPath);
    
    char *retData = (char *)malloc(sizeof(char) * (int)strlen(tempData));
    strcpy(retData, tempData);
    return retData;
} 
