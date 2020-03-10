#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initializeList();
void readLists();
void addElementT(char *p,char *strbuf);
void addElementC(char *p,char *strbuf);
void printSums();


typedef struct node
{
    int data;
    struct node *next;
    struct node *previous;
}NodeT;

NodeT *firstT, *lastT;

typedef struct customer
{
    char *name;
    int money;
    int time;
    struct customer *next;
    struct customer *previous;
}NodeC;

NodeC *firstC, *lastC;
