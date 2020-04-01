//
// Created by Bobby on 3/4/2020.
//

#include "double.h"

void InitializeList() {
    list = (DoubleList *) malloc(sizeof(DoubleList));
    list->first = NULL;
    list->last = NULL;
}

void AddFirst(int x) {
    if (list->first == NULL) {
        list->first = (List *) malloc(sizeof(List));
        list->first->val = x;
        list->first->next = list->last;
        list->first->prev = NULL;
        list->last = list->first;
    } else {
        List *node = (List *) malloc(sizeof(List));
        node->val = x;
        node->next = list->first;
        list->first->prev = node;
        node->prev = NULL;
        list->first = node;
    }
}

void AddLast(int x) {
    if (list->first == NULL) {
        AddFirst(x);
    } else {
        List *node = (List *) malloc(sizeof(List));
        node->val = x;
        node->next = NULL;
        node->prev = list->last;
        list->last->next = node;
        list->last = node;
    }
}

void DeleteFirst() {
    if (list->first != NULL) {
        List *node = list->first;
        list->first = list->first->next;
        if (list->first != NULL)
            list->first->prev = NULL;
        free(node);
        if (list->first == NULL)
            list->last = NULL;
    }
}

void DeleteLast() {
    if (list->last == list->first)
        DeleteFirst();
    else {
        List *node = list->last;
        list->last = list->last->prev;
        list->last->next = NULL;
        free(node);
    }
}

void DeleteList() {
    while (list->first != NULL)
        DeleteFirst();
}

void DeleteElem(int x) {
    if (list->first->val == x) {
        DeleteFirst();
    } else {
        List *cl = list->first->next;
        while (cl != list->last && cl != NULL) {
            if (cl->val == x) {
                cl->next->prev=cl->prev;
                cl->prev->next=cl->next;
                free(cl);
                return;
            }
            cl = cl->next;
        }
        if (list->last->val == x)
            DeleteLast();
    }
}

void PrintList() {
    List *cr = list->first;
    while (cr != NULL) {
        printf("%d ", cr->val);
        cr = cr->next;
    }
    printf("\n");
}
void PrintFirst(int x) {
    List *cl =list->first;
    for (int i = 0; i < x && cl != NULL; i++, cl = cl->next) {
        printf("%d ", cl->val);
    }
    printf("\n");
}

void PrintLast(int x) {
    List *crl =list->last;
    for (int i = 1; i < x && crl->prev != NULL; i++)
    {
        crl = crl->prev;
    }
    while(crl != NULL)
    {
        printf("%d ", crl->val);
        crl=crl->next;
    }
    printf("\n");
}