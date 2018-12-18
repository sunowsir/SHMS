/*
 * File Name:    getInfo.c
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * GitHub:       github.com/sunowsir
 * Created Time: 2018年12月16日 星期日 12时09分17秒
 */

#include "../include/getInfo.h"

void *getInfo() {
    /* 从配置文件中获取日志文件所在位置 */
    
    printf("getInfo(): 从配置文件中获取logPath\n");

    char *logPath = getConf("logPath", "./server.conf");
    if (logPath == NULL) {
        printf("server.conf \033[31;merror\033[0m don't have logPath.\n");
        return NULL;
    }
    if (logPath[(int)strlen(logPath) - 1] == '/') {
        logPath[(int)strlen(logPath) - 1] = '\0';
    }
    
    /* 从配置文件中获取脚本所在位置  */

    printf("getInfo(): 从配置文件中获取ScriptPath\n");
    
    char *ScriptPath = getConf("ScriptPath", "./server.conf");
    if (ScriptPath == NULL) {
        printf("server.conf \033[31;merror\033[0m don't have ScriptPath.\n");
        return NULL;
    }
    if (ScriptPath[(int)strlen(ScriptPath) - 1] == '/') {
        ScriptPath[(int)strlen(ScriptPath) - 1] = '\0';
    }
    
    for (int i = 100; i <= 105; i++) {
        int sleepTime;
        if (i == 100 || i == 103) {
            sleepTime = 5;
        } else if (i == 101 || i == 104 || i == 105) {
            sleepTime = 60;
        } else if (i == 102) {
            sleepTime = 30;
        }
        if (monitorHealth(ScriptPath, logPath, i, sleepTime)) {
            perror("monitorHealth()");
            if (logPath != NULL) {
                free(logPath);
            }
            if (ScriptPath != NULL) {
                free(ScriptPath);
            }
            return NULL;
        }
    }
    if (logPath != NULL) {
        free(logPath);
    }
    if (ScriptPath != NULL) {
        free(ScriptPath);
    }
    
    return NULL;
}

