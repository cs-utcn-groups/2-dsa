//
// Created by Alex on 05.03.2020.
//

#include "doubleNode.h"

void InitializeList() {
    Dlist = (DoubleList *) malloc(sizeof(DoubleList));
    Dlist->first = NULL;
    Dlist->last = NULL;
}

void AddFirst(int x) {
    if (Dlist->first == NULL) {
        Dlist->first = (List *) malloc(sizeof(List));
        Dlist->first->val = x;
        Dlist->first->next = Dlist->last;
        Dlist->first->prev = NULL;
        Dlist->last = Dlist->first;
    } else {
        List *newnode = (List *) malloc(sizeof(List));
        newnode->val = x;
        newnode->next = Dlist->first;
        Dlist->first->prev = newnode;
        newnode->prev = NULL;
        Dlist->first = newnode;
    }
}

void AddLast(int x) {
    if (Dlist->first == NULL) {
        AddFirst(x);
    } else {
        List *newnode = (List *) malloc(sizeof(List));
        newnode->val = x;
        newnode->next = NULL;
        newnode->prev = Dlist->last;
        Dlist->last->next = newnode;
        Dlist->last = newnode;
    }
}

void DeleteFirst() {
    if (Dlist->first != NULL) {
        List *newnode = Dlist->first;
        Dlist->first = Dlist->first->next;
        if (Dlist->first != NULL)
            Dlist->first->prev = NULL;
        free(newnode);
        if (Dlist->first == NULL)
            Dlist->last = NULL;
    }
}

void DeleteLast() {
    if (Dlist->last == Dlist->first)
        DeleteFirst();
    else {
        List *newnode = Dlist->last;
        Dlist->last = Dlist->last->prev;
        Dlist->last->next = NULL;
        free(newnode);
    }
}

void DeleteList() {
    while (Dlist->first != NULL)
        DeleteFirst();
}

void DeleteElem(int x) {
    if (Dlist->first->val == x) {
        DeleteFirst();
    } else {
        List *curelem = Dlist->first->next;
        while (curelem !=Dlist->last && curelem != NULL) {
            if (curelem->val == x) {
                curelem->next->prev=curelem->prev;
                curelem->prev->next=curelem->next;
                free(curelem);
                return;
            }
            curelem = curelem->next;
        }
        if (Dlist->last->val == x)
            DeleteLast();
    }
}

void PrintList() {
    List *curnode = Dlist->first;
    while (curnode != NULL) {
        printf("%d ", curnode->val);
        curnode = curnode->next;
    }
    printf("\n");
}
void PrintFirst(int x) {
    List *curelem =Dlist->first;
    for (int i = 0; i < x && curelem != NULL; i++, curelem = curelem->next) {
        printf("%d ", curelem->val);
    }
    printf("\n");
}

void PrintLast(int x) {
    List *curelem =Dlist->last;
    for (int i = 1; i < x && curelem->prev != NULL; i++)
    {
        curelem = curelem->prev;
    }
    while(curelem!=NULL)
    {
        printf("%d ",curelem->val);
        curelem=curelem->next;
    }
    printf("\n");
}