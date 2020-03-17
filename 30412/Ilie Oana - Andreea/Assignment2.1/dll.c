//
// Created by Andreea on 07-Mar-20.
//
#include <stdlib.h>
#include "dll.h"

void initializeSLL() {
    first = NULL;
    last = NULL;
}

void AL(int data) {
    NodeT *newElement = (NodeT *) malloc(sizeof(NodeT));
    newElement->data = data;
    newElement->next = NULL;
    newElement->prev = last;
    if (last != NULL)
        last->next = newElement;
    else
        first = newElement;
    last = newElement;
}

void AF(int data) {
    NodeT *newElement = (NodeT *) malloc(sizeof(NodeT));
    newElement->data = data;
    newElement->next = first;
    newElement->prev = NULL;
    if (first != NULL)
        first->prev = newElement;
    else
        last = newElement;
    first = newElement;

}

void DF() {
    if (first != NULL) {
        NodeT *firstElement = first;
        NodeT *nextElement = firstElement->next;
        first = first->next;
        if (nextElement != NULL) {
            nextElement->prev = firstElement;
        }
        free(firstElement);
    }
}

void DL() {
    if (last != NULL) {
        NodeT *lastElement = last;
        NodeT *prevElement = last->prev;
        prevElement->next = NULL;
        last = last->prev;
        free(lastElement);
    }

}

void DOOM_THE_LIST() {
    NodeT *currentElement = first;
    while (currentElement != NULL) {
        first = first->next;
        free(currentElement);
        currentElement = first;
    }
}

void DE_x(int x) {
    NodeT *currentElement = first;
    NodeT *previousElement;
    NodeT *nextElement;
    while (currentElement != NULL) {
        if (currentElement->data == x) {
            previousElement = currentElement->prev;
            nextElement = currentElement->next;
            if (previousElement != NULL)
                previousElement->next = nextElement;
            else
                first = first->next;
            if (nextElement != NULL)
                nextElement->prev = previousElement;
            else

                last = last->prev;
            free(currentElement);
            currentElement = nextElement;
        } else
            currentElement = currentElement->next;
    }
}

void PRINT_ALL(FILE *outputFile) {
    if (first == NULL) {
        fprintf(outputFile, "List is empty!\n");
    } else {
        NodeT *currentElement = first;
        while (currentElement != NULL) {
            fprintf(outputFile, "%d ", currentElement->data);
            currentElement = currentElement->next;
        }
        fprintf(outputFile, "\n");
    }
}

void PRINT_F(int x, FILE *outputFile) {
    if (first == NULL) {
        fprintf(outputFile, "List is empty!\n");
    } else {
        NodeT *currentElement = first;
        int k = 0;
        while (k <= x - 1 && currentElement != NULL) {
            fprintf(outputFile, "%d ", currentElement->data);
            currentElement = currentElement->next;
            k++;
        }
        fprintf(outputFile, "\n");
    }
}

void PRINT_L(int x, FILE *outputFile) {
    if (first == NULL) {
        fprintf(outputFile, "List is empty!\n");
    } else {
        NodeT *currentElement = last;
        int k = 0;
        while (k < x - 1 && currentElement->prev != NULL) {
            currentElement = currentElement->prev;
            k++;
        }
        if (x - 1 > k)
            PRINT_ALL(outputFile);
        else {
            while (currentElement != NULL) {
                fprintf(outputFile, "%d ", currentElement->data);
                currentElement = currentElement->next;
            }
        }
        fprintf(outputFile, "\n");
    }
}
