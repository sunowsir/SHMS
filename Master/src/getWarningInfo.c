/*
 * File Name:    getWarningInfo.c
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * GitHub:       github.com/sunowsir
 * Created Time: 2018年12月11日 星期二 20时04分50秒
 */

#include "../include/getWarningInfo.h"

void *getWarningInfo() { 
    /* 从配置文件中获取本机IP  */
    
    char *localIP = getConf("localIP", "./master.conf");
    if (localIP == NULL) {
        printf("\033[1;31mmaster.conf error : don't have localIP.\033[0m\n");
        exit(1);
    }

    /* 从配置文件中获取本机紧急监听开启哪个端口 */
    
    char *strLocalWPort = getConf("localWPort", "./master.conf");
    if (strLocalWPort == NULL) {
        printf("\033[1;31mmaster.conf error : don't have locaWPort.\033[0m\n");
        exit(1);
    }
    int localWPort = StrtoInt(strLocalWPort);
    free(strLocalWPort);
    
    
    /* 开启紧急监听，等待服务器端连入*/
    
    int sockFd = sockServer(localIP, localWPort);
    struct sockaddr_in addrSon;
    socklen_t addrSonLen = sizeof(addrSon);
    free(localIP);

    while (1) {
        int sockSon = accept(sockFd, (struct sockaddr *)&addrSon, &addrSonLen);
        if (sockSon < 0) {
            printf("getWarningInfo.c accept \033[1;31merror\033[0m\n");
            return NULL;
        }
        
        char IP[20] = {'0'};
        sockGetFromIP(IP, (struct sockaddr_in *)&addrSon);
        
        char warning[MAXBUFF] = {'0'};
        if (recv(sockSon, warning, MAXBUFF, 0) == -1) {
            perror("getWarningInfo.c recv");
            continue;
        }
        
        char *logPath = getConf("logPath", "./master.conf");
        if (logPath == NULL) {
            printf("\033[1;31mmaster.conf error : don't have logPath.\033[0m\n");
        }
        if (logPath[(int)strlen(logPath) - 1] == '/') {
            logPath[(int)strlen(logPath) - 1] = '\0';
        }
        char *logpath = (char *)malloc(sizeof(char) * ((int)strlen(logPath) + (int)strlen(IP) + 1 + 5 /* 多开5个防止溢出 */ ));
        strcpy(logpath, logPath);
        strcpy(logpath, "/");
        strcpy(logpath, IP);
        strcpy(logPath, "/warning.log");
        free(logPath);
        if (writePiLog(logpath, warning) == 1) {
            return NULL;
        }
        
    }
    
    return NULL;
}

