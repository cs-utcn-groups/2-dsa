#include "header.h"
#include <string.h>

void Initialize()
{
    Sentinel = (SENTINEL*)malloc(sizeof(SENTINEL));
    Sentinel->First = NULL;
    Sentinel->Last = NULL;
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
    char *token = strtok(StrBuf, " \n");
    char *function = (char*)malloc(sizeof(char)*20);
    int value;

    strcpy(function, token);
    token = strtok(NULL, " \n");

    if (token!=NULL)
    {
        value = atoi(token);
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
    node->next = Sentinel->First;
    if (Sentinel->First == NULL)
    {
        Sentinel->First = node;
        Sentinel->Last=Sentinel->First;
    }
    else
    {
        Sentinel->First->prev = node;
        Sentinel->First = node;
    }
}

void AddLast (int Value)
{
    NODE *node = (NODE*)malloc(sizeof(NODE));
    node->Value = Value;
    node->next = NULL;
    node->prev = Sentinel->Last;
    Sentinel->Last->next = node;
    Sentinel->Last = node;
    if (Sentinel->First == NULL)
    {
        Sentinel->First = Sentinel->Last;
    }
}

void DeleteFirst()
{
    if (Sentinel->First != NULL)
    {
        NODE* node = Sentinel->First;
        if (Sentinel->Last == Sentinel->First)
        {
            Sentinel->Last = NULL;
        }
        Sentinel->First = Sentinel->First->next;
        Sentinel->First->prev = NULL;
        free(node);
    }
}

void DeleteLast()
{
    if (Sentinel->First != NULL)
    {
        NODE *temp = Sentinel->Last;
        Sentinel->Last = Sentinel->Last->prev;
        Sentinel->Last->next = NULL;
        free(temp);
    }
}

void DoomList()
{
    NODE *node = Sentinel->First;
    while (node!=NULL)
    {
        Sentinel->First = Sentinel->First->next;
        free(node);
        node=Sentinel->First;
    }
}

void DeleteValue (int Value)
{
    NODE *current;
    current = Sentinel->First;

    while (current != NULL)
    {
        if (current->Value == Value)
        {
            if (current == Sentinel->First)
            {
                Sentinel->First = Sentinel->First->next;
            }
            else if (current == Sentinel->Last)
            {
                Sentinel->Last = current->prev;
                Sentinel->Last->next = NULL;
            }
            else
            {
                current->prev = current->next;
            }
            current = current->next;
            free(current->prev);
        }
        else
        {
            current = current->next;
        }
    }
}

void PrintAll()
{
    FILE *g = fopen("output.dat", "a");
    NODE* node = Sentinel->First;

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

    NODE *node = Sentinel->First;
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

    NODE *node = Sentinel->Last;
    int temp = Value;
    while (temp != 0 && node!=NULL)
    {
        temp--;
        node = node->prev;
    }
    node = node->next;
    while (Value>0)
    {
        fprintf(g, "%d ", node->Value);
        node = node->next;
        Value--;
    }
    fprintf(g, "\n");
    fclose(g);
}
