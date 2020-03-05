//
// Created by Cosmin on 26-Feb-20.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *input, *output;

typedef struct node {
    int data;
    struct node *next;
} Node;

#define MAX_CMD_LINE 100

void init();
void AF(int x);
void AL(int x);
void DF();
void DL();
void DOOM_THE_LIST();
void DE(int x);
void PRINT_ALL();
void PRINT_F(int x);
void PRINT_L(int x);