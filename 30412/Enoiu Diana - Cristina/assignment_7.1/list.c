//
// Created by Diana on 07/05/2020.
//
#include "list.h"
#include "io.h"

nodeT * createNode(char * content)
{
    nodeT * n = (nodeT*) malloc(sizeof(nodeT));
    n->content = (char*) malloc(sizeof(char) * MAX_STRING_LENGTH);
    n->content = content;
    n->next = NULL;
    return n;
}

void addToList(listT *l, char * content)
{
    nodeT * node = createNode(content);
    if (l->head == NULL) {
        l->head = node;
        l->tail = l->head;
    } else {
        l->tail->next = node;
        l->tail = l->tail->next;
    }
    l->sizeList++;
}
