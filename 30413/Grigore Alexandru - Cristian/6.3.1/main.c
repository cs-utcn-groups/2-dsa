#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int main()
{
    FILE *f=fopen("input.txt","r");
    char c;
    NodeT *p=NULL;
    char name[60];
    while(fscanf(f,"%s",name)!=-1)
    {
        c=*name;
        strcpy(name,name+1);
        if(c=='i')
        {
            p=insertNode(name);
        }
        if(c=='f')
        {
            p=findNode(name);
            if(p!=NULL)
            {
                printf("\nYES\n");
            }
            else
            {
                printf("\nNO\n");
            }
        }
        if(c=='d')
        {
            deleteNode(name);
        }
        if(c=='l')
        {
             printBucket();
        }
    }
    return 0;
}
