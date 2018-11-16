/*************************************************************************
	> File Name:    Sendio.c
	> Author:       sunowsir
	> Mail:         sunowsir@protonmail.com
	> Created Time: 2018年09月28日 星期五 17时17分14秒
 ************************************************************************/

#include "head.h" 

void Sendio(int *sock) {
    printf("TYPE:[STDOUT]\n");
    char word[10240] = "";
    while (fgets(word, 1024, stdin) != NULL) {
        Sendw(sock, word);
        memset(word, 0, sizeof(word));
    }

    return;
}

