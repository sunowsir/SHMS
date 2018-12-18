/*
 * File Name:    runScriptAndSave.c
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * GitHub:       github.com/sunowsir
 * Created Time: 2018年12月18日 星期二 13时44分45秒
 */

#include "../include/runScriptAndSave.h"

char *ScriptFile, *logFile;
int sleepTime, monitorWarning;

void *RunAndSave() {
    FILE *fp = fopen(logFile, "a");
    while (1) {
        char Cmd[MAXBUFF] = {'0'};
        strcpy(Cmd, ScriptFile);
        
        /* 运行其他不含有警报信息的脚本 */
        
        if (monitorWarning == 0) {
            
            /* 直接执行shell命令：xxx.sh >> xxx/xxx.log  */
            
            strcpy(Cmd + (int)strlen(Cmd), " >> ");
            strcpy(Cmd + (int)strlen(Cmd), logFile);
            
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
            
            FILE *lfp = fopen(logFile, "a");
            fscanf(lfp, "%s", runRes);
            fclose(lfp);
            
            /* 判断脚本运行结果中是否有警报信息 */
            
            if (strstr(runRes, "warning") != NULL) {
                if (sendWarningInfo(runRes)) {
                    printf("sendWarningInfo \033[1;31merror\033[0m\n");
                }
            }
        }
        sleep(sleepTime);
    }
    fclose(fp);
    
    return NULL;
}


int monitorHealth(char *script, char *logfile, int type, int sleeptime) {
    logFile = logfile;
    ScriptFile = script;
    sleepTime = sleeptime;
    monitorWarning = 0;
    
    switch (type) {
        case 100 : {
            strcpy(logFile + (int)strlen(logFile), "/cpu.log");
            strcpy(ScriptFile + (int)strlen(ScriptFile), "/CPU_info.sh");
        } break;
        case 101 : {
            strcpy(logFile + (int)strlen(logFile), "/disk.log");
            strcpy(ScriptFile + (int)strlen(ScriptFile), "/Disk_info.sh");
        } break;
        case 102 : {
            strcpy(logFile + (int)strlen(logFile), "/malips.log");
            strcpy(ScriptFile + (int)strlen(ScriptFile), "/Malicious_ps_info.sh");
        } break;
        case 103 : {
            strcpy(logFile + (int)strlen(logFile), "/mem.log");
            strcpy(ScriptFile + (int)strlen(ScriptFile), "/Mem_info.sh");
        } break;
        case 104 : {
            monitorWarning = 1;
            strcpy(logFile + (int)strlen(logFile), "/sys.log");
            strcpy(ScriptFile + (int)strlen(ScriptFile), "/Sys_info.sh");
        } break;
        case 105 : {
            strcpy(logFile + (int)strlen(logFile), "/user.log");
            strcpy(ScriptFile + (int)strlen(ScriptFile), "/User_info.sh");
        } break;
    }
    
    pthread_t RAS_pthread;
    if (pthread_create(&RAS_pthread, NULL, RunAndSave, NULL)) {
        perror("monitorHealth(): pthread create RunAndSave");
        return -1;
    }
    
    pthread_join(RAS_pthread, NULL);
    pthread_exit(NULL);
    
    return 0;
}



