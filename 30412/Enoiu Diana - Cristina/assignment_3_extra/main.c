#include <stdio.h>
#include "string.h"
#include "stdlib.h"
#include "ctype.h"
#define MAX_STRING 5
FILE * in;
typedef struct nodeTree {
    char * dataT;
    struct nodeTree * left;
    struct nodeTree * right;
}NodeT;
typedef struct queue {
    char * dataQ;
    struct queue * next;
}Queue;
NodeT * createBinaryTree ();
int isLeaf (const char * string);
void print(NodeT * nodeTre);
int main() {
    in = fopen("../input.txt","r");
    NodeT * root = createBinaryTree();
    print(root);
    return 0;
}
NodeT * createBinaryTree () {
    char * string = (char *) malloc (MAX_STRING * sizeof(char));
    if(fscanf(in,"%s",string)) {
        printf("%s ",string);
        NodeT * newNode = malloc(sizeof(NodeT));
        strcpy(newNode->dataT, string);
        if (isLeaf(string)) {
            newNode->left = NULL;
            newNode->right = NULL;
        }
        else {
            newNode->left = createBinaryTree();
            newNode->right = createBinaryTree();
        }
        return newNode;
    }
    return NULL;
}
int isLeaf (const char * string) {
    if (isdigit(*string)) return 1;
    else if (strcmp(string,"-") == 0) isLeaf(string+1);
    else if (strcmp(string,"+") == 0) isLeaf(string+1);
    else if(strcmp(string,".") == 0) isLeaf(string+1);
    else return 0;
}
void print(NodeT * nodeTre) {
    if (nodeTre == NULL) return;
    printf("%s ",nodeTre->dataT);
    print(nodeTre->left);
    print(nodeTre->right);
}