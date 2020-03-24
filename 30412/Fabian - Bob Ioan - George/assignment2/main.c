#include "double.h"
#include <stdio.h>
#include <string.h>
#define fileIN "../input.dat"

int main() {
    InitializeList();
    FILE *fIN = fopen(fileIN, "r");
    char *consoleInput = (char *) malloc(100 * sizeof(char));
    while (!feof(fIN)) {
        fscanf(fIN, "%s", consoleInput);
        int x;
        if (strcmp(consoleInput, "AF") == 0) {
            fscanf(fIN, "%d", &x);
            AddFirst(x);
            continue;
        }
        if (strcmp(consoleInput, "AL") == 0) {
            fscanf(fIN, "%d", &x);
            AddLast(x);
            continue;
        }
        if (strcmp(consoleInput, "DE") == 0) {
            fscanf(fIN, "%d", &x);
            DeleteElem(x);
            continue;
        }
        if (strcmp(consoleInput, "PRINT_F") == 0) {
            fscanf(fIN, "%d", &x);
            PrintFirst(x);
            continue;
        }
        if (strcmp(consoleInput, "PRINT_L") == 0) {
            fscanf(fIN, "%d", &x);
            PrintLast(x);
            continue;
        }
        if (strcmp(consoleInput, "DF") == 0) {
            DeleteFirst();
            continue;
        }
        if (strcmp(consoleInput, "DL") == 0) {
            DeleteLast();
            continue;
        }
        if (strcmp(consoleInput, "DOOM_THE_LIST") == 0) {
            DeleteList();
            continue;
        }
        if (strcmp(consoleInput, "PRINT_ALL") == 0) {
            PrintList();
            continue;
        }
    }
    free(consoleInput);
    fclose(fIN);
    return 0;
}