#include<stdio.h>
#include<stdlib.h>


void Initialize_Q();
void Add_Customer(int,int);
void Add_Time(int);
int Nr_of_Rubles(int);

typedef struct Times
{
    int sec;
    struct Times *next;
}TimeT;

TimeT *first_t,*last_t;

typedef struct Customer
{
    int rubles;
    int seconds;
    struct Customer *next;
}CustomerT;

CustomerT *first_cust,*last_cust;
