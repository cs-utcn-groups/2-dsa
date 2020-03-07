//
// Created by Ivan on 3/7/2020.
//

#ifndef QUEUES_QWEWE_H
#define QUEUES_QWEWE_H

#include <stdio.h>
#define MAX_LEN 256
#define MAX_NAME 40

typedef struct _node
{
    char* name;
    int roubles, time;
    struct _node* next;
}Node;

typedef struct _list
{
    Node* first;
    Node* last;
    int noOfElements;
}listPtr;

listPtr* qwewe;
FILE *f, *g;

listPtr* instantiateQwewe();
Node* instantiateNode();
void addNode(Node* t);
void printAll();
int computeTime(int TIME);

#endif //QUEUES_QWEWE_H
