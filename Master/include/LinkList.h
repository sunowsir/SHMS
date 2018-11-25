/*
* File Name: LinkList.h
* Author:    sunowsir
* Mail:      sunowsir@protonmail.com
* GitHub:    github.com/sunowsir
* Created Time: 2018年11月16日 星期五 10时11分15秒
*/

#ifndef _LINKLIST_H
#define _LINKLIST_H

#include "../../Share/include/needHead.h"

typedef struct LinkNode {
    // char *IP;
    int sockFd;
    struct LinkNode *next;
} LinkNode;

typedef struct LinkList {
    LinkNode head;
    int length;
} LinkList;

LinkList *linkInit();

LinkNode *linkGetNewNode(/* char *, */ int /* Port */);

void linkInsert(LinkList *, /* char *, */ int /* Port */);

void linkErase(LinkList *, LinkNode *);

/* return : success(0), false(1) */

int linkSearch(LinkList *, /* const char * */ int);

void linkClear(LinkList *);

#endif
