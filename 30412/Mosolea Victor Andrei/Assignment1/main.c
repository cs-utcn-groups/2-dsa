#include <stdio.h>
#include <string.h>
#include "head.h"

int main() {
    List list = createList();
    FILE *f = fopen("../input.dat", "r");
    FILE *g = fopen("../output.dat", "w");
    while (feof(f) == 0) {
        char command[MAX_COMMAND];
        int x;
        fscanf(f, "%s", command);
        if (strcmp(command, "AF") == 0) {
            fscanf(f, "%d", &x);
            addElementFirst(x, &list);
        } else if (strcmp(command, "AL") == 0) {
            fscanf(f, "%d", &x);
            addElementLast(x, &list);
        } else if (strcmp(command, "DF") == 0)
            deleteFirst(&list);
        else if (strcmp(command, "DL") == 0)
            deleteLast(&list);
        else if (strcmp(command, "DOOM_THE_LIST") == 0)
            removeAll(&list);
        else if (strcmp(command, "DE") == 0) {
            fscanf(f, "%d", &x);
            deleteElement(x, &list);
        } else if (strcmp(command, "PRINT_ALL") == 0)
            printList(list, g);
        else if (strcmp(command, "PRINT_F") == 0) {
            fscanf(f, "%d", &x);
            printFirstN(x, list, g);
        } else if (strcmp(command, "PRINT_L") == 0) {
            fscanf(f, "%d", &x);
            printLastN(x, list, g);
        }
    }
}