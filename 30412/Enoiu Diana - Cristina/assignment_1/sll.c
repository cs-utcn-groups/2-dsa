//
// Created by Diana on 2/29/2020.
//
#include "sll.h"
void initializeSll() {
    first = NULL;
    last = NULL;
}
void AF(int data) {
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
void AL(int data) {
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
void DF() {
    if(first != NULL) {
        NodeT *firstElement = first;
        first = first->next;
        free(firstElement);
    }
}
void DL() {
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
void DOOM_THE_LIST(){
    NodeT * currentElement = first;
    NodeT * previousElement = first;
    if (first != NULL) {
        while (currentElement != NULL) {
            currentElement = currentElement->next;
            free(previousElement);
        }
        first = NULL;
        last = NULL;
    }
}
void DE(int data) {
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
            previousElement = currentElement;
        }
        else {
            previousElement = currentElement;
            currentElement = currentElement->next;
        }
    }
}
void PRINT_F (FILE * output, int tillValue) {
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
void PRINT_L (FILE * output, int tillValue) {
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
            PRINT_ALL(output);
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

void PRINT_ALL(FILE * output) {
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