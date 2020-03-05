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
void addCountry(char *name)
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
void deleteCountry(country *deletedCountry)
{
    if(deletedCountry == firstCountry)
    {
        country *tempNext = deletedCountry->next;
        free(deletedCountry);
        firstCountry = tempNext;
        if(firstCountry == NULL)
        {
            lastCountry = NULL;
        }
    }
    else
    {
        country *currentElement = firstCountry;
        while(currentElement-> next != deletedCountry)
        {
            currentElement = currentElement->next;
        }
        country *tempNext = deletedCountry->next;
        free(deletedCountry);
        currentElement->next = tempNext;
        if(currentElement->next == NULL)
        {
            lastCountry = currentElement;
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
        deleteCountry(currentCountry);
    }
}