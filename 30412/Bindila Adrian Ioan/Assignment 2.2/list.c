//
// Created by bindi on 3/9/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

timeListSentinel *timeSentinel;
cashierListSentinel *cashierSentinel;

void initTimeList(void) {
    timeSentinel = (timeListSentinel *) malloc(sizeof(timeListSentinel));
    timeSentinel->first = NULL;
    timeSentinel->last = NULL;
}

void initCashierList(void) {
    cashierSentinel = (cashierListSentinel *) malloc(sizeof(cashierListSentinel));
    cashierSentinel->first = NULL;
    cashierSentinel->last = NULL;
    ///we initialize the list with 0 money at time 0
    cashierAddLast(0, 0);
}

void timeAddLast(int time) {
    timeList *newElement = (timeList *) malloc(sizeof(timeList));
    newElement->time = time;
    newElement->next = NULL;
    if (timeSentinel->first == NULL) {
        ///list is empty
        timeSentinel->first = newElement;
        timeSentinel->last = newElement;
    } else {
        ///list not empty
        timeSentinel->last->next = newElement;
        timeSentinel->last = newElement;
    }
}

void cashierAddLast(int money, int time) {
    ///in this list each element denotes the total amount of money and the exact
    ///moment when the money was added to the total
    cashierList *newElement = (cashierList *) malloc(sizeof(cashierList));
    newElement->money = money;
    newElement->time = time;
    newElement->next = NULL;
    newElement->prev = NULL;
    if (cashierSentinel->first == NULL) {
        cashierSentinel->first = newElement;
        cashierSentinel->last = newElement;
    } else {
        ///list is not empty
        newElement->money = cashierSentinel->last->money + money;
        newElement->time = cashierSentinel->last->time + time;
        newElement->prev = cashierSentinel->last;
        cashierSentinel->last->next = newElement;
        cashierSentinel->last = newElement;
    }

}

void printTimeAndMoney(FILE *output) {
    ///we assume that the time may be in a random order
    timeList *currentTimeElement = timeSentinel->first;
    cashierList *currentCashierElement = cashierSentinel->first;
    while (currentTimeElement != timeSentinel->last) {
        if (currentTimeElement->time > currentCashierElement->time) {
            while (currentCashierElement->next != NULL &&
                   currentTimeElement->time > currentCashierElement->time &&
                   currentTimeElement->time >= currentCashierElement->next->time) {
                currentCashierElement = currentCashierElement->next;
            }
        } else if (currentTimeElement->time < currentCashierElement->time) {
            while (currentCashierElement->prev != NULL &&
                   currentTimeElement->time < currentCashierElement->time &&
                   currentTimeElement->time <= currentCashierElement->prev->time) {

                currentCashierElement = currentCashierElement->prev;

            }
            if(currentTimeElement->time<currentCashierElement->time){
                currentCashierElement = currentCashierElement->prev;
            }
        }

        fprintf(output, "After %d seconds: %d\n", currentTimeElement->time, currentCashierElement->money);
        currentTimeElement = currentTimeElement->next;
    }

}
