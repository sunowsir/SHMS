/*************************************************************************
	> File Name:    Get_fsize.c
	> Author:       sunowsir
	> Mail:         sunowsir@protonmail.com
	> Created Time: 2018年09月28日 星期五 17时38分36秒
 ************************************************************************/

#include "head.h"

int Get_filesize(char *filename) {

    struct stat statbuf;
    stat(filename,&statbuf);
    int size=statbuf.st_size;

    return size;
}
