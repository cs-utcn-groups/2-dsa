#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nrOfVertices 5
#define maxNrOfEdges 20

typedef struct edge {
    int source;
    int destination;
} Edge;

int *getVertices(FILE *f) {
    char *buffer = (char *) malloc(sizeof(char) * 60);
    int *arrayOfVertices = (int *) malloc(sizeof(int) * nrOfVertices);
    fgets(buffer, 60, f);
    char *pch = strtok(buffer, " ");
    pch = strtok(NULL, " ");
    pch = strtok(NULL, " ");
    int nr = 0;
    while (pch != NULL) {
        arrayOfVertices[nr] = atoi(pch);
        nr++;
        pch = strtok(NULL, " ");
    }
    return arrayOfVertices;
}

void checkArcs(int nrOfEdges, int nrOfPartialVert, Edge *edges, int *arrayOfVerticesPartial) {
    printf("V' arcs: ");
    for (int i = 0; i < nrOfEdges - 1; i++) {
        int ok1 = 0, ok2 = 0;
        for (int j = 0; j < nrOfPartialVert; j++) {
            if (edges[i].source == arrayOfVerticesPartial[j]) {
                ok1 = 1;
            }
            if (edges[i].destination == arrayOfVerticesPartial[j]) {
                ok2 = 1;
            }
        }
        if (ok1 == 1 && ok2 == 1) {
            printf("(%d %d) ", edges[i].source, edges[i].destination);
        }
    }
}

int main() {
    FILE *f;
    f = fopen("input.txt", "r");
    char *buffer = (char *) malloc(sizeof(char) * 60);
    int *arrayOfVertices = (int *) malloc(sizeof(int) * nrOfVertices);
    int *arrayOfVerticesPartial = (int *) malloc(sizeof(int) * nrOfVertices);
    Edge *edges = (Edge *) malloc(sizeof(Edge) * maxNrOfEdges);

    int *array = getVertices(f);

    fgets(buffer, 60, f);
    char *pch = strtok(buffer, " ");
    pch = strtok(NULL, " ");
    pch = strtok(NULL, ")");
    edges[0].source = atoi(&pch[1]);
    edges[0].destination = atoi(&pch[3]);
    int index = 1;
    pch = strtok(NULL, ")");
    while (pch != NULL) {
        edges[index].source = atoi(&pch[2]);
        edges[index].destination = atoi(&pch[4]);
        index++;
        pch = strtok(NULL, ")");
    }

    fgets(buffer, 60, f);
    pch = strtok(buffer, " ");
    pch = strtok(NULL, " ");
    pch = strtok(NULL, " ");
    int index1 = 0;
    while (pch != NULL) {
        arrayOfVerticesPartial[index1] = atoi(pch);
        index1++;
        pch = strtok(NULL, " ");
    }

    checkArcs(index,index1,edges,arrayOfVerticesPartial);

    fclose(f);
    return 0;
}