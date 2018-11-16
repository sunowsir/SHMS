/*
* File Name: LinkList.h
* Author:    sunowsir
* Mail:      sunowsir@protonmail.com
* GitHub:    github.com/sunowsir
* Created Time: 2018年11月16日 星期五 10时11分15秒
*/

#ifndef _LINKLIST_H
#define _LINKLIST_H

#include "../../includeShare/needHead.h"

typedef struct LinkNode {
    char *IP;
    int Port;
    struct LinkNode *next;
} LinkNode;

typedef struct LinkList {
    LinkNode head;
    int length;
} LinkList;

LinkList *init();

LinkNode *getNewNode(const char * /* IP */ , int /* Port */);

void insert(LinkList *, const char * /* IP */ , int /* Port */, int);

void erase(LinkList *, int);

void clear(LinkList *);

#endif
