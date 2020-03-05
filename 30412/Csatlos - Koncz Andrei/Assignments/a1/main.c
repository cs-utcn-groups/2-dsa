#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sll.h"

void SeparateLine(char line[50], int *key);

int main() {
    FILE *inF;
    inF = fopen(INPUT_FILE_PATH,"r");
    InitializeSll();
    char line[50];
    int key;
    while(fgets(line,50,inF))
    {
        SeparateLine(line,&key);
        //printf("%s %d --- ",line,key);
        if(strcmp(line,"AF") == 0)
        {
            AF(key);
        }
        if(strcmp(line,"AL") == 0)
        {
            AL(key);
        }
        if(strcmp(line,"DF") == 0)
        {
            DF();
        }
        if(strcmp(line,"DL") == 0)
        {
            DL();
        }
        if(strcmp(line,"PRINT_ALL") == 0)
        {
            PRINT_ALL();
        }
        if(strcmp(line,"DE") == 0)
        {
            DE(key);
        }
        if(strcmp(line,"DOOM_THE_LIST") == 0)
        {
            removeAll();
        }
        if(strcmp(line,"PRINT_F") == 0)
        {
            PRINT_F(key);
        }
        if(strcmp(line,"PRINT_L") == 0)
        {
            PRINT_L(key);
        }
    }
    return 0;
}
void SeparateLine(char line[50], int *key)
{
    char *p;
    p = strtok(line," \n");
    strcpy(line,p);
    p = strtok(NULL," \n");
    *key = atoi(p);
    //printf("--%s *%d",line,*key);
}