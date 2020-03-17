//
// Created by Diana on 3/9/2020.
//

#ifndef ASSIGNMENT_2_DLL_H
#define ASSIGNMENT_2_DLL_H
typedef struct _node {
    struct _node * next;
    struct _node * prev;
    int data;
} dll_node;
dll_node * sentinel, * current;
void initializeDll();
void addFirst(int data);
void printAll(FILE * output);
void addLast(int data);
void deleteFirst();
void deleteLast();
void doomTheList();
void deleteElement(int data);
void printFirstElements(FILE * output,int tillValue);
void printLastElements(FILE * output,int tillValue);
void reverse(int nr,int tillValue,FILE * output);
#endif //ASSIGNMENT_2_DLL_H
