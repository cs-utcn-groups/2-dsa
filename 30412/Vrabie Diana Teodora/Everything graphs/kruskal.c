//
// Created by diana on 10/05/2020.
//

#include "kruskal.h"

/*
 * 1. sort all edges in non-decreasing order of weight
 * 2. pick smallest edge, check if it forms a cycle with the
 *    spanning tree formed so far; if it doesn't, add edge to
 *    spanning tree. Else, discard it.
 * 3. repeat step 2 until there are V-1 edges in the spanning tree
 */

int find(Subset *subsets, int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void unionFun(Subset *subsets, int x, int y) {
    int xRoot = find(subsets, x);
    int yRoot = find(subsets, y);

    if (subsets[xRoot].rank < subsets[yRoot].rank)
        subsets[xRoot].parent = yRoot;
    else if (subsets[xRoot].rank > subsets[yRoot].rank)
        subsets[yRoot].parent = xRoot;
    else {
        subsets[yRoot].parent = xRoot;
        subsets[xRoot].rank++;
    }
}

int compare(const void *a, const void *b) {
    // function used by qsort
    Edge *edgeA = (Edge *) a;
    Edge *edgeB = (Edge *) b;
    return edgeA->weight > edgeB->weight;
}

void kruskal(Graph *graph) {
    int nrOfVertices = graph->nrOfVertices;
    Edge result[nrOfVertices];
    int e = 0, i = 0;

    // Step 1:  Sort all the edges in non-decreasing order of their weight.
    qsort(edges, 7, sizeof(edges[0]), compare);

    Subset *subsets = (Subset *) malloc(nrOfVertices * sizeof(Subset));

    for (int j = 0; j < nrOfVertices; ++j) {
        subsets[j].parent = j;
        subsets[j].rank = 0;
    }

    while (e < nrOfVertices - 1 && i < 7) { // 7 is nr of edges
        Edge nextEdge = edges[i++];

        int x = find(subsets, nextEdge.source);
        int y = find(subsets, nextEdge.destination);

        if (x != y)
        {
            result[e++] = nextEdge;
            unionFun(subsets, x, y);
        }
    }

    printf("Following are the edges in the constructed MST\n");
    for (i = 0; i < e; ++i)
        printf("%d -- %d == %d\n", result[i].source, result[i].destination,
               result[i].weight);
}