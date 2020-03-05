#include "list.h"
#include <string.h>

void Initialize()
{
    Sentinel = (LIST*)malloc(sizeof(LIST));
    Sentinel->First = NULL;
    Sentinel->Last = NULL;

    Country = (LIST**)malloc(sizeof(LIST*)*MAX_LENGTH);
    for (int i=0; i<MAX_LENGTH; i++)
    {
        Country[i]=(LIST*)malloc(sizeof(LIST));
        Country[i]->First = NULL;
        Country[i]->Last = NULL;
    }
}

void AddLast(LIST *Struct, int Value)
{
    NODE *node = (NODE*)malloc(sizeof(NODE));
    node->Value = Value;
    node->Next = NULL;

    if (Struct->First == NULL)
    {
        Struct->First = node;
        Struct->Last = node;
    }
    else
    {
        Struct->Last->Next = node;
        Struct->Last = node;
    }
}

void ParseString(char *StrBuf, int I)
{
    char *token = strtok(StrBuf, " \n");
    Country[I]->Name = (char*)malloc(sizeof(char)*MAX_LENGTH);
    strcpy(Country[I]->Name, token);

    token = strtok(NULL, " \n");
    Country[I]->Strength = 0;
    while (token!=NULL)
    {
        int val = atoi(token);
        AddLast(Country[I], val);
        Country[I]->Strength+=val;
        token = strtok(NULL, " \n");
    }
}

void AttackSuccess(int M)
{
    FILE *g = fopen("output.dat", "a");

    int sum=0;
    for (int i=0; i<M; i++)
    {
        sum+=Country[i]->Strength;
    }
    if (sum>Sentinel->Strength)
    {
        fprintf(g, "The tyrant was killed!!\n");
    }
    else
    {
        fprintf(g, "The tyrant was not killed..\n");
    }
    fclose(g);
}

void LastHit(int M)
{
    FILE *g = fopen("output.dat", "a");

    int sum = Sentinel->Strength;
    LIST **temp = Country;
    int notNull = 1;
    while (sum>0 && notNull)
    {
        notNull =0;
        for (int i=0; i<M; i++)
        {
            if (temp[i]->First!=NULL)
            {
                notNull=1;
                sum-=temp[i]->First->Value;
                temp[i]->First = temp[i]->First->Next;
            }
            if (sum<=0)
            {
                fprintf(g, "Last hit was done by: %s\n", Country[i]->Name);
                break;
            }
        }
    }
    fclose(g);
}

void StrongestCountry(int M)
{
    FILE *g = fopen("output.dat", "a");

    int Max = 0;
    char *temp = (char*)malloc(sizeof(char)*MAX_LENGTH);
    for (int i=0; i<M; i++)
    {
        if (Country[i]->Strength > Max)
        {
            Max = Country[i]->Strength;
            strcpy(temp, Country[i]->Name);
        }
    }
    fprintf(g, "The strongest country was: %s\n", temp);
    fclose(g);
}

void WeakestCountry(int M)
{
    FILE *g = fopen("output.dat", "a");

    int Min = Country[0]->Strength;
    char *temp = (char*)malloc(sizeof(char)*MAX_LENGTH);
    strcpy(temp, Country[0]->Name);
    for (int i=1; i<M; i++)
    {
        if (Country[i]->Strength < Min)
        {
            Min = Country[i]->Strength;
            strcpy(temp, Country[i]->Name);
        }
    }
    fprintf(g, "The weakest country was: %s\n", temp);
    fclose(g);
}

void DefeatAllSentinels(int M)
{
    FILE *g = fopen("output.dat", "a");

    int Max = 0;
    int temp;
    for (int i=0; i<M; i++)
    {
        if (Country[i]->Strength>= Sentinel->Strength)
        {
            fprintf(g, "%s could have defeated all the sentinels.\n", Country[i]->Name);
            fclose(g);
            return;
        }
        if (Country[i]->Strength > Max)
        {
            Max = Country[i]->Strength;
            temp = i;
        }
    }
    fprintf(g, "No country could have defeated all the sentinels.\n");
    fprintf(g, "%s ", Country[temp]->Name);
    NODE *node = Sentinel->First;
    int sum = Country[temp]->Strength;
    int nrOfSentinels=0;
    int fragmen =0;
    while (sum>=node->Value)
    {
        sum-=node->Value;
        nrOfSentinels++;
        node = node->Next;
    }
    fprintf(g, "Could have brought down the fist %d sentinels ", nrOfSentinels);
    if (sum>0)
    {
        fprintf(g, "and would have chipped off %d life points from sentinel %d.\n", sum, nrOfSentinels+1);
    }

    fclose(g);
}
