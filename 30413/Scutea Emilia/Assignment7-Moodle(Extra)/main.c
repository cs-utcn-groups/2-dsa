#include <stdio.h>
#include <stdlib.h>
typedef struct work
{
    int time,cost,speed;
} Worker;
Worker * array;
int nrOfWorkers,nrOfUnits;

void readArray(FILE * f)
{
    int n,d,i;
    fscanf(f,"%d",&n);
    fscanf(f,"%d",&d);
    nrOfUnits=d;
    nrOfWorkers=n;
    array=(Worker*)malloc(sizeof(Worker)*nrOfWorkers);
    for(i=0; i<nrOfWorkers; i++)
    {
        fscanf(f,"%d",&array[i].time);
        fscanf(f,"%d",&array[i].cost);
        fscanf(f,"%d",&array[i].speed);
    }
}
void printArray()
{
    for(int i=0; i<nrOfWorkers; i++)
        printf("%d %d %d\n",array[i].time,array[i].cost,array[i].speed);
}

void orderAscendingTime()
{
    int i,done=0;
    Worker * aux=(Worker*)malloc(sizeof(Worker));
    while(done!=1)
    {
        done=1;
        for(i=0; i<nrOfWorkers-1; i++)
            if(array[i].time>array[i+1].time)
            {
                *aux=array[i];
                array[i]=array[i+1];
                array[i+1]=*aux;
                done=0;
            }
    }
}
void minPaintingCost()
{
    int minCost=0,unitsPainted=0,i;
    for(i=0; i<nrOfWorkers; i++)
        if(array[i].speed<nrOfUnits)
            if(unitsPainted+1<nrOfUnits && array[i].speed>0)
            {
                while(unitsPainted+1<nrOfUnits && array[i].speed>0)
                {
                    unitsPainted++;
                    array[i].speed--;
                }
                minCost=minCost+array[i].cost;
            }
    printf("Minimum cost: %d",minCost);
}
int main()
{
    FILE * f=fopen("input.dat","r");
    readArray(f);
    orderAscendingTime();
    printArray();
    minPaintingCost();
}
