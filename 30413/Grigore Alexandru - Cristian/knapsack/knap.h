#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int value;
    int weight;
}Item;

bool cmp(Item *a,Item *b);
void swapLoot(Item *a,Item *b);
void sortLoot(Item *loot,int n);
void greedy(Item *loot,int n,int W);
