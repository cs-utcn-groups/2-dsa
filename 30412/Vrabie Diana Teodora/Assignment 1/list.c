//
// Created by diana on 26/02/2020.
//

#include "list.h"

int countElements();

void initializeList() {
    first = NULL;
    last = NULL;
}

void addElementToFront(int data) {
    if (first == NULL) {
        first = (ListElement*) malloc(sizeof(ListElement));
        first->data = data;
        first->next = last;
        last = first;
    } else {
        ListElement *newElement = (ListElement *) malloc(sizeof(ListElement));
        newElement->next = first;
        newElement->data = data;
        first = newElement;
    }
}

void printAll(FILE *file) {
    if (countElements() == 0) return;
    if (first == NULL) {
        fprintf(file, "List is empty!\n");
    } else {
        ListElement *currentElement = first;
        while (currentElement != NULL) {
            fprintf(file, "%d ", currentElement->data);
            currentElement = currentElement->next;
        }
        fprintf(file, "\n");
    }
}

void addElementToEnd(int data) {
    if (first == NULL) {
        first->data = data;
        first->next = last;
        last = first;
    } else {
        ListElement *newElement = (ListElement*) malloc(sizeof(ListElement));
        last->next = newElement;
        newElement->next = NULL;
        newElement->data = data;
        last = newElement;
    }
}

void removeFirstElement() {
    if (countElements() == 0) return;
    if (first== NULL) {
        return;
        //perror("Invalid remove first element, exiting...\n");
        //exit(-1);
    } else {
        ListElement *element = first;
        first = first->next;
        free(element);
    }
}

void removeLastElement() {
    if (countElements() == 0) return;
    if (last == NULL) {
        return;
        //perror("Invalid remove last element, exiting...\n");
        //exit(-1);
    } else {
        ListElement *element = first;
        while (element->next->next != NULL) {
            element = element->next;
        }
        last = element;
        free(element->next);
        last->next = NULL;
    }
}

void deleteList() {
    if (countElements() == 0) return;
    while (first != NULL)
        removeFirstElement();
}

void removeElement(int data) {
    if (countElements() == 0)
        return;
    ListElement *currentElement = first;
    ListElement *prevElement = first;
    while (currentElement != NULL) {
        if (currentElement->data == data) {
            if (currentElement == first) {
                first = first->next;
            }
            else if (currentElement == last) {
                last = prevElement;
                last->next = NULL;
            }
            else {
                prevElement->next = currentElement->next;
            }
            prevElement = currentElement;
            currentElement = currentElement->next;
            free(prevElement);
            prevElement = currentElement;
        } else {
            prevElement = currentElement;
            currentElement = currentElement->next;
        }
    }
}

void printFirstNElements(int nr, FILE *file) {
    if (countElements() == 0) return;
    ListElement *currentElement = first;
    for (int i = 0; i < nr; ++i) {
        if (currentElement == NULL) break;
        fprintf(file, "%d ", currentElement->data);
        currentElement = currentElement->next;
    }
    fprintf(file, "\n");
}

void printLastNElements(int nr, FILE *file) {
    int nrOfElements = countElements();
    if (nrOfElements == 0) return;

    if (nrOfElements <= nr)
        printAll(file);
    else {
        int nrOfSkips = nrOfElements - nr;
        ListElement *element = first;
        for (int i = 0; i < nrOfSkips; ++i) {
            element = element->next;
        }
        while (element!= NULL) {
            fprintf(file, "%d ", element->data);
            element = element->next;
        }
        fprintf(file, "\n");
    }
}

int countElements() {
    int nrOfElements = 0;
    ListElement *element = first;
    while (element != NULL) {
        nrOfElements ++;
        element = element->next;
    }
    return nrOfElements;
}



