#include "header.h"

void read(FILE * in)
{
    int nrItems;
    fscanf(in,"%d",&nrItems);
    fscanf(in,"%d",&capacity);

    objectStructure * item=(objectStructure *) malloc(sizeof(objectStructure) * nrItems);

    for(int i=0; i<nrItems; i++)
    {
        fscanf(in,"%d",&item[i].weight);
        fscanf(in,"%d",&item[i].value);
        item[i].dividedValue=(float) item[i].weight/item[i].value;

        totalWeight+=item[i].weight;
    }

    objectStructure * splittedItem=splitIntoPieces(item,nrItems);

    dynamicProgramming(splittedItem,newNrItems,capacity);

    free(item);
    fclose(in);
}

void dynamicProgramming(objectStructure * item,int nrItems,int capacity)
{
    float ** matrix=(float **) malloc(sizeof(float *) * nrItems);

    for(int i=0; i<nrItems; i++)
    {
        matrix[i]=(float *) calloc(capacity+1,sizeof(float));
    }

    for(int i=0; i<nrItems; i++)
    {
        for(int j=1; j<=capacity; j++)
        {
                if(i-1>=0)
                {
                    if(j-1>=1)
                    {
                        matrix[i][j]=maxi(matrix[i-1][j],item[i].dividedValue+matrix[i-1][j-1]);
                    }
                    else
                    {
                        matrix[i][j]=maxi(matrix[i-1][j],item[i].dividedValue);
                    }
                }
                else
                {
                    matrix[i][j]=item[i].dividedValue;
                }
            ///  outputMatrix(matrix,nrItems,capacity);
        }
    }

    printf("value: %f",matrix[nrItems-1][capacity]);
}

void outputMatrix(float ** matrix, int rows, int collumns)
{

    for(int i=0; i<rows; i++)
    {
        for(int j=1; j<=capacity; j++)
        {
            printf("%d   ",matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n");
}

float maxi(float a, float b)
{
    if(a>b)
    {
        return a;
    }

    return b;
}

objectStructure * splitIntoPieces(objectStructure * item, int nrItems)
{
    objectStructure * splittedItem=(objectStructure *) malloc(sizeof(objectStructure) * totalWeight);

    for(int i=0; i<nrItems; i++)
    {
        for(int j=0; j<item[i].weight; j++)
        {
            splittedItem[newNrItems++].dividedValue=item[i].dividedValue;
        }
    }

    return splittedItem;
}
