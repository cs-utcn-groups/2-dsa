//
// Created by q on 3/6/2020.
//

#include "customer.h"

QueueT * createQueue() {
    QueueT * q = (QueueT *)malloc(sizeof(QueueT));
    if(q) {
        q->time = q->amount = 0;
        q->first = q->last = 0;
        return q;
    }
    else {
        perror(ERR_MEMORY);
        exit(EXIT_FAILURE);
    }
}
void freeQueue(QueueT * queuePtr) {
    CustomerT * temp = queuePtr->first;
    while(temp) {
        queuePtr->first = temp->next;
        free(temp);
        temp = queuePtr->first;
    }
    free(queuePtr);
}

CustomerT * createCustomer(int X, int Y) {
    CustomerT * c = (CustomerT*)malloc(sizeof(CustomerT));
    if(c) {
        c->sec = Y;
        c->rubles = X;
        c->next = c->prev = NULL;
        return c;
    }
    else {
        perror(ERR_MEMORY);
        exit(EXIT_FAILURE);
    }
}
QueueT * readQueue(FILE * fp) {
    QueueT * queuePtr = createQueue();
    int X,Y;
    while(!feof(fp)) {
        fscanf(fp,"%*s %d %d",&X,&Y);
        enqueue(queuePtr,X,Y);
    }
    return queuePtr;
}
/*
 * whenever we add another customer to the queue, we update the fields:
 * amount => the total amount of the sum received so far by the cashier;
 * time => the time that passed since the first customer;
 * -- this way we can keep track of how the sum grows in time
 */
CustomerT * readData(QueueT * queuePtr, int x, int y) {
    queuePtr->amount += x;
    queuePtr->time += y;
    CustomerT * newCustomer = createCustomer(queuePtr->amount,queuePtr->time);
    return newCustomer;
}
void enqueue(QueueT * queuePtr, int X, int Y) {
   CustomerT * newCustomer = readData(queuePtr,X,Y);
    if(queuePtr->first == NULL) {
        queuePtr->first = newCustomer;
    }
    else {
        newCustomer->prev = queuePtr->last;
        queuePtr->last->next = newCustomer;
    }
    queuePtr->last = newCustomer;
}
CustomerT * findCustomer(QueueT * queuePtr, int time) {
    CustomerT * customer = queuePtr->first;
    while(customer && customer->sec < time) {
        customer = customer->next;
    }
    if(customer == NULL) {
        /*
         * when the total amount of time is less than the time given
         * we want to print the whole sum received so far, so we return the last element
         */
        return queuePtr->last;
    }
    else {
        if (customer->sec > time) {
            customer = customer->prev;
        }
        return customer;
    }
}