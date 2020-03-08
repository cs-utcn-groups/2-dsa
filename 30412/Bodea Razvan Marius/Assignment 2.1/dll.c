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
        first->prev = NULL;
        last = first;
    } else {
        NodeT *newNode = (NodeT *) malloc(sizeof(NodeT));
        newNode->data = data;
        newNode->next = first;
        first->prev = newNode;
        newNode->prev = NULL;
        first = newNode;
    }

}

void Add_Last(int data) {
    if (first == NULL) {
        first = (NodeT *) malloc(sizeof(NodeT));
        first->next = last;
        first->data = data;
        first->prev = NULL;
        last = first;
    } else {
        NodeT *newNode = (NodeT *) malloc(sizeof(NodeT));
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = last;
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
    first->prev = NULL;
    free(newNode);
}

void Delete_Last() {
    if (first == NULL) {
        return;
    }
    if (first == last) {
        Delete_First();
        return;
    }
    NodeT *newNode = last;
    last = last->prev;
    last->next = NULL;
    free(newNode);
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
        while (current != last) {
            if (current->data == n) {
                current->next->prev = current->prev;
                current->prev->next = current->next;
                free(current);
                return;
            }
            current = current->next;
        }
        if (last->data == n)
            Delete_Last();
    }
}

/*
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
*/

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

void Print_Last_N(int nr, FILE *fptr) {
    //we don't need to keep track of the nr of elements in this case
    NodeT *current = last;
    for (int i = 1; i < nr; i++) {
        current = current->prev;
    }
    while (current != NULL) {
        fprintf(fptr, "%d ", current->data);
        current = current->next;
    }
    fprintf(fptr, "\n");
}