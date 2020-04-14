
#include "header.h"

int main() {

    FILE *f;
    f = fopen("../matrix.dat", "r");
    readAdjMatrix(f);
    printAdjMatrix();


    GraphT* graph = createNewGraph(noOfVertices);
    graph->noEdges = 8;
    graph->noVertices = 5;

    // add edge 0-1
    graph->edge[0].source = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].length = -1;

    // add edge 0-2
    graph->edge[1].source = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].length = 4;

    // add edge 1-2
    graph->edge[2].source = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].length = 3;

    // add edge 1-3
    graph->edge[3].source = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].length = 2;

    // add edge 1-4
    graph->edge[4].source = 1;
    graph->edge[4].dest = 4;
    graph->edge[4].length = 2;

    // add edge 3-2
    graph->edge[5].source = 3;
    graph->edge[5].dest = 2;
    graph->edge[5].length = 5;

    // add edge 3-1
    graph->edge[6].source = 3;
    graph->edge[6].dest = 1;
    graph->edge[6].length = 1;

    // add edge 4-3
    graph->edge[7].source = 4;
    graph->edge[7].dest = 3;
    graph->edge[7].length = -3;


    BellmanFord(graph, 0);

    edgeIndex = 0;
    GraphT *Graph = getGraphFromMatrix();
    KruskalMST(Graph);

        return 0;
    }



