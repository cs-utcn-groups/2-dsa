#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "SLL.h"
#include "Solve.h"

int main()
{
    FILE *inputFilePtr = fopen("input.dat", "r");
    FILE *outputFilePtr = fopen("output.dat", "w");
    int noOfSentinels, noOfCountries, lifePoints;
    char line[MAX_LINE], *countryName, *waveToken;
    initializeCountry();
    initializeSentinel();
    fscanf(inputFilePtr, "%d", &noOfSentinels);
    for(int i = 0; i < noOfSentinels; i++)
    {
        fscanf(inputFilePtr, "%d", &lifePoints);
        addSentinel(lifePoints);
    }
    addSentinel(1);
    fscanf(inputFilePtr, "%d", &noOfCountries);
    fgetc(inputFilePtr);
    for(int i = 0; i < noOfCountries; i++)
    {
        fgets(line, MAX_LINE, inputFilePtr);
        countryName = strtok(line, " \n");
        addCountry(countryName);
        waveToken = strtok(NULL, " \n");
        while(waveToken != NULL)
        {
            char *restOfLine;
            int waveInt = strtol(waveToken, &restOfLine, 10);
            addWave(waveInt, lastCountry);
            waveToken = strtok(NULL, " \n");
        }
    }
    char strongestC[MAX_NAME], weakestC[MAX_NAME];
    strcpy(strongestC, strongestCountry()->name);
    strcpy(weakestC, weakestCountry()->name);
    char singleWarMessage[MAX_LINE];
    strcpy(singleWarMessage, canDefeat(strongestCountry()));
    country *lastHitCountry;
    int ok = kill(&lastHitCountry);
    if(ok == 1)
    {
        fprintf(outputFilePtr, "The tyrant was killed!\n");
        fprintf(outputFilePtr, "The last hit was done by: %s\n", lastHitCountry->name);
    }
    else
    {
        fprintf(outputFilePtr, "The tyrant was not killed!\n");
    }
    fprintf(outputFilePtr, "The strongest country was: %s\n", strongestC);
    fprintf(outputFilePtr, "The weakest country was: %s\n", weakestC);
    fprintf(outputFilePtr, "%s\n", singleWarMessage);

    return 0;
}