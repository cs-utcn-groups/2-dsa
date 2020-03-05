//
// Created by ileana on 3/1/2020.
//

#ifndef ASSIGNMENT_1_SLL_H
#define ASSIGNMENT_1_SLL_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int key;
    struct node *next;
}NodeT;

NodeT * first, * last;

void initializeSll();

void addFirst(int givenKey);
void addLast(int key);

void deleteFirst();
void deleteLast();
void removeElement(int givenKey);
void removeAll();

void printSllData(FILE *fptr);
void printFirstValues(int n,FILE *fptr);
void printLastValues(int n, FILE *fptr);

#endif //ASSIGNMENT_1_SLL_H
