#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void initializeList();
void AF(int data);
void AL(int data);
void DE(int x);
void DF();
void DL();
void DOOM_THE_LIST();
void PRINT_F(int x,FILE * g);
void PRINT_L(int x,FILE * g);
void PRINT_ALL(FILE * g);
void readFile(FILE * f,FILE * g);
typedef struct node
{
    int data;
    struct node * next;
}
NodeT;
NodeT * first, * last;
