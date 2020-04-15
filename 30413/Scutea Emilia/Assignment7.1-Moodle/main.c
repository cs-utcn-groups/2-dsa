#include <stdio.h>
#include <stdlib.h>
typedef struct list
{
    int weight,value;
} List;
List * array;
int nrOfElements;
int W;
List *  readList(FILE * f)
{
    int i,n,w;
    fscanf(f,"%d",&n);
    fscanf(f,"%d",&w);
    W=w;
    nrOfElements=n;
    List * array=(List*)malloc(sizeof(List)*n);
    for(i=0; i<n; i++)
    {
        fscanf(f,"%d",&array[i].weight);
        fscanf(f,"%d",&array[i].value);

    }
    return array;
}

void printList(List * array)
{
    printf("The number of objects is %d and the maximum weight is %d.\nThe objects are:\n",nrOfElements,W);
    for(int i=0; i<nrOfElements; i++)
    {
        printf("Object %d with weight %d and value %d.\n",i+1,array[i].weight,array[i].value);
    }
}

void descendingOrder(List * array)
{
    int done=0;
    List * aux=(List*)malloc(sizeof(List)*nrOfElements);
    while(done!=1)
    {
        done=1;
        for(int i=0; i<nrOfElements-1; i++)
            if(array[i].value<array[i+1].value)
            {
                *aux=array[i];
                array[i]=array[i+1];
                array[i+1]=*aux;
                done=0;
            }
    }
}
void maximumLoad1(List * array)
{
    int i,totalValue=0,totalWeight=0;
    for(i=0;i<nrOfElements;i++)
    {
        if(array[i].weight+totalWeight<W)
        {
            totalWeight=totalWeight+array[i].weight;
            totalValue=totalValue+array[i].value*array[i].weight;
        }

    }
    printf("\n0-1: Total weight %d, total value %d.\n",totalWeight,totalValue);
}
void maximumLoad2(List * array)
{
    int i,totalValue=0,totalWeight=0;
    for(i=0;i<nrOfElements;i++)
    {
        while(array[i].weight>0)
        {
            if(totalWeight+1<=W)
            {
                totalWeight++;
                totalValue=totalValue+array[i].value;
            }
            array[i].weight--;
        }
    }
    printf("\nFractional problem: Total weight %d, total value %d.\n",totalWeight,totalValue);
}
int main()
{
    FILE * f=fopen("input.dat","r");
    List * array=readList(f);
    printList(array);
    descendingOrder(array);
    maximumLoad1(array);
    maximumLoad2(array);
}
