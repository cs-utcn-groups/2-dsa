#include <stdio.h>
#include "graphRepresentation.h"
#include "graphTraversals.h"
#include "list.h"

int main() {
    FILE *f = fopen("../matrix.txt","r");
    if(f==NULL) perror("ERROR");

    readFromAdjMatrix(f);
    printAdjMatrix();
    NodeT **list = adjToList();
    //printList(list);
    int **a = listToAdj(list);
    printMatrix(a);

    return 0;
}