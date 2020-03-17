#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int time;
    struct node * next;
} moment;

typedef struct nodeC
{
    int money, sec;
    struct nodeC * next;
} customer;

moment * firstM, * lastM;
customer * firstC, * lastC;

void initializeC ()
{
    firstC = lastC = NULL;
}

void initializeM ()
{
    firstM = lastM = NULL;
}

void addMoment (int data)
{
    if (firstM == NULL)
    {
        firstM = (moment*) malloc (sizeof (moment));
        firstM->time = data;
        firstM->next = NULL;
        lastM = firstM;
    }
    else
    {
        moment * newMoment = (moment*) malloc (sizeof (moment));
        newMoment->time = data;
        newMoment->next = NULL;
        lastM->next = newMoment;
        lastM = newMoment;
    }
}

void readMoments (FILE * fin)
{
    char * s = (char*) malloc (sizeof (char) * 55);
    fgets (s, 55, fin);
    char * token = strtok (s, " \n");
    while (token != NULL)
    {
        int data = atoi (token);
        addMoment (data);
        token = strtok (NULL, " \n");
    }
}

void addCustomer (int money, int sec)
{
    if (firstC == NULL)
    {
        firstC = (customer*) malloc (sizeof (customer));
        firstC->money = money;
        firstC->sec = sec;
        firstC->next = NULL;
        lastC = firstC;
    }
    else
    {
        customer * newCustomer = (customer*) malloc (sizeof (customer));
        newCustomer->money = money;
        newCustomer->sec = sec;
        newCustomer->next = NULL;
        lastC->next = newCustomer;
        lastC = newCustomer;
    }
}

void readCustomers (FILE * fin)
{
    char * s = (char*) malloc (sizeof (char) * 55);
    while (fgets (s, 55, fin))
    {
        char * token = strtok (s, " \n");
        token = strtok (NULL, " \n");
        int money = atoi (token);
        token = strtok (NULL, " \n");
        int sec = atoi (token);
        addCustomer (money, sec);
    }
}

void print ()
{
    customer * q = firstC;
    while (q != NULL)
    {
        printf ("%d %d\n", q->money, q->sec);
        q = q->next;
    }
}

void compute (FILE * fout)
{
    moment * currentMoment = firstM;
    customer * currentCustomer = firstC;
    int amount = 0, seconds = 0;
    while (currentMoment != NULL)
    {
        while (currentCustomer != NULL && seconds + currentCustomer->sec <= currentMoment->time)
        {
            seconds += currentCustomer->sec;
            amount += currentCustomer->money;
            customer * newC = currentCustomer;
            currentCustomer = currentCustomer->next;
            free (newC);
        }
        fprintf (fout, "After %d seconds: %d\n", currentMoment -> time, amount);
        moment * newM = currentMoment;
        currentMoment = currentMoment->next;
        free (newM);
    }
}

int main ()
{
    FILE * fin = fopen ("input1.dat", "r");
    FILE * fout = fopen ("output1.dat", "w");
    initializeM ();
    initializeC ();
    readMoments (fin);
    readCustomers (fin);
    compute (fout);

    return 0;
}
