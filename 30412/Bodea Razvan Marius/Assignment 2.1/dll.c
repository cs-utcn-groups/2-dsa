//
// Created by razvi on 3/1/2020.
//

#include "head.h"

void initializeDll() {
    list = (LisT *) malloc(sizeof(LisT));
    list->first = NULL;
    list->last = NULL;

}


void Add_First(int data) {
    if (list->first == NULL) {
        list->first = (NodeT *) malloc(sizeof(NodeT));
        list->first->next = NULL;
        list->first->data = data;
        list->first->prev = NULL;
    } else if (list->last == NULL) {
        list->last = (NodeT *) malloc(sizeof(NodeT));
        list->last->data = data;
        list->last->next = NULL;
        list->first->next = list->last;
        list->last->prev = list->first;
    } else {
        NodeT *newNode = (NodeT *) malloc(sizeof(NodeT));
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = list->last;
        list->last->next = newNode;
        list->last = newNode;
    }
}


void Add_Last(int data) {
    if (list->first == NULL) {
        list->first = (NodeT *) malloc(sizeof(NodeT));
        list->first->next = NULL;
        list->first->data = data;
        list->first->prev = NULL;
    } else if (list->last == NULL) {
        list->last = (NodeT *) malloc(sizeof(NodeT));
        list->last->data = data;
        list->last->next = NULL;
        list->first->next = list->last;
        list->last->prev = list->first;
    } else {
        NodeT *newNode = (NodeT *) malloc(sizeof(NodeT));
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = list->last;
        list->last->next = newNode;
        list->last = newNode;
    }
}

void Delete_First() {
    if (list->first == NULL) {
        return;
    }
    NodeT *newNode = list->first;
    list->first = list->first->next;
    list->first->prev = NULL;
    free(newNode);
}

void Delete_Last() {
    if (list->first == NULL) {
        return;
    }
    if (list->first == list->last) {
        Delete_First();
        return;
    }
    NodeT *newNode = list->last;
    list->last = list->last->prev;
    list->last->next = NULL;
    free(newNode);
}


void Remove_All() {
    NodeT *current = list->first;
    while (current != NULL) {
        list->first = list->first->next;
        free(current);
        current = list->first;
    }
    list->first = NULL;
    list->last = NULL;
}

void Delete_Element(int n) {
    if (list->first->data == n) {
        Delete_First();
    } else {
        NodeT *current = list->first->next;
        while (current != list->last) {
            if (current->data == n) {
                current->next->prev = current->prev;
                current->prev->next = current->next;
                free(current);
                return;
            }
            current = current->next;
        }
        if (list->last->data == n)
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
        if (list->first == NULL) {
            fprintf(fptr, "List is empty!\n");
        } else {
            NodeT *current = list->first;
            while (current != NULL) {
                fprintf(fptr, "%d ", current->data);
                current = current->next;
            }
            fprintf(fptr, "\n");
        }
    }
}

void Print_First_N(int nr, FILE *fptr) {
    if (list->first == NULL) {
        fprintf(fptr, "List is empty\n");
    } else {
        NodeT *current = list->first;
        for (int i = 0; i < nr && current != NULL; i++) {
            fprintf(fptr, "%d ", current->data);
            current = current->next;
        }
        fprintf(fptr, "\n");
    }
}

void Print_Last_N(int nr, FILE *fptr) {
    //we don't need to keep track of the nr of elements in this case
    NodeT *current = list->last;
    for (int i = 1; i < nr; i++) {
        current = current->prev;
    }
    while (current != NULL) {
        fprintf(fptr, "%d ", current->data);
        current = current->next;
    }
    fprintf(fptr, "\n");
}