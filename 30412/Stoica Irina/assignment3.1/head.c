//
// Created by Irina on 23/03/2020.
//

#include "head.h"

NodeT *createBinaryTree(){
    char *c = (char*)malloc(sizeof(char));
    scanf("%s", c);
    if (strcmp(c, "*") == 0) {
        return NULL;
    }
    NodeT *newNode = (NodeT*) malloc(sizeof(NodeT));
    newNode->id = c[0];
    newNode->left = createBinaryTree();
    newNode->right = createBinaryTree();
    return newNode;
}
void initializeList(){
    first = NULL;
    last = NULL;
}
void addNode(char id){
    NodeL * currentNode = (NodeL*)malloc(sizeof(NodeL));
    currentNode->previous = currentNode->next = NULL;
    currentNode->id = id;
    if(first == NULL){
        first = currentNode;
        last = first;
    } else {
        currentNode->previous = last;
        last->next = currentNode;
        last = currentNode;
    }
}
NodeL *getListFromTree(NodeT *root){
    if(root != NULL){
        addNode(root->id);
        getListFromTree(root->left);
        getListFromTree(root->right);
    } else {
        addNode('*');
    }
    return first;
}
void traverseList(){
    NodeL * currentNode = first;
    while(currentNode!=NULL){
        printf("%c ", currentNode->id);
        currentNode = currentNode->next;
    }
    printf("\n");
}
NodeT *getTreeFromList(){
    char *c = (char*)malloc(sizeof(char));
    c[0] = first->id;
    first = first->next;
    if(strcmp(c, "*")==0) {
        return NULL;
    }
    NodeT *newNode = (NodeT*)malloc(sizeof(NodeT));
    newNode->id = c[0];
    newNode->left = getTreeFromList();
    newNode->right = getTreeFromList();
    return newNode;
}
void prettyPrint(NodeT *currentRoot, int level) {
    if (currentRoot == NULL)
        return;
    level= level+4;
    prettyPrint(currentRoot->right, level);
    printf("\n");
    for (int i = 0; i < level; i++)
        printf(" ");
    printf("%c", currentRoot->id);
    prettyPrint(currentRoot->left, level);
}
