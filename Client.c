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
        if (!strcmp(type, "STDIO") || !strcmp(type, "FILE")) {
            break;
        } else {
            printf("TYPE ERROR !\n");
        }
    }
    
    // 创建sockaddr_in　结构体
    struct sockaddr_in  caddr;

    // 初始化sockaddr_in　结构体
    memset(&caddr, 0, sizeof(caddr));
    caddr.sin_family = AF_INET;  
    caddr.sin_port = htons(Port);  
    
    // 创建新的socket
    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    
    if(inet_pton(AF_INET, IP, &caddr.sin_addr) <= 0) {
        perror("Inet_pton");
        exit(1);
    }

    if (connect(sock, (struct sockaddr*)&caddr, sizeof(caddr)) < 0) {
        perror("Connect");
        exit(1);
    }


    if (send(sock, type, strlen(type), 0) < 0) {
        perror("Send");
        exit(1);
    }

    if (!strcmp(type, "STDIO")) {
        printf("TYPE:[STDOUT]\n");
        char word[10240] = "";
        while (fgets(word, 1024, stdin) != NULL) {
            if (send(sock, word, strlen(word), 0) < 0) {
                perror("Send");
                exit(1);
            }
            memset(word, 0, sizeof(word));
        }
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

            if (send(sock, file_path, strlen(file_path), 0) < 0) {
                perror("Send");
                exit(1);
            }
            FILE *fp = fopen(file_path, "r");
            int word_len;
            char word[10240] = "";
            while ((word_len = fread(word, sizeof(char), 1024, fp)) > 0) {
                if (send(sock, word, strlen(word), 0) < 0) {
                    perror("Send");
                    exit(1);
                }
                memset(word, 0, sizeof(word));
            }
            fclose(fp);
        }
    }

    printf("Already Exit.\n");

    close(sock);
    
    return 0;
}
