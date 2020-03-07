//
// Created by q on 3/6/2020.
//

#ifndef LASTTRY_CUSTOMER_H
#define LASTTRY_CUSTOMER_H

#endif //LASTTRY_CUSTOMER_H

#include <stdio.h>
#include <stdlib.h>
#define ERR_MEMORY "Error allocating memory"

typedef struct _customer {
    int sec;
    int rubles;
    struct _customer * prev, * next;
}CustomerT;
/*
 * the new data type CustomerT has 2 fields (sec, rubles):
 * rubles => contains the total sum received by the cashier after serving the respective customer;
 * sec => amount of time that passed since opening until the respective customer, measured in seconds;
 */
typedef struct _queue {
    int time;
    int amount;
    CustomerT * first, * last;
}QueueT;

QueueT * createQueue();
void freeQueue(QueueT * queuePtr);
/*
 * read data and create customer
 */
CustomerT * readData(QueueT * q, int X, int Y);
CustomerT * createCustomer(int X, int Y);
QueueT * readQueue(FILE * fp);
/*
 * add new customer to the queue
 */
void enqueue(QueueT * queuePtr, int X, int Y);
/*
 * find the last customer served before the given time expires
 */
CustomerT * findCustomer(QueueT * queuePtr, int time);