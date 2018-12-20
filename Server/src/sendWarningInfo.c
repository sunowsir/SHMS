/*
 * File Name:    sendWarningInfo.c
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * GitHub:       github.com/sunowsir
 * Created Time: 2018年12月16日 星期日 12时03分32秒
 */

#include "../include/sendWarningInfo.h"

int sendWarningInfo(char *sendInfo) {
    /* 读取配置文件获取Master端IP和sock紧急端口 */
    
    char *MasterIP = getConf("MasterIP", "./server.conf");
    if (MasterIP == NULL) {
        printf("server.conf \033[1;31merror\033[0m : don't have MasterIP\n");
        return -1;
    }
    
    char *strMasterWPort = getConf("MasterWPort", "./server.conf");
    if (strMasterWPort == NULL) {
        printf("server.conf \033[1;31merror\033[0m : don't have MasterWPort\n");
        return -1;
    }
    int MasterWPort = StrtoInt(strMasterWPort);
    if (strMasterWPort != NULL) {
        free(strMasterWPort);
    }
    int WsockFd = sockClient(MasterIP, MasterWPort);
    if (send(WsockFd, sendInfo, sizeof(char) * (int)strlen(sendInfo), 0) < 0) {
        perror("sendWarningInfo()");
        close(WsockFd);
        return -1;
    }
    
    close(WsockFd);
    return 0;
}

