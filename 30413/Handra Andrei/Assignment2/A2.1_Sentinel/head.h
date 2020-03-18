#include<stdlib.h>
#include<stdio.h>

void Initialize_Dll();
void Add_first(int x);
void Add_last(int x);
void Delete_first();
void Delete_last();
void Delete_all();
void Delete_el(int x);
void Print_all(FILE *);
void Print_f(int ,FILE *);
void Print_l(int , FILE *);

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *previous;
}NodeT;

typedef struct Sentinel1
{
    NodeT *first;
    NodeT *last;
}sentinell;

sentinell *sentinel;

