#include <stdio.h>
#include <stdlib.h>

#ifndef ASSIGNMENT4_HEAD_H
#define ASSIGNMENT4_HEAD_H

typedef struct node{
    int key;
    struct node *left, *right;
    int height;
}NodeT;



#endif