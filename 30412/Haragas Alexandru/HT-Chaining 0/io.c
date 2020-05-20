//
// Created by Alex on 03.05.2020.
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
    char * filename = (char*) malloc(sizeof(char)*12);
    itoa(N,filename,10);
    strcat(filename,".data");
    char *string=(char*)malloc(sizeof(char)*255);
    strcpy(string,"D:\\DSA\\2-dsa\\30412\\Haragas Alexandru\\HT-Chaining 0\\");
    strcat(string,filename);
    return fopen(string, "rw");
}