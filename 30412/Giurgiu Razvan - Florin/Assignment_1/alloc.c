//
// Created by TheRa on 2/26/2020.
//

#include "alloc.h"


void startSll() {
    first = (NodeT *) malloc(sizeof(NodeT));
    last = (NodeT *) malloc(sizeof(NodeT));
    first = NULL;
    last = NULL;
}

void af(int data) {
    p = (NodeT *) malloc(sizeof(NodeT));
    p->data = data;
    if (first == NULL) {
        first = p;
        first->next = NULL;
        last = first;
    } else if (first == last) {
        p->next = last;
        first = p;
    } else {
        p->next = first;
        first = p;
    }

}

void al(int data) {
    p = (NodeT *) malloc(sizeof(NodeT));
    p->data = data;
    if (last == NULL) {
        last = p;
        last->next = NULL;
        first = last;
    } else {
        last->next = p;
        last = p;
        last->next = NULL;
    }

}

void df() {
    if (first) {
        p = first;
        first = first->next;
        free(p);
        if (first == NULL)
            last = NULL;
    }
}

void dl() {
    p = first;
    NodeT *q = NULL;
    if (p) {
        while (p != last) {
            q = p;
            p = p->next;
        }
        if (p == first)
            first = last = NULL;
        else {
            q->next = NULL;
            last = q;
        }
        free(p);
    }
}

void doom() {
    p = first;
    while (p != last) {
        df();
        p = p->next;
    }
    last = first = NULL;
}

void d_spec(int data) {
    p = first;
    NodeT *prev = NULL;
    if (first == last && first->data == data)
        first = last = NULL;

    if (first->data == data)
        first = first->next;
    else
        while (p != NULL) {
            if (p->data == data) {
                prev->next = p->next;

            }
            prev = p;
            p = p->next;
        }
    free(p);

}

void print_f_x(FILE *f, int x) {
    p = first;
    int c = 1;
    while (p != NULL && c <= x) {
        fprintf(f, "%d ", p->data);
        p = p->next;
        c++;
    }
    fprintf(f, "\n");
}

void nr_of_items(FILE *f, int x, int *count, NodeT *q) {
    if (!q) {
        *count = 0;
        return;
    }
    nr_of_items(f, x, count, q->next);
    (*count)++;
}

void print_l_x(FILE *f, int data, int k) {
    p = first;
    int c = 0;
    data = k - data;
    while (p) {
        if (c >= data) fprintf(f, "%d ", p->data);
        p = p->next;
        c++;
    }
    fprintf(f, "\n");
}

void print_all(FILE *f) {
    p = first;
    while (p != NULL) {
        fprintf(f, "%d ", p->data);
        p = p->next;
    }
    fprintf(f, "\n");
}


