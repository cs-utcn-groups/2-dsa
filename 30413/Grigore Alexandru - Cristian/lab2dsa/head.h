#include <stdio.h>
#include <stdlib.h>

void initializeDll();
void AF(int key);
void AL(int key);
void print_All(FILE *o);
void DE(int key);
void DF();
void DL();
void DOOM_THE_LIST();
void PRINT_F(int nr,FILE *o);
void PRINT_L(int nr,FILE *o);

typedef struct node {
    int data;
    struct node * next;
    struct node * prev;
} NodeT;

typedef struct sentinel{
    NodeT *first;
    NodeT *last;
}SentinelT;

