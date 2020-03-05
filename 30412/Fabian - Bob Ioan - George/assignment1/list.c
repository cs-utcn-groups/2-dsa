//
// Created by Bobby on 3/3/2020.
//

#include "list.h"


void startSLL() {
    first = (NodeT *) malloc(sizeof(NodeT));
    last = (NodeT *) malloc(sizeof(NodeT));
    first = NULL;
    last = NULL;
}

void AF(int data) {
    aux = (NodeT *) malloc(sizeof(NodeT));
    aux->data = data;
    if (first == NULL) {
        first = aux;
        first->next = NULL;
        last = first;
    } else if (first == last) {
        aux->next = last;
        first = aux;
    } else {
        aux->next = first;
        first = aux;
    }

}

void AL(int data) {
    aux = (NodeT *) malloc(sizeof(NodeT));
    aux->data = data;
    if (last == NULL) {
        last = aux;
        last->next = NULL;
        first = last;
    } else {
        last->next = aux;
        last = aux;
        last->next = NULL;
    }

}

void DF() {
    if (first) {
        aux = first;
        first = first->next;
        free(aux);
        if (first == NULL)
            last = NULL;
    }
}

void DL() {
    aux = first;
    NodeT *q = NULL;
    if (aux) {
        while (aux != last) {
            q = aux;
            aux = aux->next;
        }
        if (aux == first)
            first = last = NULL;
        else {
            q->next = NULL;
            last = q;
        }
        free(aux);
    }
}

void DOOM() {
    aux = first;
    while (aux != last) {
        DF();
        aux = aux->next;
    }
    last = first = NULL;
}

void DE(int data) {
    aux = first;
    NodeT *prev = NULL;
    if (first == last && first->data == data)
        first = last = NULL;

    if (first->data == data)
        first = first->next;
    else
        while (aux != NULL) {
            if (aux->data == data) {
                prev->next = aux->next;

            }
            prev = aux;
            aux = aux->next;
        }
    free(aux);

}

void printF(FILE *f, int x) {
    aux = first;
    int c = 1;
    while (aux != NULL && c <= x) {
        fprintf(f, "%d ", aux->data);
        aux = aux->next;
        c++;
    }
    fprintf(f, "\n");
}

void noOfItems(FILE *f, int x, int *count, NodeT *q) {
    if (!q) {
        *count = 0;
        return;
    }
    noOfItems(f, x, count, q->next);
    (*count)++;
}

void printL(FILE *f, int data, int k) {
    aux = first;
    int c = 0;
    data = k - data;
    while (aux) {
        if (c >= data) fprintf(f, "%d ", aux->data);
        aux = aux->next;
        c++;
    }
    fprintf(f, "\n");
}

void printALL(FILE *f) {
    aux = first;
    while (aux != NULL) {
        fprintf(f, "%d ", aux->data);
        aux = aux->next;
    }
    fprintf(f, "\n");
}
