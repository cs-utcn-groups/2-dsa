//
// Created by csatl on 2/27/2020.
//

#include "sll.h"

void InitializeSll()
{
    first = NULL;
    last = NULL;
}

void AL(int key)
{
    if(first == NULL)
    {
        first = (NodeT*)malloc(sizeof(NodeT));
        first -> next = last;
        first -> data = key;
        last = first;
    }
    else
    {
        NodeT * newElement = (NodeT*)malloc(sizeof(NodeT));
        last->next = newElement;
        newElement->next = NULL;
        newElement->data = key;
        last = newElement;
        last->next = NULL;
    }
}

void AF(int key)
{
    if(first == NULL)
    {
        first = (NodeT*)malloc(sizeof(NodeT));
        first -> next = last;
        first -> data = key;
        last = first;
    }
    else
    {
        NodeT * newElement = (NodeT*)malloc(sizeof(NodeT));
        newElement->next = first;
        newElement->data = key;
        first = newElement;
    }
}

void DF()
{
    NodeT * currentElement;
    currentElement = first;
    first = first->next;
    free(currentElement);
}
void DL()
{
    NodeT * currentElement;
    currentElement = first;
    if(first == NULL)
    {
        //printf("%d",last->data);
        return;
    }
    while(currentElement->next->next != NULL)
    {
        currentElement = currentElement->next;
    }
    free(last);
    last = currentElement;
    last->next = NULL;
}

void PRINT_ALL()
{
    NodeT * currentElement = first;
    FILE * outF;
    outF = fopen(OUTPUT_FILE_PATH,"a");
    while(currentElement != NULL)
    {
        fprintf(outF,"%d ",currentElement->data);
        currentElement = currentElement->next;
    }
    fprintf(outF,"\n");
    fclose(outF);
}

void PrintList()
{
    NodeT * currentElement = first;
    while(currentElement != NULL)
    {
        printf("%d ",currentElement->data);
        currentElement = currentElement->next;
    }
    printf("\n");
}

void DE(int key)
{
    NodeT * currentElement;
    currentElement = first;
    while(currentElement != NULL)
    {
        if(currentElement->data == key)
        {
            if (currentElement == first)
            {
                DF();
                currentElement = first;
            }
            else
            {
                NodeT *removeEelement;
                if (currentElement->next->data == key) {
                    removeEelement = currentElement->next;
                    if (removeEelement == last) {
                        last = currentElement;
                    }
                    currentElement->next = currentElement->next->next;
                    free(removeEelement);
                }
            }
        }
        //PrintList();
        currentElement = currentElement->next;
    }
}
void PRINT_F(int nr)
{
    FILE * outF = fopen(OUTPUT_FILE_PATH,"a");
    NodeT * currentElement = first;
    while(currentElement != NULL && nr!=0)
    {
        fprintf(outF,"%d ",currentElement->data);
        nr--;
        currentElement = currentElement->next;
    }
    fprintf(outF,"\n");
    fclose(outF);
}
void PRINT_L(int nr)
{
    FILE * outF = fopen(OUTPUT_FILE_PATH,"a");
    NodeT * currentElement = first;
    if(nr<ListLength())
        nr = ListLength() - nr ;
    else
        nr = 0;
    int cnt = 0;
    while(currentElement != NULL)
    {
        if(cnt >= nr)
            fprintf(outF,"%d ",currentElement->data);
        cnt = cnt + 1;
        currentElement = currentElement->next;
    }
    fprintf(outF,"\n");
    fclose(outF);
}
int ListLength()
{
    int nr = 0;
    NodeT * q = first;
    while(q != NULL)
    {
        nr++;
        q = q->next;
    }
    return nr;
}
void removeAll()
{
    NodeT * currentElement = first;
    while(currentElement != NULL)
    {
        DF();
        currentElement = first;
    }
    InitializeSll();
}