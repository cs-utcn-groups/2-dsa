//
// Created by Andreea on 09-Mar-20.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "customer.h"

#define MAX_NAME 30

void initializeCustomer() {
    firstC = NULL;
    lastC = NULL;
}

void readCustomer(FILE *inputFile) {
    char *name = (char *) malloc(MAX_NAME * sizeof(char));;
    int roubles, time;
    while (!feof(inputFile)) {
        fscanf(inputFile, "%s %d %d", name, &roubles, &time);
        AL(roubles, time);
    }
}

void AL(int roubles, int time) {
    customerT *newElement = (customerT *) malloc(sizeof(customerT));
    newElement->roubles = roubles;
    newElement->time = time;
    newElement->next = NULL;
    newElement->prev = lastC;
    if (lastC != NULL)
        lastC->next = newElement;
    else
        firstC = newElement;
    lastC = newElement;
}
