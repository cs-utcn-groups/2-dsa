//
// Created by Dominic on 3/10/2020.
//

#ifndef SENTINEL2_INSTRUCTIONS_H
#define SENTINEL2_INSTRUCTIONS_H

#endif //SENTINEL2_INSTRUCTIONS_H
#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    int data;
    struct node *prev,*next;

}NodeT;

typedef struct sentinel{
    NodeT *first,*last;
}SentinelT;

void initializeSentinel();

void addFirst(int x);

void addLast(int x);

void deleteFirst();

void deleteLast();

void DOOM_THE_LIST();

void delete(int x);

void printAll(FILE *f);

void printFirstX(FILE *f, int x);

void printLastX(FILE *F, int x);
