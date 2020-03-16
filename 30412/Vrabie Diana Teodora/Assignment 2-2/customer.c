//
// Created by diana on 09/03/2020.
//

#include "customer.h"
#include "customerlist.h"
#include <stdlib.h>

Customer *initializeNullCustomer() {
    Customer *customer = (Customer *) malloc(sizeof(Customer));
    return customer;
}

void readCustomer(FILE *file) {
    char line[200], *parsePtr;
    fgets(line, 200, file);
    fgetc(file);
    parsePtr = strtok(line, " ");
    parsePtr = strtok(NULL, " ");
    int time, cash;
    cash = atoi(parsePtr);
    parsePtr = strtok(NULL, " ");
    time = atoi(parsePtr);
    addCustomerToList(cash, time);
}
