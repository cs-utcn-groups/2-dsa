//
// Created by ileana on 3/28/2020.
//

#ifndef ASSIGNMENT_4_1_HEAD_H
#define ASSIGNMENT_4_1_HEAD_H

#include<stdio.h>
#include<stdlib.h>
#define COUNT 2

typedef struct node{
    int key;
    int height;
    struct node * left, * right;
}NodeT;

FILE * fin;



NodeT * insert(NodeT * root, int key);

NodeT * createNode(int key);

void prettyPrint(NodeT *root, int space);

#endif //ASSIGNMENT_4_1_HEAD_H
