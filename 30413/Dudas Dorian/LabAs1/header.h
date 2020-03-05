#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fAF();
void fAL();

void fDF();
void fDL();
void fDOOM();
void fDE();

void fPA();
void fPF();
void fPL();

typedef struct node
{
    int data;
    struct node * next;
} NodeT;

NodeT * first, * last;