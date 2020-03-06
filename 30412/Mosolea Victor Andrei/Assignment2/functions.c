//
// Created by Victor on 3/6/2020.
//
#include "head.h"


void initList(List *list) {
    list->first = NULL;
    list->last = NULL;
}

void addFirst(List *list, int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->first;
    if (list->first != NULL)
        list->first->previous = newNode;
    list->first = newNode;
    if (list->last == NULL) {
        list->last = list->first;
    }
}

void addLast(List *list, int data) {
    if (list->first == NULL) {
        addFirst(list, data);
    } else {
        Node *newNode = (Node *) malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;
        newNode->previous = list->last;
        list->last->next = newNode;
        list->last = newNode;
    }
}

void deleteFirst(List *list) {
    if (list->first != NULL) {
        Node *aux = list->first;
        list->first = list->first->next;
        free(aux);
    }
}

void deleteLast(List *list) {
    if (list->first != NULL) {
        Node *aux = list->last;
        list->last = list->last->previous;
        list->last->next = NULL;
        free(aux);
    }
}

void removeAll(List *list) {
    while (list->first != NULL)
        deleteFirst(list);
    initList(list);
}

void deleteX(List *list, int data) {
    Node *currentNode = list->first;
    Node *previousNode = list->first;
    while (currentNode != NULL) {
        if (currentNode == list->first && currentNode->data == data) {
            deleteFirst(list);
            currentNode = list->first;
            previousNode = list->first;
        } else if (currentNode == list->last && currentNode->data == data) {
            deleteLast(list);
            currentNode = NULL;
        } else if (currentNode->data == data) {
            Node *aux = currentNode;
            previousNode->next = currentNode->next;
            currentNode = currentNode->next;
            currentNode->previous = previousNode;
            free(aux);
            currentNode->previous = previousNode;
        } else {
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
    }
}

void printList(List list, FILE *g) {
    if (list.first == NULL)
        printf("List is empty\n");
    else {
        Node *currentNode = list.first;
        while (currentNode != NULL) {
            fprintf(g, "%d ", currentNode->data);
            currentNode = currentNode->next;
        }
    }
    fprintf(g, "\n");
}

void printFirstN(List list, int n, FILE *g) {
    Node *currentNode = list.first;
    while (n) {
        fprintf(g, "%d ", currentNode->data);
        currentNode = currentNode->next;
        n--;
    }
    fprintf(g, "\n");
}

void printLastN(List list, int n, FILE *g) {
    Node *currentNode = list.last;
    while (n) {
        fprintf(g, "%d ", currentNode->data);
        currentNode = currentNode->previous;
        n--;
    }
    fprintf(g, "\n");
}

