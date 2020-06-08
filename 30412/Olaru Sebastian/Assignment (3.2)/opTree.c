//
// Created by acer on 5/27/2020.
//

#include "opTree.h"

NodeOT *createBinTree() {
    NodeOT *p = (NodeOT *)malloc(sizeof(NodeOT));
    p->data = (char *)malloc(sizeof(char) * MAX_KEY_LENGTH);
    char *key = (char *)malloc(sizeof(char) * MAX_KEY_LENGTH);
    scanf("%s", key);
    getchar();
    strcpy(p->data, key);
    if(!isOperator(key)){
        p->right = NULL;
        p->left = NULL;
        return p;
    }
    else{
        p->left = createBinTree();
        p->right = createBinTree();
        return p;
    }
}
void prettyPrint(NodeOT *root, int padding) {
    if (root != NULL){
        padding += PADDING_STEP;
        prettyPrint(root->right, padding);
        for (int i = PADDING_STEP; i < padding; i++)
            printf(" ");
        printf("%s\n", root->data);
        prettyPrint(root->left, padding);
    }
}
int isOperator(char *key) {
    return strcmp(key, "+") == 0 || strcmp(key, "*") == 0 || strcmp(key, "-") == 0 || strcmp(key, "/") == 0;
}