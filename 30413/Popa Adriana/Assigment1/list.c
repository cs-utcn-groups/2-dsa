#include "list.h"

void initializeList()
{
    first = NULL;
    last = NULL;
}

void readInput()
{
    FILE *f=fopen("input.dat","r");
    FILE *g=fopen("output.dat","w");
    char *instr=(char*)malloc(sizeof(char)*100);
    char *p=(char*)malloc(sizeof(char)*100);
    int x;
    while(fgets(instr,100,f)!=NULL)
    {
        p=strtok(instr," ");
        if(strcmp(p,"AF")==0)
        {
            p=strtok(NULL," ");
            x=atoi(p);
            addElementFirst(x);
        }
        else
        {
            if(strcmp(p,"AL")==0)
            {
                p=strtok(NULL," ");
                x=atoi(p);
                addElementLast(x);
            }
            else
            {
                if(verify(p,"DF")==1)
                {
                    deleteFirst();
                }
                else
                {
                    if(verify(p,"DL")==1)
                    {
                        deleteLast();
                    }
                    else
                    {
                        if(verify(p,"DE")==1)
                        {
                            p=strtok(NULL," ");
                            x=atoi(p);
                            removeElement(x);
                        }
                        else
                        {
                            if(verify(p,"DOOM_THE_LIST")==1)
                            {
                                removeAll();
                            }
                            else
                            {
                                if(verify(p,"PRINT_ALL")==1)
                                {
                                    printList(g);
                                }
                                else
                                {
                                    if(verify(p,"PRINT_F")==1)
                                    {
                                        p=strtok(NULL," ");
                                        x=atoi(p);
                                        printFirst(x,g);
                                    }
                                    else
                                    {
                                        if(strcmp(p,"PRINT_L")==0)
                                        {
                                            p=strtok(NULL," ");
                                            x=atoi(p);
                                            printLast(x,g);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        //printList(g);
    }
    fclose(f);
    fclose(g);
}

int verify(char *a,char *b)
{
    int i,ok=1;
    for(i=0; i<strlen(b)&&ok==1&&i<strlen(a); i++)
    {
        if(a[i]!=b[i])
            ok=0;
    }
    return ok;
}

void addElementFirst(int data)
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

void addElementLast(int data)
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

void deleteFirst()
{
    NodeT * currentElement = first;
    NodeT * previousElement= first;
    first = first->next;
    previousElement = currentElement;
    currentElement = currentElement->next;
    free(previousElement);
    previousElement = currentElement;
}

void deleteLast()
{
    NodeT * currentElement = first;
    NodeT * previousElement= first;
    while(currentElement != NULL)
    {
        if(currentElement == last)
        {
            last = previousElement;
            last->next = NULL;
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

void removeElement(int data)
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

void printList(FILE *g)
{
    if(first == NULL)
    {
        fputs("List is empty!\n",g);
    }
    else
    {
        NodeT * currentElement = first;
        while(currentElement != NULL)
        {
            fprintf(g,"%d ", currentElement->data);
            currentElement = currentElement->next;
        }
        fputs("\n",g);
    }

}

void removeAll()
{
    NodeT * currentElement = first;
    while(currentElement != NULL)
    {
        first = first->next;
        free(currentElement);
        currentElement = first;
    }
}

void printFirst(int x,FILE *g)
{
    while(x>0)
    {
        if(first == NULL)
        {
            fputs("List is empty!\n",g);
            x=0;
        }
        else
        {
            NodeT * currentElement = first;
            while(currentElement != NULL&&x!=0)
            {
                fprintf(g,"%d ", currentElement->data);
                x--;
                currentElement = currentElement->next;
            }
            fputs("\n",g);
        }
    }
}

void printLast(int x,FILE *g)
{
    int ct=0;
    NodeT * currentElement = first;
    while(currentElement != NULL)
    {
        currentElement = currentElement->next;
        ct++;
    }

    if(first == NULL)
    {
        fputs("List is empty!\n",g);
    }
    else
    {
        currentElement = first;
        while(ct>x && currentElement != NULL)
        {
            ct--;
            currentElement = currentElement->next;
        }
        while(currentElement != NULL&&x>0)
        {
            fprintf(g,"%d ", currentElement->data);
            currentElement = currentElement->next;
            x--;
        }
        fputs("\n",g);
    }
}
