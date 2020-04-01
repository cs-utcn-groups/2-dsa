//
// Created by csatl on 3/21/2020.
//

#ifndef A3_BINARY_TREE_H
#define A3_BINARY_TREE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _tree{
    char id;
    struct _tree *left,*right;
}tree;

typedef struct _dll_tree{
    char id;
    struct _dll_tree *n_left, *n_right, *p_left, *p_right;
    struct _dll_tree *previous;
}dll_tree;

tree *CreateBinaryTree();
dll_tree *GetListFromTree(tree * root, dll_tree * ant);

void PrettyPrint(tree *currentRoot, int level);
void PrettyPrintDLL(dll_tree *currentRoot, int level);
/*
 A
 B
 D
 *
 G
 *
 *
 *
 C
 E
 *
 *
 F
 *
 H
 *
 *
 */
#endif //A3_BINARY_TREE_H
