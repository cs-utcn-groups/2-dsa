//
// Created by User on 06.04.2020.
//

#ifndef ASSIGNMENT5_EXTRA_NODE_H
#include<stdlib.h>
#include <stdio.h>
typedef struct node{
    int key;
    struct node *next;
}NodeT;
NodeT *createNode(int key);
#define ASSIGNMENT5_EXTRA_NODE_H

#endif //ASSIGNMENT5_EXTRA_NODE_H
