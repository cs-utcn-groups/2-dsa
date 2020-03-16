#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void initList()
{
    list0=(listt *) malloc(sizeof(listt));
    list0->first=NULL;
    list0->last=NULL;
    list0->nrElements=0;
}

void addToEnd(int data)
{
    list0->nrElements++;

    node *element = (node *) malloc(sizeof(node));
    element->info =data;
    element->next = NULL;
    element->previous = NULL;

    if (list0->last == NULL)
    {
        list0->first = element;
        list0->last = element;
    }

    else
    {
        list0->last->next = element;
        element->previous = list0->last;
        list0->last = element;
    }
}

void addElementAtFront(int data)
{
    list0->nrElements++;

    if(list0->first==NULL)
    {
        list0->first=(node *) malloc(sizeof(node));
        list0->first->info=data;
        list0->first->next=list0->last;
        list0->last=list0->first;
        list0->last->previous=list0->first;
    }

    else
    {
        node * element=(node *) malloc(sizeof(node));
        element->next=list0->first;
        element->info=data;
        list0->first=element;
        list0->first->next->previous=list0->first;
    }
}

void DOOM_THE_LIST ()
{
    if(list0->first == NULL)
    {
        return;
    }

    list0->nrElements=0;
    node * element = list0->first;

    while(element != NULL)
    {
        list0->first = list0->first->next;
        free(element);
        element = list0->first;
    }
    list0->last=NULL;
}

void deleteFirst()
{
    if(list0->first==NULL || list0->last==NULL)
    {
        return;
    }

    list0->nrElements--;
    node * element=list0->first;
    list0->first=list0->first->next;
    list0->first->previous=NULL;
    free(element);
}

void deleteLast()
{
    if(list0->first==NULL || list0->last==NULL)
    {
        return;
    }

    if(list0->first->next==NULL)
    {
        node * element=list0->first;
        list0->first=list0->last=NULL;
        free(element);
        return;
    }

    list0->nrElements--;
    node * element=list0->last;
    list0->last=list0->last->previous;
    list0->last->next=NULL;
    free(element);
}

void PRINT_ALL (FILE *o)
{
    if(list0->first==NULL || list0->last==NULL)
    {
        fprintf(o,"List is emtpy\n");
        return;
    }

    node * element=list0->first;

    while(element!=NULL)
    {
        fprintf(o,"%d ",element->info);
        element=element->next;
    }
    fprintf(o,"\n");
}

void deleteElement(int data)
{
    if(list0->first==NULL)
    {
        return;
    }

    node * element=list0->first;

    while(element->info==data)
    {
        node * temp=element;
        element=element->next;
        list0->first=element;
        free(temp);
        list0->nrElements--;
    }

    element=list0->first;

    while(element!=NULL)
    {
        if(element->info==data)
        {
            node * temp=element;

            if(element->next==NULL)
            {
                list0->last=element->previous;
                list0->last->next=NULL;
                element=element->next;
                free(temp);
                list0->nrElements--;
            }
            else
            {
                element->previous->next=element->next;
                element->next->previous=element->previous;

                element=element->next;
                free(temp);
                list0->nrElements--;
            }
        }
        else
        {
            element=element->next;
        }
    }
}

void PRINT_F(int nr,FILE *o)
{
    node * element=list0->first;

    for(int i=0; i<nr && element!=NULL; i++)
    {
        fprintf(o,"%d ",element->info);
        element=element->next;
    }

    fprintf(o,"\n");
}

void PRINT_L(int nr,FILE *o)
{
    if(nr>list0->nrElements)
    {
        PRINT_ALL(o);
        return;
    }

    node * element=list0->first;

    for(int i=0; i<list0->nrElements-nr && element!=NULL; i++)
    {
        element=element->next;
    }

    while(element!=NULL)
    {
        fprintf(o,"%d ",element->info);
        element=element->next;
    }
    fprintf(o,"\n");
}

void readInstructions(FILE *f,FILE *o)
{
    char *s=(char *) malloc(sizeof(char)*maxLengthInstruction);

    while(fgets(s,maxLengthInstruction,f)!=NULL)
    {
        char * token=NULL;
        token=strtok(s," \n");

        if(!strcmp(s,"AF"))
        {
            token=strtok(NULL," \n");
            addElementAtFront(atoi(token));
        }

        else
        {
            if(!strcmp(s,"AL"))
            {
                token=strtok(NULL," \n");
                addToEnd(atoi(token));
            }
            else
            {
                if(!strcmp(s,"DL"))
                {
                    deleteLast();
                }
                else
                {
                    if(!strcmp(s,"DF"))
                    {
                        deleteFirst();
                    }
                    else
                    {
                        if(!strcmp(s,"DOOM_THE_LIST"))
                        {
                            DOOM_THE_LIST();
                        }

                        else
                        {
                            if(!strcmp(s,"DE"))
                            {
                                token=strtok(NULL," \n");
                                deleteElement(atoi(token));
                            }
                            else
                            {
                                if(!strcmp(s,"PRINT_ALL"))
                                {
                                    PRINT_ALL(o);
                                }
                                else
                                {
                                    if(!strcmp(s,"PRINT_F"))
                                    {
                                        token=strtok(NULL," \n");
                                        PRINT_F(atoi(token),o);
                                    }
                                    else
                                    {
                                        if(!strcmp(s,"PRINT_L"))
                                        {
                                            token=strtok(NULL," \n");
                                            PRINT_L(atoi(token),o);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    FILE *f=fopen("input.dat","r");
    FILE *o=fopen("output.dat","w+");
    initList();
    readInstructions(f,o);

    return 0;
}
