/*
* File Name: dataTransmission.c
* Author:    sunowsir
* Mail:      sunowsir@protonmail.com
* GitHub:    github.com/sunowsir
* Created Time: 2018年11月14日 星期三 17时35分43秒
*/

#include "../include/dataTransmission.h" 

int recvData(int sockFd, char *logPath) {
    printf("===recvData===\n");
    
    for (int i = 0; i < 6; i++) {
        printf("\n");
        
        int dataType = 100 + i;
        
        if (send(sockFd, &dataType, sizeof(int), 0) < 0) {
            perror("recvData (send INFO)");
            return -1;
        }
        
        printf("Send dataType(%d)\n", dataType);
        
        /* receive dataSize. */
        
        int dataSize = 0;
        int recvRet = 1;
        recvRet = recv(sockFd, &dataSize, sizeof(int), 0);
        if(recvRet == -1) {
            perror("recvData (recv dataSize)");
            return -1;
        } else if (recvRet == 0) {
            break;
        } else if (dataSize <= 0) {
            printf("dataSize num error\n");
            return -1;
        } else if (dataSize == CLOSE_NOW) {
            return 0;
        }
        
        printf("Receive dataSize(%d)\n", dataSize);
        
        /* receive data. */
        
        char *data = (char *)calloc(sizeof(char), (dataSize + 10));
        recvRet = recv(sockFd, data, sizeof(char) * (dataSize + 5), 0);
        if (recvRet == -1) {
            perror("recvData (recv data)");
            return -1;
        } else if (!strcmp(data, "NULL")) {
            printf("recvData(): receive data is NULL\n");
            free(data);
            continue;
        }
        printf("Receive data: {%s}\n", data);
        
        
        switch (dataType) {
            case 100 : {
                strcat(logPath, "/cpu.log");
            } break;
            case 101 : {
                strcat(logPath, "/disk.log");
            } break;
            case 102 : {
                strcat(logPath, "/malips.log");
            } break;
            case 103 : {
                strcat(logPath, "/mem.log");
            } break;
            case 104 : {
                strcat(logPath, "/sys.log");
            } break;
            case 105 : {
                strcat(logPath, "/user.log");
            } break;
        }
        
        /* 将数据写入日志文件 */
        printf("Write data to log file\n");
        
        if (writePiLog(logPath, data) == 1) {
            free(data);
            return -1;
        }
        
        if (data != NULL) {
            free(data);
        }
    }
    printf("\n");
    return 0;
}

void *dataTransmission(void *arg) {
    /* get logPath. */
    
    char *logPath = getConf("logPath", "./master.conf");
    if (logPath == NULL) {
        printf("\033[1;31mmaster.conf error : don't have logPath.\033[0m\n");
    }
    if (logPath[(int)strlen(logPath) - 1] == '/') {
        logPath[(int)strlen(logPath) - 1] = '\0';
    }
    char logpath[MAXBUFF] = {'0'};
    free(logPath);
    
    LinkList *list = (LinkList *)arg;

    while (list->head.next == NULL) sleep(1);
    LinkNode *currentNode = list->head.next;
    
    while (1) {
        while (list->length == 0) sleep(1);
        
        strcpy(logpath, logPath);
        strcat(logpath, "/");
        strcat(logpath, currentNode->IP);
        strcat(logPath, "/");
        
        printf("mkdir %s/\n", currentNode->IP);
        
        char Cmd[MAXBUFF] = {'0'};
        strcpy(Cmd, "mkdir ");
        strcat(Cmd, logPath);
        strcat(Cmd, " 2> /dev/null");
        if (system(Cmd) == -1) {
            perror("recvData() (mkdir log directory)");
            break;
        }
        
        /* 读取套接字sockFd，进行数据传输 */
        
        if (recvData(currentNode->sockFd, logpath) == -1) {
            printf("\033[1;31mrecvData error!\033[0m");
            break;
        }
        
        /* 断开连接 */
        
        printf("Have a connect already close!\n");
        linkErase(list, currentNode);
        
        if (currentNode->next == NULL) {
            while (list->head.next == NULL) sleep(1);
            currentNode = list->head.next;
        } else {
            currentNode = currentNode->next;
        }
    }
    linkClear(list);
    return NULL;
}

