//
// Created by bindi on 3/2/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include "list.h"


void initList(void) {
    first = NULL;
    last = NULL;
}

void addFirst(int x) {
    list *newElement = (list *) malloc(sizeof(list));///first, we initialize the element to be added
    newElement->data = x;
    newElement->next = NULL;
    if (first == NULL) {///list is empty
        first = newElement;
        last = newElement;
    } else if (first != NULL) {///list contains elements
        newElement->next = first;
        first = newElement;
    }

}

void addLast(int x) {
    list *newElement = (list *) malloc(sizeof(list));
    newElement->data = x;
    newElement->next = NULL;
    if (first == NULL) {///empty list
        first = newElement;
        last = newElement;
    } else if (last != NULL) {
        last->next = newElement;
        last = newElement;
    }

}

void deleteFirst(void) {
    list *currentElement;
    if (first != NULL) {///list is not empty
        currentElement = first;
        first = first->next;
        free(currentElement);
        if (first == NULL) {
            last = NULL;
        }
    }
}

void deleteLast(void) {
    list *previousElement = NULL;
    list *currentElement = first;
    ///if the list is empty nothing needs to be done
    if (currentElement != NULL) {///list isn't empty
        while (currentElement != last) {
            previousElement = currentElement;
            currentElement = currentElement->next;
        }///we have reached the last element (via currentElement)
        if (currentElement == first) {
            ///if the list has one element
            first = last = NULL;
        } else {
            ///if the list has more than one element
            previousElement->next = NULL;
            last = previousElement;
        }
        free(currentElement);
    }
}

void doomTheList(void) {
    list *previousElement = NULL;
    list *currentElement = first;
    while (currentElement != NULL) {
        previousElement = currentElement;
        free(previousElement);
        currentElement = currentElement->next;
    }
    first = last = NULL;
}

void deleteElement(int x) {
    list *previousElement = NULL;
    list *currentElement = first;
    while (currentElement != NULL) {
        if (currentElement->data == x) break;
        previousElement = currentElement;
        currentElement = currentElement->next;
    }
    if (currentElement != NULL) {
        if (currentElement == first) {
            first = first->next;
            free(currentElement);
            if (first == NULL) {
                last = NULL;
            }
        } else {
            previousElement->next = currentElement->next;
            if (currentElement == last) last = previousElement;
            free(currentElement);
        }
    }
}

void printAll(void) {
    FILE *fout = fopen("../output.dat", "w");
    list *currentElement = first;
    while (currentElement != NULL) {
        fprintf(fout, "%d ", currentElement->data);
        currentElement = currentElement->next;
    }
    fprintf(fout, "\n");
    fclose(fout);
}

void printFirst(int noOfElements) {
    FILE *fout = fopen("../output.dat", "w");
    list *currentElement = first;
    while (noOfElements > 0 && currentElement != NULL) {
        fprintf(fout, "%d ", currentElement->data);
        currentElement = currentElement->next;
        noOfElements--;
    }
    fprintf(fout, "\n");
    fclose(fout);
}

void printLast(int noOfElements) {
    ///we cannot print the last x elements of a list unless we know exactly how many elements are in total
    FILE *fout = fopen("../output.dat", "w");
    list *currentElement = first;
    int k = 0;
    while (currentElement != NULL) {
        k++;
        currentElement = currentElement->next;
    }
    currentElement = first;
    for (int i = 0; i < k - noOfElements; i++) {
        currentElement = currentElement->next;
    }
    while (currentElement != NULL) {
        fprintf(fout, "%d ", currentElement->data);
        currentElement = currentElement->next;
    }
    fprintf(fout, "\n");
    fclose(fout);
}

void printDebugList(void) {
    ///prints the list in console
    list *currentElement = first;
    while (currentElement != NULL) {
        printf("%d ", currentElement->data);
        currentElement = currentElement->next;
    }
    printf("\n");
}