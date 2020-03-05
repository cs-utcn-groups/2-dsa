//
// Created by Bori on 2/25/2020.
//

#include <stdlib.h>
#include <stdio.h>
#include "list.h"

list createList() {
    list newList;
    newList.first = NULL;
    newList.last = NULL;
    return newList;
}

int isEmpty(list *myList) {
    if (myList->first == NULL) {
        return 1;
    }
    return 0;
}

void addFirst(list *myList, int value) {
    node *newNode = createNodeWithNext(value, myList->first);
    myList->first = newNode;
    if (myList->last == NULL) {
        myList->last = myList->first;
    }
}

void addLast(list *myList, int value) {
    if (myList->first == NULL) {
        addFirst(myList, value);
    } else {
        node *newNode = createNode(value);
        myList->last->next = newNode;
        myList->last = newNode;
    }
}

void deleteFirst(list *myList) {
    if (myList->first != NULL) {
        node *prevFirst = myList->first;
        myList->first = myList->first->next;
        free(prevFirst);
        if (myList->first == NULL) myList->last = NULL;
    }
}

int sumOfElements(list *myList) {
    node *curNode = myList->first;
    int sum = 0;
    while (curNode != NULL) {
        sum += curNode->data;
        curNode = curNode->next;
    }
    return sum;
}

int firstValue(list *myList) {
    if (myList->first == NULL) {
        return 0;
    }
    return myList->first->data;
}

int subtractFromFirstValue(list *myList, int value) {
    myList->first->data -= value;
}

int size(list *myList) {
    int noNodes = 0;
    node *curNode = myList->first;
    while (curNode != NULL) {
        noNodes++;
        curNode = curNode->next;
    }
    return noNodes;
}

int noElementsWithSumSmallerOrEqual(list *myList, int sum, int *unUsedOfSum) {
    int noElements = 0;
    node *curNode = myList->first;
    int curSum = 0;
    while (curNode != NULL && curSum + curNode->data <= sum) {
        curSum += curNode->data;
        noElements++;
        curNode = curNode->next;
    }
    *unUsedOfSum = sum - curSum;
    return noElements;
}