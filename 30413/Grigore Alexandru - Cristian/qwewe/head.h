#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct seconds{
    int data;
    struct seconds *next;
} SecondsT;

typedef struct customers{
    int roubles,seconds;
    struct customers *next;
} CustomersT;

SecondsT *firstS,*lastS;
CustomersT *firstC,*lastC;

void initializeQwewe();
void AddSeconds(int key);
void AddCustomers(int key,int ss);
int compute(int time);





