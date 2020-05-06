#include "head.h"

int main()
{
    FILE *f=fopen("input.in","r");
    FILE *g=fopen("output.out","w");

    int nrOfObjects, maxWeight,weightSack;
    float profit;
    int *weight=initializeArray();
    int *value=initializeArray();
    float *valuePerWeight=initializeFloatArray();
    float *quantity=initializeFloatArray();

    readFile(&nrOfObjects,&maxWeight,weight,value,f);
    valuePerWeightArray(valuePerWeight,weight,value,&nrOfObjects);
    quantityArray(&nrOfObjects,&maxWeight,valuePerWeight,weight,value,quantity);
    computeTheProfit(&profit,quantity,&nrOfObjects,value);
    computeTheWeight(&weightSack,quantity,&nrOfObjects,weight);
    print(g,&weightSack,&profit,quantity,&nrOfObjects);

    return 0;
}
