#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#define MAX_LEN 20
#include <string.h>
#include <stdio.h>

FILE *f, *g;

typedef struct node
{
    int data;
    struct node *next;
} NodeT;

NodeT *first, *last;

void initList();
void AL(int data);
void AF(int data);
void DF();
void DL();
void DOOM_THE_LIST();
void DE(int data);
void PRINT_ALL();
void PRINT_F(int x);
void PRINT_L(int x);

#endif // LIST_H_INCLUDED
