#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ID 50

typedef struct node_tree{
    char *id;
    struct node_tree *left, *right;
}NodeT;

int isOperator(char *str);
NodeT *createBinTree();
void prettyPrint(NodeT *root, int space);

int main() {
    NodeT *root = createBinTree();
    prettyPrint(root, 0);

    return 0;
}

NodeT *createBinTree() {
    NodeT *p = (NodeT *)malloc(sizeof(NodeT));
    p->id = (char *)malloc(sizeof(char) * MAX_ID);
    char *str = (char *)malloc(sizeof(char) * MAX_ID);
    scanf("%s", str);
    getchar();

    strcpy(p->id, str);

    if(!isOperator(str)){
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
void prettyPrint(NodeT *root, int space) {
    if (root == NULL)
        return;
    space += 5;

    // Process right child first
    prettyPrint(root->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%s\n", root->id);

    // Process left child
    prettyPrint(root->left, space);
}
int isOperator(char *str) {
    return strcmp(str,"-") == 0 || strcmp(str,"+") == 0 || strcmp(str,"*") == 0 || strcmp(str,"/") == 0;
}
