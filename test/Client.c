/*************************************************************************
	> File Name:    Client.c
	> Author:       sunowsir
	> Mail:         sunowsir@protonmail.com
	> Created Time: 2018年09月23日 星期日 16时21分22秒
 ************************************************************************/

#include "head.h"

int main (int argc, char **argv) {

    char *IP, type[10];
    int Port;
    IP = argv[1];
    sscanf(argv[2], "%d", &Port);
    while (1) {
        printf("TYPE:");
        scanf("%s", type);
        if (!strcmp(type, "STDIO") || !strcmp(type, "FILE"), !strcmp(type, "LOG")) {
            break;
        } else {
            printf("TYPE ERROR !\n");
        }
    }

    // Greate connect and return socket.
    int sock;
    Cret_cont(&sock, IP, Port);

    Sendw(&sock, type);

    if (!strcmp(type, "STDIO")) {
        Sendio(&sock);
    } else if (!strcmp(type, "FILE")) {
        printf("TYPE:[FILE]\n");

        while (1) {
            printf("input file and file path:\n");
            
            // send path and file name.
            char file_path[1000] = "";
            scanf("%s", file_path);
            if (!strcmp(file_path, "exit") || !strcmp(file_path, "quit")) {
                break;
            }
            Sendfile(&sock, file_path);
        }
    } else if (!strcmp(type, "LOG")) {
        while (1) {

            pid_t pid1;
            if ((pid1 = fork()) < 0) {
                perror("Fork98");
                exit(1);
            } else if (pid1 == 0) {
                printf("pid1 son: \n");
                pid_t pid2;
                if ((pid2 = fork()) < 0) {
                    perror("Fork102");
                    exit(1);
                } else if (pid2 == 0) {
                    printf("pid2 son\n");
                    char result[1000] = "";
                    FILE  *fp = popen("~/GitHub/MyShell/CPU_info.sh", "r");
                    fgets(result, sizeof(result), fp);
                    pclose(fp);

                    strcat(result, "cpu.log");
                    // send information
                    Sendw(&sock, result);
                    exit(0);
                } else {
                    if(wait(NULL) < 0) {
                        perror("Wait136");
                    }
                    printf("pid2 father\n");
                    char result[1000] = "";
                    FILE  *fp = popen("~/GitHub/MyShell/Disk_info.sh", "r");
                    fgets(result, sizeof(result), fp);
                    pclose(fp);

                    strcat(result, "disk.log");
                    // send information
                    Sendw(&sock, result);
                }
                exit(0);
            } else {
                if(wait(NULL) < 0) {
                    perror("Wait136");
                }
                printf("pid1 father\n");
                char result[1000] = "";
                FILE  *fp = popen("~/GitHub/MyShell/Mem_info.sh", "r");
                fgets(result, sizeof(result), fp);
                pclose(fp);

                strcat(result, "mem.log");
                // send information
                Sendw(&sock, result);

                // sleep five second .
                printf("sleep 5s\n");
                usleep(5000000);
            }
        }
    }

    printf("Already Exit.\n");

    Sclose(&sock);
    
    return 0;
}
