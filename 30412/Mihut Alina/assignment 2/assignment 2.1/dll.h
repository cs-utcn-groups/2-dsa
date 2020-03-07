//
// Created by Alina Mihut on 3/7/20.
//

#ifndef ASSIGNMENT_2_1_DLL_H
#define ASSIGNMENT_2_1_DLL_H
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
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
#endif //ASSIGNMENT_2_1_DLL_H
