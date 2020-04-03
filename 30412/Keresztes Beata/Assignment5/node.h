//
// Created by q on 4/1/2020.
//

#ifndef ASSIGNMENT5_NODE_H
#define ASSIGNMENT5_NODE_H

#include <stdio.h>
#include <stdlib.h>
#define ERR_ALLOC_MEM "Error allocating memory"
#define new_line printf("\n")

typedef struct node {
    int data;
    struct node * next;
}NodeT;

// function to create a new node
NodeT * createNode(int data);
// function to display an error message when memory could not be allocated
void errMessage();

#endif //ASSIGNMENT5_NODE_H
