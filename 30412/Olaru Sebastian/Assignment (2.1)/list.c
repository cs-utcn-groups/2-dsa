//
// Created by acer on 3/10/2020.
//

#include "list.h"

List createList(){
    List newList;
    newList.santinel = createNode(0, NULL, NULL);
    newList.santinel->next = newList.santinel;
    newList.santinel->prev = newList.santinel;
    return newList;
}

void AddElementFirst(int x) {
    Node *newNode = createNode(x, doubleLinkedList.santinel, doubleLinkedList.santinel->next);
    doubleLinkedList.santinel->next->prev = newNode;
    doubleLinkedList.santinel->next = newNode;

}

void AddElementLast(int x) {
    Node *newNode = createNode(x, doubleLinkedList.santinel->prev, doubleLinkedList.santinel);
    doubleLinkedList.santinel->prev->next = newNode;
    doubleLinkedList.santinel->prev = newNode;

}

void DeleteFirst() {
    if (doubleLinkedList.santinel->next != doubleLinkedList.santinel) {
        Node *currentFirst = doubleLinkedList.santinel->next;
        doubleLinkedList.santinel->next = doubleLinkedList.santinel->next->next;
        doubleLinkedList.santinel->next->prev = doubleLinkedList.santinel;
        free(currentFirst);
    }
}

void DeleteLast() {
    if (doubleLinkedList.santinel->prev != doubleLinkedList.santinel) {
        Node *currentLast = doubleLinkedList.santinel->prev;
        doubleLinkedList.santinel->prev = doubleLinkedList.santinel->prev->prev;
        doubleLinkedList.santinel->prev->next = doubleLinkedList.santinel;
        free(currentLast);
    }
}

void DeleteWholeList() {
    Node *currentFirst;
    while (doubleLinkedList.santinel->next != doubleLinkedList.santinel) {
        currentFirst = doubleLinkedList.santinel->next;
        doubleLinkedList.santinel->next = doubleLinkedList.santinel->next->next;
        free(currentFirst);
    }
    doubleLinkedList.santinel->prev = doubleLinkedList.santinel;
}

void DeleteElement(int x) {
    Node *currentNode = doubleLinkedList.santinel->next;
    Node *previousNode = doubleLinkedList.santinel;
    while (currentNode != doubleLinkedList.santinel) {
        if (currentNode->data == x)
        {
            previousNode->next = currentNode->next;
            currentNode->next->prev = previousNode;
            free(currentNode);
            currentNode = previousNode->next;
        } else {
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
    }
}

void PrintWholeList() {
    if (doubleLinkedList.santinel->next == doubleLinkedList.santinel) fprintf(fout, "List is empty\n");
    else {
        Node *currentNode = doubleLinkedList.santinel->next;
        while (currentNode != doubleLinkedList.santinel) {
            fprintf(fout, "%d ", currentNode->data);
            currentNode = currentNode->next;
        }
        fprintf(fout, "\n");
    }
}

void PrintFirstNElements(int x) {
    if (doubleLinkedList.santinel->next == doubleLinkedList.santinel)
        fprintf(fout, "List is empty\n");
    else {
        int count = 0;
        Node *currentNode = doubleLinkedList.santinel->next;
        while (count < x && currentNode != doubleLinkedList.santinel) {
            fprintf(fout, "%d ", currentNode->data);
            currentNode = currentNode->next;
            count++;
        }
        fprintf(fout, "\n");
    }
}

void PrintLastNElements(int x) {
    if (doubleLinkedList.santinel->prev == doubleLinkedList.santinel)
        fprintf(fout, "List is empty\n");
    else {
        int count = 0;
        Node *currentNode = doubleLinkedList.santinel->prev;
        while (count < x && currentNode != doubleLinkedList.santinel) {
            fprintf(fout, "%d ", currentNode->data);
            currentNode = currentNode->prev;
            count++;
        }
        fprintf(fout, "\n");
    }
}