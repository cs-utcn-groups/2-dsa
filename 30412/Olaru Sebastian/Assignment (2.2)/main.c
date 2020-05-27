#include "queue.h"

int main() {
    line = (Line *) malloc(sizeof(Line));
    line->first = NULL;
    line->last = NULL;

    fin = fopen("input.dat", "r");
    fout = fopen("output.dat", "w+");
    int c, i = 0;
    do {
        fscanf(fin, "%d", &timeTable[i]);
        c = getc(fin);
        i++;
    } while (c != '\n');

    while (!feof(fin)) {
        addCustomer();
    }
    prettyPrint(i);
    return 0;
}

