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
        
        /* 获取即将发送的字符串 */
        
        int dataSize = 0;
        char *sendData = getScriptRunInfo(dataType);
        
        /* 根据需要字符串长度定义Package，发送Package */
        Package *pack = PackageInit();
        /* 从配置文件中读取本机IP */
        char *localIP = getConf("localIP", "./server.conf");
        if (localIP == NULL) {
            printf("server.conf \033[31;merror\033[0m don't have localIP.\n");
            return -1;
        }
        
        pack = PackageCreate(localIP, dataType, dataSize);
        if (send(sockFd, pack, sizeof(Package), 0) < 0) {
            perror("dataTransmission.c (send Package)");
            return -1;
        }
        
        sleep(0.01);
        
        /* 发送字符串 */
        if (send(sockFd, sendData, sizeof(char) * (int)strlen(sendData), 0) < 0)  {
            perror("dataTransmission.c (send Data)");
            return -1;
        }
        if (sendData != NULL) {
            free(sendData);
        }
    }

    return 0;
}
