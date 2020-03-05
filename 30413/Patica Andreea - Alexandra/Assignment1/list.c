#include "list.h"
#include <string.h>

void Initialize()
{
    First = NULL;
    Last = NULL;
}

void AddFirst(int Value);
void AddLast(int Value);
void DeleteFirst();
void DeleteLast();
void DoomList();
void DeleteValue(int Value);
void PrintAll();
void PrintFirst(int Value);
void PrintLast(int Value);

void ParseString (char *StrBuf)
{
    char *token = strtok(StrBuf, " ");
    char *function = (char*)malloc(sizeof(char)*20);
    int value;

    strcpy(function, token);
    token = strtok(NULL, " ");

    if (token!=NULL)
    {
        value = atoi(token);
    }
    else
    {
        int i=0;
        while (function[i]!=NULL)
        {
            i++;
        }
        function[i-1]=NULL;
    }

    if (strcmp("AF", function) == 0)
    {
        AddFirst(value);
    }
    else if (strcmp("AL", function) == 0)
    {
        AddLast(value);
    }
    else if (strcmp("DF", function) == 0)
    {
        DeleteFirst();
    }
    else if (strcmp("DL", function) == 0)
    {
        DeleteLast();
    }
    else if (strcmp("DOOM_THE_LIST", function) == 0)
    {
        DoomList();
    }
    else if (strcmp("DE", function) == 0)
    {
        DeleteValue(value);
    }
    else if (strcmp("PRINT_ALL", function) == 0)
    {
        PrintAll();
    }
    else if (strcmp("PRINT_F", function) == 0)
    {
        PrintFirst(value);
    }
    else if (strcmp("PRINT_L", function) == 0)
    {
        PrintLast(value);
    }
}

void AddFirst(int Value)
{
    NODE *node = (NODE*)malloc(sizeof(NODE));
    node->Value = Value;
    node->next = First;
    if (First == NULL)
    {
        First = node;
        Last=First;
    }
    else
    {
        First = node;
    }
}

void AddLast (int Value)
{
    NODE *node = (NODE*)malloc(sizeof(NODE));
    node->Value = Value;
    node->next = NULL;
    Last->next = node;
    Last = node;
    if (First == NULL)
    {
        First = Last;
    }
}

void DeleteFirst()
{
    if (First != NULL)
    {
        NODE* node = First;
        if (Last == First)
        {
            Last = NULL;
        }
        First = First->next;
        free(node);
    }
}

void DeleteLast()
{
    if (First!=NULL)
    {
        NODE *temp = First;
        while (temp->next != Last)
        {
            temp = temp->next;
        }
        free(Last);
        Last = temp;
        Last->next = NULL;
    }
}

void DoomList()
{
    NODE *node = First;
    while (node!=NULL)
    {
        First = First->next;
        free(node);
        node=First;
    }
}

void DeleteValue (int Value)
{
    NODE *prev, *current;
    prev = current = First;

    while (current != NULL)
    {
        if (current->Value == Value)
        {
            if (current == First)
            {
                First = First->next;
            }
            else if (current == Last)
            {
                Last = prev;
                Last->next = NULL;
            }
            else
            {
                prev->next = current->next;
            }
            prev = current;
            current = current->next;
            free(prev);
            prev = current;
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }
}

void PrintAll()
{
    FILE *g = fopen("output.dat", "a");
    NODE* node = First;

    while (node != NULL)
    {
        fprintf(g, "%d ", node->Value);
        node = node->next;
    }
    fprintf(g, "\n");
    fclose(g);
}

void PrintFirst(int Value)
{
    FILE *g = fopen("output.dat", "a");

    NODE *node = First;
    while (Value != 0 && node!=NULL)
    {
        fprintf(g, "%d ", node->Value);
        Value--;
        node = node->next;
    }
    fprintf(g, "\n");
    fclose(g);
}

void PrintLast(int Value)
{
    FILE *g = fopen("output.dat", "a");
    NODE *current = First;
    NODE *prev = First;

    int tempValue = 0;

    while (current != NULL)
    {
        tempValue++;
        if (tempValue > Value)
        {
            tempValue--;
            prev = prev->next;
        }
        current = current->next;
    }

    while (prev != NULL)
    {
        fprintf(g, "%d ", prev->Value);
        prev = prev->next;
    }
    fprintf(g, "\n");
    fclose(g);
}
