//
// Created by Victor on 3/1/2020.
//
#include "head.h"

List createList() {
    List list;
    list.first = NULL;
    list.last = NULL;
    return list;
}

void addElementFirst(int data, List *list) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->first;
    if (list->first == NULL) {
        list->first = newNode;
        list->last = list->first;
        list->last->next = NULL;
    } else
        list->first = newNode;
}

void addElementLast(int data, List *list) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (list->first == NULL) {
        list->first = newNode;
        list->last = list->first;
        list->last->next = NULL;
    } else
        list->last->next = newNode;
    list->last = newNode;
}

void printList(List list, FILE *f) {
    if (list.first == NULL)
        printf("List is empty");
    else {
        Node *currentNode = list.first;
        while (currentNode != NULL) {
            fprintf(f, "%d ", currentNode->data);
            currentNode = currentNode->next;
        }
    }
    fprintf(f, "\n");
}

void deleteFirst(List *list) {
    if (list->first != NULL) {
        Node *aux = list->first;
        list->first = list->first->next;
        free(aux);
    }
    if (list->first == NULL)
        list->last = NULL;
}

void deleteLast(List *list) {
    if (list->first == list->last)
        deleteFirst(list);
    else {
        Node *previousNode = list->first;
        Node *currentNode = list->first;
        while (currentNode != list->last) {
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
        free(list->last);
        list->last = previousNode;
        list->last->next = NULL;
    }
    if (list->last == NULL)
        list->first = NULL;
}

void removeAll(List *list) {
    while (list->first != NULL)
        deleteFirst(list);
}

void printFirstN(int n, List list, FILE *f) {
    Node *currentNode = list.first;
    while (n && currentNode != NULL) {
        fprintf(f, "%d ", currentNode->data);
        currentNode = currentNode->next;
        n--;
    }
    fprintf(f, "\n");
}

void printLastN(int n, List list, FILE *f) {
    int noOfElements = 0;
    Node *currentNode = list.first;
    while (currentNode != NULL) {
        noOfElements++;
        currentNode = currentNode->next;
    }
    int aux = noOfElements - n;
    if (aux < 0)
        printList(list, f);
    else {
        currentNode = list.first;
        while (aux) {
            currentNode = currentNode->next;
            aux--;
        }
        while (currentNode != NULL) {
            fprintf(f, "%d ", currentNode->data);
            currentNode = currentNode->next;
        }
        fprintf(f, "\n");
    }
}

void deleteElement(int data, List *list) {
    Node *previousNode = list->first;
    Node *currentNode = list->first;
    while (currentNode != NULL) {
        if (currentNode->data == data) {
            if (currentNode == list->first) {
                deleteFirst(list);
                currentNode = list->first;
            } else if (currentNode == list->last)
                deleteLast(list);
            else {
                previousNode->next = currentNode->next;
                free(currentNode);
                currentNode = previousNode->next;
            }
        } else {
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
    }
}

