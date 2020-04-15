#include "header.h"

void read(FILE * in)
{
    fscanf(in,"%d",&nrItems);
    fscanf(in,"%d",&capacity);

    objectStructure * item=(objectStructure *) malloc(sizeof(objectStructure) * nrItems);

    for(int i=0; i<nrItems; i++)
    {
        fscanf(in,"%d",&item[i].weight);
        fscanf(in,"%d",&item[i].value);
    }

    /// item=sortt(item,nrItems);
    /// greedy(item,nrItems,capacity);
    dynamicProgramming(item,nrItems,capacity);

    free(item);
    fclose(in);
}


void dynamicProgramming(objectStructure * item,int nrItems,int capacity)
{
    int ** matrix=(int **) malloc(sizeof(int *) * nrItems);

    for(int i=0; i<nrItems; i++)
    {
        matrix[i]=(int *) calloc(capacity+1,sizeof(int));
    }

    for(int i=0; i<nrItems; i++)
    {
        for(int j=1; j<=capacity; j++)
        {
            if(item[i].weight>capacity)
            {
                if(i-1>=0)
                {
                    matrix[i][j]=matrix[i-1][j];
                }
                else
                {
                    matrix[i][j]=0;
                }
            }

            else
            {
                if(i-1>=0)
                {
                    /// printf("%d\n",j-item[i].weight);

                    if(j-item[i].weight>=1)
                    {
                        matrix[i][j]=maxi(matrix[i-1][j],item[i].value+matrix[i-1][j-item[i].weight]);
                    }
                    else
                    {
                        matrix[i][j]=maxi(matrix[i-1][j],item[i].value);
                    }
                }
                else
                {
                    matrix[i][j]=item[i].value;
                }
            }
          ///  outputMatrix(matrix,nrItems,capacity);
        }
    }

    printf("value: %d",matrix[nrItems-1][capacity]);
}

void outputMatrix(int ** matrix, int rows, int collumns)
{

    for(int i=0;i<rows;i++)
    {
        for(int j=1;j<=capacity;j++)
        {
            printf("%d   ",matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n");
}

int maxi(int a, int b)
{
    if(a>b)
    {
        return a;
    }

    return b;
}


objectStructure * sortt(objectStructure * item,int nrItems)
{
    for(int i=0; i<nrItems-1; i++)
    {
        for(int j=i+1; j<nrItems; j++)
        {
            if(item[i].value<item[j].value)
            {
                objectStructure aux=item[i];
                item[i]=item[j];
                item[j]=aux;
            }
        }
    }

    return item;
}

void greedy(objectStructure * item,int nrItems,int capacity)
{
    int value=0;
    int auxCap=capacity;

    for(int i=0; i<nrItems; i++)
    {
        if(auxCap>0)
        {
            auxCap-=item[i].weight;
            value+=item[i].value;
        }
    }

    printf("%d %d",capacity-auxCap,value);
}
