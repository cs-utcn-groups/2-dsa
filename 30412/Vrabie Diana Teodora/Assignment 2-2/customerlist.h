//
// Created by diana on 09/03/2020.
//

#ifndef ASSIGNMENT_2_2_CUSTOMERLIST_H
#define ASSIGNMENT_2_2_CUSTOMERLIST_H

#include "customer.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct _customerList {
    int nrOfCustomers;
    Customer *first;
    Customer *last;
} CustomerList;

CustomerList *customerList;

void initializeCustomerList();

void addCustomerToList(int cash, int time);

void printCustomerList();

Customer *getTopCustomer();

#endif //ASSIGNMENT_2_2_CUSTOMERLIST_H
