//
// Created by Victor on 3/6/2020.
//
#include "head.h"


void initList(List *list) {
    list->sentinel = NULL;
}

void addFirst(List *list, int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    if (list->sentinel == NULL) {
        list->sentinel = newNode;
        list->sentinel->next = list->sentinel;
        list->sentinel->previous = list->sentinel;
    } else {
        newNode->next = list->sentinel->next;
        list->sentinel->next->previous = newNode;
        list->sentinel->next = newNode;
        list->sentinel->next->previous = list->sentinel;
    }
}


void addLast(List *list, int data) {
    if (list->sentinel == NULL) {
        addFirst(list, data);
    } else {
        Node *newNode = (Node *) malloc(sizeof(Node));
        newNode->data = data;
        newNode->previous = list->sentinel;
        newNode->next = list->sentinel->next;
        list->sentinel = newNode;
        list->sentinel->previous->next = list->sentinel;
    }
}

void deleteFirst(List *list) {
    if (list->sentinel != NULL) {
        Node *aux = list->sentinel->next;
        list->sentinel->next = list->sentinel->next->next;
        list->sentinel->next->previous = list->sentinel;
        free(aux);
    }
}

void deleteLast(List *list) {
    if (list->sentinel != NULL) {
        Node *aux = list->sentinel;
        list->sentinel->previous->next = list->sentinel->next;
        list->sentinel = list->sentinel->previous;
        free(aux);
    }
}

void removeAll(List *list) {
    while (list->sentinel != list->sentinel->next)
        deleteFirst(list);
    free(list->sentinel);
    initList(list);
}

void deleteX(List *list, int data) {
    Node *currentNode = list->sentinel->next;
    Node *previousNode = list->sentinel;
    do {
        if (currentNode == list->sentinel->next && currentNode->data == data) {
            deleteFirst(list);
            currentNode = list->sentinel->next;
            previousNode = list->sentinel;
        } else if (currentNode == list->sentinel && currentNode->data == data) {
            deleteLast(list);
            currentNode = list->sentinel->next;
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

    } while (currentNode != list->sentinel->next);
}


void printList(List list, FILE *g) {
    if (list.sentinel == NULL)
        fprintf(g, "List is empty\n");
    else {
        Node *currentNode = list.sentinel->next;
        do {
            fprintf(g, "%d ", currentNode->data);
            currentNode = currentNode->next;
        } while (currentNode != list.sentinel->next);
    }
    fprintf(g, "\n");
}

void printFirstN(List list, int n, FILE *g) {
    Node *currentNode = list.sentinel->next;
    do {
        fprintf(g, "%d ", currentNode->data);
        currentNode = currentNode->next;
        n--;
    } while (n && currentNode != list.sentinel->next);
    fprintf(g, "\n");
}

void printLastN(List list, int n, FILE *g) {
    Node *currentNode = list.sentinel;
    do {
        fprintf(g, "%d ", currentNode->data);
        currentNode = currentNode->previous;
        n--;
    } while (n && currentNode != list.sentinel);
    fprintf(g, "\n");
}

