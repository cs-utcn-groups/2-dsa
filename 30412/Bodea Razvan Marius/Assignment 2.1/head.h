//
// Created by razvi on 3/1/2020.
//

#ifndef CLION_HEAD_H
#define CLION_HEAD_H

#include <stdio.h>
#include <stdlib.h>

void initializeDll();

void Add_First(int data);

void Add_Last(int data);

void Delete_First();

void Delete_Last();

void Remove_All();

void Delete_Element(int data);

void Print_All(FILE *fptr);

void Print_First_N(int nr, FILE *fptr);

void Print_Last_N(int nr, FILE *fptr);

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} NodeT;

typedef struct list {
    NodeT *first;
    NodeT *last;
} LisT;

LisT *list;

#endif //CLION_HEAD_H
