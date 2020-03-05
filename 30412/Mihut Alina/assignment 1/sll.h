//
// Created by Alina Mihut on 3/1/20.
//
#include <stdio.h>
#include <stdlib.h>
#ifndef ASSIGNMENT_1_SLL_H
#define ASSIGNMENT_1_SLL_H
typedef struct node {
    int data;
    struct node * next;
} NodeT;

NodeT * first, * last;
void initializeList();
void addFirst(int data);
void addLast (int data);
void deleteFirst();
void deleteLast();
void deleteElement (int data);
void doomTheList ();
void printAllElements (FILE *fout);
void printFirst (int x, FILE *fout);
void printLast (int x, FILE *fout);


#endif //ASSIGNMENT_1_SLL_H
