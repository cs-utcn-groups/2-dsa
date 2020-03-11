#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *next;
} time;

typedef struct node1 {
    int rubles,seconds;
    struct node1 *next;
}customers;

time *firstTime, *lastTime;
customers *firstCustomers, *lastCustomers;

void addLastTime(int data) {
    if (firstTime == NULL) {
        firstTime = (time *) malloc(sizeof(time));
        firstTime->next = lastTime;
        firstTime->data = data;
        lastTime = firstTime;
    } else {
        time *newElement = (time *) malloc(sizeof(time));
        lastTime->next = newElement;
        newElement->next = NULL;
        newElement->data = data;
        lastTime = newElement;
    }
}

void addLastCustomers (int rubles, int seconds)
{
    if (firstCustomers == NULL) {
        firstCustomers = (customers *) malloc(sizeof(customers));
        firstCustomers->next = lastCustomers;
        firstCustomers->rubles = rubles;
        firstCustomers->seconds=seconds;
        lastCustomers = firstCustomers;
    } else {
        customers *newElement = (customers *) malloc(sizeof(customers));
        lastCustomers->next = newElement;
        newElement->next = NULL;
        newElement->rubles = rubles;
        newElement->seconds=seconds;
        lastCustomers = newElement;
    }
}

void readTimes(FILE *f)
{
    char *strbuf = (char *) malloc(sizeof(char) * 200);
    fgets(strbuf, 200, f);
    char *pch;
    pch = strtok(strbuf, " ");
    while (pch != NULL) {
        addLastTime(atoi(pch));
        pch = strtok(NULL, " ");
    }
}

void readCustomers(FILE *f)
{
    char *strbuf = (char *) malloc(sizeof(char) * 200);
    while (fgets(strbuf,200,f)!=NULL)
    {
        char *p;
        p=strtok(strbuf," ");
        p=strtok(NULL," ");
        int rubles=atoi(p);
        p=strtok(NULL, " ");
        int seconds=atoi(p);
        addLastCustomers(rubles,seconds);
    }
}

void printResult(FILE *g)
{
    time *current=firstTime;
    int seconds=0,rubles=0;
    while (current->next!=NULL)
    {
        while(firstCustomers && firstCustomers->seconds+seconds<=current->data)
        {
            seconds=seconds+firstCustomers->seconds;
            rubles=rubles+firstCustomers->rubles;
            customers *node=firstCustomers;
            firstCustomers=firstCustomers->next;
            free(node);
        }
        fprintf(g,"After %d seconds: %d\n",current->data,rubles);
        current=current->next;
    }

    while(firstCustomers && firstCustomers->seconds+seconds<=current->data)
    {
        seconds=seconds+firstCustomers->seconds;
        rubles=rubles+firstCustomers->rubles;
        customers *node=firstCustomers;
        firstCustomers=firstCustomers->next;
        free(node);
    }
    fprintf(g,"After %d seconds: %d\n",current->data,rubles);
}

int main() {
    FILE *f;
    f = fopen("input.dat", "r");
    FILE *g;
    g = fopen("output.dat", "w");

    readTimes(f);
    readCustomers(f);

    printResult(g);

    fclose(f);
    fclose(g);
    return 0;
}