#include <stdio.h>
#include "tasks.h"
#define INPUT_FILE_NAME "../input.dat"
#define OUTPUT_FILE_NAME "../output.dat"

int main() {
    //read data
    FILE * fIn = openFile(INPUT_FILE_NAME,"r");
    int N, resistance;
    int * sentinels = getEnemyData(fIn, &N, &resistance);
    int M;
    RebelT * countries = getRebelsData(fIn, &M);
    fclose(fIn);
    //perform tasks
    FILE * fOut = openFile(OUTPUT_FILE_NAME,"w");
    // attack
    rebellion(fOut, M, countries, resistance);
    //measure strength;
    int maxPower = 0;
    int strongestCountry = findStrongest(M, countries, &maxPower);
    if (strongestCountry > -1) {
        fprintf(fOut, "The strongest country was: %s.\n", countries[strongestCountry].name);
    }
    int weakestCountry = findWeakest(M, countries);
    if (weakestCountry > -1) {
        fprintf(fOut, "The weakest country was: %s.\n", countries[weakestCountry].name);
    }
    // can the enemy be defeated alone?
    defeatAlone(fOut, N, sentinels, resistance, countries[strongestCountry],maxPower);
    fclose(fOut);
    return 0;
}