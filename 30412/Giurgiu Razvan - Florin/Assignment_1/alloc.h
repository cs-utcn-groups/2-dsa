//
// Created by TheRa on 2/26/2020.
//

#ifndef ASSIGNMENT_1_ALLOC_H
#define ASSIGNMENT_1_ALLOC_H

#include <stdlib.h>
#include <stdio.h>


typedef struct nodetype {
    int data;
    struct nodetype *next;
} NodeT;

NodeT *first, *last, *p;

void startSll();

void af(int data);

void print_all(FILE *f);

void al(int data);

void df();

void dl();

void doom();

void d_spec();

void file();

void print_f_x(FILE *f, int x);

void nr_of_items(FILE *f, int x, int *count, NodeT *q);

void print_l_x(FILE *f, int data, int k);

#endif //ASSIGNMENT_1_ALLOC_H
