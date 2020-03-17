#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heade.h"



int main()
{
    initializeList();
    char s[200];
    int vec[200];
    int i=0;
    int ru=0,timp=0;
    FILE *f=fopen("input.data","r");
    FILE *g=fopen("output.txt","w+");
    fgets(s,200,f);
    char *p=strtok(s," ");
    vec[i]=strtol(p,NULL,10);
    i++;
    while(p!=NULL)
    {
        p=strtok(NULL," \n");
        vec[i]=strtol(p,NULL,10);
        i++;
    }
    while(fgets(s,200,f)!=NULL)
    {
        char*p=strtok(s," ");
        p=strtok(NULL," ");
        ru=strtol(p,NULL,10);
        p=strtok(NULL," ");
        timp=strtol(p,NULL,10);
        addelementf(ru,timp);

    }
    Q* currentElement = first;
    while (currentElement != NULL)
    {
        printf("%d %d ", currentElement->rubles,currentElement->time);
        currentElement = currentElement->next;
    }
    printf("\n");
    print(g,vec,i);

    return 0;
}
