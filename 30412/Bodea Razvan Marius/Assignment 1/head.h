//
// Created by razvi on 3/1/2020.
//

#ifndef CLION_HEAD_H
#define CLION_HEAD_H

#include <stdio.h>
#include <stdlib.h>

void initializeSll();

void Add_First(int data);

void Add_Last(int data);

void Delete_First();

void Delete_Last();

void Remove_All();

void Delete_Element(int data);

void Print_All(FILE *fptr);

void Print_First_N(int nr, FILE *fptr);

void Print_Last_N(int nr, int noOfEl, FILE *fptr);

int Check_Element(int n);

typedef struct node {
    int data;
    struct node *next;
} NodeT;

NodeT *first, *last;


#endif //CLION_HEAD_H
