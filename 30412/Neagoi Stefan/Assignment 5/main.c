
#include "header.h"

int main() {

    FILE *f;
    f = fopen("../matrix.dat", "r");

    readAdjMatrix(f);
    printAdjMatrix();

        int V = 5;
        GraphT* graph = getGraphFromMatrix(noOfVertices);
        printGraph(graph);

        return 0;
    }

