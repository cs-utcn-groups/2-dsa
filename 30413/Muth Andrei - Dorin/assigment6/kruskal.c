#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int x;
    int y;
    int weight;
} edgeT;

edgeT * edges, * MSTEdges;
int N, E, * parent, edgesInMST;

void initialize ()
{
    edges = (edgeT*) malloc (sizeof (edgeT) * N * (N - 1) / 2);
    parent = (int*) malloc (sizeof (int) * N);
    for (int i = 0; i < N; i++)
    {
        parent[i] = i;
    }
    MSTEdges = (edgeT*) malloc (sizeof (edgeT) * (N - 1));
}

void readGraph ()
{
    FILE * fin = fopen ("kruskal.in", "r");
    fscanf (fin, "%d\n", &N);
    initialize ();
    int x, y, weight;
    E = 0;
    while (fscanf (fin, "%d %d %d\n", &x, &y, &weight) > 0)
    {
        edges[E].x = x;
        edges[E].y = y;
        edges[E].weight = weight;
        E++;
    }
    fclose (fin);
}

void sortEdgesByWeight ()
{
    for (int i = 0; i < E - 1; i++)
    {
        for (int j = i + 1; j < E; j++)
        {
            if (edges[i].weight > edges[j].weight)
            {
                edgeT aux = edges[i];
                edges[i] = edges[j];
                edges[j] = aux;
            }
        }
    }
}

int findAncestor (int v)
{
    if (v == parent[v])
        return v;
    return findAncestor (parent[v]);
}

void uniteSubtrees (int x, int y, edgeT edge)
{
    parent[y] = x;
    MSTEdges[edgesInMST] = edge;
    edgesInMST++;
}

void printOutput (int minCost)
{
    printf ("Kruskal MST is:\n");
    for (int i = 0; i < N - 1; i++)
    {
        printf ("%d -> %d\n", MSTEdges[i].x, MSTEdges[i].y);
    }
    printf ("The cost of Kruskal MST is: %d.\n", minCost);
}

void kruskal ()
{
    int currentEdge = 0, minCost = 0;
    edgesInMST = 0;;
    while (edgesInMST < N - 1)
    {
        int x = edges[currentEdge].x;
        int y = edges[currentEdge].y;
        int weight = edges[currentEdge].weight;
        int xroot = findAncestor (x);
        int yroot = findAncestor (y);
        if (xroot != yroot)
        {
            uniteSubtrees (x, y, edges[currentEdge]);
            minCost += weight;
        }
        currentEdge++;
    }
    printOutput (minCost);
}

int main ()
{
    readGraph ();
    sortEdgesByWeight ();
    kruskal ();
    return 0;
}
