/*
 * File Name:    mainServer.c
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * GitHub:       github.com/sunowsir
 * Created Time: 2018年11月22日 星期四 15时02分57秒
 */

#include "./include/mainServer.h"

int main() {
    
    pid_t serverPID = fork();
    if (serverPID < 0) {
        perror("main(Fork)");
        return 1;
    }
    else if (serverPID == 0) {
        
        /* 重定向错误信息到运行日志 */
        if (freopen(RUN_LOG_SERVER, "a", stderr) == NULL) {
            perror("main (freopen)");
            exit(1);
        }
        if (freopen("/dev/null", "a", stdout) == NULL) {
            perror("main (freopen)");
            exit(1);
        }
        
        if (ServerConnect()) {
            printf("ServerConnect \033[1;31merror\033[0m\n");
        }
    } else {
        const char PIDFile[] = "/etc/SHMS-server/server.pid";
        FILE *fp = fopen(PIDFile, "w");
        if (fp == NULL) {
            perror("main(open PIDFile)");
            return 1;
        }
        if (fprintf(fp, "%d", serverPID) < 0) {
            fclose(fp);
            perror("main(write pid to PIDFile)");
            return 1;
        }
        fclose(fp);
    }
    
    return 0;
}
