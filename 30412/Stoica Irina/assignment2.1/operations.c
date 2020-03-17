//
// Created by Irina on 08/03/2020.
//
#include <stdlib.h>
#include <stdio.h>
#include "head.h"

void initialiseList(){
    first = NULL;
    last = NULL;
}
node * getNewNode(int number){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->value = number;
    newNode->next = NULL;
    newNode->previous = NULL;
    return newNode;
}
node * getSentinel(){
    node * sentinel = getNewNode(0);
    sentinel->previous = NULL;
    sentinel->next = first = last;
    return sentinel;
}
void addFirst(int number, node * sentinel){
    node * newNode = getNewNode(number);
    if(first == NULL){
        last = newNode;
    }
    newNode->next = first;
    newNode->previous = sentinel;
    first = newNode;
}
void addLast(int number) {
    node *newNode = getNewNode(number);
    newNode->previous = last;
    newNode->next = NULL;
    last->next = newNode;
    last = newNode;
}
void deleteFirst(node * sentinel){
    if(first != NULL) {
        node *toDelete = first;
        first = first->next;
        first->previous = sentinel;
        free(toDelete);
    }
}
void deleteLast() {
    if (first != NULL) {
        node *toDelete = last;
        last = last->previous;
        last->next = NULL;
        free(toDelete);
    }
}
void deleteElement(int number){
    node * currentNode = first;
    node * previousNode= first;
    while(currentNode != NULL){
        if(currentNode->value == number){
            if(currentNode == first){
                first = first->next;
            }
            else if(currentNode == last){
                last = previousNode;
                last->next = NULL;
            } else {
                previousNode->next = currentNode->next;
            }
            previousNode = currentNode;
            currentNode = currentNode->next;
            free(previousNode);
            previousNode = currentNode;
        }
        else{
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
    }
}
void printAll(FILE * output){
    node * currentNode = first;
    while(currentNode!=NULL){
        fprintf(output, "%d ", currentNode->value);
        currentNode = currentNode->next;
    }
    fprintf(output, "\n");
}
void printFirstNumbers(int number, FILE * output){
    node * currentNode = first;
    int k=0;
    while(currentNode !=NULL && k<number){
        fprintf(output, "%d ", currentNode->value);
        currentNode = currentNode->next;
        k++;
    }
    fprintf(output, "\n");
}
void printLastNumbers(int number, FILE * outputFile){
    if(first == NULL){
        fprintf(outputFile, "List is empty!\n");
    } else {
        int noOfNodes = 0;
        node *newNode = first;
        while (newNode != NULL) {
            newNode = newNode->next;
            noOfNodes++;
        }
        int k = noOfNodes - number;
        node *currentNode = first;
        while (k < noOfNodes) {
            currentNode = currentNode->next;
            if (k < noOfNodes && k > (noOfNodes - number - 1)) {
                fprintf(outputFile, "%d ", currentNode->value);
            }
            k++;
        }
        fprintf(outputFile, "\n");
    }
}
void deleteAll(){
    node * currentNode = first;
    while(currentNode !=NULL){
        first = first->next;
        free(currentNode);
        currentNode = first;
    }
}