//
// Created by Tudor Tise on 10/03/2020.
//

#ifndef ASSIGNMEN_2___SECOND_LISTS_H
#define ASSIGNMEN_2___SECOND_LISTS_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NAME_SIZE 50

void setUpFile();
void initializeList();
void appendToListSeconds(int);
void printAllSeconds();
void appendToListCustomer(char[NAME_SIZE], int, int);
void printAllCustomers();


typedef struct nodeT {
    int data;
    struct nodeT * next;
} NodeTime;

typedef struct nodeC {
    int rubles;
    int seconds;
    char name[NAME_SIZE];
    struct nodeC * next;
} NodeCustomer;

NodeTime * firstT, * lastT;
NodeCustomer *firstC, *lastC;


FILE *g;



#endif //ASSIGNMEN_2___SECOND_LISTS_H
