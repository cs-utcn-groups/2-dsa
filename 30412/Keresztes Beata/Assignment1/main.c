#include <stdio.h>
#include "list_instructions.h"

#define INPUT_FILE_NAME "../input.dat"
#define OUTPUT_FILE_NAME "../output.dat"
#define MAX_SIZE_INSTRUCT 30

int main() {

    FILE * fIn = openFile(INPUT_FILE_NAME, "r");
    FILE *fOut = openFile(OUTPUT_FILE_NAME, "w");

    initializeList();

    while(!feof(fIn)) {

        char * instruction = (char *)malloc(MAX_SIZE_INSTRUCT*sizeof(char));
        fscanf(fIn,"%s",instruction);
        int x;
        if(strcmp(instruction,"AF")==0) {
            fscanf(fIn,"%d",&x);
            addFirst(x);
        }
        else if(strcmp(instruction,"AL")==0) {
            fscanf(fIn,"%d",&x);
            addLast(x);
        }
        else if(strcmp(instruction,"DF")==0) {
            deleteFirst();
        }
        else if(strcmp(instruction,"DL")==0) {
            deleteLast();
        }
        else if(strcmp(instruction,"DOOM_THE_LIST")==0) {
            removeAllElements();
        }
        else if(strcmp(instruction,"DE")==0) {
            fscanf(fIn,"%d",&x);
            delete(x);
        }
        else if(strcmp(instruction,"PRINT_ALL")==0) {
            printAll(fOut);
        }
        else if(strcmp(instruction,"PRINT_F")==0) {
            fscanf(fIn,"%d",&x);
            printFirst(fOut,x);
        }
        else if(strcmp(instruction,"PRINT_L")==0) {
            fscanf(fIn,"%d",&x);
            printLast(fOut,x);
        }
        free(instruction);
    }
    fclose(fIn);
    fclose(fOut);
    return 0;
}