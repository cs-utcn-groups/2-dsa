//
// Created by Dominic on 3/10/2020.
//

#include "instructions.h"

SentinelT *Sentinel;

void initializeSentinel() {
    Sentinel = (SentinelT *) malloc(sizeof(SentinelT));
    Sentinel->first = NULL;
    Sentinel->last = NULL;
}

void addFirst(int x) {
    NodeT *newNode = (NodeT *) malloc(sizeof(NodeT));
    newNode->data = x;
    newNode->next=NULL;
    newNode->prev=NULL;
    if (Sentinel->first == NULL) { //empty list
        Sentinel->first = newNode;
        Sentinel->last = newNode;
    } else { //non-empty list
        newNode->next = Sentinel->first;
        Sentinel->first->prev = newNode;
        Sentinel->first = newNode;
    }
}

void addLast(int x) {
    NodeT *newNode = (NodeT *) malloc(sizeof(NodeT));
    newNode->data = x;
    newNode->prev=NULL;
    newNode->next=NULL;
    if (Sentinel->last == NULL) {//empty list
        Sentinel->first = newNode;
        Sentinel->last = newNode;
    } else { //non-empty
        Sentinel->last->next = newNode;
        newNode->prev = Sentinel->last;
        Sentinel->last = newNode;
    }
}

void deleteFirst() {
    NodeT *temp;
    if (Sentinel->first != NULL) {//non-empty
        if (Sentinel->first->next == NULL){//one element in list
           temp=Sentinel->first;
            Sentinel->last=NULL;
            Sentinel->first=NULL;
            free(temp);
        } else {//more than 2 elements
            temp = Sentinel->first;
            Sentinel->first = Sentinel->first->next;
            Sentinel->first->prev=NULL;
            free(temp);
        }
    }
}


void deleteLast() {
    NodeT *temp = Sentinel->first;
    if (Sentinel->first != NULL) {//non-empty
        if (Sentinel->first->next == Sentinel->last) {//one element in list
            Sentinel->first = NULL;
            Sentinel->last = NULL;
        } else {//more elements
            while (temp->next != Sentinel->last) {
                temp = temp->next;
            }
            temp->next = NULL;
            free(Sentinel->last);
            Sentinel->last = temp;
        }
    }
}


void DOOM_THE_LIST() {
    NodeT *currNode = Sentinel->first;
    while (currNode != NULL) {
        Sentinel->first = Sentinel->first->next;
        free(currNode);
        currNode = Sentinel->first;
    }
    Sentinel->first = NULL;
    Sentinel->last = NULL;
}

void delete(int x) {
    NodeT *currNode = Sentinel->first;
    NodeT *prevNode = Sentinel->first;
    if (currNode->data == x) {
        if (currNode == Sentinel->first) {//first in list
            deleteFirst();
            currNode = Sentinel->first;
        } else {
            if (currNode == Sentinel->last) {
                deleteLast();
                currNode = Sentinel->last;
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

void printAll(FILE *f) {
    NodeT *temp = Sentinel->first;
    if (Sentinel->first == NULL) {
        fprintf(f, "List is empty.\n");
        return;
    }
    while (temp != NULL) {
        fprintf(f, " %d ", temp->data);
        temp = temp->next;
    }
    fprintf(f, "\n");
}

void printFirstX(FILE *f, int x) {
    NodeT *temp = Sentinel->first;
    if (temp == NULL) {
        fprintf(f, "List is empty.\n");
        return;
    }
    while (temp != NULL && x) {
        fprintf(f, " %d ", temp->data);
        x--;
        temp = temp->next;
    }
    fprintf(f, "\n");
}

void printLastX(FILE *f, int x) {
    NodeT *temp = Sentinel->first;
    if (Sentinel->first == NULL) {
        fprintf(f, "List is empty.\n");
        return;
    }
    int nrNodes = 0;
    while (temp != NULL) {
        nrNodes++;
        temp = temp->next;
    }
    temp = Sentinel->first;
    while (temp != NULL && nrNodes > x) {
        temp = temp->next;
        nrNodes--;
    }
    while (temp != NULL && nrNodes) {
        fprintf(f, " %d ", temp->data);
        temp = temp->next;
        nrNodes--;
    }
    fprintf(f, "\n");

}