#include <stdio.h>
#include <stdlib.h>
static int MAX_ACTION=20;
typedef struct node
{
    int data;
    struct node * next;
} NodeT;
NodeT * first, * last;

void initializeSll()
{
    first = NULL;
    last = NULL;
}
void DF()
{
    NodeT* currentElement=first;
    if(first==NULL)
        return;
    first=first->next;
    free(currentElement);
}
void DL()
{
    NodeT* currentElement=first;
    if(first==NULL)
        return;
    while(currentElement->next!=last)
    {
        currentElement=currentElement->next;
    }
    free(last);
    last=currentElement;
}
void AL(int data)
{
    if(first == NULL)
    {
        first = (NodeT*)malloc(sizeof(NodeT));
        first->next = last;
        first->data = data;
        last = first;
    }
    else
    {
        NodeT * newElement = (NodeT*)malloc(sizeof(NodeT));
        last->next = newElement;
        newElement->next = NULL;
        newElement->data = data;
        last = newElement;
    }
}


void AF(int data)
{
    if(first == NULL)
    {
        first = (NodeT*)malloc(sizeof(NodeT));
        first->next = last;
        first->data = data;
        last = first;
    }
    else
    {
        NodeT * newElement = (NodeT*)malloc(sizeof(NodeT));
        newElement->next=first;
        newElement->data=data;
        first=newElement;
    }
}
void DE(int data)
{
    NodeT * currentElement = first;
    NodeT * previousElement= first;
    while(currentElement != NULL)
    {
        if(currentElement->data == data)
        {
            if(currentElement == first)
            {
                first = first->next;
            }
            else if(currentElement == last)
            {
                last = previousElement;
                last->next = NULL;
            }
            else
            {
                previousElement->next = currentElement->next;
            }
            previousElement = currentElement;
            currentElement = currentElement->next;
            free(previousElement);
            previousElement = currentElement;
        }
        else
        {
            previousElement = currentElement;
            currentElement = currentElement->next;
        }

    }
}

void PRINT_ALL(FILE *g)
{
    if(first == NULL)
    {
        fprintf(g,"List is empty!\n");
    }
    else
    {
        NodeT * currentElement = first;
        while(currentElement != NULL)
        {
            fprintf(g,"%d ", currentElement->data);
            currentElement = currentElement->next;
        }
        fprintf(g,"\n");
    }

}
void PRINT_F(int k,FILE *g)
{
    int ok=0;
    if(first == NULL)
    {
        fprintf(g,"List is empty!\n");
    }
    else
    {
        NodeT * currentElement = first;
        while(currentElement != NULL)
            if(ok<k)
            {
                fprintf(g,"%d ", currentElement->data);
                currentElement = currentElement->next;
                ok++;
            }
        fprintf(g,"\n");
    }
}
void PRINT_L(int k,FILE *g)
{
    NodeT *currentNode=first;
    int nrElements=0;
    while(currentNode!=NULL)
    {
        nrElements++;
        currentNode=currentNode->next;

    }
    int i;
    currentNode=first;
    if(nrElements<=k)
    {
        PRINT_ALL(g);
    }
    else
    {
        for(i=1; i<=nrElements; i++)
        {
            if(i>nrElements-k)
            {
                fprintf(g,"%d",currentNode->data);
            }
            currentNode=currentNode->next;
        }
    }
    fprintf(g,"\n");
}
void DOOM_THE_LIST()
{
    NodeT * currentElement = first;
    while(currentElement != NULL)
    {
        first = first->next;
        free(currentElement);
        currentElement = first;
    }
}
void Actiuni(FILE *f,FILE *g)
{
    char *strbuf=(char*)malloc(sizeof(char)*250);
    char*p;
    while (fgets(strbuf,MAX_ACTION,f)!=NULL)
    {
        p=strtok(strbuf," ");
        if (strcmp(p,"AF") == 0)
        {
            p=strtok(NULL," ");
            AF(atoi(p));
        }
        else if (strcmp(p,"AL")==0)
        {

            p=strtok(NULL," ");
            AL(atoi(p));
        }
        else if(strcmp(p,"DP")==0)
        {
            DF();
        }
        else if(strcmp(p,"DL")==0)
        {
            DL();

        }
        else if(strcmp(p,"DOOM_THE_LIST")==0)
        {
            DOOM_THE_LIST();
        }
        else if(strcmp(p,"DE")==0)
        {
            p=strtok(NULL," ");
            DE(atoi(p));
        }
        else if(strcmp(p,"PRINT_ALL")==0)
        {
            PRINT_ALL(g);
        }
        else if(strcmp(p,"PRINT_L")==0)
        {
            p=strtok(NULL," ");
            PRINT_L(atoi(p),g);
        }
        else if(strcmp(p,"PRINT_F")==0)
        {
            p=strtok(NULL," ");
            PRINT_F(atoi(p),g);
        }
    }
}
int main()
{
    initializeSll();

    FILE *f=fopen("input.dat","r");
    FILE *g=fopen("output.dat","w");
    Actiuni(f,g);

    return 0;
}
