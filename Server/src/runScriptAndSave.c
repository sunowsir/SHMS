/*
 * File Name:    runScriptAndSave.c
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * GitHub:       github.com/sunowsir
 * Created Time: 2018年12月18日 星期二 13时44分45秒
 */

#include "../include/runScriptAndSave.h"

int RunAndSave(char *logFile, char *ScriptFile, int sleepTime, int monitorWarning) {
    while (1) {
        char Cmd[MAXBUFF] = {'0'};
        strcpy(Cmd, ScriptFile);
        
        /* 运行其他不含有警报信息的脚本 */
        
        if (monitorWarning == 0) {
            
            /* 直接执行shell命令：xxx.sh >> xxx/xxx.log  */
            
            strcat(Cmd, " >> ");
            strcat(Cmd, logFile);
            
            FILE *pfp = popen(Cmd, "w");
            pclose(pfp);
        }
        
        /* 运行系统信息脚本，分析运行结果是否有警报信息 */
        
        if (monitorWarning == 1) {
            char runRes[MAXBUFF] = {'0'};
            
            /* 获取脚本运行结果 */
            
            FILE *pfp = popen(Cmd, "r");
            fgets(runRes, sizeof(runRes), pfp);
            pclose(pfp);
            
            /* 将脚本运行结果写入日志文件 */
            
            if (writePiLog(logFile, runRes) == -1) {
                perror("RunAndSave()(writePiLog)");
                break;
            }
            
            /* 判断脚本运行结果中是否有警报信息 */
            
            if (strstr(runRes, "warning") != NULL) {
                if (sendWarningInfo(runRes)) {
                    printf("sendWarningInfo \033[1;31merror\033[0m\n");
                    break;
                }
            }
        }
        sleep(sleepTime);
    }
    
    return 0;
}


void *monitorHealth(void *arg) {
    char *ScriptFile, *logFile;
    int sleepTime, monitorWarning;

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
    
    logFile = (char *)calloc(sizeof(char), ((int)strlen(logPath) + 30));
    ScriptFile = (char *)calloc(sizeof(char), ((int)strlen(ScriptPath) + 30));
    
    strcpy(logFile, logPath);
    strcpy(ScriptFile, ScriptPath);
    monitorWarning = 0;

    int dataType = *((int *)arg);
    switch (dataType) {
        case 100 : {
            sleepTime = 5;
            strcat(logFile, "/cpu.log");
            strcat(ScriptFile, "/CPU_info.sh");
        } break;
        case 101 : {
            sleepTime = 60;
            strcat(logFile, "/disk.log");
            strcat(ScriptFile, "/Disk_info.sh");
        } break;
        case 102 : {
            sleepTime = 30;
            strcat(logFile, "/malips.log");
            strcat(ScriptFile, "/Malicious_ps_info.sh");
        } break;
        case 103 : {
            sleepTime = 5;
            strcat(logFile, "/mem.log");
            strcat(ScriptFile, "/Mem_info.sh");
        } break;
        case 104 : {
            sleepTime = 60;
            monitorWarning = 1;
            strcat(logFile, "/sys.log");
            strcat(ScriptFile, "/Sys_info.sh");
        } break;
        case 105 : {
            sleepTime = 60;
            strcat(logFile, "/user.log");
            strcat(ScriptFile, "/User_info.sh");
        } break;
    }
    
    printf("%s >> %s\n", ScriptFile, logFile);
    
    if (RunAndSave(logFile, ScriptFile, sleepTime, monitorWarning) == -1) {
        return NULL;
    }
    
    return NULL;
}



