/*
* File Name: dataTransmission.c
* Author:    sunowsir
* Mail:      sunowsir@protonmail.com
* GitHub:    github.com/sunowsir
* Created Time: 2018年11月14日 星期三 17时35分43秒
*/

#include "dataTransmission.h" 

int recvData(int sockFd, char *logPath) {
    
    for (int i = 0; i < 6; i++) {
        
        int dataType = 100 + i;
        
        if (send(sockFd, &dataType, sizeof(int), 0) < 0) {
            perror("recvData (send INFO)");
            return -1;
        }
        
        /* receive dataSize. */
        
        int dataSize = MAXBUFF;
        // int recvRet = 1;
        // recvRet = recv(sockFd, &dataSize, sizeof(int), 0);
        // if(recvRet == -1) {
        //     perror("recvData (recv dataSize)");
        //     return -1;
        // } else if (recvRet == 0) {
        //     break;
        // } else if (dataSize <= 0) {
        //     perror("dataSize error");
        //     return -1;
        // } else if (dataSize == CLOSE_NOW) {
        //     return 0;
        // }
        
        /* receive data. */
        
        char logFile[MAXBUFF] = {'\0'};
        strcpy(logFile, logPath);
        
        switch (dataType) {
            case 100 : {
                strcat(logFile, "/cpu.log");
            } break;
            case 101 : {
                strcat(logFile, "/disk.log");
            } break;
            case 102 : {
                strcat(logFile, "/malips.log");
            } break;
            case 103 : {
                strcat(logFile, "/mem.log");
            } break;
            case 104 : {
                strcat(logFile, "/sys.log");
            } break;
            case 105 : {
                strcat(logFile, "/user.log");
            } break;
        }
        
        char Data[MAXBUFF] = {'0'};
        
        if (recv(sockFd, Data, sizeof(char) * (dataSize), 0) < 0) {
            perror("recvData (recv data)");
            return -1;
        } else if (!strcmp(Data, "NULL")) {
            perror("recvData() (receive data is NULL)");
            continue;
        }
        printf("receive Data : <%s>\n", Data);
        /* 将数据写入日志文件 */
        
        if (writePiLog(logFile, Data) == 1) {
            return -1;
        }

    }
    
    return 0;
}

void *dataTransmission(void *arg) {
    signal(SIGPIPE, SIG_IGN);
    
    /* get logPath. */
    
    char *templogPath = getConf("logPath", CONF_MASTER);
    if (templogPath == NULL) {
        perror("master.conf error (don't have logPath)");
    }
    if (templogPath[(int)strlen(templogPath) - 1] == '/') {
        templogPath[(int)strlen(templogPath) - 1] = '\0';
    }
    char logPath[MAXBUFF] = {'\0'};
    strcpy(logPath, templogPath);
    free(templogPath);
    
    LinkList *list = (LinkList *)arg;

    while (list->head.next == NULL) sleep(1);
    LinkNode *currentNode = list->head.next;
    
    char logpath[MAXBUFF] = {'\0'};
    char Cmd[MAXBUFF] = {'\0'};
    while (1) {
        while (list->length == 0) sleep(1);
        
        memset(logpath, '\0', sizeof(logpath));
        strcpy(logpath, logPath);
        
        strcat(logpath, "/");
        strcat(logpath, currentNode->IP);
        
        memset(Cmd, '\0', sizeof(Cmd));
        strcpy(Cmd, "mkdir ");
        strcat(Cmd, logpath);
        strcat(Cmd, " 2> /dev/null");
        if (system(Cmd) == -1) {
            perror("recvData() (mkdir log directory)");
            break;
        }
        
        /* 读取套接字sockFd，进行数据传输 */
        
        if (recvData(currentNode->sockFd, logpath) == -1) {
            perror("recvData error");
            break;
        }
        
        /* 断开连接 */
        
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

