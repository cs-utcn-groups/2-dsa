#include "head.h"

void initializeList()
{
    first=NULL;
    last=NULL;
}

void PRINT_ALL()
{
    NodeT*currentNode = first;
    while(currentNode != NULL)
    {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
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
    last=NULL;
    /// printf("List have been cleared\n");
}
void DL()
{
    NodeT*currentElement=first;
    NodeT*previousElement=first;
    if(last==NULL)
    {
        /// printf("The list is empty\n");
        return;
    }
    else
    {
        if(first==last)
        {
            free(first);
            first=last=NULL;
        }

        while(currentElement->next!=NULL)
        {
            previousElement=currentElement;
            currentElement=currentElement->next;
        }
        free(currentElement);
        previousElement->next=NULL;
        last=previousElement;
    }

}

void DF()
{
    NodeT*currentElement=first;
    if(first==NULL)
    {
        ///printf("List is already empty\n");
        return;
    }
    else
    {
        currentElement=first;
        first=first->next;
    }
    free(currentElement);
}

void AddL(int data)
{

    NodeT*newElem1=(NodeT*)malloc(sizeof(NodeT));
    newElem1->data=data;
    newElem1->next=NULL;
    NodeT*currentElement=first;
    if(first==NULL)
    {
        first=newElem1;
    }
    while(currentElement->next!=NULL)
    {
        currentElement=currentElement->next;
    }

    currentElement->next=newElem1;
    last=newElem1;


}
void AF(int data)
{
    NodeT*newElem1=(NodeT*)malloc(sizeof(NodeT));
    newElem1->data=data;
    newElem1->next=NULL;
    ///NodeT*currentElement=first;
    if(first==NULL)
    {
        first=newElem1;
    }
    else
    {
        newElem1->next=first;
        first=newElem1;
    }
}
void DE(int x)
{
    NodeT*currentNode=first;
    NodeT*previousNode=NULL;

    while(currentNode!=NULL)
    {
        if(currentNode->data==x)
            break;
        previousNode=currentNode;
        currentNode=currentNode->next;
    }

    if(currentNode!=NULL)
    {
        if(currentNode==first)
        {
            first=first->next;
            free(currentNode);
        }


        else
        {
            previousNode->next = currentNode->next;

            free( currentNode );
        }

    }
}
void PRINT_F(int x)
{
    NodeT*currentNode=first;
    int i=0;
    while(currentNode != NULL && i<x)
    {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
        i++;
    }
    printf("\n");
}
int countAll()
{
    int count=0;
    NodeT*currentNode=first;
    while(currentNode!=NULL)
    {
        count++;
        currentNode=currentNode->next;
    }
    return count;
}
void PRINT_L(int x)
{
    NodeT*currentNode=first;
    int nr=countAll();
    if(x>nr)
    {
        PRINT_ALL();
    }
    else
    {
        for(int i=0; i<nr-x; i++)
        {
            currentNode=currentNode->next;
        }
        while(currentNode!=NULL)
        {
            printf("%d ",currentNode->data);
            currentNode=currentNode->next;
        }
        printf("\n");
    }
}
void executeInstr(char *s1)
{
    int nr=0;
    char *s2=(char*)malloc(sizeof(char)*100);
    if(strstr(s1,"AF")!=0)
    {
        for(int i=0; i<strlen(s1); i++)
        {
            if(s1[i]>='0'&&s1[i]<='9')
            {
                s2[nr]=s1[i];
                nr++;
            }
        }
        s2[nr]='\0';
        AF(atoi(s2));
    }
    if(strstr(s1,"AddL")!=0)
    {
        for(int i=0; i<strlen(s1); i++)
        {
            if(s1[i]>='0'&&s1[i]<='9')
            {
                s2[nr]=s1[i];
                nr++;
            }
        }
        s2[nr]='\0';
        AddL(atoi(s2));
    }
    if(strstr(s1,"DE")!=0)
    {
        for(int i=0; i<strlen(s1); i++)
        {
            if(s1[i]>='0'&&s1[i]<='9')
            {
                s2[nr]=s1[i];
                nr++;
            }
        }
        s2[nr]='\0';
        DE(atoi(s2));
    }

    if(strstr(s1,"PRINT_L")!=0)
    {
        for(int i=0; i<strlen(s1); i++)
        {
            if(s1[i]>='0'&&s1[i]<='9')
            {
                s2[nr]=s1[i];
                nr++;
            }
        }
        s2[nr]='\0';
        PRINT_L(atoi(s2));
    }
    if(strstr(s1,"PRINT_F")!=0)
    {
        for(int i=0; i<strlen(s1); i++)
        {
            if(s1[i]>='0'&&s1[i]<='9')
            {
                s2[nr]=s1[i];
                nr++;
            }
        }
        s2[nr]='\0';
        PRINT_F(atoi(s2));
    }
    if(strstr(s1,"DL")!=0)
    {
        DL();
    }
    if(strstr(s1,"DOOM")!=0)
    {
        DOOM_THE_LIST();
    }
    if(strstr(s1,"PRINT_ALL")!=0)
    {
        PRINT_ALL();
    }
    if(strstr(s1,"DF")!=0)
    {
        DF();
    }
}
