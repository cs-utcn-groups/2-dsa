#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "binTree.h"

#define FILE_ERR_CODE 1
#define FILE_ERR_MESS "error opening file"
#define MAX_LINE_LENGTH 1000

FILE *openFile(char *name, char *mode);

Queue getExpressionQueue(char* expression);

int main() {
    FILE* inFile = openFile("../data.in", "r");
    char* expression = (char*) malloc(sizeof(char)*MAX_LINE_LENGTH);
    fgets(expression, MAX_LINE_LENGTH, inFile);
    Queue expQueue = getExpressionQueue(expression);
    printf("original expression is:");
    printAllQueue(&expQueue, stdout);
    binTree* expTree = createBinTree(&expQueue);
    printf("the tree constructed from this expression is:\n");
    inOrder(expTree, 0,  stdout);

    return 0;
}

FILE *openFile(char *name, char *mode) {
    FILE *newFile = fopen(name, mode);
    if (newFile == NULL) {
        perror(FILE_ERR_MESS);
        exit(FILE_ERR_CODE);
    }
    return newFile;
}

Queue getExpressionQueue(char* expression)
{
    Queue expQueue = createQueue();
    char separator[] = " ";
    char* exp = strtok(expression, separator);
    while(exp!=NULL)
    {
        push(&expQueue, exp);
        exp = strtok(NULL, separator);
    }
    return expQueue;
}