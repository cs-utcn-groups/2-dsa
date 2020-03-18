//
// Created by q on 3/16/2020.
//

#include "tree.h"

NodeT * createTree(NodeT * sentinel) {
    /*
     * function that creates the operation tree, from the queue;
     * every node added to the tree, will be deleted from the queue;
     *  --returns : pointer to the root
     */
    NodeT * first = sentinel->right;
    if(first!= sentinel) {
        if (strcmp(first->data,"#") == 0) {
            // the previously added node was a leaf
            return NULL;
        }
        NodeT * node = createNode(first->data);
        deleteFirst(sentinel);
        node->left = createTree(sentinel);
        deleteFirst(sentinel);
        node->right = createTree(sentinel);
        return node;
    }
}

void printTree(NodeT * root, int depth) {
    /*
     * function that prints the operation tree;
     * -- static variable "currLevel" indicates the current level of the nodes displayed;
     * -- parameter "depth" indicates the depth of the tree ( longest distance from root);
     */
    int static currLevel = 0;
    if(root) {
        if(currLevel == 0) {
            for (int i = 0; i <= depth; i++)
                printf(" ");
            printf("%s\n", root->data);
        }
        printChildren(root,depth);
        currLevel++;
        printTree(root->left,depth-1);
        printTree(root->right,depth+1);
    }
}
void printChildren(NodeT * root,int depth) {
    /*
     * every operator has exactly 2 operands;
     */
    for(int i=0;i<depth;i++)
        printf(" ");
    if(root->right && root->left) {
        printf("/ \\\n");
        for(int i=0;i<depth-1;i++)
            printf(" ");
        printf("%s %s\n",root->left->data,root->right->data);
    }
}

void freeTree(NodeT ** root) {
    /*
     * recursive function that frees the memory allocated to the tree;
     */
    if(*root) {
        freeTree(&(*root)->right);
        freeTree(&(*root)->left);
        free((*root)->data);
        free(*root);
        *root = NULL;
    }
}
