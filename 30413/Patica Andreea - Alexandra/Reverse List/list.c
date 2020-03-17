#include "header.h"

void Initialize()
{
    First = NULL;
    Last = NULL;
}

void AddValue (int Value)
{
    NODE *node = (NODE*)malloc(sizeof(NODE));
    node->Value = Value;
    node->next = NULL;
    if (Last!=NULL)
    {
        Last->next = node;
    }
    Last = node;
    if (First == NULL)
    {
        First = Last;
    }
}

void ReverseList()
{
    NODE *prev, *current, *next;
    prev = First;
    current = First->next;
    next = current->next;

    prev->next = NULL;

    while (current!=NULL)
    {
            current->next = prev;
            prev = current;
            current = next;

            if (next!=NULL)
            {
                next = next->next;
            }
    }

    NODE *temp = First;
    First = Last;
    Last = temp;
}

void PrintList()
{
    NODE* node = First;

    while (node != NULL)
    {
        printf("%d ", node->Value);
        node = node->next;
    }
}
