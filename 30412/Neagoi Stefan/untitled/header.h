//
// Created by htbc4 on 3/10/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef UNTITLED_HEADER_H
typedef struct _node{
    int rubles;
    int time;
    int data;
    struct _node *prev, *next;
} NodeT;

typedef struct _list{
    NodeT *sentinel;
} doublyLinked;



doublyLinked getTime(FILE *file);
void initialiseList(doublyLinked *list);
void addFirst(int data,doublyLinked *list);
void addLast(int data,doublyLinked *list);
void deleteFirst(doublyLinked *list);
void deleteLast(doublyLinked *list);
void doomList(doublyLinked *list);
void deleteElement(int data,doublyLinked *list);
void printAll(doublyLinked *list,FILE *FILE);
void printFirst(int a,doublyLinked *list, FILE *file);
void printLast(int a, doublyLinked *list, FILE *file);
int getListLength(doublyLinked *list);
doublyLinked getCustomerData(FILE *file);
void printCustomerData(doublyLinked *list, FILE *file);
#define UNTITLED_HEADER_H
#endif //UNTITLED_HEADER_H
