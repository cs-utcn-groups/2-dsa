#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_LENGTH_INPUT 25
#define MAX_NR_ENTRIES 105
#define MAX_NR_DATA 10000
#define oo 1<<30

char data[MAX_NR_DATA][MAX_LENGTH_INPUT],maxRange=-1,minRange=oo;
int nrEntries;

int hashFunction(char * array)
{
    int arrayLength=strlen(array);
    int firstLetter=array[0],secondLetter=array[1],lastLetter=array[arrayLength-2],penLastLetter=array[arrayLength-3];

    if(isupper(array[0]))
    {
        firstLetter-='A';
    }

    else
    {
        firstLetter-='a';
    }

    if(isupper(array[1]))
    {
        secondLetter-='A';
    }

    else
    {
        secondLetter-='a';
    }

    if(isupper(array[arrayLength-2]))
    {
        lastLetter-='A';
    }

    else
    {
        lastLetter-='a';
    }

    if(isupper(array[arrayLength-3]))
    {
        penLastLetter-='A';
    }

    else
    {
        penLastLetter-='a';
    }

    int firstIndex=0,lastIndex=0;
    bool exitSignalFirst=false,exitSignalLast=false;

    for(int i=0; i<=26 && (exitSignalFirst==false || exitSignalLast==false); i++)
    {
        for(int j=0; j<=26  && (exitSignalFirst==false || exitSignalLast==false) ; j++)
        {
            if(i==firstLetter && j==secondLetter)
            {
                exitSignalFirst=true;
            }

            if(i==penLastLetter && j==lastLetter)
            {
                exitSignalLast=true;
            }

            if(exitSignalFirst==false)
            {
                firstIndex++;
            }

            if(exitSignalLast==false)
            {
                lastIndex++;
            }
        }
    }
    /// printf("%d   %d\n\n\n",firstIndex,lastIndex);

    return firstIndex*10+lastIndex;
}

int adjust(char * array)
{
    /// 2nd has function

    int sum=0;

    for(int i=0; array[i]!='\0'; i++)
    {
        sum+=array[i];
    }

    return sum%100;
}

void insert(char * array)
{
    int index=hashFunction(array);

    if(data[index])
    {
        index=adjust(array);
    }

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
    printf("Attemtping to delete %s\n",array);

    int index=hashFunction(array);

    if(!strcmp(data[index],array))
    {
        data[index][0]='\0';
        printf("Deleted %s on index %d\n\n",array,index);
    }

    else
    {
        index=adjust(array);

        if(!strcmp(data[index],array))
        {
            data[index][0]='\0';
            printf("Deleted %s on index %d\n\n",array,index);
        }

        else
        {
            printf("Couldn't delete %s\n",array);
        }
    }
}

void find(char * array)
{
    printf("Attemtping to find %s\n",array);

    int index=hashFunction(array);

    if(!strcmp(data[index],array))
    {
        printf("Found %s on index %d\n\n",array,index);
    }

    else
    {
        index=adjust(array);

        if(!strcmp(data[index],array))
        {
            printf("Found %s on index %d\n\n",array,index);
        }

        else
        {
            printf("Couldn't find %s\n",array);
        }
    }
}

void list()
{
    printf("Attempting to list all entries:\n");

    for(int i=0; i<MAX_NR_DATA; i++)
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
        }
    }
}

int main()
{
    FILE * f=fopen("input.txt","r");

    read(f);

    return 0;
}
