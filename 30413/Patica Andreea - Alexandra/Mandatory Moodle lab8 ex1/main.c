#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int value;
    int weight;
}ITEM;

void swap (ITEM *a, ITEM *b)
{
    ITEM *aux = a;
    a=b;
    b=aux;
}

void sort(ITEM *item, int n)
{
    int ok;
    do
    {
        ok=0;
        for (int i=0; i<n-1; i++)
        {
            if ((item[i].value<item[i+1].value) || (item[i].value<item[i+1].value && item[i].weight>item[i+1].weight))
            {
                swap(item+i,item+i+1);
                ok=1;
            }
        }
    }while(!ok);
}


void Greedy(ITEM *item, int n, int W)
{
    int value = 0;
    int weight = 0;
    double valueFractional = 0.0;
    int weightFractional = 0;
    for (int i=0; i<n; i++)
    {
        if (item[i].weight<=W)
        {
            value +=item[i].value;
            weight += item[i].weight;
            valueFractional +=item[i].value;
            weightFractional += item[i].weight;
            W -= item[i].weight;
        }
        else
        {
            valueFractional += (double)(W*item[i].value)/item[i].weight;
            weightFractional += W;
            break;
        }
    }

    printf("For 1-0: %d %d\n", weight, value);
    printf("For fractional: %d %lf\n", weightFractional, valueFractional);
}


int main()
{
    int n, W;
    scanf("%d%d", &n,&W);
    ITEM *item = (ITEM*)malloc(sizeof(ITEM)*n);
    for (int i=0; i<n; i++)
    {
        int x,y;
        scanf("%d%d", &x, &y);
        item[i].weight = x;
        item[i].value = y;
    }

    sort(item,n);
    Greedy(item,n,W);

    return 0;
}
