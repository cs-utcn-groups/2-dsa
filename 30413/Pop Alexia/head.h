#include <stdio.h>
#include <stdlib.h>

void initialize();
void addelementf(int data);
void addelementi(int data);
void eraseelement(int data);
void erasei();
void erasef();
void print();
void eraseall();
void printix(int x);
void printfx(int x);

typedef struct node
{
   int data;
   struct node* next;
} NodeT;

NodeT* first, * last;
