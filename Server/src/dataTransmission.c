/*
 * File Name:    dataTransmission.c
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * GitHub:       github.com/sunowsir
 * Created Time: 2018年11月23日 星期五 18时58分10秒
 */

#include "../include/dataTransmission.h"

int dataTransmission(int sockFd) {
    /* 传输6个脚本的数据 */

    for (int i = 0; i < 6; i++) {
        /* 通过接收标识码调用getScriptRunInfo.c获取一段指定长度的字符串  */
        
        int recvRet, dataType;
        recvRet = recv(sockFd, &dataType, sizeof(int), 0);
        if (recvRet == -1) {
            perror("dataTransmission.c (recvRet)");
            return -1;
        }
        
        printf("recv dataType : %d --- \n", dataType);
        
        /* 获取即将发送的字符串 */
        
        char *sendData = getScriptRunInfo(dataType);
        if (sendData == NULL) {
            printf("dataType(%d) data is NULL\n", dataType);
            sendData = strdup("NULL");
        }
        
        printf("dataTransmission.c : send dataSize\n");
        
        int dataSize = (int)strlen(sendData);
        if (send(sockFd, &dataSize, sizeof(int), 0) < 0) {
            perror("dataTransmission.c (send dataSize)");
            return -1;
        }
        
        /* 发送字符串 */
        printf("send data : <%s>\n", sendData);
        
        if (send(sockFd, sendData, sizeof(char) * (int)strlen(sendData), 0) < 0)  {
            perror("dataTransmission.c (send Data)");
            return -1;
        }
        if (sendData != NULL) {
            free(sendData);
        }
        
        sleep(1);
    }

    return 0;
}
