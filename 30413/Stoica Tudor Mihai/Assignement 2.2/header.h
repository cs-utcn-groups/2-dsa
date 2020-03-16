#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct customers
{
    int money;
    int seconds;
    char * name;
    struct customers * next;
} customers;

typedef struct node
{
    int info;
    struct node * next;
} node;

customers * customerFirst, * customerLast;
node * first, * last;

void initList();
void readInput(FILE * f, FILE * o);
void addElementToEndNode(int data);
void addElementToEndCustomers(char * name, int money, int seconds);
void computeSum();
