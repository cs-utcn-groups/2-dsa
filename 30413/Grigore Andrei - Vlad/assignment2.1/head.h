#include <stdio.h>
#include <stdlib.h>

void initializeDll();
void PRINT_ALL(FILE *o);
void AL(int data);
void AF(int data);
void DL();
void DF();
void DE(int data);
void DOOM_THE_LIST();
void PRINT_F(int value,FILE *o);
void PRINT_L(int nr,FILE *o);

typedef struct node {
    int data;
    struct node * next;
    struct node * prev;
} NodeT;

typedef struct _san {

   NodeT *first;
   NodeT *last;

}Sentinel;
//Sentinel*san=NULL;
Sentinel*san;
