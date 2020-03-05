//
// Created by Bobby on 3/3/2020.
//

#ifndef ASSIGNMENT_1_ALLOC_H
#define ASSIGNMENT_1_ALLOC_H

#include <stdlib.h>
#include <stdio.h>


typedef struct node {
    int data;
    struct node *next;
} NodeT;

NodeT *first, *last, *aux;

void startSLL();

void AF(int data);

void printALL(FILE *f);

void AL(int data);

void DF();

void DL();

void DOOM();

void DE();

void printF(FILE *f, int x);

void noOfItems(FILE *f, int x, int *count, NodeT *q);

void printL(FILE *f, int data, int k);

#endif //ASSIGNMENT1_LIST_H
