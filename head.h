#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void initializeList();
void AF(int data);
void AL(int data);
void DF();
void DL();
void DE(int x);
void PRINT_ALL(FILE * g);
void PRINT_L(FILE * g,int x);
void PRINT_F(FILE * g,int x);
void DOOM_THE_LIST();
void readFile(FILE * f,FILE * g);
typedef struct node
{
    int data;
    struct node * next, * previous;
} NodeT;
NodeT * first, * last;
