/*
* File Name: LinkList.c
* Author:    sunowsir
* Mail:      sunowsir@protonmail.com
* GitHub:    github.com/sunowsir
* Created Time: 2018年11月16日 星期五 10时14分53秒
*/

#include "../include/LinkList.h"

LinkList *linkInit() {
    LinkList *p = (LinkList *)malloc(sizeof(LinkList));
    p->head.next = NULL;
    p->length = 0;
    return p;
}

LinkNode *linkGetNewNode(char *IP, int sockFd) {
    LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));
    p->IP = strdup(IP);
    p->sockFd = sockFd;
    p->next = NULL;
    return p;
}

void linkInsert(LinkList *l, char *IP, int sockFd) {
    LinkNode *p = &(l->head);
    
    while (p->next) {
        p = p->next;
    }
    
    LinkNode *insert_node = linkGetNewNode(IP, sockFd);
    insert_node->next = p->next;
    p->next = insert_node;
    l->length += 1;
    return ;
}

// delete
void linkErase(LinkList *l, LinkNode *needDelete) {
    LinkNode *p = &(l->head);
    
    while (p->next) {
        if (p->next == needDelete) {
            break;
        }
    }
    
    if (p->next == NULL) {
        return ;
    }
    LinkNode *delete_node = p->next;
    p->next = p->next->next;
    free(delete_node->IP);
    close(delete_node->sockFd);
    free(delete_node);
    l->length -= 1;
    return ;
}

void linkClear(LinkList *l) {
    if (l->head.next == NULL) {
        return ;
    }
    LinkNode *now_node = l->head.next, *free_node;
    while (now_node) {
        free_node = now_node;
        now_node = now_node->next;
        close(free_node->sockFd);
        free(free_node->IP);
        free(free_node);
    }
    free(l);
    return ;
}

int search(LinkList *list, /* const char *IP */int sockFd) {
    LinkNode *currentNode = list->head.next;
    while (currentNode) {
        if (/* !strcmp(currentNode->IP, IP) */ currentNode->sockFd == sockFd) {
            return 0;
        }
        currentNode = currentNode->next;
    }
    return 1;
}

// void output(LinkList *l) {
//     printf("[%.2d] ", l->length);
//     LinkNode *output_node = l->head.next;
//     while (output_node) {
//         printf(" %d -> ", output_node->data);
//         output_node = output_node->next;
//     }
//     printf(" NULL\n");
//     return ;
// }

