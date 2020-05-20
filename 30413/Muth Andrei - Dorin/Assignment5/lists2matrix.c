#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    struct node * next;
} nodeG;

nodeG ** adjList;

int ** graph, N, * visited, * queue;

void initialize ()
{
    graph = (int**) malloc (sizeof (int*) * N);
    for (int i = 0; i < N; i++)
    {
        graph[i] = (int*) malloc (sizeof (int) * N);
        for (int j = 0; j < N; j++)
        {
            graph[i][j] = 0;
        }
    }
    visited = (int*) malloc (sizeof (int) * N);
    queue = (int*) malloc (sizeof (int) * N);
    adjList = (nodeG**) malloc (sizeof (nodeG*) * N);
    for (int i = 0; i < N; i++)
    {
        visited[i] = 0;
        adjList[i] = NULL;
    }
}

void add2list (int x, int y)
{
    nodeG * p = (nodeG*) malloc (sizeof (nodeG));
    p->key = y;
    p->next = adjList[x];
    adjList[x] = p;
}

void readGraph ()
{
    FILE * fin = fopen ("input.txt", "r");
    fscanf (fin, "%d\n", &N);
    initialize ();
    int x, y;
    while (fscanf (fin, "%d %d\n", &x, &y) > 0)
    {
        add2list (x, y);
        add2list (y, x);
    }
    fclose (fin);
}

void transform2matrix ()
{
    for (int i = 0; i < N - 1; i++)
    {
        for (nodeG * q = adjList[i]; q != NULL; q = q->next)
        {
            graph[i][q->key] = graph[q->key][i] = 1;
        }
    }
}

void printMatrix ()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf ("%d ", graph[i][j]);
        }
        printf ("\n");
    }
}

void bfs (int src)
{
    int left, right;
    left = right = 0;
    printf ("%d ", src);
    queue[0] = src;
    visited[src] = 1;
    while (left <= right)
    {
        int v = queue[left];
        left++;
        for (int i = 0; i < N; i++)
        {
            if (graph[v][i] && visited[i] == 0)
            {
                printf ("%d ", i);
                visited[i] = 1;
                right++;
                queue[right] = i;
            }
        }
    }
    printf ("\n");
}

void reinitVis ()
{
    for (int i = 0; i < N; i++)
    {
        visited[i] = 0;
    }
}

void dfs (int src)
{
    printf ("%d ", src);
    visited[src] = 1;
    for (int i = 0; i < N; i++)
    {
        if (graph[src][i] && visited[i] == 0)
        {
            dfs (i);
        }
    }
}

int main ()
{
    readGraph ();
    transform2matrix ();
    printMatrix ();
    printf ("BFS traversal from 0 is: ");
    bfs (0);
    reinitVis ();
    printf ("DFS traversal from 0 is: ");
    dfs (0);
    return 0;
}
