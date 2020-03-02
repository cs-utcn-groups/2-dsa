//
// Created by Andreea on 3/2/2020.
//
#include <stdlib.h>
#include <string.h>
#include "SLL.h"

void initializeSentinel()
{
    firstSentinel = NULL;
    lastSentinel = NULL;
}
void initializeCountry()
{
    firstCountry = NULL;
    lastCountry = NULL;
}
void addSentinel(int lifePoints)
{
    sentinel *element = (sentinel*)malloc(sizeof(sentinel));
    element->lifePoints = lifePoints;
    if (lastSentinel == NULL)
    {
        element->next = NULL;
        firstSentinel = element;
        lastSentinel = element;
    }
    else
    {
        lastSentinel->next = element;
        lastSentinel = element;
        lastSentinel->next = NULL;
    }
}
void addCountry(char name[])
{
    country *element = (country*)malloc(sizeof(country));
    strcpy(element->name, name);
    if(lastCountry == NULL)
    {
        element->next = NULL;
        firstCountry = element;
        lastCountry = element;
        element->first = NULL;
        element->last = NULL;
    }
    else
    {
        lastCountry->next = element;
        lastCountry = element;
        lastCountry->next = NULL;
        element->first = NULL;
        element->last = NULL;
    }
}
void addWave(int damage, country* currentCountry)
{
    wave *element = (wave*)malloc(sizeof(wave));
    element->damage = damage;
    if(currentCountry->last == NULL)
    {
        element->next = NULL;
        currentCountry->first = element;
        currentCountry->last = element;
    }
    else
    {
        currentCountry->last->next = element;
        currentCountry->last = element;
        currentCountry->last->next = NULL;
    }
}
void deleteCountry(char name[])
{
    country* currentElement = firstCountry;
    country* oldCurrentElement;
    country* previousElement = firstCountry;
    while(currentElement != NULL)
    {
        if(strcmp(currentElement->name, name) == 0)
        {
            if(currentElement == firstCountry)
            {
                country* oldFirst = firstCountry;
                if(firstCountry != NULL)
                {
                    firstCountry = firstCountry->next;
                    free(oldFirst);
                }
                if(firstCountry == NULL)
                    lastCountry = NULL;
                currentElement = firstCountry;
            }
            else
            if(currentElement == lastCountry)
            {
                country* oldLast = lastCountry, *currentElementTemp = firstCountry;
                if(firstCountry == lastCountry)
                {
                    free(firstCountry);
                    firstCountry = NULL;
                    lastCountry = NULL;
                }
                else
                if (lastCountry != NULL)
                {
                    while(currentElementTemp->next != lastCountry)
                        currentElementTemp = currentElementTemp->next;
                    currentElementTemp->next = NULL;
                    lastCountry = currentElementTemp;
                    free(oldLast);
                }
            }
            else
            {
                oldCurrentElement = currentElement;
                previousElement->next = currentElement ->next;
                free(oldCurrentElement);
                previousElement = currentElement;
                currentElement = currentElement->next;
            }
        }
        else
        {
            previousElement = currentElement;
            currentElement = currentElement->next;
        }
    }
}
void deleteWave(country *currentCountry)
{
    wave* oldFirst = currentCountry->first;
    if(currentCountry->first != NULL)
    {
        currentCountry->first = currentCountry->first->next;
        free(oldFirst);
    }
    if(currentCountry->first == NULL)
    {
        currentCountry->last = NULL;
        deleteCountry(currentCountry->name);
    }
}