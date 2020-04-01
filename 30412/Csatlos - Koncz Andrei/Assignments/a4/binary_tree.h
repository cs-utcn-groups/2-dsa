//
// Created by csatl on 3/30/2020.
//

#ifndef A4_BINARY_TREE_H
#define A4_BINARY_TREE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _tree{
    int id;
    int height;
    struct _tree *left,*right;
}tree;

tree *Insert(tree * root, int key);
int Height(tree *root);
int Max(int a, int b);
tree *LeftRotate(tree *root);
tree *RightRotate(tree *root);;
int GetBalance(tree *N);
tree *CreateNode(int key);
void PrettyPrint(tree *currentRoot, int level);

#endif //A4_BINARY_TREE_H
