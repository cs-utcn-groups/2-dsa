#include "queue.h"
#include "tree.h"
#define DATA_PATH "../input.dat"

int main() {

    fin=fopen(DATA_PATH,"r");
    if(fin == NULL) {
        printf("File could not be opened");
        exit(EXIT_FAILURE);
    }
    createQueue();
    NodeT * root = createExpressionTree();
    printf("The tree for the expression is:\n");
    preOrder(root,0);
    printf("\n");
    printTree(root,0);
    return 0;
}