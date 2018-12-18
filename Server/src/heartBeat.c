/*
 * File Name:    heartBeat.c
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * GitHub:       github.com/sunowsir
 * Created Time: 2018年11月23日 星期五 16时31分40秒
 */

#include "../include/heartBeat.h"

void sleepSometime() {
    srand(time(0));
    
    /* 从配置文件中读取master最大连接数 */
    
    char *strMasterMaxConnectNum = getConf("MasterMaxConnectNum", "./server.conf");
    if (strMasterMaxConnectNum == NULL) {
        printf("server.conf \033[1;31merror\033[0m : don't have MasterMaxConnectNum\n");
    }
    int MasterMaxConnectNum = StrtoInt(strMasterMaxConnectNum);
    if (strMasterMaxConnectNum != NULL) {
        free(strMasterMaxConnectNum);
    }
    
    double sleepTime=fabs((double)(rand() % MasterMaxConnectNum) / 100.0);
    sleep (sleepTime);
    return ;
}

void *heartBeat() {
    /* 读取配置文件获取Master端IP和sock端口 */

    printf("heartBeat(): get Master IP and sock Port.\n");
    
    char *MasterIP = getConf("MasterIP", "./server.conf");
    if (MasterIP == NULL) {
        printf("server.conf \033[1;31merror\033[0m : don't have MasterIP\n");
        exit(1);
    }
    
    char *strMasterPort = getConf("MasterPort", "./server.conf");
    if (strMasterPort == NULL) {
        printf("server.conf \033[1;31merror\033[0m : don't have MasterPort\n");
        exit(1);
    }
    int MasterPort = StrtoInt(strMasterPort);
    if (strMasterPort != NULL) {
        free(strMasterPort);
    }
    
    printf("heartBeat(): will go to while true.\n");
    
    while (1) {
        printf("heartBeat(): will sleep sometime.\n");
        /* sleep sometime. */
        sleepSometime();
        
        /* 请求连接 */

        printf("heartBeat(): will request connection.\n");
        
        int sockFd = sockClient(MasterIP, MasterPort);
        if (MasterIP != NULL) {
            free(MasterIP);
        }
        if (sockFd != -1) {
            printf("heartBeat(): will run dataTransmission()\n");
            if (dataTransmission(sockFd) == -1) {
                printf("dataTransmission \033[1;31merror\033[0m\n");
            }
            
            /* 通知Master数据传输结束关闭连接 */
            /* 发送结束码CLOSE_NOW */

            printf("heartBeat(): will send CLOSE_NOW\n");
            
            int sendClose = CLOSE_NOW;
            if (send(sockFd, &sendClose, sizeof(int), 0) < 0) {
                perror("heartBeat.c send CLOSE_NOW \033[1;31merror\033[0m: ");
                close(sockFd);
                exit(1);
            }
            close(sockFd);
        }
    }
    return NULL;
}


