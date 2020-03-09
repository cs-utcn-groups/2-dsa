#include <stdio.h>
#include <stdlib.h>
#include "qwewes.h"
#include <string.h>

int main() {

    qwewe = instantiateQwewe();
    char *TIME = (char *) malloc(sizeof(char) * MAX_LEN);
    f = fopen("../dataIn.txt", "r");
    g = fopen("../dataOut.txt", "w");
    fgets(TIME, 256, f);

    char *name = (char *) malloc(sizeof(char) * MAX_NAME);
    int roubles, time;
    for( ;; )
    {
        fscanf(f, "%s", name);
        if( feof(f ))
            break;

        fscanf(f, "%d", &roubles);
        fscanf(f, "%d", &time);

        Node* new = instantiateNode(name, roubles, time);
        addNode(new);
    }

    char* p = strtok(TIME, " "), *end;
    int x_time;
    while(p != NULL)
    {
        x_time = strtol(p, &end, 10);
        fprintf(g, "After %d seconds -> %d\n", x_time, computeTime(x_time));
        p = strtok(NULL, " ");
    }
}