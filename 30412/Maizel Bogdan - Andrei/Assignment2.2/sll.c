#include "sll.h"

void initList() {
    first = (nodeT *) malloc(sizeof(nodeT));
    last = (nodeT *) malloc(sizeof(nodeT));
    first = NULL;
    last = NULL;
}

void AddLastCostumer(int money, int seconds) {
    nodeT *newCustomer = (nodeT *) malloc(sizeof(nodeT));
    if (first == NULL) {
        first = (nodeT *) malloc(sizeof(nodeT));
        first->money = money;
        first->seconds = seconds;
        first->next = NULL;
        last = first;
    } else if (last != NULL) {
        newCustomer->next = NULL;
        last->next = newCustomer;
        newCustomer->money = money;
        newCustomer->seconds = seconds;
        last = newCustomer;
    }
}

void deleteFirstCustomer() {
    nodeT *costumer;
    if (first != NULL) {
        costumer = first;
        first = first->next;
        free(costumer);
        if (first == NULL) last = NULL;
    }
}

void printAllElements(FILE *fout) {
    nodeT *currentElement = first;
    while (currentElement != NULL) {
        fprintf(fout, " %d %d", currentElement->money, currentElement->seconds);
        currentElement = currentElement->next;
    }
    fprintf(fout, " \n ");

}