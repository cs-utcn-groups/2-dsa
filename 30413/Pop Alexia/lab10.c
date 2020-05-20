#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void deleteLetter (char string[], int poz)
{
    for (int i = poz; i < strlen (string); i++)
    {

        string[i] = string[i + 1];
    }
    string[strlen (string)] = 0;
}

void replaceLetter (char string[], char sstring[], int poz)
{
    string[poz] = sstring[poz];
}

void insertLetter (char string[], int pozitie, char letter)
{
    for (int i = strlen (string); i >= pozitie; i--)
    {
        string[i + 1] = string[i];

    }
    string[pozitie] = letter;
}

int operations (char v[], char v1[])
{
    int ct=0;
    if (strlen (v) >= strlen (v1))
    {
        for (int i = 0; i < strlen (v1); i++)
        {
            if (v[i + 1] == v1[i])
            {
                deleteLetter (v, i);
                ct++;
            }
            else if (v[i] != v1[i])
            {
                replaceLetter (v, v1, i);
                ct++;
            }

        }
        ct+=strlen(v)-strlen(v1);
    }
    else
    {
        for (int i = 0; i < strlen (v); i++)
        {
            if (v1[i + 1] == v1[i])
            {
                deleteLetter (v1, i);
                ct++;
            }
            else if (v[i] != v1[i])
            {
                replaceLetter (v1, v, i);
                ct++;
            }
        }
        ct+=strlen(v1)-strlen(v);
    }

    return ct;
}

int main ()
{
    FILE*f=fopen("in.txt","r+");
    FILE*g=fopen("out.txt","w+");
    int testCases;
    char v[200];
    char v1[200];
    fscanf(f,"%d",&testCases);
    for(int i=0; i<testCases; i++)
    {
        fscanf(f,"%s",v);
        fscanf(f,"%s",v1);
        int a=operations(v,v1);
        fprintf (g,"%d\n",a);
    }
    return 0;
}
