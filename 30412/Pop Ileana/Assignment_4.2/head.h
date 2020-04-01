//
// Created by ileana on 3/29/2020.
//

#ifndef ASSIGNMENT_4_2_HEAD_H
#define ASSIGNMENT_4_2_HEAD_H


#include<stdio.h>
#include<stdlib.h>
#define COUNT 2

typedef struct node{
    int key;
    int height;
    struct node * left, * right;
}NodeT;

FILE * fin;


NodeT * createNode(int key);
void prettyPrint(NodeT *root, int space);
int getMax(int a, int b);
int height(NodeT * node);
int getBalance(NodeT * node);
NodeT * minValue(NodeT * root);
NodeT * leftRotate(NodeT * node);
NodeT * rightRotate(NodeT * node);


#endif //ASSIGNMENT_4_2_HEAD_H
