#include <stdio.h>
#include<stdlib.h>
#include "sll.h"
#include "input.h"
#include "functions.h"
#include<string.h>

#define DATA_PATH_IN "../input.dat"
#define DATA_PATH_OUT "../output.dat"

FILE * fin, * fout;


int main() {

    fin = fopen(DATA_PATH_IN,"r");
    if(fin==NULL)
    {
        perror("File could not be opened");
        exit(EXIT_FAILURE);
    }
    fout = fopen(DATA_PATH_OUT,"w");

    int noOfSentinels, noOfCountries,totalDamageNeeded=0;

    initialize(firstSentinel,lastSentinel);
    readSentinels(&noOfSentinels, &totalDamageNeeded, fin);
    printf("There are %d sentinels\n",noOfSentinels);
    printSll(firstSentinel,lastSentinel);
    printf("Total damage needed is %d\n",totalDamageNeeded);

    firstCountry=lastCountry=NULL;
    fscanf(fin,"%d",&noOfCountries);
    fgetc(fin);

    firstNodes = createArrayOfNodes(noOfCountries);
    lastNodes = createArrayOfNodes(noOfCountries);
    readCountries(noOfCountries, fin);
    printf("There are %d countries\n",noOfCountries);
    printSll1(firstCountry,lastCountry);

    for(int i=0;i<noOfCountries;i++)
        printSll(firstNodes[i],lastNodes[i]);

    int positionStrongestCountry;
    char * strongest=(char*)malloc(50*sizeof(char));
    strcpy(strongest,strongestCountry(noOfCountries,&positionStrongestCountry));
    char * weakest=(char*)malloc(50*sizeof(char));
    strcpy(weakest,weakestCountry(noOfCountries));

    int allSentinels=verifyIfAllSentinels(totalDamageNeeded,noOfCountries);
    int * characteristicValues = bestCountryOverview(noOfCountries,positionStrongestCountry);
    verifyIfKilled(totalDamageNeeded,noOfCountries,fout);
    findLastHit(noOfSentinels,noOfCountries,fout);
    fprintf(fout,"The strongest country was: %s\n",strongest);
    fprintf(fout,"The weakest country was: %s\n",weakest);
    if(allSentinels==0)
        fprintf(fout,"No country could have defeated all the sentinels.\n");
    fprintf(fout,"%s could have brought down the first %d\nsentinels and would have had chipped off %d\nlife points from sentinel %d.",strongest, characteristicValues[0],characteristicValues[1],characteristicValues[2]);

    return 0;
}
