#include "list.h"

void initList(List *list) {
    list->first = NULL;
    list->last = NULL;
}

void enqueue(int data, List *list) {
    NodeT *newNode = (NodeT *) malloc(sizeof(NodeT));
    newNode->data = data;
    newNode->next = NULL;
    if (list->first == NULL) {
        list->first = newNode;
        list->last = list->first;
        list->last->next = NULL;
    } else
        list->last->next = newNode;
    list->last = newNode;
}

int dequeue(List *list) {
    int dequeue = list->first->data;
    if (list->first != NULL) {
        NodeT *aux = list->first;
        list->first = list->first->next;
        free(aux);
    }
    if (list->first == NULL)
        list->last = NULL;
    return dequeue;
}