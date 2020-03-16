//
// Created by Diana on 2/29/2020.
//
#include "sll.h"
void initializeSll() {
    first = NULL;
    last = NULL;
}
void addFirst(int data) {
    if (first == NULL) {
        first = (NodeT *)malloc(sizeof(NodeT));
        first->data = data;
        first->next = NULL;
        last = first;
    }
    else {
        NodeT * newElement = (NodeT *)malloc(sizeof(NodeT));
        newElement->data = data;
        newElement->next = first;
        first = newElement;
    }
}
void addLast(int data) {
    if (first == NULL) {
        first = (NodeT*)malloc(sizeof(NodeT));
        first->data = data;
        first->next = NULL;
        last = first;
    }
    else {
        NodeT * newElement = (NodeT*)malloc(sizeof(NodeT));
        last->next = newElement;
        newElement->data = data;
        newElement->next = NULL;
        last = newElement;
    }
}
void deleteFirst() {
    if(first != NULL) {
        NodeT *firstElement = first;
        first = first->next;
        free(firstElement);
    }
}
void deleteLast() {
    if(first != NULL) {
        NodeT * currentElement = first;
        NodeT * previousElement = first;
        while (currentElement->next != NULL) {
            previousElement = currentElement;
            currentElement = currentElement->next;
        }
        free (currentElement);
        last = previousElement;
        last->next = NULL;
    }
}
void doomTheList(){
    NodeT * currentElement = first;
    NodeT * previousElement;
    if (first != NULL) {
        while (currentElement != NULL) {
            previousElement = currentElement;
            currentElement = currentElement->next;
            free(previousElement);
        }
        first = NULL;
        last = NULL;
    }
}
void deleteElement(int data) {
    NodeT * currentElement = first;
    NodeT * previousElement= first;
    while(currentElement != NULL) {
        if(currentElement->data == data) {
            if(currentElement == first) {
                first = first->next;
            }
            else {
                if (currentElement == last) {
                    last = previousElement;
                    last->next = NULL;
                } else {
                    previousElement->next = currentElement->next;
                }
            }
            previousElement = currentElement;
            currentElement = currentElement->next;
            free(previousElement);
        }
        else {
            previousElement = currentElement;
            currentElement = currentElement->next;
        }
    }
}
void printFirst (FILE * output, int tillValue) {
    NodeT * currentElement = first;
    if (first == NULL) {
        fprintf(output,"List is empty\n");
    }
    else {
        for (int i = 0; i < tillValue; i++) {
            if (currentElement != NULL) {
                fprintf(output, "%d ", currentElement->data);
                currentElement = currentElement->next;
            }
        }
        fprintf(output,"\n");
    }
}
void printLast (FILE * output, int tillValue) {
    if(first == NULL) {
        fprintf(output,"List is empty\n");
    }
    else {
        int noOfElements = 0;
        NodeT * currentElement = first;
        while(currentElement != NULL) {
            noOfElements++;
            currentElement = currentElement->next;
        }
        if(noOfElements <= tillValue) {
            printAll(output);
        }
        else {
            currentElement = first;
            int index = 0;
            while (index < noOfElements-tillValue) {
                currentElement = currentElement->next;
                index++;
            }
            while (currentElement != NULL) {
                fprintf(output, "%d ", currentElement->data);
                currentElement = currentElement->next;
            }
            fprintf(output,"\n");
        }
    }
}

void printAll(FILE * output) {
    if(first == NULL) {
        fprintf(output,"List is empty!\n");
    }
    else {
        NodeT * currentElement;
        currentElement = first;
        while (currentElement != NULL) {
            fprintf(output,"%d ", currentElement->data);
            currentElement = currentElement->next;
        }
        fprintf(output,"\n");
    }
}