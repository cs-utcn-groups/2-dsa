///
// Created by acer on 4/11/2020.
//

#include "graphAlgorithms.h"

int findParrent(int *parent, int i) {
    if (parent[i] == -1)
        return i;
    return findParrent(parent, parent[i]);
}

void makeUnion(int *parent, int x, int y) {
    int xset = findParrent(parent, x);
    int yset = findParrent(parent, y);
    if (xset != yset) {
        parent[xset] = yset;
    }
}

int findCycle(int E, int V, edgeT **edges) {
    int *parent = (int *) malloc(V * sizeof(int));
    for (int i = 0; i < V; i++)
        parent[i] = -1;

    for (int i = 0; i < E; ++i) {
        int x = findParrent(parent, edges[i]->src);
        int y = findParrent(parent, edges[i]->dest);
        if (x == y)
            return 1;
        makeUnion(parent, x, y);
    }
    return 0;
}

int inputMatrix(int **AdjMatrix, int V) {
    int x;
    int no = 0;
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++) {
            fscanf(fin, "%d", &x);
            if (x != 0) {
                AdjMatrix[i][j] = x;
                no++;
            }
        }
    return no;
}

void initializeMatrix(int V) {
    AdjMatrix = (int **) malloc(sizeof(int *) * V);
    for (int i = 0; i < V; i++)
        AdjMatrix[i] = (int *) malloc(sizeof(int) * V);

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            AdjMatrix[i][j] = 0;
}

void findEdges(edgeT **edges, int V) {
    int index = 0;
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            if (AdjMatrix[i][j] != 0) {
                edges[index] = (edgeT *) malloc(sizeof(edgeT));
                edges[index]->src = i;
                edges[index]->dest = j;
                edges[index]->weight = AdjMatrix[i][j];
                index++;
            }
}

void sortEdges(int E, edgeT **edges) {
    for (int i = 0; i < E; i++)
        for (int j = i + 1; j < E; j++)
            if (edges[i]->weight > edges[j]->weight) {
                edgeT *temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
}

void kruskal(int V, int E, edgeT **e) {
    edgeT **edges = (edgeT **) malloc(sizeof(edgeT *) * E);
    for (int i = 0; i < E; i++) {
        edges[i] = (edgeT *) malloc(sizeof(edgeT));
        edges[i]->src = e[i]->src;
        edges[i]->dest = e[i]->dest;
        edges[i]->weight = e[i]->weight;
    }
    edgeT **spanTree = (edgeT **) malloc(sizeof(edgeT) * (V - 1));
    int i = 0;
    while (i != V - 1) {
        sortEdges(E, edges);
        if (spanTree[i] == NULL)
            spanTree[i] = (edgeT *) malloc(sizeof(edgeT));

        spanTree[i] = edges[0];
        if (!findCycle(i + 1, V, spanTree))
            i++;

        for (int i = 0; i < E - 1; i++)
            edges[i] = edges[i + 1];
        E--;
    }

    for (int i = 0; i < E; i++)
        free(edges[i]);
    free(edges);

    for (int j = 0; j < V - 1; j++)
        printf("%d -> %d = %d\n", spanTree[j]->src, spanTree[j]->dest, spanTree[j]->weight);

}

void bellmanFord(int V, int E, edgeT **edges) {
    int source = 0;
    int dist[V];
    for (int i = 0; i < V; i++)
        dist[i] = MAX;
    dist[source] = 0;

    for (int i = 1; i < V; ++i) {
        for (int j = 0; j < E; ++j) {
            int u = edges[j]->src;
            int v = edges[j]->dest;
            int weight = edges[j]->weight;
            if (dist[u] != MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    for (int j = 0; j < E; ++j) {
        int u = edges[j]->src;
        int v = edges[j]->dest;
        int weight = edges[j]->weight;
        if (dist[u] != MAX && dist[u] + weight < dist[v]) {
            printf("negative wieght cycle");
            return;
        }
    }

    for (int i = 0; i < V; i++)
        printf("distance(%d) = %d \n", i, dist[i]);

}