#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dll.h"
#define MAX_LINE_LENGTH 10

int main() {

    int a;
    doublyLinked *list;
    initialiseList(list);

    FILE *f;
    f = fopen("../in.dat", "r");
    FILE *g;
    g = fopen("../out.dat", "w");
    char *commandLine = (char *) malloc(sizeof(char) * MAX_LINE_LENGTH);

    while (!feof(f)) {
        fscanf(f, "%s", commandLine);
        if (strcmp(commandLine, "AF") == 0) {
            fscanf(f, "%d", &a);
            addFirst(a, list);
        } else if (strcmp(commandLine, "AL") == 0) {
            fscanf(f, "%d", &a);
            addLast(a, list);
        } else if (strcmp(commandLine, "DE") == 0) {
            fscanf(f, "%d", &a);
            deleteElement(a, list);
        } else if (strcmp(commandLine, "PRINT_L") == 0) {
            fscanf(f, "%d", &a);
            printLast(a, list, g);
        } else if (strcmp(commandLine, "PRINT_F") == 0) {
            fscanf(f, "%d", &a);
            printFirst(a, list, g);
        } else if (strcmp(commandLine, "PRINT_ALL") == 0) {
            printAll(list, g);
        } else if (strcmp(commandLine, "DOOM_THE_LIST") == 0) {
            doomList(list);
        } else if (strcmp(commandLine, "DF") == 0) {
            deleteFirst(list);
        } else if (strcmp(commandLine, "DL") == 0) {
            deleteLast(list);
        }
    }
}