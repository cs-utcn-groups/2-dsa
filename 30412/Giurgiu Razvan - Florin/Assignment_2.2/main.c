#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define file_in "../input.dat"
#define file_out "../output.dat"

int main() {
    FILE *outputFile, *inputFile;
    char name[25];
    int money = 0,timePassed=0,time,askedTimes[100],i=0,k=0,moneyCollected=0,t;
    outputFile = fopen(file_out, "w");
    if (outputFile == NULL) {
        perror("File could not be open");
        exit(-1);
    }
    inputFile = fopen(file_in, "r");
    if (inputFile == NULL) {
        perror("File could not be open");
        exit(-1);
    }

    initialize();
    while(fscanf(inputFile,"%d",&askedTimes[k])) k++;
    while(fscanf(inputFile,"%s %d %d",name,&money,&time)!=EOF)
    {
        add(name,money,time,&timePassed,&moneyCollected);
         employ[i].money=moneyCollected;
         employ[i].time=timePassed;
         i++;
    }
    t=i;


        /*for(int j=0 ; j<t ;j++)
           printf("After %d seconds: %d\n",employ[j].time,employ[j].money);*/

    int j=0;
    for(int i=0;i<k;i++)
    {
        j=0;
        while(employ[j].time<=askedTimes[i]) j++;
        j--;
        printf("After %d seconds: %d\n",askedTimes[i],employ[j].money);
    }
    return 0;
}