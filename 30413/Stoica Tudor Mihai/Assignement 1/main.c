#include <stdio.h>
#include <stdlib.h>
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
        // printf("List is emtpy\n");
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
    //printf("%d",last->info);
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
    char *number=(char *) malloc(sizeof(char)*maxLengthInstruction);

    while(fgets(s,maxLengthInstruction,f)!=NULL)
    {
        ///  printf("%s\n%s\n\n",s,strstr(s,"PRINT_L"));
        //PRINT_ALLL();
        //printf("%s\n",s);
        int len=0;
        if(s[0]=='A' && s[1]=='F')
        {
            int index=3;

            while(isdigit(s[index]))
            {
                number[len++]=s[index++];
            }
            number[len++]=NULL;
            /// printf("%d\n",atoi(number));
            addElementAtFront(atoi(number));
        }
        else
        {
            if(s[0]=='A' && s[1]=='L')
            {
                int index=3;

                while(isdigit(s[index]))
                {
                    number[len++]=s[index++];
                }
                number[len++]=NULL;
                /// printf("%d\n",atoi(number));
                addElementAtEnd(atoi(number));
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
                                int index=3;

                                while(isdigit(s[index]))
                                {
                                    number[len++]=s[index++];
                                }
                                number[len++]=NULL;
                                /// printf("%d\n",atoi(number));
                                deleteElement(atoi(number));
                            }
                            else
                            {
                                if(!strcmp(s,"PRINT_ALL\n"))
                                {

                                    PRINT_ALL(o);
                                }
                                else
                                {
                                    /// printf("sadfgsdhvfnisdjhvdshvsdbvjsdbvijsd");
                                    if(strstr(s,"PRINT_F"))
                                    {
                                        PRINT_ALLL();
                                        int index=8;

                                        while(isdigit(s[index]))
                                        {
                                            number[len++]=s[index++];
                                        }
                                        number[len++]=NULL;
                                        ///   printf("%d\n",atoi(number));
                                        PRINT_F(atoi(number),o);
                                    }
                                    else
                                    {
                                        ///printf("%s\n%s\n",s,strstr(s,"PRINT_L"));
                                        if(strstr(s,"PRINT_L"))
                                        {
                                            PRINT_ALLL();
                                            int index=8;

                                            while(isdigit(s[index]))
                                            {
                                                number[len++]=s[index++];
                                            }
                                            number[len++]=NULL;
                                            ///   printf("%d\n",atoi(number));
                                            PRINT_L(atoi(number),o);
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
    return s;
}

int main()
{
    init();
    FILE *f=fopen("input.dat","r");
    FILE *o=fopen("output.dat","w");
    readInstructions(f,o);

//    addElementAtEnd(1);
//    addElementAtEnd(2);
//    addElementAtEnd(3);
//    addElementAtEnd(4);
//    PRINT_ALLL();
//    DOOM_THE_LIST();
//    PRINT_ALLL();

    return 0;
}
