#include "io.h"

void writeToFile(int N)
{
    srand (time(NULL));
    FILE * f =  fopen("C:\\Users\\razvi\\Desktop\\Hash tables\\100.data","rw");
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

    //The read function didn't work for me so I just change the path here

    FILE * f = fopen("C:\\DSA_LAB\\2-dsa\\30412\\Bodea Razvan Marius\\Assignment 7\\100.data","rw");

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

