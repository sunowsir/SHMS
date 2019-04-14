/*
 * File Name:    sendWarningInfo.c
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * GitHub:       github.com/sunowsir
 * Created Time: 2018年12月16日 星期日 12时03分32秒
 */

#include "sendWarningInfo.h"

int sendWarningInfo(char *sendInfo) {
    signal(SIGPIPE, SIG_IGN);
    
    /* 读取配置文件获取Master端IP和sock紧急端口 */
    
    char *MasterIP = getConf("MasterIP", CONF_SERVER);
    if (MasterIP == NULL) {
        perror("server.conf error (don't have MasterIP)");
        return -1;
    }
    
    char *strMasterWPort = getConf("MasterWPort", CONF_SERVER);
    if (strMasterWPort == NULL) {
        perror("server.conf (error don't have MasterWPort)");
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

