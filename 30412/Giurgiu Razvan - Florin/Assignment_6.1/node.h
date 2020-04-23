//
// Created by TheRa on 3/31/2020.
//

#ifndef ASSIGNMENT_5_1_NODE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int content;
    struct node *next;
}NodeT;

NodeT *createNode( int content );
#define ASSIGNMENT_5_1_NODE_H

#endif //ASSIGNMENT_5_1_NODE_H
