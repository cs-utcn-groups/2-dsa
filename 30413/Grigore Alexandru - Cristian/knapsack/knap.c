#include "knap.h"

bool cmp(Item *a,Item *b)
{
   double r1=(double)(*a).value/(*a).weight;
   double r2=(double)(*b).value/(*b).weight;
   return r1>r2;
}

void swapLoot(Item *a,Item *b)
{
    Item *aux=a;
    a=b;
    b=aux;
}

void sortLoot(Item *loot,int n)
{
    int ok;
    do
    {
        ok=0;
        for(int i=0;i<n;i++)
        {
            if(cmp(loot+i,loot+i+1)==false)
            {
                swapLoot(loot+i,loot+i+1);
                ok=1;
            }
        }
    }while(!ok);
}

void greedy(Item *loot,int n,int W)
{
    int value=0;
    int weight=0;
    int currentWeight=0;
    double finalValue=0.0;
    for(int i=0;i<n;i++)
    {
        if(loot[i].weight<=W)
        {
            value+=loot[i].value;
            weight+=loot[i].weight;
            currentWeight+=loot[i].weight;
            finalValue+=loot[i].value;
            W-=loot[i].weight;
        }
        else
        {
            currentWeight+=W;
            finalValue+=(double)(W*(loot[i].value/loot[i].weight));
            break;
        }
    }
    printf("\nFor 1-0: %d %d\n",value,weight);
    printf("\nFor fractional loot: %lf %d\n",finalValue,currentWeight);
}
