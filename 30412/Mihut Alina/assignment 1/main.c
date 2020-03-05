#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sll.h"

int main() {
    FILE *fin, *fout;
    fin=fopen("../input.dat","r");
    fout=fopen("../output.dat", "w");
    if (fin==NULL)
        perror("File couldn't be open\n");
    char instruction[200];
    int number;

    initializeList();
    while (!feof(fin))
    {
        fscanf(fin, "%s", instruction);
        fgetc(fin);
        if(strcmp(instruction, "AF")==0)
        {   fscanf (fin, "%d", &number);
            addFirst(number);}
        if(strcmp(instruction, "AL")==0)
        {   fscanf (fin, "%d", &number);
            addLast(number);}
        if(strcmp(instruction, "DF")==0)
            deleteFirst();
        if(strcmp(instruction, "DL")==0)
            deleteLast();
        if(strcmp(instruction, "DE")==0)
        {   fscanf (fin, "%d", &number);
            deleteElement(number);}
        if(strcmp(instruction, "DOOM_THE_LIST")==0)
            doomTheList();
        if(strcmp(instruction, "PRINT_ALL")==0)
            printAllElements(fout);
        if(strcmp(instruction, "PRINT_F")==0)
        {   fscanf (fin, "%d", &number);
            printFirst(number, fout);}
        if(strcmp(instruction, "PRINT_L")==0)
        {   fscanf (fin, "%d", &number);
            printLast(number, fout);}

    }
    fclose(fin);
    fclose(fout);
    return 0;
}
