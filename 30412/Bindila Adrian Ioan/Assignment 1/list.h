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

void initList(void);//good

void addFirst(int x);//good

void addLast(int x);//good

void deleteFirst(void);//good

void deleteLast(void);//good

void doomTheList(void);//good

void deleteElement(int x);//good

void printAll(FILE *output);

void printFirst(int noOfElements,FILE *output);

void printLast(int noOfElements,FILE *output);

#endif //ASSIGNMENT_1_LIST_H
