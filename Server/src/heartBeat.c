/*
 * File Name:    heartBeat.c
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * GitHub:       github.com/sunowsir
 * Created Time: 2018年11月23日 星期五 16时31分40秒
 */

#include "../include/heartBeat.h"

int MasterMaxConnectNum;

void sleepSometime() {
    srand(time(0));
    
    double sleepTime=fabs((double)(rand() % MasterMaxConnectNum) / 100.0) + 1;
    sleep (sleepTime);
    return ;
}

void *heartBeat() {
    
    /* 从配置文件中读取master最大连接数 */
    
    char *strMasterMaxConnectNum = getConf("MasterMaxConnectNum", CONF_SERVER);
    if (strMasterMaxConnectNum == NULL) {
        perror("server.conf error (don't have MasterMaxConnectNum)");
        return NULL;
    }
    MasterMaxConnectNum = StrtoInt(strMasterMaxConnectNum);
    if (strMasterMaxConnectNum != NULL) {
        free(strMasterMaxConnectNum);
    }
    
    /* 读取配置文件获取Master端IP和sock端口 */
    
    char *MasterIP = getConf("MasterIP", CONF_SERVER);
    if (MasterIP == NULL) {
        perror("server.conf error (don't have MasterIP)");
        return NULL;
    }
    
    char *strMasterPort = getConf("MasterPort", CONF_SERVER);
    if (strMasterPort == NULL) {
        perror("server.conf (error don't have MasterPort)");
        return NULL;
    }
    int MasterPort = StrtoInt(strMasterPort);
    if (strMasterPort != NULL) {
        free(strMasterPort);
    }
    
    char IP[15] = {'0'};
    int Port = MasterPort;
    strcpy(IP, MasterIP);
    if (MasterIP != NULL) {
        free(MasterIP);
    }
    
    while (1) {
        /* sleep sometime. */
        sleepSometime();
        
        /* 请求连接 */
        
        int sockFd = sockClient(IP, Port);
        if (sockFd != -1) {
            dataTransmission(sockFd);
        } else {
            perror("Connect false");
        }
        close(sockFd);
    }
    return NULL;
}



