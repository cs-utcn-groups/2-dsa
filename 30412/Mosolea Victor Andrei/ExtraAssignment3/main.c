#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STRING_LENGTH 20
typedef struct node {
    char id[MAX_STRING_LENGTH];
    bool number;
    struct node *left, *right;
} NodeT;

void prettyPrint(NodeT *root, int level) {
    if (root->right != NULL)
        prettyPrint(root->right, level + 1);
    for (int i = 0; i < level; i++)
        printf("    ");
    printf("%s\n", root->id);
    if (root->left != NULL)
        prettyPrint(root->left, level + 1);
}

NodeT *createOperationTree(FILE *f) {
    NodeT *newNode = (NodeT *) malloc(sizeof(NodeT));
    fscanf(f, "%s", newNode->id);
    getc(f);
    newNode->number = false;
    for (int i = 0; i < strlen(newNode->id); i++)
        if (newNode->id[i] >= '0' && newNode->id[i] <= '9')
            newNode->number = true;
    if (newNode->number == true) {
        newNode->right = NULL;
        newNode->left = NULL;
    } else {
        newNode->left = createOperationTree(f);
        newNode->right = createOperationTree(f);
    }
    return newNode;
}

int main() {
    FILE *f = fopen("../input.dat", "r");
    NodeT *root = createOperationTree(f);
    prettyPrint(root, 0);
    return 0;
}
