#include <string.h>
#include <stdlib.h>
#include "header.h"

#define MAX_LENGTH 100

void AddLast (int Value);

void Initialize()
{
    First = NULL;
    Last = NULL;
}

void ParseList(char *StrBuf)
{
    char *token = strtok(StrBuf, " \n");

    while (token!=NULL)
    {
        int val = atoi(token);
        AddLast(val);
        token = strtok(NULL, " \n");
    }
}

void AddLast (int Value)
{
    NODE *node = (NODE*)malloc(sizeof(NODE));
    node->Value = Value;
    node->next = NULL;
    if (Last!= NULL)
    {
        Last->next = node;
    }
    Last = node;
    if (First == NULL)
    {
        First = Last;
    }
}

void ComputeMoney(FILE *f, FILE *g)
{
    NODE *node = First;
    char *strBuf = (char*)malloc(sizeof(char)*MAX_LENGTH);
    int totalTime = 0;
    int totalMoney = 0;


    while (fgets(strBuf, MAX_LENGTH, f)!= NULL)
    {
        char *token = strtok(strBuf, " \n");
        token = strtok(NULL, " \n");
        int x = atoi(token);

        token = strtok(NULL, " \n");
        int y = atoi(token);

        totalTime+=y;

        while (node!=NULL && totalTime>node->Value)
        {
            fprintf(g, "After %d seconds: %d\n", node->Value, totalMoney);
            node = node->next;
        }

        totalMoney+=x;
        while (node != NULL && totalTime>=node->Value)
        {
            fprintf(g, "After %d seconds: %d\n", node->Value, totalMoney);
            node = node->next;
        }

    }

    while (node!=NULL)
    {
        fprintf(g, "After %d seconds: %d\n", node->Value, totalMoney);
        node = node->next;
    }
}
