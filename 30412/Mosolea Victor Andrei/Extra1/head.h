//
// Created by Victor on 3/2/2020.
//

#ifndef EXTRA1_HEAD_H
#define EXTRA1_HEAD_H

#endif //EXTRA1_HEAD_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_COUNTRY_NAME 56
#define MAX_LINE 255
typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct list {
    Node *first;
    Node *last;
} List;
typedef struct country {
    char name[MAX_COUNTRY_NAME];
    List waves;
    int totalDamage;
    int totalPower;
} Country;


struct list createList();

void addElementFirst(int data, List *list);

void addElementLast(int data, List *list);

void printList(List list, FILE *f);

void deleteFirst(List *list);

void deleteLast(List *list);

void removeAll(List *list);

void printFirstN(int n, List list, FILE *f);

void printLastN(int n, List list, FILE *f);

void deleteElement(int data, List *list);