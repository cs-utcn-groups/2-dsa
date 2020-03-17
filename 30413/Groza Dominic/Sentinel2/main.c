#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "instructions.h"


int main() {
    FILE *fIN = fopen("input.dat","r");
    FILE *fOUT = fopen("output.dat","w");
    initializeSentinel();

    while(!feof(fIN)) {

        char * instruction = (char *)malloc(40*sizeof(char));
        fscanf(fIN,"%s",instruction);
        int x;
        if(strcmp(instruction,"AF")==0) {
            fscanf(fIN,"%d",&x);
            addFirst(x);
        }
        else if(strcmp(instruction,"AL")==0) {
            fscanf(fIN,"%d",&x);
            addLast(x);
        }
        else if(strcmp(instruction,"DF")==0) {
            deleteFirst();
        }
        else if(strcmp(instruction,"DL")==0) {
            deleteLast();
        }
        else if(strcmp(instruction,"DOOM_THE_LIST")==0) {
            DOOM_THE_LIST();
        }
        else if(strcmp(instruction,"DE")==0) {
            fscanf(fIN,"%d",&x);
            delete(x);
        }
        else if(strcmp(instruction,"PRINT_ALL")==0) {
            printAll(fOUT);
        }
        else if(strcmp(instruction,"PRINT_F")==0) {
            fscanf(fIN,"%d",&x);
            printFirstX(fOUT,x);
        }
        else if(strcmp(instruction,"PRINT_L")==0) {
            fscanf(fIN,"%d",&x);
            printLastX(fOUT,x);
        }
        free(instruction);
    }
    fclose(fIN);
    fclose(fOUT);
    return 0;
}
