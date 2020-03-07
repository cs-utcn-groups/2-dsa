//
// Created by Dominic on 3/4/2020.
//

#include "instructions.h"

void initializeSLL() {
    first = NULL;
    last = NULL;
}

void AF(int x) {
    NodeT *newNode = (NodeT *) malloc(sizeof(NodeT));
    newNode->data = x;
    if (first == NULL) { //list empty
        first = newNode;
        last = first;
        newNode->next = NULL;
    } else {
        newNode->next = first;
        first = newNode;
    }
}

void AL(int x) {
    NodeT *newNode = (NodeT *) malloc(sizeof(NodeT));
    newNode->data = x;
    newNode->next = NULL;
    if (last == NULL) {
        last = newNode;
        newNode->next = NULL;
    } else {
        last->next = newNode;
        last = newNode;
    }
}

void DL() {
    if (first != NULL) {
        if (first == last) {
            free(first);
            initializeSLL();
        } else {
            NodeT *t = first;
            while (t->next != last) {
                t = t->next;
            }
            t->next = NULL;
            free(last);
            last = t;
        }
    }
}

void DF() {
    if (first != NULL) {
        NodeT *t = first;
        first = t->next;
        if (first == NULL) {
            last = first;
        }
        free(t);
    }
}

void doomSLL() {
    NodeT *t = first;
    while (t != NULL) {
        first = first->next;
        free(t);
        t = first;
    }
    last = NULL;
}

void delete(int x) {
    NodeT *currNode = first;
    NodeT *prevNode = first;

    while (currNode != NULL) {
        if (currNode->data == x) {
            if (currNode == first) {
                DF();
                currNode = first;
            } else {
                if (currNode == last) {
                    DL();
                    currNode = last;
                } else {
                    prevNode->next = currNode->next;
                    free(currNode);
                    currNode = prevNode->next;
                }
            }
        } else {
            prevNode = currNode;
            currNode = currNode->next;
        }
    }
}
void printAll (FILE *f){
    NodeT *temp=first;
    if (first==NULL){
        fprintf(f,"List is empty.\n");
        return;
    }
    while (temp!=NULL){
        fprintf(f,"%d",temp->data);
        temp=temp->next;
    }
    fprintf(f,"\n");
}
void printFirstX(FILE *f, int x){
    NodeT *temp= first;
    if (first==NULL){
        fprintf(f,"List is empty.\n");
        return;
    }
    while(temp !=NULL && x){
        fprintf(f,"%d",temp->data);
        x--;
        temp=temp->next;
    }
    fprintf(f,"\n");
}
void printLastX(FILE *f, int x){
    NodeT *temp=first;
    if (first==NULL){
        fprintf(f,"List is empty.\n");
        return;
    }
    int nrNodes=0;
    while (temp!=NULL){
        nrNodes++;
        temp=temp->next;
    }
    temp=first;
    while(temp!=NULL && nrNodes>x){
        temp=temp->next;
        nrNodes--;
    }
    while (temp!=NULL && nrNodes){
        fprintf(f,"%d",temp->data);
        temp=temp->next;
        nrNodes--;
    }
    fprintf(f,"\n");
}