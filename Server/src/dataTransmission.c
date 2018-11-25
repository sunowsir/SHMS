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

        /* 根据需要字符串长度定义Package，发送Package */

        /* 发送字符串 */
        
    }
    /* 发送结束码CLOSE_NOW */
    

    return 0;
}
