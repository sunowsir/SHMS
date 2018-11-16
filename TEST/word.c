/*
* File Name: word.c
* Author:    sunowsir
* Mail:      sunowsir@protonmail.com
* GitHub:    github.com/sunowsir
* Created Time: 2018年11月15日 星期四 17时24分42秒
*/

#include "./needHead.h"

void *test(void *arg) {
    int *pi = (int *)arg;
    printf("Communicating on server 'pi%d'\n", *pi);
    return NULL;
}

int main() {
    
    int num = 1;
    pthread_t thread[11];

    while (1) {
        usleep(10000);
        num = num % 10;
        if (pthread_create(&thread[num], NULL, test, (void *)&num) != 0) {
            perror("Create error!");
            exit(1);
        }
        num++;
    }
    pthread_exit(NULL);

    return 0;
}
