#include <stdio.h>
#include "head.h"
#include <string.h>

#define MAX_LEN 50
#define FILE_PATH "..//input.dat"
#define FILE_PATH_OUT "..//output.txt"

int main() {
    int noOfEl = 0;
    FILE *f = fopen(FILE_PATH, "r");
    if (f == NULL) {
        perror("File could not be open");
        exit(EXIT_FAILURE);
    }
    FILE *fptr = fopen(FILE_PATH_OUT, "w");
    initializeSll();
    char *operation = (char *) malloc(MAX_LEN * sizeof(char));
    while (!feof(f)) {
        fscanf(f, "%s", operation);
        int n;
        if (strcmp(operation, "AF") == 0) {
            fscanf(f, "%d", &n);
            Add_First(n);
            noOfEl++;
        } else if (strcmp(operation, "AL") == 0) {
            fscanf(f, "%d", &n);
            Add_Last(n);
            noOfEl++;
        } else if (strcmp(operation, "DF") == 0) {
            if (first != NULL) {
                noOfEl--;
            }
            Delete_First();
        } else if (strcmp(operation, "DL") == 0) {
            if (first != NULL) {
                noOfEl--;
            }
            Delete_Last();
        } else if (strcmp(operation, "DOOM_THE_LIST") == 0) {
            Remove_All();
            noOfEl = 0;
        } else if (strcmp(operation, "DE") == 0) {
            fscanf(f, "%d", &n);
            if (Check_Element(n)) {
                noOfEl--;
            }
            Delete_Element(n);
        } else if (strcmp(operation, "PRINT_ALL") == 0) {
            Print_All(fptr);
        } else if (strcmp(operation, "PRINT_F") == 0) {
            fscanf(f, "%d", &n);
            Print_First_N(n, fptr);
        } else if (strcmp(operation, "PRINT_L") == 0) {
            fscanf(f, "%d", &n);
            Print_Last_N(n, noOfEl, fptr);
        }
    }
    free(operation);
    fclose(f);
    return 0;
}
