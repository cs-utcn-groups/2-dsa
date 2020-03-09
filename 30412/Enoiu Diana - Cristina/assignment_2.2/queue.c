//
// Created by Diana on 3/9/2020.
//
#include <stdio.h>
#include "head.h"
#include "stdlib.h"
void initializeQueue(){
    first = NULL;
    last = NULL;
}
void allocMemory() {
    in = fopen("../input.dat","r");
    out = fopen("../output.dat","a");
    stringForTime = (char *) malloc (MAX_STRING_SIZE * sizeof(char));
    personName = (char *) malloc (MAX_STRING_SIZE * sizeof(char));
    rubles = (char *) malloc (MAX_STRING_SIZE * sizeof(char));
    secondsSpent = (char *) malloc (MAX_STRING_SIZE * sizeof(char));
    customer = (person *) malloc (sizeof(person));
}
void readCustomerData() {
    fscanf(in,"%s%s",rubles,secondsSpent);
    customer->rubles = strtol(rubles,&ptr,10);
    customer->secondsSpent = strtol(secondsSpent,&ptr,10);
}
void addCustomer() {
    if(first == NULL) {
        first = (moneyEarned *)malloc(sizeof(moneyEarned));
        first->value = customer->rubles;
        first->time = customer->secondsSpent;
        first->nextPerson = NULL;
        last = first;
    }
    else {
        moneyEarned * newCustomer;
        newCustomer = (moneyEarned *)malloc(sizeof(moneyEarned));
        last->nextPerson = newCustomer;
        newCustomer->nextPerson = NULL;
        newCustomer->value = last->value + customer->rubles;
        newCustomer->time = last->time + customer->secondsSpent;
        last = newCustomer;
    }
}
void printValue() {
    moneyEarned * currentCustomer;
    moneyEarned * previousCustomer;
    currentCustomer = first;
    previousCustomer = first;
    while(afterXSeconds > currentCustomer->time && currentCustomer->nextPerson != NULL) {
        previousCustomer = currentCustomer;
        currentCustomer = currentCustomer->nextPerson;
    }
    if(currentCustomer->nextPerson == NULL) {
        fprintf(out,"After %d seconds: %d\n",afterXSeconds,previousCustomer->nextPerson->value);
    }
    else {
        fprintf(out,"After %d seconds: %d\n",afterXSeconds,previousCustomer->value);
    }
}