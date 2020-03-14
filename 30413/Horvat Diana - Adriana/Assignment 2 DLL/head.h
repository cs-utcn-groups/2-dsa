#include <stdio.h>
#include <stdlib.h>

void readFile(FILE *f, FILE *g);
void initializeDLL();
void addFirst(int data);
void addLast(int data);
void deleteFirst();
void deleteLast();
void removeAll();
void deleteEl(int data);
void print_first(int x,FILE *g);
void print_last(int x, FILE *g);
void print_all(FILE *g);


typedef struct node
{
    int value;
    struct node *next;
    struct node *prev;
} Node;
Node *first;
Node *last;



