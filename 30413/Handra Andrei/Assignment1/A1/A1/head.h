#include<stdio.h>
#include<stdlib.h>

void InitializeSLL();
void print_all(FILE *g);
void print_f(int n,FILE *g);
void print_l(int n,FILE *g);
void doom_list();
void add_first(int key);
void add_last(int key);
void Delete_first();
void Delete_Last();
void DE(int key);

typedef struct Node
{
    int data;
    struct Node *next;
}NodeT;

NodeT *first, *last;


