#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node * next;
} NodeT;

NodeT * first, * last;

void initializeList();
void PRINT_ALL();
void DOOM_THE_LIST();
void DL();
void DF();
void AL(int data);
void AF(int data);
void DE(int x);
void PRINT_F(int x);
void PRINT_L(int x);
int countAll();
