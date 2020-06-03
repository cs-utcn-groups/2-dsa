#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main() {
    FILE *fin, *fout;
    fin = fopen("../input.dat", "r");
    fout = fopen("../output.dat", "w");
    if (fin == NULL)
        perror("File couldn't be opened!\n");
    char instruction[200];
    int number;

    initList();
    while (!feof(fin)) {
        fscanf(fin, "%s", instruction);
        fgetc(fin);
        if (strcmp(instruction, "AF") == 0) {
            fscanf(fin, "%d", &number);
            addFirst(number);
        } else if (strcmp(instruction, "AL") == 0) {
            fscanf(fin, "%d", &number);
            addLast(number);
        } else if (strcmp(instruction, "DF") == 0)
            deleteFirst();
        else if (strcmp(instruction, "DL") == 0)
            deleteLast();
        else if (strcmp(instruction, "DE") == 0) {
            fscanf(fin, "%d", &number);
            deleteElement(number);
        } else if (strcmp(instruction, "DOOM_THE_LIST") == 0)
            doomTheList();
        else if (strcmp(instruction, "PRINT_ALL") == 0)
            printAll(fout);
        else if (strcmp(instruction, "PRINT_F") == 0) {
            fscanf(fin, "%d", &number);
            printFirst(number, fout);
        } else if (strcmp(instruction, "PRINT_L") == 0) {
            fscanf(fin, "%d", &number);
            printLast(number, fout);
        }

    }
    fclose(fin);
    fclose(fout);
    return 0;
}
