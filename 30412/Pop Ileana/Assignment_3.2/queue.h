//
// Created by ileana on 3/21/2020.
//

#ifndef ASSIGNMENT_3_2_QUEUE_H
#define ASSIGNMENT_3_2_QUEUE_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
    double operand;
    char operator;
    int type;
    struct node * next;
}NodeL;

FILE *fin;
NodeL * first, * last;


void createQueue();
void dequeue();

#endif //ASSIGNMENT_3_2_QUEUE_H
