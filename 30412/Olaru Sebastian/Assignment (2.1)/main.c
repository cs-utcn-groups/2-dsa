#include "list.h"

#define MAX_FUNCTION_CALL 128

int main() {
    fin = fopen("input.dat", "r");
    fout = fopen("output.dat", "a");

    doubleLinkedList = createList();

    char *functionCall = (char *) malloc(MAX_FUNCTION_CALL * sizeof(char));
    int x;

    if (fin != NULL) {
        while (!feof(fin)) {
            fscanf(fin, "%s", functionCall);
            getc(fin);
            if (strcmp(functionCall, "AF") == 0) {
                fscanf(fin, "%d", &x);
                getc(fin);
                AddElementFirst(x);
            }
            if (strcmp(functionCall, "AL") == 0) {
                fscanf(fin, "%d", &x);
                getc(fin);
                AddElementLast(x);
            }
            if (strcmp(functionCall, "DF") == 0) {
                DeleteFirst();
            }
            if (strcmp(functionCall, "DL") == 0) {
                DeleteLast();
            }
            if (strcmp(functionCall, "DOOM_THE_LIST") == 0) {
                DeleteWholeList();
            }
            if (strcmp(functionCall, "DE") == 0) {
                fscanf(fin, "%d", &x);
                getc(fin);
                DeleteElement(x);
            }
            if (strcmp(functionCall, "PRINT_F") == 0) {
                fscanf(fin, "%d", &x);
                getc(fin);
                PrintFirstNElements(x);
            }
            if (strcmp(functionCall, "PRINT_L") == 0) {
                fscanf(fin, "%d", &x);
                getc(fin);
                PrintLastNElements(x);
            }
            if (strcmp(functionCall, "PRINT_ALL") == 0) {
                PrintWholeList();
            }
        }
    }
    fclose(fin);
    fclose(fout);
    return 0;
}

