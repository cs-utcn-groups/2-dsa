#include <stdio.h>
#include <stdlib.h>
#include "instructions.h"


int main() {
    FILE *fIN = fopen("input.dat","r");
    FILE *fOUT = fopen("output.dat","w");
   initializeSLL();

    while(!feof(fIN)) {

        char * instruction = (char *)malloc(40*sizeof(char));
        fscanf(fIN,"%s",instruction);
        int x;
        if(strcmp(instruction,"AF")==0) {
            fscanf(fIN,"%d",&x);
            AF(x);
        }
        else if(strcmp(instruction,"AL")==0) {
            fscanf(fIN,"%d",&x);
            AL(x);
        }
        else if(strcmp(instruction,"DF")==0) {
            DF();
        }
        else if(strcmp(instruction,"DL")==0) {
            DL();
        }
        else if(strcmp(instruction,"DOOM_THE_LIST")==0) {
            doomSLL();
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

