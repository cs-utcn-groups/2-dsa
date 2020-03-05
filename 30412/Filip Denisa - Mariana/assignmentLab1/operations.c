//
// Created by Denisa on 2/26/2020.
//
#include "head.h"

void initializeSll() {
    first = NULL;
    last = NULL;
}

void AF(int x) {
    if (first == NULL) {
        first = (NodeT *) malloc(sizeof(NodeT));
        first->next = NULL;
        first->data = x;
        last = first;
    } else {
        NodeT *newElement = (NodeT *) malloc(sizeof(NodeT));
        newElement->next = first;
        newElement->data = x;
        first = newElement;
    }
}

void AL(int x) {
    if (last == NULL) {
        last = (NodeT *) malloc(sizeof(NodeT));
        last->next = NULL;
        last->data = x;
        first = last;
    } else {
        NodeT *newElement = (NodeT *) malloc(sizeof(NodeT));
        last->next = newElement;
        newElement->next = NULL;
        newElement->data = x;
        last = newElement;
    }
}

void DF() {
    NodeT *currentElement = first;
    if (currentElement != NULL) {
        first = first->next;
        free(currentElement);
        if (first == NULL) {
            last = NULL;
        }
    }
}

void DL() {
    NodeT *currentElement = first;
    NodeT *previousElement = first;
    if (currentElement != NULL) {
        while (currentElement != last) {
            previousElement = currentElement;
            currentElement = currentElement->next;
        }
        if (currentElement == first) {
            first = last = NULL;
        } else {
            previousElement->next = NULL;
            last = previousElement;
        }
        free(currentElement);
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

void DE(int x) {
    NodeT *currentElement = first;
    NodeT *previousElement = first;
    while (currentElement != NULL) {
        if (currentElement->data == x) {
            if (currentElement == first) {
                first = first->next;
                currentElement = first;
                free(previousElement);
                previousElement = first;
            } else {
                if (currentElement == last) {
                    previousElement->next = NULL;
                    last = previousElement;
                } else {
                    previousElement->next = currentElement->next;
                }
                free(currentElement);
                currentElement = previousElement->next;
            }
        } else {
            previousElement = currentElement;
            currentElement = currentElement->next;
        }
    }
}

void PRINT_ALL(FILE *output) {
    if (first == NULL) {
        fprintf(output, "The list is empty! \n");
    } else {
        NodeT *currentElement = first;
        while (currentElement != NULL) {
            fprintf(output, "%d ", currentElement->data);
            currentElement = currentElement->next;
        }
        fprintf(output, "\n");
    }
}

void PRINT_F(FILE *output, int x) {
    if (first == NULL) {
        fprintf(output, "The list is empty! \n");
    } else {
        NodeT *currentElement = first;
        for (int i = 0; i < x; i++) {
            if (currentElement != NULL) {
                fprintf(output, "%d ", currentElement->data);
                currentElement = currentElement->next;
            }
        }
        fprintf(output, "\n");
    }
}

void PRINT_L(FILE *output, int x) {
    if (first == NULL) {
        fprintf(output, "The list is empty! \n");
    } else {
        NodeT *currentElement = first;
        NodeT *previousElement = first;
        for (int i = 1; i < x; i++) {
            currentElement = currentElement->next;
        }
        while (currentElement->next != NULL) {
            currentElement = currentElement->next;
            previousElement = previousElement->next;
        }
        while (previousElement != NULL) {
            fprintf(output, "%d ", previousElement->data);
            previousElement = previousElement->next;
        }
        fprintf(output, "\n");
    }
}
