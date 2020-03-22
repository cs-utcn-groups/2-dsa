//
// Created by q on 3/17/2020.
//

#ifndef ASS3_EXTRA_QUEUE_H
#define ASS3_EXTRA_QUEUE_H

#endif //ASS3_EXTRA_QUEUE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_SIZE_DATA 10
#define ERR_ALLOC_MEM "Error allocating memory"
#define newLine printf("\n")

typedef struct node {
    char * data;
    struct node * left, * right;
}NodeT;

//functions that creates a new node
NodeT * createSentinel();
//function that creates the sentinel
NodeT * createNode(char * data);
//function that displays an error message, and exits program when memory could not be allocated
void errorMessage();
/*
 * function that creates a queue with the elements read from the input file
 * -- returns: depth of the tree ( to be created)
 */
int enQueue(FILE * fp, NodeT * s);
// auxiliary function, which determines if the respective string is a number
int CheckIfNumber(char * string);
// functions for working with queue
void deleteFirst(NodeT * s);
//function that appends a new node to the queue
void append(NodeT * s, char * data);
