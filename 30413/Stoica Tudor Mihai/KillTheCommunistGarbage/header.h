#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAXIMUM_NR_OF_COUNTRIES 105
#define MAXIMUM_LENGTH_COUNTRY_NAME 25
#define MAXIMUM_LENGTH_LINE 205

typedef struct node
{
    struct node * next;
    int info;

} node;

node * firstSentinel=NULL, *lastSentinel=NULL;
// node ** firstCountry, ** lastCountry;
node * firstCountry[MAXIMUM_NR_OF_COUNTRIES], * lastCountry[MAXIMUM_NR_OF_COUNTRIES];

char ** nameOfCountry;
int *totalDmgCountry;
int *totalWavesCountry;

int totalDefenseSentinels;

int nrOfSentinels,nrOfCountries;
int maxDmg=-1,minDmg=1<<30;
int weakestCountryIndex,strongestCountryIndex;
int totalDmgCountries;

void readInput(FILE *f,FILE *o);
void addElementAtEndSentinels(int data);
void addElementAtEndCountry(int data,int index);
void PRINT_ALL(node * first, node * last,FILE *o);
void weakest_strongest_country();
void attackSuccededTask(FILE * o);
int * assignValuesToSentinelsArray(int * v);
void outputStrongestAndWeakest();
void computeWhoCouldWinAlone(FILE *o);

int accessWaveFromCountry(int wave, int countryIndex);

typedef struct countries{
    int totalWaves;
    int totalDmgCountry;
    char *name;
}countries;

countries *country;

void initCountries();
