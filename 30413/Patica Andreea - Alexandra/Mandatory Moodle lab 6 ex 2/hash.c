#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <string.h>

void Initialize()
{
    for (int i=0; i<MAX_LENGTH; i++)
    {
        BucketTable[i] = NULL;
    }
}

int GetIndex(char *Key)
{
    int sum = 0;
    int len = strlen(Key);

    for (int i=0; i<len; i++)
    {
        sum += Key[i];
    }
    return (sum % MAX_LENGTH);
}

void FillNode(NodeT **p, char *Key)
{
    (*p)->Key = (char*)malloc(sizeof(char)*MAX_LENGTH);
    strcpy((*p)->Key, Key);
}
void Insert(char *Key)
{
    NodeT *p = (NodeT*)malloc(sizeof(NodeT));
    if(p != NULL)
    {
        FillNode(&p, Key);
        int index = GetIndex(p->Key);
        while (BucketTable[index] != NULL)
        {
            if (strcmp(BucketTable[index]->Key, "--")!=0)
            {
                ++index;
                index %= MAX_LENGTH;
            }
        }

        BucketTable[index] = p;

    }
    else
    {
        return;
    }
}


void Delete(char *Key)
{
    int index = GetIndex(Key);

    while (BucketTable[index] != NULL)
    {
        if (strcmp(BucketTable[index]->Key, Key) == 0)
        {
            strcpy(BucketTable[index]->Key, "--");
            return;
        }

        ++index;
        index %= MAX_LENGTH;
    }
}

int Find(char *Key)
{
    int index = GetIndex(Key);
    while(BucketTable[index] != NULL)
    {
        if (strcmp(BucketTable[index]->Key, Key) == 0)
        {
            return index;
        }

        ++index;
        index %= MAX_LENGTH;
    }

    return -1;
}


void Print(FILE *g)
{
    for (int i=0; i<MAX_LENGTH; i++)
    {
        if (BucketTable[i] != NULL)
        {
            fprintf(g, "%s\n", BucketTable[i]->Key);
        }
        else
        {
            fprintf(g, "--\n");
        }
    }
}
