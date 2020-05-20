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
    (*p)->Next = NULL;
}
void Insert(char *Key)
{
    NodeT *p = (NodeT*)malloc(sizeof(NodeT));
    if(p != NULL)
    {
        FillNode(&p, Key);
        int index = GetIndex(p->Key);
        if (BucketTable[index] == NULL)
        {
            BucketTable[index] = p;
            p->Next = NULL;
        }
        else
        {
            NodeT *node = BucketTable[index];
            while (node->Next != NULL)
            {
                node = node->Next;
            }
            node->Next = p;
        }
    }
    else
    {
        return;
    }
}


void Delete(char *Key)
{
    int index = GetIndex(Key);
    NodeT *node = BucketTable[index];

    if (strcmp(node->Key, Key) == 0)
    {
         BucketTable[index] = node->Next;
         free(node->Key);
         free(node);
    }
    else
    {
        while (node != NULL && strcmp(node->Next->Key, Key)!= 0)
        {
            node = node->Next;
        }
        NodeT *temp = node->Next;
        node->Next = temp->Next;
        free(temp->Key);
        free(temp);
    }
}

int Find(char *Key)
{
    int index = GetIndex(Key);
    NodeT *node = BucketTable[index];

    if (strcmp(node->Key, Key) == 0)
    {
        return index;
    }
    else
    {
        while (node != NULL && strcmp(node->Next->Key, Key)!= 0)
        {
            node = node->Next;
        }

        if (node != NULL)
        {
            return index;
        }
        else
        {
            return -1;
        }
    }
}


void Print(FILE *g)
{
    for (int i=0; i<MAX_LENGTH; i++)
    {
        if (BucketTable[i] != NULL)
        {
            fprintf(g, "Bucket for hash value %d: ", i);
            NodeT *node = BucketTable[i];
            while (node != NULL)
            {
                fprintf(g, "%s ", node->Key);
                node = node->Next;
            }

            fprintf(g, "\n");
        }
    }
}
