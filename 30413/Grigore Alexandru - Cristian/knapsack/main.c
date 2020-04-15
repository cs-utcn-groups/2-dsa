#include <stdio.h>
#include <stdlib.h>
#include "knap.h"



int main()
{
   int n,W;
   printf("Enter nr of items and their weight:\n");
   scanf ("%d %d",&n,&W);
   Item *loot=(Item*)malloc(sizeof(Item)*n);
   for(int i=0;i<n;i++)
   {
       int v,we;
       printf("Value and weight of item %d:",i);
       scanf("%d %d",&v,&we);
       loot[i].value=v;
       loot[i].weight=we;
   }
   sortLoot(loot,n);
   greedy(loot,n,W);
    return 0;
}
