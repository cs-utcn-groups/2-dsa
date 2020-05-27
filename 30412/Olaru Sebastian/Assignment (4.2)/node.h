#ifndef ASSIGNMENT__4_1__NODE_H
#define ASSIGNMENT__4_1__NODE_H

#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int key;
    struct node *left, *right;
    int height;
} NodeAVL;

NodeAVL *createNode(int key);

#endif //ASSIGNMENT__4_1__NODE_H
