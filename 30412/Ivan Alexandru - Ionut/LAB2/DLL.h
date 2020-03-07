//
// Created by Ivan on 3/5/2020.
//

#ifndef UNTITLED_DLL_H
#define UNTITLED_DLL_H

#include <stdlib.h>
#include <stdio.h>
#define MAX_LEN 20

typedef struct node
{
    int data;
    struct node* next;
    struct node* prev;
}Node;

typedef struct list
{
    int numberOfElements;
    Node* first;
    Node* last;
}listPtr;

listPtr* createEmptyList();
void addFirst(int key);
void addLast(int key);
void deleteFirst();
void deleteLast();
void printAll();
void deleteElement(int key);
void deleteAll();
void printFirst(int x);
void printLast(int x);

FILE* f, *g;
listPtr* LIST;

#endif //UNTITLED_DLL_H
