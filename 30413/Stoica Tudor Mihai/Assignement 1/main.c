#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void init()
{
    last=first=NULL;
}

void addElementAtEnd(int data)
{
    nrElements++;
    if(first==NULL)
    {
        first=(node *) malloc(sizeof(node));
        first->info=data;
        first->next=last;
        last=first;
    }

    else
    {
        node * element=(node *) malloc(sizeof(node));
        element->next = NULL;
        element->info = data;
        last->next = element;
        last = element;
    }
}

void addElementAtFront(int data)
{
    nrElements++;
    if(first==NULL)
    {
        first=(node *) malloc(sizeof(node));
        first->info=data;
        first->next=last;
        last=first;
    }

    else
    {
        node * element=(node *) malloc(sizeof(node));
        element->next=first;
        element->info=data;
        first=element;
    }
}

void DOOM_THE_LIST ()
{

    if(first == NULL)
    {
        return;
    }
    nrElements=0;
    node * element = first;
    while(element != NULL)
    {
        first = first->next;
        free(element);
        element = first;
    }
    last=NULL;
}

void deleteFirst()
{
    nrElements--;
    if(first==NULL || last==NULL)
    {
        return;
    }

    first=first->next;
}

void deleteLast()
{
    nrElements--;
    if(first==NULL || last==NULL)
    {
        return;
    }

    if(first->next==NULL)
    {
        first=last=NULL;
        return;
    }

    node * element=first;

    while(element->next!=last)
    {
        element=element->next;
    }

    last=element;
    last->next=NULL;
}

void PRINT_ALL (FILE *o)
{
    if(first==NULL || last==NULL)
    {
        fprintf(o,"List is emtpy\n");
        return;
    }

    node * element=first;

    while(element!=NULL)
    {
        fprintf(o,"%d ",element->info);
        element=element->next;
    }
    fprintf(o,"\n");
}

void deleteElement(int data)
{
    nrElements--;
    while(first->info==data)
    {
        first=first->next;
    }

    node * element=first->next;
    node * previous=first;

    while(element!=NULL)
    {
        if(element->info==data)
        {
            previous->next=element->next;
        }

        else
        {
            previous=element;
        }
        element=element->next;
    }
}

void PRINT_F(int nr,FILE *o)
{
    node * element=first;

    for(int i=0; i<nr && element!=NULL; i++)
    {
        fprintf(o,"%d ",element->info);
        element=element->next;
    }

    fprintf(o,"\n");
}

void PRINT_L(int nr,FILE *o)
{
    if(nr>nrElements)
    {
        PRINT_ALL(o);
        return;
    }

    node * element=first;

    for(int i=0; i<nrElements-nr+1 && element!=NULL; i++)
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

void PRINT_ALLL ()
{
    if(first==NULL || last==NULL)
    {
        printf("List is emtpy\n");
        return;
    }

    node * element=first;

    while(element!=NULL)
    {
        printf("%d ",element->info);
        element=element->next;
    }
    printf("\n");
}


void readInstructions(FILE *f,FILE *o)
{
    char *s=(char *) malloc(sizeof(char)*maxLengthInstruction);

    while(fgets(s,maxLengthInstruction,f)!=NULL)
    {
        if(s[0]=='A' && s[1]=='F')
        {
            char * token=strtok(s," ");
            token=strtok(NULL," ");

            addElementAtFront(atoi(token));
        }
        else
        {
            if(s[0]=='A' && s[1]=='L')
            {
                char * token=strtok(s," ");
                token=strtok(NULL," ");
                addElementAtEnd(atoi(token));
            }
            else
            {
                if(s[0]=='D' && s[1]=='L')
                {
                    deleteLast();
                }
                else
                {
                    if(s[0]=='D' && s[1]=='F')
                    {
                        deleteFirst();
                    }
                    else
                    {
                        if(!strcmp(s,"DOOM_THE_LIST\n"))
                        {
                            DOOM_THE_LIST();
                        }
                        else
                        {
                            if(s[0]=='D' && s[1]=='E')
                            {
                                char * token=strtok(s," ");
                                token=strtok(NULL," ");
                                deleteElement(atoi(token));

                            }
                            else
                            {
                                if(!strcmp(s,"PRINT_ALL\n"))
                                {

                                    PRINT_ALL(o);
                                }
                                else
                                {
                                    if(strstr(s,"PRINT_F"))
                                    {
                                        char * token=strtok(s," ");
                                        token=strtok(NULL," ");
                                        PRINT_F(atoi(token),o);

                                    }
                                    else
                                    {

                                        if(strstr(s,"PRINT_L"))
                                        {
                                            char * token=strtok(s," ");
                                            token=strtok(NULL," ");
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
    init();
    FILE *f=fopen("input.dat","r");
    FILE *o=fopen("output.dat","w");
    readInstructions(f,o);

    return 0;
}
