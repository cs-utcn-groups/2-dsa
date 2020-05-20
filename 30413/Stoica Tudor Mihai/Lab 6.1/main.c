#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH_INPUT 25
#define MAX_NR_ENTRIES 105
#define oo 1<<30

int nrEntries,maxRange=-1,minRange=oo;
char data[1005][25];

int hashFunction(char * array)
{
    int sum=0;

    for(int i=0; array[i]!='\0'; i++)
    {
        sum+=array[i];
    }

    return (sum%100);
}

int adjust(int index)
{
    while(!data[index])
    {
        index++;
    }
    return index;
}

int adjustFind(int index,char * array)
{        //printf("%s%s",data[index],array);
    while(strcmp(data[index],array) && data[index][0]!='\0')
    {
        // printf("%s %s\n",data[index],array);
       // printf("%s",data[index]);
        index++;
    }

    if(!strcmp(data[index],array))
    {
       return index;
    }
        return -1;
}

void insert(char * array)
{
    int index=hashFunction(array);
    index=adjust(index);

    strcpy(data[index],array);
    printf("%s inserted on index %d\n\n",array,index);

    if(index>maxRange)
    {
        maxRange=index;
    }

    if(index<minRange)
    {
        minRange=index;
    }
}

void del(char * array)
{
//    printf("Attemtping to delete %s\n",array);
//
//    for(int i=minRange; i<=maxRange; i++)
//    {
//        if(!strcmp(data[i],array))
//        {
//            data[i][0]='\0';
//            printf("%s deleted\n\n",array);
//            return;
//        }
//    }
//
//    printf("Couldn't delete %s\n",array);

    printf("Attemtping to delete %s\n",array);
    int index=hashFunction(array);
    index=adjustFind(index,array);

    if(index==-1)
    {
        printf("Couldn't delete %s\n",array);
    }

    else
    {
        data[index][0]='\0';
        printf("%s deleted    index %d\n\n",array,index);
    }
}

void find(char * array)
{
//    for(int i=minRange; i<=maxRange; i++)
//    {
//        if(!strcmp(data[i],array))
//        {
//            printf("Found %s on index %d\n\n",array,i);
//            return;
//        }
//    }
//
//    printf("Couldn't find %s\n",array);

    printf("Attemtping to find %s\n",array);
    int index=hashFunction(array);
    index=adjustFind(index,array);

    if(index==-1)
    {
        printf("Couldn't find %s\n",array);
    }

    else
    {
        printf("%s found on index %d\n\n",array,index);
    }
}

void list()
{
    printf("Attempting to list all entries:\n");
    for(int i=minRange; i<=maxRange; i++)
    {
        if(data[i][0]!='\0')
        {
            printf("%s",data[i]);
        }
    }
    printf("\n");
}

void throwError(char * errorMessage)
{
    if(errorMessage==NULL)
    {
        printf("ERROR\n");
        return;
    }
}

void read(FILE * f)
{
    char * array=(char *) malloc(MAX_LENGTH_INPUT);
    fscanf(f,"%d",&nrEntries);

    for(int i=0; i<nrEntries; i++)
    {
        fgets(array,MAX_LENGTH_INPUT,f);
//printf("%s\n",array);
//printf("%c\n\n\n",array[0]);
        switch (array[0])
        {
        case 'i':
            insert(array+2);
            break;

        case 'd':
            del(array+2);
            break;

        case 'f':
            find(array+2);
            break;

        case 'l':
            list();
            break;

        default:
            throwError("Input is not written properly");
            //  throwError(array);
        }
    }
}

int main()
{
    FILE * f=fopen("input.txt","r");

    read(f);

    return 0;
}
