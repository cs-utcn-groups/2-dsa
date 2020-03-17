#include <stdio.h>
#include <stdlib.h>

void pushStack();
void popStack();
void topStack();
void deleteStack();

void enqueue();
void dequeue();
void deleteQueue();

void printSllData();




typedef struct node {
    int data;
    struct node * next;
} NodeT;

NodeT * first, * last;