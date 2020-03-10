//
// Created by Irina on 10/03/2020.
//

#ifndef ASSIGNMENT2_2_CUSTOMER_H
#define ASSIGNMENT2_2_CUSTOMER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "node.h"

#define MAX_LENGTH 200
#define MAX_NAME 50

void readTime(int * time, int *count, FILE * input);

void readCustomers(FILE * input);

void printCustomer(FILE * output, int * time, int count);

#endif //ASSIGNMENT2_2_CUSTOMER_H
