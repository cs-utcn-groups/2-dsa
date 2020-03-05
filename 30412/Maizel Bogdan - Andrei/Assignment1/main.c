#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CMD_LEN 15
typedef struct nodetype {
    int value;
    struct nodetype *next;
} nodeT;
nodeT *first, *last;
void initList();
void addFirst(int x);
void addLast(int x);
void deleteFirst();
void deleteLast();
void deleteElement(int x);
void deleteAll();
void printAll();
void printFirst(int x);
void printLast(int x);
// AF AL DF DL DOOM_THE_LIST DE PRINT_ALL PRINT_F PRINT_L
int main() {
    FILE *inputFile = fopen("..\\input.dat", "r");
    if (inputFile== NULL) {
        perror("Error: no file found!\n");
        exit(1);
    }
    char *instruction = (char*)malloc(MAX_CMD_LEN* sizeof(char));
    initList();
    fscanf(inputFile, "%s", instruction);
    while (!feof(inputFile)) {
        if (strcmp(instruction, "AF") == 0) {
            int x;
            fscanf(inputFile, "%d", &x);
            addFirst(x);
        }
        else if (strcmp(instruction, "AL") == 0) {
            int x;
            fscanf(inputFile, "%d", &x);
            addLast(x);
        }
        else if (strcmp(instruction, "DF") == 0) {
            deleteFirst();
        }
        else if (strcmp(instruction, "DL") == 0) {
            deleteLast();
        }
        else if (strcmp(instruction, "DOOM_THE_LIST") == 0) {
            deleteAll();
        }
        else if (strcmp(instruction, "DE") == 0) {
            int x;
            fscanf(inputFile, "%d", &x);
            deleteElement(x);
        }
        else if (strcmp(instruction, "PRINT_ALL") == 0) {
            printAll();
        }
        else if (strcmp(instruction, "PRINT_F") == 0) {
            int x;
            fscanf(inputFile, "%d", &x);
            printFirst(x);
        }
        else if (strcmp(instruction, "PRINT_L") == 0) {
            int x;
            fscanf(inputFile, "%d", &x);
            printLast(x);
        }
        fscanf(inputFile, "%s", instruction);
    }
    return 0;
}

void initList() {
    first=NULL;
    last=NULL;
}

void addFirst(int x) {
    if((first)==NULL) {
        first = (nodeT*)malloc(sizeof(nodeT));
        first->next = last;
        first->value = x;
        last = first;
    }
    else {
        nodeT *newFirst = (nodeT*)malloc(sizeof(nodeT));
        newFirst->value=x;
        nodeT *copyFirst=first;
        newFirst->next=copyFirst;
        first=newFirst;
    }
}

void addLast(int x) {
    if(first == NULL) {
        first = (nodeT*)malloc(sizeof(nodeT));
        first->next = last;
        first->value = x;
        last = first;
    }
    else {
        nodeT *newLast = (nodeT*)malloc(sizeof(nodeT));
        newLast->value=x;
        newLast->next=NULL;
        last->next=newLast;
        last=newLast;
    }
}

void deleteFirst() {
    nodeT *newFirst = first->next;
    free(first);
    first=newFirst;
}

void deleteLast() {
    if (first!=NULL) {
        nodeT *newLast = first;
        while (newLast->next != last) {
            newLast = newLast->next;
        }
        newLast->next = NULL;
        free(last);
        last=newLast;
    }
}

void deleteElement(int x) {
    nodeT * currentElement = first;
    nodeT * previousElement= first;
    int foundElement=0;
    while(currentElement != NULL && foundElement==0) {
        if(currentElement->value == x) {
            foundElement=1;
            if(currentElement == first) {
                first = first->next;
            }
            else if(currentElement == last) {
                last = previousElement;
                last->next = NULL;
            }
            else {
                previousElement->next = currentElement->next;
            }
            previousElement = currentElement;
            currentElement = currentElement->next;
            free(previousElement);
            previousElement = currentElement;
        }
        else {
            previousElement = currentElement;
            currentElement = currentElement->next;
        }

    }
}

void deleteAll() {
    nodeT * currentElement = first;
    while(currentElement != NULL) {
        first = first->next;
        free(currentElement);
        currentElement = first;
    }
}

void printAll() {
    FILE *outputFile = fopen("..\\output.dat", "a");
    if(first == NULL) {
        printf("List is empty!\n");
    }
    else {
        nodeT * currentElement = first;
        while(currentElement != NULL) {
            fprintf(outputFile, "%d ", currentElement->value);
            currentElement = currentElement->next;
        }
        fprintf(outputFile, "\n");
    }
    fclose(outputFile);
}

void printFirst(int x) {
    FILE *outputFile = fopen("..\\output.dat", "a");
    nodeT *currentNode = first;
    while (x>0 || currentNode == NULL) {
        fprintf(outputFile, "%d ", currentNode->value);
        --x;
    }
    fprintf(outputFile, "\n");
    fclose(outputFile);
}

int countNodesInList() {
    nodeT *currentNode = first;
    int numberOfNodes=0;
    while (currentNode != NULL) {
        numberOfNodes++;
        currentNode=currentNode->next;
    }
    return numberOfNodes;
}

void printLast(int x) {
    FILE *outputFile = fopen("..\\output.dat", "a");
    nodeT *currentNode = first;
    int currentIndex=1, lastIndex=countNodesInList();
    if (lastIndex<x) {
        printAll();
    }
    else {
        while (currentIndex < lastIndex - x + 1) {
            currentNode = currentNode->next;
            currentIndex++;
        }
        while (currentNode != NULL) {
            fprintf(outputFile, "%d", currentNode->value);
            currentNode=currentNode->next;
        }
    }
    fclose(outputFile);
}
