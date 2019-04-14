/*
 * File Name:    dataTransmission.c
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * GitHub:       github.com/sunowsir
 * Created Time: 2018年11月23日 星期五 18时58分10秒
 */

#include "dataTransmission.h"

int sendDataString(int sockFd, int dataSize, char *sendData) {
       
    int nowDataSize = dataSize;
    char *nowDataStrStarPos = &sendData[0];
    
    while (nowDataSize > 0) {
        int sendDataSize;
        nowDataSize = (int)strlen(nowDataStrStarPos);
        sendDataSize = (TRANS_MAX < nowDataSize ? TRANS_MAX: nowDataSize);
        
        if (send(sockFd, nowDataStrStarPos, sizeof(char) *sendDataSize, 0) < 0)  {
            perror("dataTransmission.c (send Data)");
            return -1;
        }
        nowDataStrStarPos += sendDataSize;
    }
    
    return 0;
}

int dataTransmission(int sockFd) {
    signal(SIGPIPE, SIG_IGN);
    
    /* 传输6个脚本的数据 */

    for (int i = 0; i < 6; i++) {
        /* 接收标识码  */
        
        int recvRet, dataType;
        recvRet = recv(sockFd, &dataType, sizeof(int), 0);
        if (recvRet == -1) {
            perror("dataTransmission.c (recvRet)");
            return -1;
        } else if (dataType < 100 || dataType > 105) {
            perror("recv dataType error");
            sendClose(sockFd);
            return 0;
        }
        
        /* 获取即将发送的字符串 */
        
        signal(SIGPIPE, SIG_DFL);
        char *sendData = getScriptRunInfo(dataType);
        if (sendData == NULL) {
            perror("getScriptRunInfo() run error");
            return -1;
        }
        signal(SIGPIPE, SIG_IGN);
        
        /* 发送字符串长度 */
        
        int dataSize = (int)strlen(sendData) + 5;
        // if (send(sockFd, &dataSize, sizeof(int), 0) < 0) {
        //     perror("dataTransmission.c (send dataSize)");
        //     return -1;
        // }
        // 
        // sleep(0.5);
        
        /* 发送字符串 */
        
        // if (sendDataString(sockFd, dataSize, sendData) == -1) {
        //     return -1;
        // }
        printf("sendData : <%s>\n", sendData);
        if (send(sockFd, sendData, sizeof(char) * dataSize, 0) < 0)  {
            perror("dataTransmission.c (send Data)");
            return -1;
        }
        
        /* 释放sendData字符串空间 */
        
        if (sendData != NULL) {
            free(sendData);
        }
    }
    
    return 0;
}
