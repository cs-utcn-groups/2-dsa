//
// Created by Dominic on 3/4/2020.
//

#ifndef LAB1ASSIGNMENT_INSTRUCTIONS_H
#define LAB1ASSIGNMENT_INSTRUCTIONS_H

#endif //LAB1ASSIGNMENT_INSTRUCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *next;
} NodeT;

NodeT *first, *last;

void initializeSLL();

void AF(int x);

void AL(int x);

void DF();

void DL();

void doomSLL();

void delete(int x);

void printAll(FILE *f);

void printFirstX(FILE *f, int x);

void printLastX(FILE *F, int x);