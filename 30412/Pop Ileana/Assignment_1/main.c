#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include "sll.h"

#define FILE_PATH_IN "../input.dat"
#define FILE_PATH_OUT "../output.dat"

FILE * fin,* fout;

int identifyAction(char s[]);


int main() {

    fin=fopen(FILE_PATH_IN,"r");
    char string[25];
    int key;

    if(fin==NULL)
    {
        perror("File could not be opened");
        exit(EXIT_FAILURE);
    }

    fout=fopen(FILE_PATH_OUT,"a");
    if(fout==NULL)
    {
        perror("File could not be opened");
        exit(EXIT_FAILURE);
    }

    enum Action {
        ADD_FIRST, ADD_LAST, DELETE_FIRST, DELETE_LAST, DOOM_LIST, DELETE_EL, PRINT_ALL, PRINT_FIRST_EL, PRINT_LAST_EL
    };

    int action=0;
    initializeSll();

    while(!feof(fin))
    {
        fscanf(fin,"%s",string);
        action=identifyAction(string);
        switch(action){
            case ADD_FIRST:{
                fscanf(fin,"%d",&key);
                addFirst(key);
                break;
            }
            case ADD_LAST:{
                fscanf(fin,"%d",&key);
                addLast(key);
                break;
            }
            case DELETE_FIRST:{
                deleteFirst();
                break;
            }
            case DELETE_LAST:{
                deleteLast();
                break;
            }
            case DOOM_LIST:{

                removeAll();
                break;
            }
            case DELETE_EL:{
                fscanf(fin,"%d",&key);
                removeElement(key);
                break;
            }
            case PRINT_ALL:{
                printSllData(fout);
                break;
            }
            case PRINT_FIRST_EL:{
                fscanf(fin,"%d",&key);
                printFirstValues(key,fout);
                break;
            }
            case PRINT_LAST_EL:{
                fscanf(fin,"%d",&key);
                printLastValues(key,fout);
                break;
            }
            default: fprintf(fout,"There is no such operation\n");
        }
    }
    fclose(fin);
    fclose(fout);
    return 0;
}

int identifyAction(char s[])
{
    if(strcmp(s,"AF")==0)
        return 0;
    if(strcmp(s,"AL")==0)
        return 1;
    if(strcmp(s,"DF")==0)
        return 2;
    if(strcmp(s,"DL")==0)
        return 3;
    if(strcmp(s,"DOOM_THE_LIST")==0)
        return 4;
    if(strcmp(s,"DE")==0)
        return 5;
    if(strcmp(s,"PRINT_ALL")==0)
        return 6;
    if(strcmp(s,"PRINT_F")==0)
        return 7;
    if(strcmp(s,"PRINT_L")==0)
        return 8;
    return -1;
}