//
// Created by acer on 3/10/2020.
//

#include "queue.h"

void addCustomer() {
    if (line->last == NULL) {
        line->last = (Customer *) malloc(sizeof(Customer));
        line->last->next = NULL;
        line->last->prev = NULL;

        fscanf(fin, "%*s %d %d", &line->last->rubles, &line->last->seconds);
        getc(fin);

        line->first = line->last;
    } else {
        Customer *newCustomer = (Customer *) malloc(sizeof(Customer));

        newCustomer->next = NULL;
        newCustomer->prev = line->last;
        line->last->next = newCustomer;

        fscanf(fin, "%*s %d %d", &newCustomer->rubles, &newCustomer->seconds);
        getc(fin);

        line->last = newCustomer;
    }
}

void prettyPrint(int i) {
    Customer *currCustomer = line->first;
    int j = 0;
    totalSec = 0;
    totalRubles  = 0;
    while (j < i) {
        while (totalSec < timeTable[j] && currCustomer) {
            totalRubles += currCustomer->rubles;
            totalSec += currCustomer->seconds;
            currCustomer = currCustomer->next;
        }
        if (totalSec > timeTable[j]) {
            currCustomer = currCustomer->prev;
            totalRubles -= currCustomer->rubles;
            totalSec -= currCustomer->seconds;
        }
        fprintf(fout, "After %d seconds: %d\n", timeTable[j], totalRubles);
        j++;
    }
}