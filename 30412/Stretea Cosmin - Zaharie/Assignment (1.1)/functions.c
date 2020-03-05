//
// Created by Cosmin on 26-Feb-20.
//
#include "head.h"


Node *first, *last;

void init(){
    first = NULL;
    last = NULL;
}
void AF(int x){
    if(first == NULL){
        first = (Node *)malloc(sizeof(Node));
        first->data = x;
        first->next = NULL;
        last = first;
    }
    else{
        Node * newNode = (Node *)malloc(sizeof(Node));
        newNode->data = x;
        newNode->next = first;
        first = newNode;
    }

}
void AL(int x){
    if(last == NULL){
        last = (Node *)malloc(sizeof(Node));
        last->data = x;
        last->next = NULL;
        first = last;
    }
    else{
        Node * newNode = (Node *)malloc(sizeof(Node));
        newNode->data = x;
        newNode->next = NULL;
        last->next = newNode;
        last = newNode;
    }

}
void DF(){
    Node * currentNode = first;
    first = first->next;
    free(currentNode);
}
void DL() {
    if (first) {
        Node *currentNode = first;
        while (currentNode->next != NULL) {
            last = currentNode;
            currentNode = currentNode->next;
        }
        free(last->next);
        last->next = NULL;
    }
}
void DOOM_THE_LIST(){
    Node * currentNode;
    while(first != NULL){
        currentNode = first;
        first = first->next;
        free(currentNode);
    }
    last = NULL;
}
void DE(int x){
    Node * currentNode = first;
    Node * previousNode = first;
    while(currentNode != NULL){
        if(currentNode->data == x){
            if(currentNode == first){
                first = first->next;
            }
            else if(currentNode == last){
                last = previousNode;
                last->next = NULL;
            }
            else{
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
void PRINT_ALL(){
    Node * currentNode = first;
    while(currentNode){
        fprintf(output,"%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    fprintf(output,"\n");
}
void PRINT_F(int x){
    Node * currentNode = first;
    while(currentNode && x){
        fprintf(output,"%d ", currentNode->data);
        currentNode = currentNode->next;
        x--;
    }
    fprintf(output,"\n");
}
void PRINT_L(int x){
    int noOfNodes = 0;
    Node * currentNode = first;
    while(currentNode){
        noOfNodes++;
        currentNode = currentNode->next;
    }
    if(x >= noOfNodes){
        PRINT_ALL();
    }
    else{
        int noOfDiscardedNodes = noOfNodes - x;
        currentNode = first;
        while(noOfDiscardedNodes){
            currentNode = currentNode->next;
            noOfDiscardedNodes--;
        }
        while(currentNode){
            fprintf(output,"%d ",currentNode->data);
            currentNode = currentNode->next;
        }
        fprintf(output,"\n");
    }
}