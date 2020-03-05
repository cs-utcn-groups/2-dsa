//
// Created by ileana on 3/2/2020.
//


#include "functions.h"

int sumWavesOfACountry(int i)
{
    int sum=0;
    NodeT * first;
    first=firstNodes[i];
    while(first!=NULL)
    {
        sum=sum+first->capacity;
        first=first->next;
    }
    return sum;
}

void verifyIfKilled(int totalDamageNeeded, int noOfCountries, FILE * fptr)
{
    int totalSum=0;
    for(int i=0;i<noOfCountries;i++)
        totalSum=totalSum+sumWavesOfACountry(i);
    if(totalSum>=totalDamageNeeded)
        fprintf(fptr, "The tyrant was killed!\n");
    else
        fprintf(fptr, "The tyrant was not killed!\n");
}

void findLastHit(int noOfSentinels, int noOfCountries, FILE * fptr)
{
    NodeT * sentinel=firstSentinel;
    char winner[50]="";
    while(firstSentinel!=NULL && noOfCountries!=0)
    {
        for(int j=0;j<noOfCountries;j++)
        {
            if(firstNodes[j]!=NULL) {
                NodeT *wave = firstNodes[j];
                sentinel->capacity = sentinel->capacity - wave->capacity;
                int d = sentinel->capacity;
                if (sentinel->capacity <= 0) {
                    deleteFirstSentinel();
                    d=-d;
                    (wave->next)->capacity = (wave->next)->capacity +d;
                    noOfSentinels--;
                }

                deleteWave(j);
                if(firstSentinel==NULL)
                {
                    int k = 0;
                    NodeT1 *element = firstCountry;
                    while (k != j) {
                        element = element->next;
                        k++;
                    }
                    strcpy(winner,element->country);
                    break;
                }
                if (firstNodes[j] == NULL) {
                    int k = 0;
                    NodeT1 *element = firstCountry;
                    while (k != j) {
                        element = element->next;
                        k++;
                    }
                    removeCountry(element->country);
                    noOfCountries--;
                }
            }
        }
    }
    if(firstSentinel==NULL)
        fprintf(fptr,"The last hit was done by: %s\n",winner);
}

char * strongestCountry(int noOfCountries, int *position)
{
    char * strongest="";
    int maxv=0;
    for(int i=0;i<noOfCountries;i++)
    {
        int s=sumWavesOfACountry(i);
        if(s>maxv)
        {
            maxv=s;
            *position=i;
            int k = 0;
            NodeT1 *element = firstCountry;
            while (k != i) {
                element = element->next;
                k++;
            }
            strcpy(strongest,element->country);
        }
    }
    return strongest;
}
char * weakestCountry(int noOfCountries)
{
    char * weakest="";
    int minv=INT_MAX;
    for(int i=0;i<noOfCountries;i++)
    {
        int s=sumWavesOfACountry(i);
        if(s<minv)
        {
            minv=s;
            int k = 0;
            NodeT1 *element = firstCountry;
            while (k != i) {
                element = element->next;
                k++;
            }
            strcpy(weakest,element->country);
        }
    }
    return weakest;
}

int verifyIfAllSentinels(int totalDamageNeeded, int noOfCountries)
{
    for(int i=0;i<noOfCountries;i++)
        if(sumWavesOfACountry(i)>totalDamageNeeded)
            return 1;
    return 0;
}

int * bestCountryOverview(int noOfCountries, int position)
{
    int * values=(int *)malloc(3*sizeof(int));
    NodeT * element=firstSentinel;
    int noOfSentinelsDefeated=0;
    int sum=sumWavesOfACountry(position);
    while(sum>0)
    {
        if(sum-element->capacity>=0) {
            sum = sum - element->capacity;
            noOfSentinelsDefeated++;
            element = element->next;
        }
        else
        {
            values[0]=noOfSentinelsDefeated;
            values[1]=sum;
            values[2]=++noOfSentinelsDefeated;
            break;
        }
    }
    return values;
}
