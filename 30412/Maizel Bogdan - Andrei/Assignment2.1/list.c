#include "list.h"

void initList() {
    ListPtr = (ListT *) malloc(sizeof(ListT));
    ListPtr->first = (nodeT *) malloc(sizeof(nodeT));
    ListPtr->last = (nodeT *) malloc(sizeof(nodeT));
    ListPtr->first = NULL;
    ListPtr->last = NULL;
}

void addFirst(int data) {
    nodeT *newElement = (nodeT *) malloc(sizeof(nodeT));
    newElement->data = data;
    if (ListPtr->first == NULL) {
        ListPtr->first = newElement;
        ListPtr->first->next = NULL;
        ListPtr->first->prev = NULL;
        ListPtr->last = ListPtr->first;
    } else {
        ListPtr->first->prev = newElement;
        newElement->next = ListPtr->first;
        newElement->prev = NULL;
        ListPtr->first = newElement;
    }

}

void addLast(int data) {
    nodeT *newElement = (nodeT *) malloc(sizeof(nodeT));
    newElement->data = data;
    if (ListPtr->first == NULL) {
        ListPtr->first = newElement;
        ListPtr->first->next = NULL;
        ListPtr->first->prev = NULL;
        ListPtr->last = ListPtr->first;
    } else if (ListPtr->last != NULL) {
        newElement->next = NULL;
        newElement->prev = ListPtr->last;
        ListPtr->last->next = newElement;
        ListPtr->last = newElement;
    }
}

void deleteFirst() {
    nodeT *element;
    if (ListPtr->first != NULL) {
        element = ListPtr->first;
        ListPtr->first = ListPtr->first->next;
        free(element);
        if (ListPtr->first == NULL)
            ListPtr->last = NULL;
        else ListPtr->first->prev = NULL;
    }
}

void deleteLast() {
    nodeT *currentElement;
    currentElement = ListPtr->first;
    if (currentElement != NULL)
        while (currentElement != ListPtr->last) {
            currentElement = currentElement->next;
        }
    if (currentElement == ListPtr->first)
        ListPtr->first = ListPtr->last = NULL;
    else {
        ListPtr->last->prev->next = NULL;
        ListPtr->last = ListPtr->last->prev;

    }
}

void doomTheList() {
    nodeT *currentElement;
    while (ListPtr->first != NULL) {
        currentElement = ListPtr->first;
        ListPtr->first = ListPtr->first->next;
        free(currentElement);
    }
    ListPtr->last = NULL;
}

void deleteElement(int data) {
    nodeT *currentElement = ListPtr->first;

    while (currentElement != NULL) {
        if (currentElement->data == data) {
            if (ListPtr->first == currentElement && ListPtr->last == currentElement) {
                ListPtr->first = NULL;
                ListPtr->last = NULL;
                free(currentElement);
            } else if (currentElement == ListPtr->first) {
                ListPtr->first = ListPtr->first->next;
                if (ListPtr->first == NULL)
                    ListPtr->last = NULL;
                else ListPtr->first->prev = NULL;
                free(currentElement);
            } else if (currentElement == ListPtr->last) {
                ListPtr->last = ListPtr->last->prev;
                ListPtr->last->next = NULL;
                free(currentElement);
            } else {
                currentElement = currentElement->prev;
                free(currentElement);
            }
        } else {
            currentElement = currentElement->next;
        }
    }
}

void printAll(FILE *fout) {
    nodeT *currentElement = ListPtr->first;
    while (currentElement != NULL) {
        fprintf(fout, " %d ", currentElement->data);
        currentElement = currentElement->next;
    }
    fprintf(fout, " \n ");

}

void printFirst(int x, FILE *fout) {
    nodeT *currentElement = ListPtr->first;
    int i = 0;
    while (i < x && currentElement != NULL) {
        fprintf(fout, " %d ", currentElement->data);
        currentElement = currentElement->next;
        i++;
    }
    fprintf(fout, "\n");
}


void printLast(int x, FILE *fout) {
    nodeT *p;
    int noOfElements = 0;
    for (p = ListPtr->first; p != NULL; p = p->next)
        noOfElements++;
    int k = noOfElements - x;
    int count = 0;
    if (k <= 0) printAll(fout);
    else
        for (p = ListPtr->first; p != NULL; p = p->next) {
            count++;
            if (count >= x) fprintf(fout, " %d ", p->data);
        }
    fprintf(fout, "\n");
}






