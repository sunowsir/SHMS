/*
* File Name: masterConnect.c
* Author:    sunowsir
* Mail:      sunowsir@protonmail.com
* GitHub:    github.com/sunowsir
* Created Time: 2018年11月13日 星期二 21时43分43秒
*/

#include "./mainMaster.h"

int masterConnect() {

    /* Get threadNum from master.conf */

    char *threadNum = getConf("threadNum", "./master.conf");
    if (threadNum == NULL) {
        printf("master.conf error : don't have threadNum.\n");
        return 1;
    }
    int MaxNum = StrtoInt(threadNum);
    pthread_t thread[MaxNum];
    LinkList *list[MaxNum];
    free(threadNum);

    getAllIP(list, MaxNum);  

    for (int i = 0; i < MaxNum; i++) {
        
        /* Create thread. */
        
        if (pthread_create(&thread[i], NULL, dataTransmission, (void *)&i)) {
            perror("pthread_create error");
            return 1;
        }
    }
    
    /*   */
    
    for (int i = 0; i < MaxNum; i++) {
        pthread_join(thread[i], NULL);
    }
    pthread_exit(NULL); 
    
    return 0;
}
