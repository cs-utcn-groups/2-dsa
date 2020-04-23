//
// Created by q on 4/14/2020.
//

#include "verticesList.h"

VlistT * createList(int N) {
    VlistT * l = (VlistT*)malloc(sizeof(VlistT));
    if(l == NULL) {
        errMessage();
        exit(EXIT_FAILURE);
    }
    l->count = 0;
    l->head = l->tail = NULL;
    return l;
}
void printingList(VlistT * l) {
    NodeT * temp = l->head;
    while(temp) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    new_line;
}
void addNewNode(VlistT * l, int x) {
    NodeT * new = createNode(x);
    if(l->count == 0) {
        l->head = l->tail = new;
    }
    else {
        l->tail->next = new;
        l->tail = new;
    }
    l->count++;
}
