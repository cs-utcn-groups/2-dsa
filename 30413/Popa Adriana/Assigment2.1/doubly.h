#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initializeList();
void readInput();
int verify(char *a,char *b);
void addLast(int data);
void addFirst(int data);
void deleteFirst();
void deleteLast();
void deleteElement(int data);
void doom();
void printList(FILE *g);
void printFirst(int x,FILE *g);
void printLast(int x,FILE *g);

typedef struct node
{
    int data;
    struct node *next;
    struct node *previous;
}NodeT;

NodeT *first, *last;
