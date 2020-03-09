#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"
#include "list.h"
#define MAX_LINE_LENGTH 32
int main() {
    FILE *input=fopen("../input.dat","r");
    FILE *output=fopen("../output.dat","w");
    char * buffer=(char*)malloc(MAX_LINE_LENGTH* sizeof(char));
    initList();
    while(fgets(buffer,MAX_LINE_LENGTH,input)){
        char *ptr,*ptr2;
        int x=0;
        strtok_r(buffer," \n",&ptr);
        x=strtol(ptr,&ptr2,10);
        readCommand(buffer,x,output);
    }
    free(buffer);
    fclose(input);
    fclose(output);
    return 0;
}
