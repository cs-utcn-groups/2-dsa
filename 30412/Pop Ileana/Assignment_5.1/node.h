//
// Created by ileana on 4/5/2020.
//

#ifndef ASSIGNMENT_5_1_NODE_H

#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    int label;
    int content;
    struct node * next;

}NodeT;


NodeT * createListNode(int label, int content);
NodeT *createNode(int label);

#define ASSIGNMENT_5_1_NODE_H

#endif //ASSIGNMENT_5_1_NODE_H
