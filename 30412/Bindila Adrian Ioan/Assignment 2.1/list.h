//
// Created by bindi on 3/9/2020.
//

#ifndef ASSIGNMENT_2_LIST_H
#define ASSIGNMENT_2_LIST_H
typedef struct _list {
    int data;
    struct _list *next;
    struct _list *prev;
} list;
typedef struct _sentinel {
    list *first;
    list *last;
} sentinel;

void initList(void);

void addFirst(int x);

void addLast(int x);

void deleteFirst(void);

void deleteLast(void);

void doomTheList(void);

void deleteElement(int x);

void printAll(FILE *output);

void printFirst(FILE *output, int x);

void printLast(FILE *output, int x);

#endif //ASSIGNMENT_2_LIST_H
