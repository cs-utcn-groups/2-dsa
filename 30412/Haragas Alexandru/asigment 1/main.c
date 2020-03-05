#include <stdio.h>
#include <string.h>
#include "node.h"


int main() {
    InitializeList();
    FILE *f = fopen("D:\\DSA\\2-dsa\\30412\\Haragas Alexandru\\asigment 1\\input.dat", "r");
    char *s = (char *) malloc(100 * sizeof(char));
    while (!feof(f)) {
        fscanf(f,"%s",s);
        int x;
        if (strcmp(s, "AF") == 0) {
            fscanf(f,"%d",&x);
            AddFirst(x);
            continue;
        }
        if (strcmp(s, "AL") == 0) {
            fscanf(f,"%d",&x);
            AddLast(x);
            continue;
        }
        if (strcmp(s, "DE") == 0) {
            fscanf(f,"%d",&x);
            DeleteElem(x);
            continue;
        }
        if (strcmp(s, "PRINT_F") == 0) {
            fscanf(f,"%d",&x);
            PrintFirst(x);
            continue;
        }
        if (strcmp(s, "PRINT_L") == 0) {
            fscanf(f,"%d",&x);
            PrintLast(x);
            continue;
        }

        if (strcmp(s, "DF") == 0) {
            DeleteFirst();
            continue;
        }
        if (strcmp(s, "DL") == 0) {
            DeleteLast();
            continue;
        }
        if (strcmp(s, "DOOM_THE_LIST") == 0) {
            DeleteList();
            continue;
        }
        if (strcmp(s, "PRINT_ALL") == 0) {
            PrintList();
            continue;
        }

    }
    free(s);
    fclose(f);
    return 0;
}