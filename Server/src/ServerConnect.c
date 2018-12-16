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
    pthread_t threadGetInfo;
    if (pthread_create(&threadGetInfo, NULL, getInfo, NULL)) {
        perror("pthread_create getInfo");
        return -1;
    }
    
    /* 心跳发送数据 */
    pthread_t threadheart;
    if (pthread_create(&threadheart, NULL, heartBeat, NULL)) {
        perror("pthread_create heartBeat");
        return -1;
    }

    pthread_join(threadheart, NULL);
    pthread_join(threadGetInfo, NULL);
    pthread_exit(NULL);
    return 0;
}
