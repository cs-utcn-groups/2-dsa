#include "tree.h"

void prettyPrint(NodeT *root, int padding) {
    if (root != NULL){
        padding += PADDING_STEP;
        prettyPrint(root->right, padding);
        for (int i = PADDING_STEP; i < padding; i++)
            printf(" ");
        printf("%c\n", root->data);
        prettyPrint(root->left, padding);
    }
}

NodeT *getTreeFromList(NodeL **first) {
    if (first) {
        if ((*first)->data == '*'){
            (*first) = (*first)->next;
            return NULL;
        }

        NodeT *newTree = createNewTreeNode((*first)->data);
        (*first) = (*first)->next;
        newTree->left = getTreeFromList(first);
        newTree->right = getTreeFromList(first);

        return newTree;
    }
    else
        return NULL;
}

NodeT *createBinTree() {
    char *c = (char *) malloc(sizeof(char));
    scanf("%s",c);
    if (strcmp(c,"*")==0) return NULL;

    NodeT *newTree = createNewTreeNode(c[0]);
    newTree->left = createBinTree();
    newTree->right = createBinTree();
    return newTree;
}