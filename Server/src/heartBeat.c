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
    
    char *strMasterMaxConnectNum = getConf("MasterMaxConnectNum", "./server.conf");
    if (strMasterMaxConnectNum == NULL) {
        printf("server.conf \033[1;31merror\033[0m : don't have MasterMaxConnectNum\n");
        return NULL;
    }
    MasterMaxConnectNum = StrtoInt(strMasterMaxConnectNum);
    if (strMasterMaxConnectNum != NULL) {
        free(strMasterMaxConnectNum);
    }
    
    /* 读取配置文件获取Master端IP和sock端口 */
    
    char *MasterIP = getConf("MasterIP", "./server.conf");
    if (MasterIP == NULL) {
        printf("server.conf \033[1;31merror\033[0m : don't have MasterIP\n");
        return NULL;
    }
    
    char *strMasterPort = getConf("MasterPort", "./server.conf");
    if (strMasterPort == NULL) {
        printf("server.conf \033[1;31merror\033[0m : don't have MasterPort\n");
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
            printf("Connect %s:%d success.\n", IP, Port);
            dataTransmission(sockFd);
            printf("\033[1;32mData sent to complete\033[0m\n");
            printf("Disconnect %s:%d.\n", IP, Port);
        } else {
            printf("Connect %s:%d false.\n", IP, Port);
        }
        close(sockFd);
        printf("\n");
    }
    return NULL;
}



