#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int weight;
    int value;
}Items;

Items *readItems(int n,FILE *f)
{
    Items *item = (Items*)malloc(sizeof(Items));
    int i;
    for(i=0;i<n;i++)
    {
        fscanf(f, "%d", &item[i].weight);
        fscanf(f, "%d", &item[i].value);
    }
    return item;
}

void order(Items *it, int n)
{
    int i,ok=0;
    Items aux;
    while(ok==0)
    {
        ok=1;
        for(i=0;i<n-1;i++)
        {
            if(it[i].weight < it[i+1].weight)
            {
                aux=it[i];
                it[i]=it[i+1];
                it[i+1]=aux;
                ok=0;
            }
        }
    }
}

Items *Greedy(Items *it, int n, int W, int *m)
{
    Items *B = (Items*)malloc(sizeof(Items));
    int i,j=0;
    order(it,n);
    for(i=0; i<n && W>0 ; i++)
    {
        if(it[i].weight <= W)
        {
            B[j++]=it[i];
            W=W-it[i].weight;
            printf("%d\n",W);
        }
    }
    *m=j;
    return B;
}

int main()
{
    FILE *f=fopen("input.txt","r");
    int n,W,m=0,i;
    fscanf(f,"%d",&n);
    fscanf(f,"%d",&W);
    Items *it = readItems(n,f);
    Items *knapsack=Greedy(it,n,W,&m);
    for(i=0; i<m; i++)
    {
        printf("%d %d \n",knapsack[i].weight,knapsack[i].value);
    }
    fclose(f);
    return 0;
}
