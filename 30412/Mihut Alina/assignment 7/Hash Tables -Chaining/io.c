//
// Created by Alina Mihut on 5/2/20.
//

#include "io.h"

void writeToFile(int N)
{
    srand (time(NULL));
    FILE * f = getFileForInt(N);
    int i;
    for(i=0; i<N; i++)
    {
        fprintf(f,"%s\n",randString());
    }
    fclose(f);
}

char ** readFromFile(int N)
{
    char ** contents = (char**) malloc(sizeof(char*) * N);
    int i;

    for(i=0; i<N; i++)
    {
        *(contents + i) = (char*) malloc(sizeof(char) * (MAX_STRING_LENGTH +1) );
    }

    FILE * f = getFileForInt(N);

    for(i=0; i<N; i++)
    {
        fgets(*(contents+i), (MAX_STRING_LENGTH + 2),f);
    }

    return contents;
}

void printContentToConsole(char ** contents, int N)
{
    int i;
    for(i=0; i<N; i++)
    {
        puts(*(contents+i));
    }
}

char * randString()
{
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()_+{}:<>?|\[];'./,";
    char * str = (char*) malloc(sizeof(char) * (MAX_STRING_LENGTH));
    int i;

    for (i = 0; i < MAX_STRING_LENGTH-1; i++)
    {
        int key = rand() % (int) (sizeof(charset) - 1);
        str[i] = charset[key];
    }
    str[MAX_STRING_LENGTH - 1] = '\0';

    return str;
}

FILE * getFileForInt(int N)
{
    //had to change the itoa function because the compiler doesn't recognise it
    //but it still didn't work so I opened th file "manually"
    char * filename = (char*) malloc(sizeof(char)*12);
    char *finalName= (char*) malloc (sizeof(char)*15);

    sprintf(filename, "%d", N);
    finalName= strcat (filename, ".data");
    return fopen("../5000.data", "rw");
}
