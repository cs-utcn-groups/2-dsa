//
// Created by Mihai on 3/23/2020.
//
#include "header.h"


NodeS *buildTree(FILE *file){

    NodeS *root = (NodeS*)malloc(sizeof(NodeS));
    fscanf(file, "%s", root->id);
    getc(file);

    if (!(strlen(root->id) == 1 && isOperator(root->id[0])))  { //check if id is a number
        root->right = NULL;
        root->left = NULL;
    }
    else {
        root->left = buildTree(file);
        root->right = buildTree(file);
    }
    return root;

}

int isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return 1;
    return 0;
}

void preorder(NodeS *currentRoot, int lv){
    if (currentRoot != NULL) {
        for (int i = 0; i < lv; i++) {
            printf(" ");
        }
        printf("%s", currentRoot->id);
        preorder(currentRoot->left, lv + 1);
        preorder(currentRoot->right, lv + 1);
    }
}


