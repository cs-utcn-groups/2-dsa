//
// Created by bindi on 3/9/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

sentinel *sent;

void initList(void) {
    sent = (sentinel *) malloc(sizeof(sentinel));
    sent->first = NULL;
    sent->last = NULL;
}

void addFirst(int x) {
    list *newElement = (list *) malloc(sizeof(list));
    newElement->data = x;
    newElement->next = NULL;
    newElement->prev = NULL;
    if (sent->first == NULL) {
        ///list is empty
        sent->first = newElement;
        sent->last = newElement;
    } else {
        ///list not empty
        newElement->next = sent->first;
        sent->first->prev = newElement;
        sent->first = newElement;
    }
}

void addLast(int x) {
    list *newElement = (list *) malloc(sizeof(list));
    newElement->data = x;
    newElement->next = NULL;
    newElement->prev = NULL;
    if (sent->last == NULL) {
        ///list is empty
        sent->first = newElement;
        sent->last = newElement;
    } else {
        ///list not empty
        sent->last->next = newElement;
        newElement->prev = sent->last;
        sent->last = newElement;
    }
}

void deleteFirst(void) {
    list *currentElement;
    ///list is empty -> we don't do anything
    if (sent->first != NULL) {
        ///list not empty
        if (sent->first->next == NULL) {
            ///list has one element
            currentElement = sent->first;
            sent->first = NULL;
            sent->last = NULL;
            free(currentElement);
        } else {
            ///list has more elements
            currentElement = sent->first;
            sent->first = sent->first->next;
            sent->first->prev = NULL;
            free(currentElement);
        }
    }
}

void deleteLast(void) {
    list *currentElement;
    ///list is empty -> we don't do anything
    if (sent->first != NULL) {
        ///list not empty
        if (sent->first->next == NULL) {
            ///list has one element
            currentElement = sent->first;
            sent->first = NULL;
            sent->last = NULL;
            free(currentElement);
        } else {
            ///list has more elements
            currentElement = sent->last;
            sent->last = sent->last->prev;
            sent->last->next = NULL;
            free(currentElement);
        }
    }
}

void doomTheList(void) {
    list *previousElement = NULL;
    list *currentElement = sent->first;
    while (currentElement != NULL) {
        free(previousElement);
        previousElement = currentElement;
        currentElement = currentElement->next;
    }
    sent->first = NULL;
    sent->last = NULL;
}

void deleteElement(int x) {
    list *currentElement = sent->first;
    while (currentElement != NULL) {
        if (currentElement->data == x) break;
        else {
            currentElement = currentElement->next;
        }
    }
    if (currentElement != NULL) {///element was found
        if (currentElement == sent->first) {///first in list
            sent->first = sent->first->next;
            free(currentElement);
        } else {
            list *previousElement = currentElement->prev;
            previousElement->next = currentElement->next;
            free(currentElement);
        }
    }
}

void printAll(FILE *output) {
    list *currentElement = sent->first;
    while (currentElement != NULL) {
        fprintf(output, "%d ", currentElement->data);
        currentElement = currentElement->next;
    }
    fprintf(output, "\n");
}

void printFirst(FILE *output, int x) {
    list *currentElement = sent->first;
    while (x > 0 && currentElement != NULL) {
        fprintf(output, "%d ", currentElement->data);
        currentElement = currentElement->next;
        x--;
    }
    fprintf(output, "\n");
}

void printLast(FILE *output, int x) {
    list *currentElement = sent->last;
    while (x > 0 && currentElement != sent->first) {
        currentElement = currentElement->prev;
        x--;
    }
    currentElement=currentElement->next;
    while (currentElement != NULL) {
        fprintf(output, "%d ", currentElement->data);
        currentElement = currentElement->next;
    }
    fprintf(output, "\n");
}
