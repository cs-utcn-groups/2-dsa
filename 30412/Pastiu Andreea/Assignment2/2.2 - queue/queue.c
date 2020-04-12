//
// Created by Andreea on 3/8/2020.
//
#include "queue.h"
void initializeTime()
{
    firstTime = NULL;
    lastTime = NULL;
}
void initializeQueue()
{
    firstQueue = NULL;
    lastQueue = NULL;
}
void addLastTime(int seconds)
{
    timeNode *newNode = (timeNode *) malloc(sizeof(timeNode));
    newNode->seconds = seconds;
    if (firstTime == NULL)
    {
        newNode->next = NULL;
        firstTime = newNode;
        lastTime = newNode;
    }
    else
    {
        lastTime->next = newNode;
        lastTime = newNode;
        lastTime->next = NULL;
    }
}
void addLastQueue(int rubles, int seconds)
{
    queueNode *newNode = (queueNode *) malloc(sizeof(queueNode));
    newNode->rubles = rubles;
    newNode->seconds = seconds;
    if (firstQueue == NULL)
    {
        newNode->next = NULL;
        firstQueue = newNode;
        lastQueue = newNode;
    }
    else
    {
        lastQueue->next = newNode;
        lastQueue = newNode;
        lastQueue->next = NULL;
    }
}
void deleteFirstTime()
{
    timeNode *oldFirst = firstTime;
    if(firstTime != NULL)
    {
        firstTime = firstTime->next;
        free(oldFirst);
    }
    if(firstTime == NULL)
        lastTime = NULL;
}
void deleteFirstQueue()
{
    queueNode *oldFirst = firstQueue;
    if(firstQueue != NULL)
    {
        firstQueue = firstQueue->next;
        free(oldFirst);
    }
    if(firstQueue == NULL)
        lastQueue = NULL;
}
void readData(FILE *ifptr, FILE *ofptr)
{
    char *line, *token, *restOfString;
    if(ifptr == NULL)
        fprintf(ofptr, "No input file");
    else
    {
        line = (char *) malloc(sizeof(char));
        restOfString = (char *) malloc(sizeof(char));
        fgets(line, MAX_LINE, ifptr);
        token = strtok(line, " \n");
        while (token != NULL)
        {
            addLastTime(strtol(token, &restOfString, 10));
            token = strtok(NULL, " \n");
        }
        while (fgets(line, MAX_LINE, ifptr) != NULL)
        {
            int rubles, seconds;
            strtok(line, " \n");
            token = strtok(NULL, " \n");
            rubles = strtol(token, &restOfString, 10);
            token = strtok(NULL, " \n");
            seconds = strtol(token, &restOfString, 10);
            addLastQueue(rubles, seconds);
        }
    }
}
void solve(FILE *ofptr)
{
    int sumOfTime=0, sumOfMoney=0, currentTime;
    while(firstTime != NULL)
    {
        currentTime = firstTime->seconds;
        while (firstQueue != NULL && sumOfTime + firstQueue->seconds <= currentTime)
        {
            sumOfMoney += firstQueue->rubles;
            sumOfTime += firstQueue->seconds;
            deleteFirstQueue();
        }
        fprintf(ofptr, "After %d seconds: %d\n", currentTime, sumOfMoney);
        deleteFirstTime();
    }
}