//
// Created by Cosmin on 06-Mar-20.
//
#include "head.h"


List *list;

void init() {
    list = (List *)malloc(sizeof(List));
    list->first = NULL;
    list->last = NULL;
}

void AF(int x) {
    if (list->first == NULL) {
        list->first = (Node *) malloc(sizeof(Node));
        list->first->data = x;
        list->first->next = NULL;
        list->first->prev = NULL;
        list->last = list->first;
    } else {
        Node *newNode = (Node *) malloc(sizeof(Node));
        newNode->data = x;
        newNode->next = list->first;
        newNode->prev = NULL;
        list->first->prev = newNode;
        list->first = newNode;
    }

}

void AL(int x) {
    if (list->last == NULL) {
        list->last = (Node *) malloc(sizeof(Node));
        list->last->data = x;
        list->last->next = NULL;
        list->last->prev = NULL;
        list->first = list->last;
    } else {
        Node *newNode = (Node *) malloc(sizeof(Node));
        newNode->data = x;
        newNode->next = NULL;
        newNode->prev = list->last;
        list->last->next = newNode;
        list->last = newNode;
    }

}

void DF() {
    if (list->first) {
        Node *currentNode = list->first;
        list->first = list->first->next;
        list->first->prev = NULL;
        free(currentNode);
    }
}

void DL() {
    if (list->last) {
        Node *currentNode = list->last;
        list->last = list->last->prev;
        list->last->next = NULL;
        free(currentNode);
    }
}

void DOOM_THE_LIST() {
    Node *currentNode;
    while (list->first != NULL) {
        currentNode = list->first;
        list->first = list->first->next;
        free(currentNode);
    }
    list->last = NULL;
}

void DE(int x) {
    Node *currentNode = list->first;
    Node *previousNode = list->first;
    while (currentNode != NULL) {
        if (currentNode->data == x) {
            if (currentNode == list->first) {
                list->first = list->first->next;
                list->first->prev = NULL;
            } else if (currentNode == list->last) {
                list->last = list->last->prev;
                list->last->next = NULL;
            } else {
                previousNode->next = currentNode->next;
                currentNode->next->prev = previousNode;
            }
            previousNode = currentNode;
            currentNode = currentNode->next;
            free(previousNode);
            previousNode = currentNode;
        } else {
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
    }
}

void PRINT_ALL() {
    Node *currentNode = list->first;
    while (currentNode) {
        fprintf(output, "%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    fprintf(output, "\n");
}

void PRINT_F(int x) {
    Node *currentNode = list->first;
    while (currentNode && x) {
        fprintf(output, "%d ", currentNode->data);
        currentNode = currentNode->next;
        x--;
    }
    fprintf(output, "\n");
}

void PRINT_L(int x) {
    Node *currentNode = list->last;
    x--; // we start from the last position therefore we have already counted 1 node
    while(currentNode && x){
        currentNode = currentNode->prev;
        x--;
    }
    while (currentNode) {
        fprintf(output, "%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    fprintf(output, "\n");
}