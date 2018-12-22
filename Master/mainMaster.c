/*
* File Name: mainMaster.c
* Author:    sunowsir
* Mail:      sunowsir@protonmail.com
* GitHub:    github.com/sunowsir
* Created Time: 2018年11月13日 星期二 20时33分34秒
*/

#include "./include/mainMaster.h"

int main() {
    pid_t masterPID = fork();
    if (masterPID < 0) {
        perror("main(Fork)");
        return 1;
    } else if (masterPID == 0) {
        if (masterConnect()) {
            perror("masterConnect error!");
            return 1;
        }
    } else {
        const char PIDFile[] = "/etc/SHMS-master/master.pid";
        FILE *fp = fopen(PIDFile, "w");
        if (fp == NULL) {
            perror("main(open PIDFile)");
            return 1;
        }
        if (fprintf(fp, "%d", masterPID) < 0) {
            fclose(fp);
            perror("main(write pid to PIDFile)");
            return 1;
        }
        fclose(fp);

    }
    return 0;
}
