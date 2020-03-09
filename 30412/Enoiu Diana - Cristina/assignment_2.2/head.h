//
// Created by Diana on 3/9/2020.
//

#ifndef ASSIGNMENT_2_2_HEAD_H
#define ASSIGNMENT_2_2_HEAD_H
#define MAX_STRING_SIZE 300
typedef struct _node{
    int value;
    int time;
    struct _node * nextPerson;
}moneyEarned;
moneyEarned * first, * last;
typedef struct _person{
    int rubles;
    int secondsSpent;
}person;
person * customer;
FILE * in;
FILE * out;
char * stringForTime;
int afterXSeconds;
char * personName,* rubles,* secondsSpent;
char * ptr;
void initializeQueue();
void allocMemory();
void readCustomerData();
void addCustomer();
void printValue();

#endif //ASSIGNMENT_2_2_HEAD_H
