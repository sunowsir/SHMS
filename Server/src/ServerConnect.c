/*
 * File Name:    ServerConnect.c
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * GitHub:       github.com/sunowsir
 * Created Time: 2018年11月23日 星期五 16时22分03秒
 */

#include "../include/mainServer.h"

int ServerConnect() {
    /* 运行六个脚本采集数据保存到日志 */
    pthread_t threadGetInfo[6];
    int dataType[6] = {100, 101, 102, 103, 104, 105};

    printf("ServerConnect(): will run getInfo()\n");
    
    for (int i = 0; i < 6; i++) {
        if (pthread_create(&threadGetInfo[i], NULL, monitorHealth, &dataType[i])) {
            perror("pthread_create getInfo");
            return -1;
        }
    }
    
    
    /* 心跳发送数据 */
    pthread_t threadheart;
    printf("ServerConnect(): will run heartBeat()\n");
    if (pthread_create(&threadheart, NULL, heartBeat, NULL)) {
        perror("pthread_create heartBeat");
        return -1;
    }

    pthread_join(threadheart, NULL);
    for (int i = 0; i < 6; i++) {
        pthread_join(threadGetInfo[i], NULL);
    }
    
    pthread_exit(NULL);
    return 0;
}



