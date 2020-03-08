#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

#define FILE_PATH "..//Input"
#define FILE_PATH_OUT "..//Output"
#define MAX_LINE_LENGTH 128

int main() {
    initializeSll();
    int M = 0;
    int T = 0;
    int counter = 0;
    int c;
    char *str = (char *) malloc(MAX_LINE_LENGTH * sizeof(char));
    FILE *f = fopen(FILE_PATH, "r");
    if (f == NULL) {
        perror("File could not be open");
        exit(EXIT_FAILURE);
    }
    FILE *fptr=fopen(FILE_PATH_OUT,"w");
    while ((c = fgetc(f)) != '\n') {
        if (c == ' ') {
            counter++;
        }
    }
    fseek(f, 0, SEEK_SET);
    for (int i = 0; i <= counter; i++) {
        fscanf(f, "%d", &c);
        Add_Last(c);   //insert the times in a Sll
    }

    while (first != NULL) {  //stops after all nodes are deleted
        if (!feof(f)) {      //the last 2 nr (m,t) would be read twice but the previous condition stops this problem (first!=NULL)
            int m, t;
            fscanf(f, "%[^ ]", str);  //read until first space
            fscanf(f, "%d", &m);
            fgetc(f);
            fscanf(f, "%d", &t);

            while (T + t > first->data) {
                fprintf(fptr,"After %d seconds: %d\n", first->data, M);
                Delete_First();
            }
            M = M + m;
            T = T + t;
        } else {
            fprintf(fptr,"After %d seconds: %d\n", first->data, M);
            Delete_First();
        }
    }

    free(str);
    fclose(f);
    fclose(fptr);
    return 0;
}