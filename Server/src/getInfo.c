/*
 * File Name:    getInfo.c
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * GitHub:       github.com/sunowsir
 * Created Time: 2018年12月16日 星期日 12时09分17秒
 */

#include "../include/getInfo.h"


char *addTailChar(char *string)  {
    char *temp = (char *)malloc(sizeof(char) * ((int)strlen(string)));
    strcpy(temp, string);
    free(string);
    char *retStr = (char *)malloc(sizeof(char) * ((int)strlen(temp) + 1));
    strcpy(retStr, temp);
    strcpy(retStr, "/");
    free(temp);
    return retStr;
}

void *getInfo() {
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
    
    /* 生成命令 */
    
    char Cmd[MAXBUFF] = {'0'};
    strcpy(Cmd, ScriptPath);
    strcpy(Cmd, "run_Script_save.sh ");
    strcpy(Cmd, logPath);
    
    /* 调用脚本执行命令 */
    
    FILE *fp = popen(Cmd, "r");
    char warning[MAXBUFF] = {'0'};
    while (strcmp(warning, "ERROR")) {
        /* 获取警报信息 */
        fgets(warning, sizeof(warning), fp);
        if (sendWarningInfo(warning)) {
            printf("sendWarningInfo \033[1;31merror\033[0m\n");
        }
    }
    pclose(fp);
    free(logPath);
    free(ScriptPath);
    
    return NULL;
}

