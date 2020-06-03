#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "tree.h"

#define PATH "../in.txt"

int main() {
    FILE *inputFile = fopen(PATH, "r");
    Queue *mathQueue = initializeQueue();
    readQueue(inputFile, mathQueue);
    Tree expressionTree = initializeTree();
    expressionTree.root = buildTreeFromQueue(expressionTree.root, mathQueue);
    printTree(expressionTree.root, 0);
    return 0;
}