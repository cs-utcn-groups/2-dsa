#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    struct node * next;
}nodeG;

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

void readGraph ()
{
    FILE * fin = fopen ("input.txt", "r");
    fscanf (fin, "%d\n", &N);
    initialize ();
    int x, y;
    while (fscanf (fin, "%d %d\n", &x, &y) > 0)
    {
        graph[x][y] = graph[y][x] = 1;
    }
    fclose (fin);
}

void add2list (int vertex, int key)
{
    nodeG * p = (nodeG*) malloc (sizeof (nodeG));
    p->key = key;
    p->next = adjList[vertex];
    adjList[vertex] = p;
}

void transform2AdjList ()
{
    for (int vertex = 0; vertex < N; vertex++)
    {
        for (int i = 0; i < vertex; i++)
        {
            if (graph[vertex][i])
            {
                add2list (vertex, i);
                add2list (i, vertex);
            }
        }
    }
}

void printList ()
{
    for (int i = 0; i < N; i++)
    {
        printf ("Adjacent vertices of %d: ", i);
        for (nodeG * q = adjList[i]; q != NULL; q = q->next)
            printf ("%d ", q->key);
        printf ("\n");
    }
}

void bfs (int src)
{
    int left, right;
    left = right = 0;
    queue[0] = src;
    visited[src] = 1;
    printf ("%d ", src);
    while (left <= right)
    {
        int v = queue[left];
        left++;
        for (nodeG * q = adjList[v]; q != NULL; q = q->next)
        {
            if (visited[q->key] == 0)
            {
                printf ("%d ", q->key);
                visited[q->key] = 1;
                right++;
                queue[right] = q->key;
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
    for (nodeG * q = adjList[src]; q != NULL; q = q->next)
    {
        if (visited[q->key] == 0)
        {
            dfs (q->key);
        }
    }
}

int main()
{
    readGraph ();
    transform2AdjList ();
    printList ();
    printf ("BFS traversal from 0 is: ");
    bfs (0);
    reinitVis ();
    printf ("DFS traversal from 0 is: ");
    dfs (0);
    return 0;
}
