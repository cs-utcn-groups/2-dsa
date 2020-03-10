#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Others.h"

#define FILE_PATH "..//Input"
#define FILE_PATH_OUT "..//Output"
#define MAX_LINE_LENGTH 128

int main() {
    initializeSll();
    int M = 0, T = 0;
    char *str = (char *) malloc(MAX_LINE_LENGTH * sizeof(char));
    FILE *f = openFile(FILE_PATH, "r");
    FILE *fptr = openFile(FILE_PATH_OUT, "w");
    readTimes_AddList(f);
    while (first != NULL) {  //stops after all nodes are deleted
        if (!feof(f)) {      //the last 2 nr (m,t) would be read twice but the previous condition stops this problem (first!=NULL)
            int m, t;
            fscanf(f, "%[^ ]", str);  //read until first space
            fscanf(f, "%d", &m);
            fgetc(f);
            fscanf(f, "%d", &t);
            while (T + t > first->data) {
                printAndDelete(fptr, M);
            }
            M = M + m;
            T = T + t;
        } else {
            printAndDelete(fptr, M);
        }
    }
    free(str);
    fclose(f);
    fclose(fptr);
    return 0;
}