//
// Created by diana on 09/03/2020.
//

#include <stdio.h>

#ifndef ASSIGNMENT_2_2_CUSTOMER_H
#define ASSIGNMENT_2_2_CUSTOMER_H

#include <string.h>
typedef struct customer {
    int cash;
    int time;
    struct customer *next;
} Customer;

void readCustomer(FILE *file);

Customer *initializeNullCustomer();

#endif //ASSIGNMENT_2_2_CUSTOMER_H
