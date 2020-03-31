//
// Created by Irina on 29/03/2020.
//

#ifndef ASSIGNMENT4_HEAD_H
#define ASSIGNMENT4_HEAD_H

#include <stdio.h>
#include <stdlib.h>
#define COUNT 10

typedef struct node{
    int value;
    int height;
    struct node * left;
    struct node * right;
}NodeT;

NodeT *createNode(int key);

NodeT * insertNode(NodeT * root, int key);

void prettyPrint(NodeT *root, int level);


#endif //ASSIGNMENT4_HEAD_H