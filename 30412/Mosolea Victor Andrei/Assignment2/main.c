#include "head.h"

void addCustomer(CustomerList *list, int money, int time);

List readFirstLineOfInput(FILE *f);

CustomerList readCustomerData(FILE *f);

void addToTotal(int *totalMoney, int *totalTime, Customer currentCustomer);

int main() {
    FILE *f = fopen("../input.dat", "r");
    FILE *g = fopen("../output.dat", "w");
    List time = readFirstLineOfInput(f);
    CustomerList list = readCustomerData(f);
    Node *currentTimeElem = time.sentinel->next;
    Customer *currentCustomer = list.sentinel->next;
    int totalTime = 0;
    int totalMoney = 0;
    while (currentCustomer != list.sentinel) {
        if (totalTime + currentCustomer->time <= currentTimeElem->data)
            addToTotal(&totalMoney, &totalTime, *currentCustomer);
        if (totalTime >= currentTimeElem->data) {
            fprintf(g,"After %d seconds: %d\n", currentTimeElem->data, totalMoney);
            currentTimeElem = currentTimeElem->next;
            currentCustomer = currentCustomer->next;
        } else if (totalTime + currentCustomer->next->time > currentTimeElem->data &&
                   totalTime + currentCustomer->next->time < currentTimeElem->next->data) {
            fprintf(g,"After %d seconds: %d\n", currentTimeElem->data, totalMoney);
            currentTimeElem = currentTimeElem->next;
            currentCustomer = currentCustomer->next;
            addToTotal(&totalMoney, &totalTime, *currentCustomer);
        } else {
            while (totalTime + currentCustomer->next->time > currentTimeElem->data) {
                fprintf(g,"After %d seconds: %d\n", currentTimeElem->data, totalMoney);
                currentTimeElem = currentTimeElem->next;
            }
            currentCustomer = currentCustomer->next;
        }

    }
    while (currentTimeElem != time.sentinel->next) {
        fprintf(g,"After %d seconds: %d\n", currentTimeElem->data, totalMoney);
        currentTimeElem = currentTimeElem->next;
    }
    return 0;
}

void addCustomer(CustomerList *list, int money, int time) {
    Customer *newCustomer = (Customer *) malloc(sizeof(Customer));
    newCustomer->money = money;
    newCustomer->time = time;
    if (list->sentinel == NULL) {
        list->sentinel = newCustomer;
        list->sentinel->next = list->sentinel;
        list->sentinel->previous = list->sentinel;
    } else {
        newCustomer->next = list->sentinel->next;
        newCustomer->previous = list->sentinel;
        list->sentinel = newCustomer;
        list->sentinel->next->previous = newCustomer;
        list->sentinel->previous->next = list->sentinel;
    }
}

List readFirstLineOfInput(FILE *f) {
    List time;
    initList(&time);
    char aux[MAX_LINE];
    fgets(aux, MAX_LINE, f);
    char *pch = strtok(aux, " ");
    while (pch != NULL) {
        int x = atoi(pch);
        addLast(&time, x);
        pch = strtok(NULL, " ");
    }
    return time;
}

CustomerList readCustomerData(FILE *f) {
    CustomerList list;
    list.sentinel = NULL;
    char aux[MAX_LINE];
    while (feof(f) == 0) {
        fscanf(f, "%s", aux);
        int x, y;
        fscanf(f, "%d %d", &x, &y);
        addCustomer(&list, x, y);
    }
    return list;
}

void addToTotal(int *totalMoney, int *totalTime, Customer currentCustomer) {
    *totalMoney = *totalMoney + currentCustomer.money;
    *totalTime = *totalTime + currentCustomer.time;
}

