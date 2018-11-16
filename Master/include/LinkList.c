/*
* File Name: LinkList.c
* Author:    sunowsir
* Mail:      sunowsir@protonmail.com
* GitHub:    github.com/sunowsir
* Created Time: 2018年11月16日 星期五 10时14分53秒
*/

#include "./LinkList.h"

LinkList *init() {
    LinkList *p = (LinkList *)malloc(sizeof(LinkList));
    p->head.next = NULL;
    p->length = 0;
    return p;
}

LinkNode *getNewNode(const char *IP, int Port) {
    LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));
    // p->IP = (char *)malloc(sizeof(char) * 20);
    p->IP = strdup(IP);
    p->Port = Port;
    p->next = NULL;
    return p;
}

void insert(LinkList *l, const char *IP, int Port, int ind) {
    /* 创建虚拟节点 */
    LinkNode *p = &(l->head);

    /* 找到需要插入的位置的前一个节点 */
    while (ind--) {
        p = p->next;
        if (p == NULL) {
            return ;
        }
    }

    /* 创建一个新的节点 */ 
    LinkNode *insert_node = getNewNode(IP, Port);

    /* 让新节点的next指向虚拟节点的下一个节点，更新头结点，让头结点的next指向链表头 */
    insert_node->next = p->next;
    p->next = insert_node;

    /* 链表长度加1 */
    l->length += 1;

    return ;
}

// delete
void erase(LinkList *l, int ind) {
    LinkNode *p = &(l->head);
    while(ind--) {
        free(p->IP);
        p = p->next;
        if (p == NULL) {
            return ;
        }
    }
    if (p->next == NULL) {
        return ;
    }
    LinkNode *delete_node = p->next;
    p->next = p->next->next;
    free(delete_node);
    l->length -= 1;
    return ;
}

void clear(LinkList *l) {
    if (l->head.next == NULL) {
        return ;
    }
    LinkNode *now_node = l->head.next, *free_node;
    while (now_node) {
        free_node = now_node;
        now_node = now_node->next;
        free(free_node);
    }
    free(l);
    return ;
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

