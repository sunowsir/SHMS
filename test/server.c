/*************************************************************************
	> File Name:    server.c
	> Author:       sunowsir
	> Mail:         sunowsir@protonmail.com
	> Created Time: 2018年09月24日 星期一 09时39分32秒
 ************************************************************************/

#include "head.h"

int main(int argc, char **argv) {

    char *IP;
    int Port;
    IP = argv[1];
    sscanf(argv[2], "%d", &Port);


    // 创建新的socket
    int ssock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    // 创建 sockaddr_in 结构体
    struct sockaddr_in saddr;

    // 初始化 socketaddr_in 结构体
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = inet_addr(IP);
    saddr.sin_port = htons(Port);

    if (bind(ssock, (struct sockaddr*)&saddr, sizeof(saddr)) < 0) {
        perror("Bind");
        exit(1);
    }

    printf("Bind success!\n");

    if (listen(ssock, 20) < 0) {
        perror("Listen");
        exit(1);
    }

    printf("Start to listen!\n");
    
    struct sockaddr_in sonaddr;
    int son_sock;
    socklen_t sonaddr_len = sizeof(sonaddr);

    int nums = 0;

    do {
        son_sock = accept(ssock, (struct sockaddr*)&sonaddr, &sonaddr_len);

        char Fromip[20];
        inet_ntop(AF_INET, (void *)&(sonaddr.sin_addr), Fromip, 16);
        //printf("IP:[%s] Connected.\n", Fromip);


        pid_t pid;

        if ((pid = fork()) < 0) {
            perror("Fork");
            exit(1);
        } else if (pid == 0) {
            close(ssock);
            char type[10] = "";
            int type_len = recv(son_sock, type, 1024, 0);
            type[type_len] = '\0';
            if (type_len == 0) {
                close(son_sock);
                break;
            }
            
            // Get client IP
            char fromip[20];
            inet_ntop(AF_INET, (void *)&(sonaddr.sin_addr), fromip, 16);
            printf("IP[%s] TYPE[%s] Connected.\n", fromip, type);

            while (1) {

                if (!strcmp(type, "FILE")) {
                    // Receive path and file name.
                    char file_path[1024] = "";
                    int file_path_len = recv(son_sock, file_path, 1000, 0);
                    if (file_path_len == 0) {
                        break;
                    }

                    // Receive file content and save
                    char acc_file[10240] = "";
                    int file_len;
                    
                    while ((file_len = recv(son_sock, acc_file, 1024, 0)) != 0) {
                        printf("Receive :\n%s\n", acc_file);

                        FILE *fp = fopen(file_path, "a");
                        fseek(fp, 0, SEEK_END);
                        fwrite(acc_file, sizeof(char), strlen(acc_file), fp);
                        fclose(fp);
                        memset(acc_file, 0, sizeof(acc_file));
                    }
                    
                    printf("Received successfully and already saved.\n");
                } else if (!strcmp(type, "LOG")) {
                    char acc_word[10240] = "";
                    int word_len = recv(son_sock, acc_word, 1024, 0);
                    if (word_len == 0) {
                        break;
                    }
                    char log_name[1000] = "";
                    strcpy(log_name, "./");
                    strcat(log_name, fromip);
                    strcat(log_name, "/");
                    int fname_len = strlen(acc_word);
                    for (int i = strlen(acc_word) - 1; i >= 0;i--) {
                        if (acc_word[i] == '\n') {
                            break;
                        }
                        fname_len--;
                    }
                    int temp = strlen(log_name);
                    for (int i = fname_len; i < strlen(acc_word); i++) {
                        log_name[temp] = acc_word[i];
                        temp++;
                    }
                    char log_info[10240] = "";
                    strncpy(log_info, acc_word, fname_len);
                    printf("%s >> %s\n", log_info, log_name);
                    //printf("From:[%s] Message:%s\n", fromip, acc_word);
                    
                    // make directory.
                    if (access(fromip, 0) == -1) {
                        
                        if (mkdir(fromip, S_IRWXU|S_IRWXG|S_IRWXO) == -1) {
                            perror("Mkdir133");
                            exit(1);
                        }
                    }
                    
                    FILE *fp = fopen(log_name, "a");
                    fseek(fp, 0, SEEK_END);
                    fwrite(log_info, sizeof(char), strlen(log_info), fp);
                    fclose(fp);
                } else {
                    char acc_word[10240] = "";
                    int word_len = recv(son_sock, acc_word, 1024, 0);
                    if (word_len == 0) {
                        break;
                    }
                    printf("From:[%s] Message:%s\n", fromip, acc_word);
                }
            }
            printf("IP[%s] TYPE[%s] Disconnect.\n", fromip, type);
            close(son_sock);
            exit(0);
        } else {
            continue;
        }
        
    } while (1);
    
    close(ssock);

    return 0;
}


