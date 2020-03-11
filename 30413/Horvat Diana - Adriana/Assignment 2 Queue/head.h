#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readFile(FILE *f);
void initialize_sec();
void initialize_cus();
void addLast(int data);
void addLastDLL(char *name,int money,int sec);
void cashier_money(FILE *g);


typedef struct sec
{
    int data;
    struct sec *next;
} Sec;
Sec *first_sec, *last_sec;

typedef struct node
{
    char *name;
    int money, sec;
    struct node *prev;
    struct node *next;
} Node;
Node *first_cus, *last_cus;
