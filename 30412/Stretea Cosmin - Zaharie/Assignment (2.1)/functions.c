//
// Created by Cosmin on 06-Mar-20.
//
#include "head.h"


Node *first, *last;

void init() {
    first = NULL;
    last = NULL;
}

void AF(int x) {
    if (first == NULL) {
        first = (Node *) malloc(sizeof(Node));
        first->data = x;
        first->next = NULL;
        first->prev = NULL;
        last = first;
    } else {
        Node *newNode = (Node *) malloc(sizeof(Node));
        newNode->data = x;
        newNode->next = first;
        newNode->prev = NULL;
        first->prev = newNode;
        first = newNode;
    }

}

void AL(int x) {
    if (last == NULL) {
        last = (Node *) malloc(sizeof(Node));
        last->data = x;
        last->next = NULL;
        last->prev = NULL;
        first = last;
    } else {
        Node *newNode = (Node *) malloc(sizeof(Node));
        newNode->data = x;
        newNode->next = NULL;
        newNode->prev = last;
        last->next = newNode;
        last = newNode;
    }

}

void DF() {
    if (first) {
        Node *currentNode = first;
        first = first->next;
        first->prev = NULL;
        free(currentNode);
    }
}

void DL() {
    if (last) {
        Node *currentNode = last;
        last = last->prev;
        last->next = NULL;
        free(currentNode);
    }
}

void DOOM_THE_LIST() {
    Node *currentNode;
    while (first != NULL) {
        currentNode = first;
        first = first->next;
        free(currentNode);
    }
    last = NULL;
}

void DE(int x) {
    Node *currentNode = first;
    Node *previousNode = first;
    while (currentNode != NULL) {
        if (currentNode->data == x) {
            if (currentNode == first) {
                first = first->next;
                first->prev = NULL;
            } else if (currentNode == last) {
                last = last->prev;
                last->next = NULL;
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
    Node *currentNode = first;
    while (currentNode) {
        fprintf(output, "%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    fprintf(output, "\n");
}

void PRINT_F(int x) {
    Node *currentNode = first;
    while (currentNode && x) {
        fprintf(output, "%d ", currentNode->data);
        currentNode = currentNode->next;
        x--;
    }
    fprintf(output, "\n");
}

void PRINT_L(int x) {
    Node *currentNode = last;
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