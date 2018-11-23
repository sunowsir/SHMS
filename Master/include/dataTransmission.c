/*
* File Name: dataTransmission.c
* Author:    sunowsir
* Mail:      sunowsir@protonmail.com
* GitHub:    github.com/sunowsir
* Created Time: 2018年11月14日 星期三 17时35分43秒
*/

#include "./dataTransmission.h" 

int recvData(int sockFd) {
    int recvRet = 1;
    while (1) {
        int tag_info = 100;
        for (int i = 0; i < 6; i++) {
            tag_info += i;
            if (send(sockFd, &tag_info, sizeof(int), 0) < 0) {
                perror("send INFO error");
                return 1;
            }
            
            /* receive package. */
            
            Package *pack = PackageInit();
            recvRet = recv(sockFd, pack, sizeof(Package), 0);
            if(recvRet == -1) {
                perror("recvData error");
                return 1;
            } else if (recvRet == 0) {
                break;
            }
            PackageClear(pack);
            
            /* receive data. */
            
            char *data = (char *)calloc(sizeof(char), (pack->dataSize));
            recvRet = recv(sockFd, data, pack->dataSize, 0);
            if (recvRet == -1) {
                perror("recvData error");
                return 1;
            } else if (recvRet == 0) {
                break;
            }
            char *logPath = getConf("logPath", "./master.conf");
            if (logPath == NULL) {
                printf("\033[1;31mmaster.conf error : don't have logPath.\033[0m\n");
            }
            if (logPath[(int)strlen(logPath) - 1] == '/') {
                logPath[(int)strlen(logPath) - 1] = '\0';
            }
            char *logpath = (char *)malloc(sizeof(char) * ((int)strlen(logPath) + (int)strlen(pack->IP) + 1 + 5 /* 多开5个防止溢出 */ ));
            strcpy(logpath, logPath);
            strcpy(logpath, "/");
            strcpy(logpath, pack->IP);
            free(logPath);
            if (writePiLog(logpath, data) == 1) {
                free(data);
                return 1;
            }
            free(data);
        }
        int closeTag;
        recvRet = recv(sockFd, &closeTag, sizeof(int), 0);
        if (recvRet == -1) {
            perror("recvData : recv closeTag error");
            return 1;
        }
        if (closeTag == CLOSE_NOW) {
            break;
        }
    }
    return 0;
}

void *dataTransmission(void *arg) {
    printf("runing dataTransmission.c\n");
    LinkList *list = (LinkList *)arg;

    while (list->head.next == NULL);
    LinkNode *currentNode = list->head.next;
    
    while (1) {
        // sleep(1.0 + (double)list->length / 1000.0);
        if (list->length == 0) {
            continue;
        }
        
        /* 读取套接字sockFd，进行数据传输 */
        
        if (recvData(currentNode->sockFd) == 1) {
            printf("\033[1;31mrecvData error!\033[0m");
        }
        
        printf("Have a connect already close!\n");
        close(currentNode->sockFd);
        linkErase(list, currentNode);
        
        if (currentNode->next == NULL) {
            while (list->head.next == NULL);
            currentNode = list->head.next;
        } else {
            currentNode = currentNode->next;
        }
    }
    linkClear(list);
    return NULL;
}

