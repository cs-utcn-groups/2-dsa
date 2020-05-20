#include <stdio.h>
#include <stdlib.h>
#define INF 2147483647

typedef struct
{
    int src;
    int dest;
    int weight;
} edgeT;

edgeT * edges;
int * distances, N, E;

void initialize ()
{
    edges = (edgeT*) malloc (sizeof (edgeT) * N * (N - 1));
    distances = (int*) malloc (sizeof (int) * N);
    for (int i = 0; i < N; i++)
    {
        distances[i] = INF;
    }
}

void readGraph ()
{
    FILE * fin = fopen ("input.txt", "r");
    fscanf (fin, "%d\n", &N);
    initialize ();
    int x, y, weight;
    E = 0;
    while (fscanf (fin, "%d %d %d\n", &x, &y, &weight) > 0)
    {
        edges[E].src = x;
        edges[E].dest = y;
        edges[E].weight = weight;
        E++;
    }

    fclose (fin);
}

int negativeCycle ()
{
    for (int i = 0; i < E; i++)
    {
        int x = edges[i].src;
        int y = edges[i].dest;
        int weight = edges[i].weight;
        if (distances[x] != INF && distances[x] + weight < distances[y])
        {
            printf ("Graph contains a negative weight cycle.\n");
            return 1;
        }
    }
    return 0;
}

void printDistances (int src)
{
    for (int i = 0; i < N; i++)
    {
        printf ("Distance from %d to %d is: %d.\n", src, i, distances[i]);
    }
}

void bellmanFord (int src)
{
    distances[src] = 0;

    for (int count = 0; count < N - 1; count++)
    {
        for (int i = 0; i < E; i++)
        {
            int x = edges[i].src;
            int y = edges[i].dest;
            int weight = edges[i].weight;
            if (distances[x] != INF && distances[x] + weight < distances[y])
            {
                distances[y] = distances[x] + weight;
            }
        }
    }

    if (!negativeCycle ())
    {
        printDistances (src);
    }
}

int main()
{
    readGraph ();
    bellmanFord (0);
    return 0;
}
