#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readFile(FILE *f,FILE *g);
void initializeSLL();
void addFirst(int data);
void addLast(int data);
void deleteFirst();
void deleteLast();
void removeAll();
void deleteEl(int data);
void printSLL();
void printFirst(int data,FILE *g);
void printLast(int data,FILE *g);

typedef struct node
{
    int data;
    struct node *next;
} Node;
Node *first;
Node *last;
