//
// Created by razvi on 3/1/2020.
//

#include "head.h"

void initializeSll() {
    first = NULL;
    last = NULL;
}


void Add_First(int data) {
    if (first == NULL) {
        first = (NodeT *) malloc(sizeof(NodeT));
        first->next = last;
        first->data = data;
        last = first;
    } else {
        NodeT *newNode = (NodeT *) malloc(sizeof(NodeT));
        newNode->data = data;
        newNode->next = first;
        first = newNode;
    }

}

void Add_Last(int data) {
    if (first == NULL) {
        first = (NodeT *) malloc(sizeof(NodeT));
        first->next = last;
        first->data = data;
        last = first;
    } else {
        NodeT *newNode = (NodeT *) malloc(sizeof(NodeT));
        newNode->data = data;
        newNode->next = NULL;
        last->next = newNode;
        last = newNode;
    }
}

void Delete_First() {
    if (first == NULL) {
        return;
    }
    NodeT *newNode = first;
    first = first->next;
    free(newNode);
}

void Delete_Last() {
    if (first == NULL) {
        return;
    }
    if (last != NULL) {
        NodeT *secondLast = first;
        if (first != last) {
            while (secondLast->next->next != NULL) {
                secondLast = secondLast->next;
            }
            free(last);
            last = secondLast;
            secondLast->next = NULL;
        } else {
            free(last);
            last = NULL;
            first = NULL;
        }
    }
}


void Remove_All() {
    NodeT *current = first;
    while (current != NULL) {
        first = first->next;
        free(current);
        current = first;
    }
}

void Delete_Element(int n) {
    if (first->data == n) {
        Delete_First();
    } else {
        NodeT *current = first->next;
        NodeT *previous = first;
        while (current != last) {
            if (current->data == n) {
                previous->next = current->next;
                free(current);
                return;
            }
            current = current->next;
        }
        if (last->data == n)
            Delete_Last();
    }
}

int Check_Element(int n) {
    NodeT *current = first;
    while (current != NULL) {
        {
            if (current->data == n)
                return 1;
            break;
        }
    }
    return 0;
}

void Print_All(FILE *fptr) {
    {
        if (first == NULL) {
            fprintf(fptr, "List is empty!\n");
        } else {
            NodeT *current = first;
            while (current != NULL) {
                fprintf(fptr, "%d ", current->data);
                current = current->next;
            }
            fprintf(fptr, "\n");
        }
    }
}

void Print_First_N(int nr, FILE *fptr) {
    if (first == NULL) {
        fprintf(fptr, "List is empty\n");
    } else {
        NodeT *current = first;
        for (int i = 0; i < nr && current != NULL; i++) {
            fprintf(fptr, "%d ", current->data);
            current = current->next;
        }
        fprintf(fptr, "\n");
    }
}

void Print_Last_N(int nr, int noOfEl, FILE *fptr) {
    //this was tricky because I had to keep track of the nr of elements   (linear complexity)
    NodeT *current = first;
    while (noOfEl > nr) {
        current = current->next;
        noOfEl--;
    }
    while (current != NULL) {
        fprintf(fptr, "%d ", current->data);
        current = current->next;
    }
    fprintf(fptr, "\n");
}