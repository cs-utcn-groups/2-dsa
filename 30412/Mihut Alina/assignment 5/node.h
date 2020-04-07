//
// Created by Alina Mihut on 4/5/20.
//

#ifndef ASSIGNMENT_5_NODE_H
#define ASSIGNMENT_5_NODE_H

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int vertex;
    struct node* next;
}NodeT;

NodeT *createNode(int v);
#endif //ASSIGNMENT_5_NODE_H
