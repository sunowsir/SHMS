/*
* File Name: masterConnect.c
* Author:    sunowsir
* Mail:      sunowsir@protonmail.com
* GitHub:    github.com/sunowsir
* Created Time: 2018年11月13日 星期二 21时43分43秒
*/

#include "../include/mainMaster.h"

int masterConnect() {

    /* Get threadNum from master.conf */

    char *threadNum = getConf("threadNum", "./master.conf");
    if (threadNum == NULL) {
        printf("master.conf error : don't have threadNum.\n");
        return 1;
    }
    int MaxNum = StrtoInt(threadNum);
    free(threadNum);

    LinkList *list[MaxNum];

    for (int i = 0; i < MaxNum; i++) {
        list[i] = linkInit();
    }
    
    /* 开启子线程，在子线程中开启socket服务，监控上线服务器，存储连接套接字。*/
    
    pthread_t listenThread = CreateConnect(list, MaxNum);
    if (listenThread  == -1)  {
        exit(1);
    }
    
    /* 创建指定数量线程，将存储服务器信息的链表作为参数传递给dataTransmission函数。*/
    
    pthread_t thread[MaxNum];
    for (int i = 0; i < MaxNum; i++) {
        if (pthread_create(&thread[i], NULL, dataTransmission, (void *)list[i])) {
            perror("pthread_create dataTransmission");
            return 1;
        }
    }
    for (int i = 0; i < MaxNum; i++) {
        pthread_join(thread[i], NULL);
    }
    
    pthread_join(listenThread, NULL);
    pthread_exit(NULL); 
    return 0;
}



