//
// Created by Andreea on 3/2/2020.
//
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "SLL.h"

country* strongestCountry()
{
    int maxDamage = -1, damage;
    country *currentCountry = firstCountry;
    country *maxCountry = firstCountry;
    while(currentCountry != NULL)
    {
        wave *currentWave = currentCountry->first;
        damage = 0;
        while(currentWave != NULL)
        {
            damage+=currentWave->damage;
            currentWave = currentWave->next;
        }
        if(damage > maxDamage)
        {
            maxDamage = damage;
            maxCountry = currentCountry;
        }
        currentCountry = currentCountry->next;
    }
    return maxCountry;
}
country* weakestCountry()
{
    int minDamage = INT_MAX, damage;
    country* minCountry = firstCountry;
    country *currentCountry = firstCountry;
    while(currentCountry != NULL)
    {
        wave *currentWave = currentCountry->first;
        damage = 0;
        while(currentWave != NULL)
        {
            damage+=currentWave->damage;
            currentWave = currentWave->next;
        }
        if(damage <= minDamage)
        {
            minDamage = damage;
            minCountry = currentCountry;
        }
        currentCountry = currentCountry->next;
    }
    return minCountry;
}

char* canDefeat(country *maxCountry)
{
    int defeatedSentinels = 0;
    sentinel *currentSentinel = firstSentinel;
    currentSentinel-> remainingLifePoints = currentSentinel->lifePoints;
    wave *currentWave = maxCountry->first;
    while(currentSentinel != NULL && currentWave != NULL)
    {
        int difference = currentSentinel->remainingLifePoints - currentWave->damage;
        if(difference <= 0)
        {
            defeatedSentinels++;
            currentSentinel = currentSentinel->next;
            if(currentSentinel != NULL)
            {
                currentSentinel->remainingLifePoints = currentSentinel->lifePoints;
                while (difference + currentSentinel->remainingLifePoints <= 0)
                {
                    defeatedSentinels++;
                    difference += currentSentinel->remainingLifePoints;
                    currentSentinel = currentSentinel->next;
                    if(currentSentinel != NULL)
                        currentSentinel->remainingLifePoints = currentSentinel->lifePoints;
                }
                if(currentSentinel != NULL)
                {
                    currentSentinel->remainingLifePoints += difference;
                    currentWave = currentWave->next;
                }
            }
        }
        else
        {
            currentSentinel->remainingLifePoints -= currentWave->damage;
            currentWave = currentWave->next;
        }
    }
    if(currentSentinel == NULL)
        return strcat(strcat("Country ", maxCountry->name), " could have defeated all the sentinels by itself\n");
    else
    {
        char format[] = "No country could have defeated all the sentinels.\n%s could have brought down the first %d sentinels and would have had chipped off %d life points from sentinel %d.";
        char returnString[MAX_LINE];
        sprintf(returnString, format, maxCountry->name, defeatedSentinels, currentSentinel->lifePoints - currentSentinel->remainingLifePoints, defeatedSentinels+1);
        return returnString;
    }
}

int kill(country **lastHitCountry)
{
    int sentinelSum = 0;
    sentinel *currentSentinel = firstSentinel;
    while(currentSentinel != NULL)
    {
        sentinelSum += currentSentinel->lifePoints;
        currentSentinel = currentSentinel->next;
    }
    country *currentCountry = firstCountry;
    while(firstCountry != NULL && sentinelSum > 0)
    {
        sentinelSum -= currentCountry->first->damage;
        if(sentinelSum <= 0)
        {
            *lastHitCountry = currentCountry;
        }
        else
        {
            if(currentCountry->first == currentCountry->last)
            {
                country *nextCountry = currentCountry->next;
                deleteWave(currentCountry);
                currentCountry = nextCountry;
            }
            else
            {
                deleteWave(currentCountry);
                currentCountry = currentCountry->next;
            }
            if(currentCountry == NULL)
                currentCountry = firstCountry;
        }
    }
    if(sentinelSum <= 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}