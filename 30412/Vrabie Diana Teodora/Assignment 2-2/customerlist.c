//
// Created by diana on 09/03/2020.
//

#include "customerlist.h"
#include <stdlib.h>

void initializeCustomerList() {
    customerList = (CustomerList *) malloc(sizeof(CustomerList));
    customerList->nrOfCustomers = 0;
    customerList->last = initializeNullCustomer();
    customerList->first = initializeNullCustomer();
}

void addCustomerToList(int cash, int time) {
    if (customerList->nrOfCustomers == 0) {
        customerList->nrOfCustomers = 1;
        customerList->first = initializeNullCustomer();
        customerList->first->cash = cash;
        customerList->first->time = time;
        customerList->first->next = NULL;
        customerList->last = customerList->first;
    } else {
        customerList->nrOfCustomers++;
        Customer *newCustomer = (Customer *) malloc(sizeof(Customer));
        newCustomer->next = NULL;
        newCustomer->time = time;
        newCustomer->cash = cash;
        customerList->last->next = newCustomer;
        customerList->last = newCustomer;
    }
}

