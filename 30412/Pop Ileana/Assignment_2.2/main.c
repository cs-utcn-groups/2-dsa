#include <stdio.h>
#include "stdlib.h"
#include "header.h"
#include "input.h"

#define DATA_PATH_IN "../input.dat"
#define DATA_PATH_OUT "../output.dat"

FILE * fin, *fout;

int main() {

    fin=fopen(DATA_PATH_IN,"r");
    if(fin==NULL)
    {
        perror("File could not be opened");
        exit(EXIT_FAILURE);
    }
    fout=fopen(DATA_PATH_OUT,"w");
    if(fout==NULL)
    {
        perror("File could not be opened");
        exit(EXIT_FAILURE);
    }

    int * timeArray=NULL,n,money=0,currentTime=0;

    readTimePeriods(&timeArray,&n,fin);
    initializeSll();
    readCustomers(fin);

    for(int i=0;i<n;i++)
    {
        if(first!=NULL) {
            while (first!=NULL && currentTime + first->y <= timeArray[i]) {
                currentTime = currentTime + first->y;
                money = money + first->x;
                deleteFirst();
            }
        }
        fprintf(fout,"After %d seconds: %d\n",timeArray[i],money);
    }
    free(timeArray);
    fclose(fin);
    fclose(fout);
    return 0;
}
