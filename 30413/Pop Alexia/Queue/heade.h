#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void initializeList ();
void addelementf(int rubles,int time);
int sum(int x);
void print(FILE *g,int vec[200],int i);
typedef struct queuee
{
    struct queuee * next;
    struct queuee * prev;
    int rubles;
    int time;
    int sumr;
    int sumt;
} Q;

Q* first, * last;

