//
// Created by TheRa on 3/3/2020.
//

#ifndef ASSIGNMENT_2_2_QUEUE_H
#define ASSIGNMENT_2_2_QUEUE_H

typedef struct nodetype {
    int time;
    int money;
    struct nodetype *next;
} NodeT;

typedef struct _cashier
{
    int money;
    int time;
}cashier;

cashier employ[100];

NodeT *first, *last, *p;

void initialize();
void add(char name[25], int money, int time, int *timePassed, int *moneyCollected);

#endif //ASSIGNMENT_2_2_QUEUE_H
