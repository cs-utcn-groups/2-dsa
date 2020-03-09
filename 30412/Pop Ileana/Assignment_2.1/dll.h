//
// Created by ileana on 3/6/2020.
//

#ifndef ASSIGNMENT_2_1_DLL_H
#define ASSIGNMENT_2_1_DLL_H


#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    int key;
    struct node * next;
    struct node * previous;
}NodeT;

typedef struct list_header
{
    NodeT * first;
    NodeT * last;
}List_header;

List_header *L;

void initializeDll();

void addFirst(int givenKey);
void addLast(int givenKey);

void deleteFirst();
void deleteLast();
void removeElement(int givenKey);
void removeAll();

void printDllData(FILE *fptr);
void printFirstValues(int n,FILE *fptr);
void printLastValues(int n, FILE *fptr,NodeT * element);



#endif //ASSIGNMENT_2_1_DLL_H
