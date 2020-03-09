#include <stdio.h>
#include <stdlib.h>
void initializeSll();
void PRINT_ALL(FILE *o);
void AL(int data);
void AF(int data);
void DL();
void DF();
void DE(int data);
void DOOM_THE_LIST();
void PRINT_F(int data,FILE *o);
void PRINT_L(int data,FILE *o);

typedef struct node {
    int data;
    struct node * next;
} NodeT;

NodeT * first, * last;
