#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#ifndef BST_2_HEAD_H
#define BST_2_HEAD_H

#define COUNT 2

#endif // BST_2_HEAD_H

typedef struct node
{
    int key;
    int height;
    struct node *left,*right;
}NodeT;

void PrettyPrint(NodeT *root,int space);
