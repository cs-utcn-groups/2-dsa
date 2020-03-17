#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initializeList();
void readInput();
int verify(char *a,char *b);
void addElementFirst(int key);
void addElementLast(int key);
void deleteFirst();
void deleteLast();
void printList(FILE *g);
void removeElement(int key);
void removeAll();
void printFirst(int key,FILE *g);
void printLast(int key,FILE *g);

typedef struct node {
    int data;
    struct node * next;
} NodeT;

NodeT * first, * last;

