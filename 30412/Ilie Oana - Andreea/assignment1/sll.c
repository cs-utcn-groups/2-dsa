//
// Created by Andreea on 02-Mar-20.
//

#include <stdlib.h>
#include "sll.h"

void initializeSLL() {
    first = NULL;
    last = NULL;
}

void AL(int data) {
    if (first == NULL) {
        first = (NodeT *) malloc(sizeof(NodeT));
        first->next = last;
        first->data = data;
        last = first;
    } else {
        NodeT *newElement = (NodeT *) malloc(sizeof(NodeT));
        last->next = newElement;
        newElement->next = NULL;
        newElement->data = data;
        last = newElement;
    }
}

void AF(int data) {
    if (first == NULL) {
        first = (NodeT *) malloc(sizeof(NodeT));
        first->next = last;
        first->data = data;
        last = first;
    } else {
        NodeT *newElement = (NodeT *) malloc(sizeof(NodeT));
        newElement->next = first;
        newElement->data = data;
        first = newElement;
    }
}

void DF() {
    if (first != NULL) {
        NodeT *firstElement = first;
        first = first->next;
        free(firstElement);
        if (!first)
            last = NULL;
    }
}

void DL() {
    if (last != NULL) {
        NodeT *currentElement = first;
        while (currentElement->next->next != NULL) {
            currentElement = currentElement->next;
        }
        currentElement->next = NULL;
        free(last);
        last = currentElement;

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
    NodeT *previousElement = first;
    while (currentElement != NULL) {
        if (currentElement->data == x) {
            if (currentElement == first) {
                first = first->next;
            } else if (currentElement == last) {
                last = previousElement;
                last->next = NULL;
            } else {
                previousElement->next = currentElement->next;
            }
            previousElement = currentElement;
            currentElement = currentElement->next;
            free(previousElement);
            previousElement = currentElement;
        } else {
            previousElement = currentElement;
            currentElement = currentElement->next;
        }

    }
}

void PRINT_ALL(FILE *outputFile) {
    if (first == NULL) {
        printf("List is empty!\n");
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
        printf("List is empty!\n");
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
        printf("List is empty!\n");
    } else {
        int noOfNodes = 0;
        NodeT *currentElement = first;
        while (currentElement != NULL) {
            noOfNodes++;
            currentElement = currentElement->next;
        }
        int k = 0;
        currentElement = first;
        while (k < noOfNodes - x && currentElement != NULL) {
            currentElement = currentElement->next;
            k++;
        }
        while (currentElement != NULL) {
            fprintf(outputFile, "%d ", currentElement->data);
            currentElement = currentElement->next;
        }
        fprintf(outputFile, "\n");
    }
}
