//
// Created by Alina Mihut on 3/22/20.
//

#ifndef ASSIGNMENT_3_DLL_H
#define ASSIGNMENT_3_DLL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    char data;
    struct node *next;
    struct node *prev;
}NodeL;

NodeL *first, *last;
void initializeDLL();
void addNode (char data);
void transverseList(NodeL *f);

#endif //ASSIGNMENT_3_DLL_H