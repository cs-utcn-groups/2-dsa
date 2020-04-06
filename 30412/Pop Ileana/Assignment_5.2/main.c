#include "graphRepresentation.h"
#include "dfs.h"

#define DATA_PATH "../matrix.txt"

int main() {

    int a, b;

    FILE * fin;
    fin = fopen(DATA_PATH,"r");

    createAdjacencyList(fin);
    printAdjacencyList();

    int maxLen=longestPath(&a,&b);
    if(maxLen==0)
        printf("There is no path between %d and %d",a,b);
    else {
        printf("The longest path between %d and %d has %d edges\n", a, b, maxLen - 1);
        printf("The longest path is:\n");
        printPath();
    }

    return 0;
}