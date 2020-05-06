#include "head.h"

int *initializeArray()
{
    int *array=(int *)malloc(sizeof(int)*MAX_LENGTH);
    return array;
}

float *initializeFloatArray()
{
    float *array=(float *)malloc(sizeof(float)*MAX_LENGTH);
    return array;
}

void readFile(int *nrOfObjects, int *maxWeight, int *weight, int *value, FILE *f)
{
    fscanf(f,"%d %d",nrOfObjects,maxWeight);

    char *s=(char *)malloc(sizeof(char)*MAX_LENGTH);
    char *token=(char *)malloc(sizeof(char)*MAX_LENGTH);

    int i=0;
    while(fgets(s,MAX_LENGTH,f))
    {
        if(i>0)
        {
            s[strlen(s)-1]='\0';
            token=strtok(s," ");
            weight[i]=atoi(token);
            token=strtok(NULL," ");
            value[i]=atoi(token);
        }

        i++;
    }

}

void valuePerWeightArray(float *valuePerWeight, int *weight, int *value, int *nrOfObjects)
{
    float var,var1,var2;
    for(int i=1; i<=*nrOfObjects; i++)
    {
        var1=value[i];
        var2=weight[i];
        var=var1/var2;
        valuePerWeight[i]=var;
    }
}

float *initializeQuantity(float *quantity, int *nrOfObjects)
{
    for(int i=1;i<=*nrOfObjects;i++)
        quantity[i]=0;
    return quantity;
}

void quantityArray(int *nrOfObjects, int *maxWeight, int *valuePerWeightArray, int *weight, int *value, float *quantity)
{
    int mx=-1,index;
    float var,var1,var2;
    quantity=initializeQuantity(quantity,nrOfObjects);
    while(*maxWeight!=0)
    {
        for(int i=1; i<=*nrOfObjects; i++)
        {
            if(valuePerWeightArray[i]>mx)
            {
                mx=valuePerWeightArray[i];
                index=i;
            }
        }
        valuePerWeightArray[index]=-1;

        if(*maxWeight>=weight[index])
        {
            *maxWeight=*maxWeight-weight[index];
            quantity[index]=1;
        }
        else
        {
            var1=*maxWeight;
            var2=weight[index];
            var=var1/var2;
            quantity[index]=var;
            *maxWeight=0;
        }
        mx=-1;
    }
}

void computeTheProfit(float *profit,float *quantity,int *nrOfObjects, int *value)
{
    *profit=0;

    for(int i=1;i<=*nrOfObjects;i++)
    {
        *profit=*profit+quantity[i]*value[i];
    }
}

void computeTheWeight(int *weightSack, float *quantity, int *nrOfObjects, int *weight)
{
    *weightSack=0;
    for(int i=1;i<=*nrOfObjects;i++)
    {
        *weightSack=*weightSack+quantity[i]*weight[i];
    }
}

void print(FILE *g,int *weightSack, float *profit, float *quantity, int *nrOfObjects)
{
     fprintf(g,"The weight is: %d\n",*weightSack);
     fprintf(g,"The profit is: %0.2f\n",*profit);
     for(int i=1;i<=*nrOfObjects;i++)
        fprintf(g,"%0.2f ",quantity[i]);
}

