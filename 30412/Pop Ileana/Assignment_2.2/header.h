//
// Created by ileana on 3/7/2020.
//

#ifndef ASSIGNMENT_2_2_HEADER_H
#define ASSIGNMENT_2_2_HEADER_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int x;         //rubles
    int y;         //seconds
    struct node * next;
}NodeT;

NodeT * first, * last;

void initializeSll();
void addLast(int rubles, int seconds);
void deleteFirst();
void printSllData(FILE *fptr);

#endif //ASSIGNMENT_2_2_HEADER_H
