#include "dll.h"

void InitializeDll()
{
    dL.first = NULL;
    dL.last = NULL;
}

void AL(int key)
{
    if(dL.first == NULL)
    {
        dL.first = (NodeT*)malloc(sizeof(NodeT));
        dL.first -> next = NULL;
        dL.first -> previous = NULL;
        dL.first -> data = key;
        dL.last = dL.first;
    }
    else
    {
        NodeT * newElement = (NodeT*)malloc(sizeof(NodeT));
        dL.last->next = newElement;
        newElement->next = NULL;
        newElement->previous = dL.last;
        newElement->data = key;
        dL.last = newElement;
        dL.last->next = NULL;
    }
}

void AF(int key)
{
    if(dL.first == NULL)
    {
        dL.first = (NodeT*)malloc(sizeof(NodeT));
        dL.first -> next = NULL;
        dL.first -> previous = NULL;
        dL.first -> data = key;
        dL.last = dL.first;
    }
    else
    {
        NodeT * newElement = (NodeT*)malloc(sizeof(NodeT));
        newElement->next = dL.first;
        newElement->previous = NULL;
        newElement->data = key;
        dL.first = newElement;
    }
}

void DF()
{
    if(dL.first == NULL)
        return;
    NodeT * currentElement = dL.first;
    dL.first = dL.first->next;
    dL.first->previous = NULL;
    currentElement->next = NULL;
    currentElement->previous = NULL;
    free(currentElement);
}
void DL()
{
    if(dL.last == NULL)
        return;
    NodeT * currentElement = dL.last;
    dL.last = dL.last->previous;
    dL.last->next = NULL;
    currentElement->previous = NULL;
    currentElement->next = NULL;
    free(currentElement);
}

void PRINT_ALL()
{
    NodeT * currentElement = dL.first;
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
    NodeT * currentElement = dL.first;
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
    currentElement = dL.first;
    while(currentElement != NULL)
    {
        if(currentElement->data == key)
        {
            if (currentElement == dL.first)
            {
                DF();
                currentElement = dL.first;
            }
            else
            {
                NodeT *removeElement;
                if (currentElement->next->data == key) {
                    removeElement = currentElement->next;
                    if (removeElement == dL.last) {
                        dL.last = currentElement;
                    }
                    currentElement->next = currentElement->next->next;
                    currentElement->next->previous = currentElement;
                    free(removeElement);
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
    NodeT * currentElement = dL.first;
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
    NodeT * currentElement = dL.first;
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
    NodeT * q = dL.first;
    while(q != NULL)
    {
        nr++;
        q = q->next;
    }
    return nr;
}
void removeAll() {
    NodeT *currentElement = dL.first;
    while (currentElement->next != NULL) {
        DE(currentElement->data);
        currentElement = dL.first;
    }
    free(currentElement);
    InitializeDll();
}