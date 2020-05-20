#include <stdio.h>
#include <stdlib.h>
#define INF 999999999


typedef struct _queue
{
    int nod;
    struct _queue *next;
}QUEUE;

void Dijkstra(int node, int **G, int **C, int *parent, int *dist)
{
    dist[node] = 0;
    parent[node] = 0;

    QUEUE *queue = (QUEUE*)malloc(sizeof(QUEUE));
    queue->next = 0;
    queue->nod = node;

    QUEUE *first = queue;

    while (first!=NULL)
    {
        int x = first->nod;

        for (int i=1; i<=G[x][0]; i++)
        {
            if (dist[G[x][i]] > dist[x] + C[x][i])
            {
                dist[G[x][i]] = dist[x] + C[x][i];
                parent[G[x][i]] = x;

                QUEUE *newNode = (QUEUE*)malloc(sizeof(QUEUE));
                newNode->next = NULL;
                newNode->nod = G[x][i];
                queue->next = newNode;
                queue = newNode;
            }
        }

        QUEUE *aux = first;
        first = first->next;
        free(aux);

    }
}

void Path(int nod2, int *parent, int **C, int *dist)
{
    int *aux = (int*)malloc(sizeof(int)*100);
    int index = 0;
    aux[0] = nod2;
    int p = parent[nod2];

    while (p != 0)
    {
        index++;
        aux[index] = p;
        p = parent[p];
    }
    printf("%d ", dist[nod2]);
    printf("1");
    for (int i=index-1; i>=0; i--)
    {
        printf("-%d", aux[i]);
    }

}

int main()
{
    int x, y, c;
    int *parent = (int*)malloc(sizeof(int)*100);
    int **G = (int**)malloc(sizeof(int)*100);
    int **C = (int**)malloc(sizeof(int)*100);
    for (int i=0; i<100; i++)
    {
        G[i] = (int*)malloc(sizeof(int)*100);
        C[i] = (int*)malloc(sizeof(int)*100);
        G[i][0] = C[i][0] = 0;
    }
    int *dist = (int*)malloc(sizeof(int)*100);
    for (int i=0;i<100; i++)
    {
        dist[i] = INF;
    }

    int Max=0;
    char *buf = (char*)malloc(sizeof(char)*100);
    FILE *f = fopen("input.in", "r");
    while (fgets(buf, 100, f)!=NULL)
    {
        sscanf(buf, "%d,%d=%d\n", &x, &y, &c);
        if (x>Max) Max=x;
        if (y>Max) Max=y;
        G[x][0]++;
        G[x][G[x][0]] = y;
        C[x][0]++;
        C[x][C[x][0]] = c;
    }

    Dijkstra(1,G,C,parent,dist);
    Path(4, parent, C,dist);

    return 0;
}
