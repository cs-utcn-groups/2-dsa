//
// Created by bindi on 3/2/2020.
//

#ifndef ASSIGNMENT_1_LIST_H
#define ASSIGNMENT_1_LIST_H
typedef struct _list {
    int data;
    struct _list *next;
} list;
list *first, *last;
void initList(void);

void addFirst(int x);

void addLast(int x);

void deleteFirst(void);

void deleteLast(void);

void doomTheList(void);

void deleteElement(int x);

void printAll(void);

void printFirst(int noOfElements);

void printLast(int noOfElements);

void printDebugList(void);
#endif //ASSIGNMENT_1_LIST_H
