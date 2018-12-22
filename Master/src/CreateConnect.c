/*
* File Name: lisenGetIP.c
* Author:    sunowsir
* Mail:      sunowsir@protonmail.com
* GitHub:    github.com/sunowsir
* Created Time: 2018年11月16日 星期五 16时37分43秒
*/

#include "../include/CreateConnect.h"

typedef struct args {
    LinkList **list;
    int listNum;
} Args;
Args arg;

void *startListen(void *None) {
    
    /* 从配置文件中获取本机IP  */
    
    char *localIP = getConf("localIP", CONF_MASTER);
    if (localIP == NULL) {
        printf("\033[1;31mmaster.conf error : don't have localIP.\033[0m\n");
        return NULL;
    }

    /* 从配置文件中获取本机监听开启哪个端口 */
    
    char *strLocalPort = getConf("localPort", CONF_MASTER);
    if (strLocalPort == NULL) {
        printf("\033[1;31mmaster.conf error : don't have localPort.\033[0m\n");
        free(localIP);
        return NULL;
    }
    int localPort = StrtoInt(strLocalPort);
    free(strLocalPort);

    /* 从配置文件中获取连接上限 */
    
    char *strConnectMax = getConf("connectMax", CONF_MASTER);
    if (strConnectMax == NULL) {
        printf("\033[1;31mmaster.conf error : don't have connectMax.\033[0m\n");
        free(localIP);
        return NULL;
    }
    int connectMax = StrtoInt(strConnectMax);
    free(strConnectMax);

    /* 开启监听，等待服务器端连入*/
    
    int sockFd = sockServer(localIP, localPort);
    struct sockaddr_in addrSon;
    socklen_t addrSonLen = sizeof(addrSon);
    free(localIP);
    
    while (1) {
        
        /* 读取所有链表的长度，获取最短链表(minLenList)和总共连接数(nowConnectNum)。*/
        
        LinkList *minLenList = arg.list[0];
        int nowConnectNum = arg.list[0]->length;
        for (int i = 1; i < arg.listNum; i++) {
            nowConnectNum += arg.list[i]->length;
            minLenList = (arg.list[i]->length < minLenList->length ? arg.list[i] : minLenList);
        }
        printf("Now connect total : %d\n", nowConnectNum);

        if (nowConnectNum >= connectMax) {
            sleep(1);
            continue;
        }
        
        /* 调用accept接受连入 */
        
        int sockSon = accept(sockFd, (struct sockaddr *)&addrSon, &addrSonLen);
        if (sockSon < 0) {
            break;
        }
        char IP[20] = {'0'};
        sockGetFromIP(IP, (struct sockaddr_in *)&addrSon);
        printf("Server %s already connect to Master!\n", IP);
        
        /* 将新建连接插入链表 */
        
        linkInsert(minLenList, IP, sockSon);
    }
    close(sockFd);
    return NULL;
}

pthread_t CreateConnect(LinkList **list, int num) {
    pthread_t thread;
    arg.list = list;
    arg.listNum = num;

    if (pthread_create(&thread, NULL, (void *)startListen, NULL)) {
        perror("listenGetIP : \033[1;31mcreate thread error\033[0m");
        return -1;
    }

    return thread;
}


