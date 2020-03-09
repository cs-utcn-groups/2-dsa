//
// Created by diana on 07/03/2020.
//

#include "list.h"

void initializeList() {
    myList = (List *) malloc(sizeof(List));
    myList->nrOfMembers = 0;
    myList->first = NULL;
    myList->last = NULL;
}

void addElementToFront(int data) {
    if (myList->first == NULL) {
        myList->first = initializeEmptyNode();
        myList->last = initializeEmptyNode();
        myList->first->value = data;
        myList->first->next = NULL;
        myList->first->prev = NULL;
        myList->last = myList->first;
        myList->nrOfMembers = 1;
    } else {
        Node *newNode = initializeEmptyNode();
        newNode->value = data;
        newNode->next = myList->first;
        newNode->prev = NULL;
        myList->first->prev = newNode;
        myList->first = newNode;
        myList->nrOfMembers++;
    }
}

void printAll(FILE *file) {
    if (myList->nrOfMembers == 0) {
        return;
    }
    Node *node = myList->first;
    while (node != NULL) {
        fprintf(file, "%d ", node->value);
        node = node->next;
    }
    fprintf(file, "\n");
}

void addElementToEnd(int data) {
    if (myList->last == NULL) {
        myList->first = initializeEmptyNode();
        myList->last = initializeEmptyNode();
        myList->last->value = data;
        myList->last->next = NULL;
        myList->last->prev = NULL;
        myList->first = myList->last;
        myList->nrOfMembers = 1;
    } else {
        Node *newNode = initializeEmptyNode();
        newNode->value = data;
        newNode->next = NULL;
        newNode->prev = myList->last;
        myList->last->next = newNode;
        myList->last = newNode;
        myList->nrOfMembers++;
    }
}

void deleteFirstElement() {
    if (myList->nrOfMembers == 0) return;
    if (myList->nrOfMembers == 1) {
        Node *node = myList->first;
        myList->first = NULL;
        myList->last = NULL;
        myList->nrOfMembers = 0;
        free(node);
        return;
    }
    Node *node = myList->first;
    myList->first = myList->first->next;
    myList->first->prev = NULL;
    free(node);
    myList->nrOfMembers--;
}

void deleteLastElement() {
    if (myList->nrOfMembers == 0) return;
    if (myList->nrOfMembers == 1) {
        Node *node = myList->last;
        myList->first = NULL;
        myList->last = NULL;
        myList->nrOfMembers = 0;
        free(node);
        return;
    }
    Node *node = myList->last;
    myList->last = myList->last->prev;
    myList->last->next = NULL;
    free(node);
    myList->nrOfMembers--;
}

void deleteList() {
    if (myList->nrOfMembers == 0)return;;
    Node *node = myList->first;
    while (node != NULL) {
        deleteFirstElement();
        node = myList->first;
    }
    myList->nrOfMembers = 0;
}

void deleteElement(int data) {
    if (myList->nrOfMembers == 0) return;
    Node *node = myList->first;
    while (node != NULL) {
        if (node->value == data) {
            if (node == myList->first) {
                deleteFirstElement();
                return;
            } else if (node == myList->last) {
                deleteLastElement();
                return;
            } else {
                node->prev->next = node->next;
                node->next->prev = node->prev;
                myList->nrOfMembers--;
                free(node);
                return;
            }
        }
        node = node->next;
    }
}

void printFirst(int nr, FILE *file) {
    if (nr > myList->nrOfMembers) {
        printAll(file);
    } else {
        Node *node = myList->first;
        for (int i = 0; i < nr; ++i) {
            fprintf(file, "%d ", node->value);
            node = node->next;
        }
        fprintf(file, "\n");
    }

}

void printLast(int nr, FILE *file) {
    if (nr > myList->nrOfMembers) {
        printAll(file);
    } else {
        Node *node = myList->last;
        for (int i = 0; i < nr; ++i) {
            node = node->prev;
        }
        while (node != NULL) {
            fprintf(file, "%d ", node->value);
            node = node->next;
        }
        fprintf(file, "\n");
    }
}


