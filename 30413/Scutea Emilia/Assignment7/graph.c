#include "header.h"
void readCost(FILE * f)
{
    int n,i,j;
    fscanf(f,"%d",&n);
    nrOfVertixes=n;
    cost=(int**)malloc(sizeof(int*)*nrOfVertixes);
    for(i=0; i<nrOfVertixes; i++)
        *(cost+i)=(int*)malloc(sizeof(int)*nrOfVertixes);
    for(i=0; i<nrOfVertixes; i++)
        for(j=0; j<nrOfVertixes; j++)
            fscanf(f,"%d",&cost[i][j]);

}
void printCost()
{
    printf("The adjacency matrix is:\n");
    for(int i=0; i<nrOfVertixes; i++)
        printf("  %c",i+'A');
    printf("\n");
    for(int i=0; i<nrOfVertixes; i++)
    {
        printf("%c ",i+'A');
        for(int j=0; j<nrOfVertixes; j++)
            printf("%2d ",cost[i][j]);
        printf("\n");
    }
}

