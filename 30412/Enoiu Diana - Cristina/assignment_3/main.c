#include <stdio.h>
#include "stdlib.h"
#include "string.h"
typedef struct nodeTree {
    char id;
    struct nodeTree * left,* right;
}NodeT;
typedef struct nodeList {
    char data;
    struct nodeList * next,* previous;
}NodeL;
NodeT * createBinTree();
NodeL * getListFromTree(NodeT * currentNodeTree);
void traverseList(NodeL * nodeFromList);
NodeT * getTreeFromList (NodeL * nodeFromList);
void prettyPrint (NodeT * nodeFromTree);
int main() {
    NodeT * root = createBinTree();
    NodeL * firstFromList = getListFromTree(root);
    printf("The list is: ");
    traverseList(firstFromList);
    printf("\n");
    root = getTreeFromList(firstFromList);
    printf("The tree is: ");
    prettyPrint(root);
    return 0;
}
NodeT * createBinTree() {
    char * c = malloc(sizeof(char));
    scanf("%s",c);
    if (strcmp(c,"*") == 0) {
        return NULL;
    }
    NodeT * newNode = (NodeT *) malloc (sizeof(NodeT));
    newNode->id = c[0];
    newNode->left = createBinTree();
    newNode->right = createBinTree();
    return newNode;
}
NodeL * getListFromTree(NodeT * currentNodeTree) {
    if(currentNodeTree == NULL) {
        NodeL * newListNode = (NodeL *) malloc (sizeof(NodeL));
        strcpy(&newListNode->data,"*");
        newListNode->next = NULL;
        newListNode->previous = NULL;
        return newListNode;
    }
    NodeL * newListNode = (NodeL *) malloc (sizeof(NodeL));
    newListNode->data = currentNodeTree->id;
    newListNode->next = getListFromTree(currentNodeTree->left);
    newListNode->previous = getListFromTree(currentNodeTree->right);
    return newListNode;
}
void traverseList(NodeL * nodeFromList) {
    if (nodeFromList == NULL) {
        return;
    }
    printf("%c",nodeFromList->data);
    traverseList(nodeFromList->next);
    traverseList(nodeFromList->previous);
}
NodeT * getTreeFromList (NodeL * nodeFromList) {
    if(nodeFromList->data == '*') return NULL;
    NodeT * newNodeTree = (NodeT *) malloc (sizeof(NodeT));
    newNodeTree->id = nodeFromList->data;
    newNodeTree->left = getTreeFromList(nodeFromList->next);
    newNodeTree->right = getTreeFromList(nodeFromList->previous);
    return newNodeTree;
}
void prettyPrint (NodeT * nodeFromTree) {
    if (nodeFromTree == NULL) {
        printf("*");
        return;
    }
    printf("%c",nodeFromTree->id);
    prettyPrint(nodeFromTree->left);
    prettyPrint(nodeFromTree->right);
}