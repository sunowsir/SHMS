/*************************************************************************
	> File Name:    Sendfile.c
	> Author:       sunowsir
	> Mail:         sunowsir@protonmail.com
	> Created Time: 2018年09月28日 星期五 17时20分05秒
 ************************************************************************/

#include "head.h" 

void Sendfile(int *sock, char *file_path) {
    // Get file size;
    int flen = Get_filesize(file_path);

    int onesend, nowsize;
    nowsize = 1024;
    onesend = flen / 1024 + 1;

    while (onesend--) {
        int sendsize;
        if (flen - nowsize < 0) {
            sendsize = flen - nowsize;
        } else {
            sendsize = 1024;
        }
        nowsize += sendsize;

        char word[sendsize + strlen(file_path) + 5];
        strcpy(word, file_path);
        strcat(word, ":");
        FILE *fp = fopen(file_path, "r");
        fread(word, sizeof(char), sendsize, fp);
        Sendw(sock, word);
        fclose(fp);
    }
    printf("Send file success!\n");

    return;
}

