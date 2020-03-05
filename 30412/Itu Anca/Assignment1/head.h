//
// Created by Anca on 3/1/2020.
//

#ifndef ASSIGNMENT1_HEAD_H
#define ASSIGNMENT1_HEAD_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int data;
    struct node * next;
}NodeT;
NodeT *first, *last;

void printSllData();
void AddFirst(int x);
void AddLast(int x);
void DeleteFirst();
void DeleteLast();
void Delete(int x);
void PrintFirstXElements(int x);
void PrintLastXElements(int x);
void DeleteAll();

FILE *fptrout;

#endif //ASSIGNMENT1_HEAD_H
