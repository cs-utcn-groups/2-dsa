//
// Created by ileana on 3/21/2020.
//

#ifndef ASSIGNMENT_3_1_LIST_H
#define ASSIGNMENT_3_1_LIST_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct node1{
    char key;
    struct node1 * previous, * next;
}NodeL;


void addElement(NodeL ** first, char givenKey);
void traverseList(NodeL * first);

#endif //ASSIGNMENT_3_1_LIST_H
