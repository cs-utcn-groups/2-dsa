#include <stdio.h>
#include <stdlib.h>

void initialize();
void addElementf(int data);
void addElementi(int data);
void eraseElement(int data);
void erasei();
void erasef();
void print();
void eraseAll();
void printIx(int x);
void printFx(int x);

typedef struct node
{
   int data;
   struct node* prev;
   struct node* next;
} NodeT;

NodeT* first, * last;

