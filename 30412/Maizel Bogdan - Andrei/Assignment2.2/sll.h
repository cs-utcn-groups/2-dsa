#ifndef ASSIGNMENT_2_2_SLL_H
#define ASSIGNMENT_2_2_SLL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node {
    int money;
    int seconds;
    struct _node *next;
} nodeT;

nodeT *first, *last;

void initList();

void AddLastCostumer(int money, int seconds);

void deleteFirstCustomer();

void printAllElements(FILE *fout);

#endif //ASSIGNMENT_2_2_SLL_H
