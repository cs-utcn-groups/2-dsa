//
// Created by Alina Mihut on 3/8/20.
//

#ifndef ASSIGNMENT_2_2_SLL_H
#define ASSIGNMENT_2_2_SLL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    int rubles;
    int seconds;
    struct node *next;
}NodeT;

NodeT *first, *last;
void initializeList();
void AddLastCostumer ( int rubles, int seconds);
void deleteFirstCostumer();
void printAllElements (FILE *fout);
#endif //ASSIGNMENT_2_2_SLL_H
