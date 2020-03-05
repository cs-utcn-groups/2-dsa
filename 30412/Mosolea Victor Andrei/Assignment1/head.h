//
// Created by Victor on 3/1/2020.
//

#ifndef ASSIGNMENT1_HEAD_H
#define ASSIGNMENT1_HEAD_H

#endif //ASSIGNMENT1_HEAD_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_COMMAND 15

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct list {
    Node *first;
    Node *last;
} List;

List createList();

void addElementFirst(int data, List *list);

void addElementLast(int data, List *list);

void printList(List list, FILE *f);

void deleteFirst(List *list);

void deleteLast(List *list);

void removeAll(List *list);

void printFirstN(int n, List list, FILE *f);

void printLastN(int n, List list, FILE *f);

void deleteElement(int data, List *list);