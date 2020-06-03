#include <stdio.h>
#include "graphRep.h"
#include "graphTraversals.h"
#include "list.h"
#include "graphAlg.h"

int main() {
    FILE *f = fopen("../matrix.txt","r");
    if(f==NULL) perror("ERROR");

    readFromAdjMatrix(f);
    //dijkstra(2);
    kruskal();
    //bellamn(2);

    return 0;
}