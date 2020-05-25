#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct cell
{
    char *Key;
}NodeT;

NodeT *BucketTable[MAX_LENGTH];

void Initialize()
{
    int i;
    for (i=0; i<MAX_LENGTH; i++)
    {
        BucketTable[i] = NULL;
    }
}

int GetIndex(char *Key)
{
    int sum = 0,i;
    int len = strlen(Key);

    for ( i=0; i<len; i++)
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
    int i;
    for (i=0; i<MAX_LENGTH; i++)
    {
        if (BucketTable[i] != NULL)
        {
            fprintf(g, "%s\n", BucketTable[i]->Key);
        }
        else
        {
            fprintf(g, "[ ]\n");
        }
    }
}

int main()
{
    FILE *f = fopen("in.txt", "r");
    FILE *g = fopen("out.txt", "w");

    Initialize();

    char function;
    while (fscanf(f, "%c", &function)>0)
    {
        if (function=='\n') break;
        char *strBuf = (char*)malloc(sizeof(char)*100);
        char aux, *token;

        switch(function)
        {
            case 'i':
                fgets(strBuf,100,f);
                token = strtok(strBuf, "\n");
                Insert(token);
                break;
            case 'd':
                fgets(strBuf,100,f);
                token = strtok(strBuf, "\n");
                Delete(strBuf);
                break;
            case 'f':
                fgets(strBuf,100,f);
                token = strtok(strBuf, "\n");
                int index = Find(token);
                if (index != -1)
                        fprintf(g, "Yes %d\n", index);
                else fprintf(g, "No\n");
                break;
            case 'l':
                fscanf(f, "%c", &aux);
                Print(g);
                fprintf(g, "\n");
                break;
            default: fprintf(g, "Invalid call for function!\n");
                break;
        }
    }

    fclose(f);
    fclose(g);

    return 0;
}
