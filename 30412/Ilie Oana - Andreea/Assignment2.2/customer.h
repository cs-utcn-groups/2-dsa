//
// Created by Andreea on 08-Mar-20.
//

#ifndef ASSIGNMENT2_2_CUSTOMER_H
#define ASSIGNMENT2_2_CUSTOMER_H

typedef struct customer {
    int roubles, time;
    struct customer *prev, *next;
} customerT;

customerT *firstC, *lastC;

void initializeCustomer();

void readCustomer(FILE *inputFile);

void AL(int roubles, int time);

#endif //ASSIGNMENT2_2_CUSTOMER_H
