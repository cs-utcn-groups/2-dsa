//
// Created by Irina on 02/03/2020.
//
#include "head.h"
#include <stdio.h>
#include <stdlib.h>

void initializeList(){
    first = NULL;
    last = NULL;
}
void addLast(int number){
    if(first == NULL){
        first = (node*)malloc(sizeof(node));
        first->next = last;
        first->number = number;
        last = first;
    } else {
        node * newNode = (node*)malloc(sizeof(node));
        last->next = newNode;
        newNode->next = NULL;
        newNode->number = number;
        last = newNode;
    }
}
void addFirst(int number){
    if(first == NULL){
        first = (node*)malloc(sizeof(node));
        first->next = last;
        first->number = number;
        last = first;
    } else{
        node * newNode = (node*)malloc(sizeof(node));
        newNode->number = number;
        newNode->next = first;
        first = newNode;
    }
}
void printList(FILE * outputFile){
    if(first == NULL){
        fprintf(outputFile, "List is empty!\n");
    } else{
        node * currentElement = first;
        while(currentElement != NULL)
        {
            fprintf(outputFile, "%d ", currentElement->number);
            currentElement = currentElement->next;
        }
        fprintf(outputFile, "\n");
    }
}
void deleteFirst(){
    if(first != NULL){
        node * firstNode = first;
        first = first->next;
        free(firstNode);
    }
}
void deleteLast(){
    if(first != NULL){
        node * currentNode = last;
        node * previousNode = first;
        while (previousNode->next != last){
            previousNode = previousNode->next;
        }
        last = previousNode;
        previousNode->next = NULL;
        free(currentNode);
    }
}
void deleteElement(int data){
    node * currentNode = first;
    node * previousNode= first;
    while(currentNode != NULL){
        if(currentNode->number == data){
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
void deleteAll(){
    node * currentElement = first;
    while(currentElement != NULL){
        first = first->next;
        free(currentElement);
        currentElement = first;
    }
}

void printFirst(int number, FILE * outputFile){
    if(first == NULL){
        fprintf(outputFile, "List is empty!\n");
    } else {
        int k = 0;
        node *currentNode = first;
        while (k < number) {
            fprintf(outputFile, "%d ", currentNode->number);
            currentNode = currentNode->next;
            k++;
        }
        fprintf(outputFile, "\n");
    }
}
void printLast(int number, FILE * outputFile){
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
                fprintf(outputFile, "%d ", currentNode->number);
            }
            k++;
        }
        fprintf(outputFile, "\n");
    }
}