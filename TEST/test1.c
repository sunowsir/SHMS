/*
* File Name: test1.c
* Author:    sunowsir
* Mail:      sunowsir@protonmail.com
* GitHub:    github.com/sunowsir
* Created Time: 2018年11月15日 星期四 17时34分25秒
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 5      //线程个数

void *print_hello(void *threadid)
{
    // 对传入的参数进行强制类型转换，由无类型指针变为整形数指针，然后再读取
    int tid = *((int*)threadid);
    printf("Hello Runoob! 线程 ID, %d\n", tid);
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int index[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; ++i) {
        printf("main() : 创建线程, %d\n", i);
        index[i] = i;
        int ret = pthread_create(&threads[i], NULL, print_hello, (void*)&(index[i]));
        if (ret != 0) {
            printf("pthread_create error: error_code = %d\n", ret);
            exit(-1);
        }
    }

    pthread_exit(NULL);
}
