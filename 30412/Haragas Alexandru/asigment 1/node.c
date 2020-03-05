//
// Created by Alex on 27.02.2020.
//
#include "node.h"

void InitializeList() {
    first = NULL;
    last = NULL;
    noelem = 0;
}

void AddFirst(int x) {
    if (first == NULL) {
        first = (List *) malloc(sizeof(List));
        first->val = x;
        first->next = last;
        last = first;
    } else {
        List *newnode = (List *) malloc(sizeof(List));
        newnode->val = x;
        newnode->next = first;
        first = newnode;
    }
    noelem++;
}

void AddLast(int x) {
    if (first == NULL) {
        first = (List *) malloc(sizeof(List));
        first->val = x;
        first->next = last;
        last = first;
    } else {
        List *newnode = (List *) malloc(sizeof(List));
        newnode->val = x;
        newnode->next = NULL;
        last->next = newnode;
        last = newnode;
    }
    noelem++;
}

void DeleteFirst() {
    if (first != NULL) {
        List *newnode = first;
        first = first->next;
        free(newnode);
        if (first == NULL)
            last = NULL;
        noelem--;
    }
}

void DeleteLast() {
    if (last == first)
        DeleteFirst();
    else {
            List *newnode = last;
            List *prevnode = first;
            while (prevnode->next != last)
                prevnode = prevnode->next;
            last = prevnode;
            prevnode->next = NULL;
            free(newnode);
            noelem--;
    }
}

void DeleteList() {
    while (first != NULL)
        DeleteFirst();
}

void DeleteElem(int x) {
    if (first->val == x) {
        DeleteFirst();
    } else {
        List *curelem = first->next;
        List *prevelem = first;
        while (curelem != last && curelem!=NULL) {
            if (curelem->val == x) {
                prevelem->next = curelem->next;
                free(curelem);
                noelem--;
                return;
            }
            curelem = curelem->next;
        }
        if (last->val == x)
            DeleteLast();
    }
}

void PrintList() {
    List *curnode = first;
    while (curnode != NULL) {
        printf("%d ", curnode->val);
        curnode = curnode->next;
    }
    printf("\n");
}

void PrintFirst(int x) {
    List *curelem = first;
    for (int i = 0; i < x && curelem != NULL; i++, curelem = curelem->next) {
        printf("%d ", curelem->val);
    }
    printf("\n");
}

void PrintLast(int x) {
    List *curelem = first;
    int c = noelem;
    while (c > x) {
        curelem = curelem->next;
        c--;
    }
    while (curelem != NULL) {
        printf("%d ", curelem->val);
        curelem = curelem->next;
    }
    printf("\n");
}
