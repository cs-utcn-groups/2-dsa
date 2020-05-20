#include <stdio.h>
#include <stdlib.h>

int *parent;
int **G;
int *dist;
int n,m;

typedef struct _queue
{
    int nod;
    struct _queue *next;
}QUEUE;

void CalculatePath(int a, int b)
{
    int **mark = (int**)malloc(sizeof(int)*(n+1));
    for (int i=0; i<=n; i++)
    {
        mark[i] = (int*)malloc(sizeof(int)*(n+1));
        for (int j=0; j<=n; j++)
        {
            mark[i][j]=0;
        }
    }

    dist[a] = 0;
    parent[a] = 0;

    QUEUE *queue = (QUEUE*)malloc(sizeof(QUEUE));
    queue->next = NULL;
    queue->nod = a;

    QUEUE *first = queue;

    while (first!=NULL)
    {
        int x = first->nod;

        for (int i=1; i<=G[x][0]; i++)
        {
            if (mark[x][G[x][i]]==0)
            {
                if (dist[G[x][i]] < dist[x] + 1)
                {
                    dist[G[x][i]] = dist[x] + 1;
                    parent[G[x][i]] = x;

                    if (G[x][i]!=b)
                    {
                        QUEUE *newNode = (QUEUE*)malloc(sizeof(QUEUE));
                        newNode->next = NULL;
                        newNode->nod = G[x][i];
                        queue->next = newNode;
                        queue = newNode;
                    }
                    mark[x][G[x][i]] = mark[G[x][i]][x] = 1; //visited
                }
            }
        }

        QUEUE *aux = first;
        first = first->next;
        free(aux);

    }
}

void Path(int nod1, int nod2)
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
    printf("%d\n", dist[nod2]);

    for (int i=index; i>=0; i--)
    {
        printf("%d ", aux[i]);
    }

}

void longestPath(int a, int b)
{
    CalculatePath(a, b);
    Path(a,b);
}

int main()
{
    int x, y;
    parent = (int*)malloc(sizeof(int)*100);
    G = (int**)malloc(sizeof(int)*100);
    for (int i=0; i<100; i++)
    {
        G[i] = (int*)malloc(sizeof(int)*100);
        G[i][0] = 0;
    }
    dist = (int*)malloc(sizeof(int)*100);
    for (int i=0;i<100; i++)
    {
        dist[i] = 0;
    }

    scanf("%d%d", &n, &m);

    for (int i=0; i<m; i++)
    {
        scanf("%d%d", &x,&y);

        G[x][0]++;
        G[x][G[x][0]] = y;
        G[y][0]++;
        G[y][G[y][0]] = x;
    }

    int a,b;
    scanf("%d%d", &a,&b);

    longestPath(a,b);

    return 0;
}

