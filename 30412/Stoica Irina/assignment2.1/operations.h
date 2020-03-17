//
// Created by Irina on 08/03/2020.
//

#ifndef ASSIGNMENT2_OPERATIONS_H
#define ASSIGNMENT2_OPERATIONS_H

#include "head.h"

void addFirst(int number, node * sentinel);

void addLast(int number);

void deleteFirst(node *sentinel);

void deleteLast();

void deleteElement(int number);

void printAll(FILE * output);

void printFirstNumbers(int number, FILE * output);

void printLastNumbers(int number, FILE * output);

void deleteAll();

void initialiseList();

node * getNewNode(int number);

node * getSentinel();

#endif //ASSIGNMENT2_OPERATIONS_H
