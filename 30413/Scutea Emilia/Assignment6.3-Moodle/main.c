#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define INFTY 1000
int ** cost;
int nrOfVertixes;

void readFile(FILE * f)
{
    int n,i,j;
    fscanf(f,"%d",&n);
    nrOfVertixes=n;
    cost=(int**)malloc(sizeof(int*)*nrOfVertixes);
    for(i=0; i<nrOfVertixes; i++)
        *(cost+i)=(int*)malloc(sizeof(int)*n);
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            fscanf(f,"%d",&cost[i][j]);
    fclose(f);
}

void printCost()
{
    int i,j;
    printf("The matrix is:\n");
    printf("   ");
    for(i=0; i<nrOfVertixes; i++)
        printf("%c   ",'A'+i);
    printf("\n");
    for(i=0; i<nrOfVertixes; i++)
    {
        printf("%c ",'A'+i);
        for(j=0; j<nrOfVertixes; j++)
            printf("%3d ",cost[i][j]);
        printf("\n");
    }
    printf("\n");
}
int minDistance(int dist[], bool sptSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < nrOfVertixes; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// A utility function to print the constructed distance array
void printSolution(int dist[])
{
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < nrOfVertixes; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int src)
{
    int dist[nrOfVertixes]; // The output array.  dist[i] will hold the shortest
    // distance from src to i

    bool sptSet[nrOfVertixes]; // sptSet[i] will be true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < nrOfVertixes; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < nrOfVertixes - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < nrOfVertixes; v++)

            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && cost[u][v] && dist[u] != INT_MAX
                && dist[u] + cost[u][v] < dist[v])
                dist[v] = dist[u] + cost[u][v];
    }

    // print the constructed distance array
    printSolution(dist);
}
int main()
{
    FILE * f=fopen("input.dat","r");
    readFile(f);
    printCost();
    printf("dijk:\n");
    dijkstra(3);
}
