#include "graphRepresentations.h"
#include "graphTraversals.h"
#define DATA_PATH "../matrix.txt"


int main() {
    FILE * fin;
    fin = fopen(DATA_PATH,"r");

    createAdjacencyList(fin);
    printAdjacencyList();

    createAdjMatrix();
    printAdjMatrix();

    bfs('G'-'A');
    dfs('G'-'A');
    dfsRecurs('G' - 'A');

    fclose(fin);

    return 0;
}