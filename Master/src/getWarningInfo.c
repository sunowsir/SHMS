/*
 * File Name:    getWarningInfo.c
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * GitHub:       github.com/sunowsir
 * Created Time: 2018年12月11日 星期二 20时04分50秒
 */

#include "getWarningInfo.h"

void *getWarningInfo() { 
    signal(SIGPIPE, SIG_IGN);
    
    /* 从配置文件中获取本机IP  */
    
    char *localIP = getConf("localIP", CONF_MASTER);
    if (localIP == NULL) {
        perror("master.conf error (don't have localIP)");
        exit(1);
    }

    /* 从配置文件中获取本机紧急监听开启哪个端口 */
    
    char *strLocalWPort = getConf("localWPort", CONF_MASTER);
    if (strLocalWPort == NULL) {
        perror("master.conf error (don't have locaWPort)");
        exit(1);
    }
    int localWPort = StrtoInt(strLocalWPort);
    free(strLocalWPort);
    
    
    /* 开启紧急监听，等待服务器端连入*/
    
    int sockFd, sockSon;
    struct sockaddr_in addrSon;
    char IP[20] = {'\0'};
    char warning[MAXBUFF] = {'\0'};
    
    sockFd = sockServer(localIP, localWPort);
    socklen_t addrSonLen = sizeof(addrSon);
    free(localIP);

    while (1) {
        sockSon = accept(sockFd, (struct sockaddr *)&addrSon, &addrSonLen);
        if (sockSon < 0) {
            perror("getWarningInfo.c accept error");
            return NULL;
        }
        
        memset(IP, '\0', sizeof(IP));
        sockGetFromIP(IP, (struct sockaddr_in *)&addrSon);
        
        memset(warning, '\0', sizeof(warning));
        if (recv(sockSon, warning, MAXBUFF, 0) == -1) {
            perror("getWarningInfo.c recv");
            continue;
        }
        
        char *logPath = getConf("logPath", CONF_MASTER);
        if (logPath == NULL) {
            perror("master.conf error (don't have logPath)");
        }
        if (logPath[(int)strlen(logPath) - 1] == '/') {
            logPath[(int)strlen(logPath) - 1] = '\0';
        }
        char *logpath = (char *)malloc(sizeof(char) * ((int)strlen(logPath) + (int)strlen(IP) + 1 + 5 /* 多开5个防止溢出 */ ));
        strcpy(logpath, logPath);
        strcat(logpath, "/");
        strcat(logpath, IP);
        strcat(logPath, "/warning.log");
        
        free(logPath);
        
        if (writePiLog(logpath, warning) == 1) {
            perror("getWarningInfo.c (writePiLog error)");
            return NULL;
        }
        
    }
    
    return NULL;
}

