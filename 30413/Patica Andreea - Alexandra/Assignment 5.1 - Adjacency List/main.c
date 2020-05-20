#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int vertex;
    struct _node *next;
}NODE;
typedef struct _graph
{
    int numVertices;
    NODE **adjList;
}GRAPH;

NODE* createNode(int v)
{
    NODE *newNode = (NODE*)malloc(sizeof(NODE));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(GRAPH *graph, int src, int dest)
{
    NODE * newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

void MatrixToList(int **A, GRAPH *graph, int n)
{
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            if (A[i][j]==1)
            {
                addEdge(graph, i, j);
            }
        }
    }
}

void ListToMatrix(int **A, GRAPH *graph, int n)
{
    NODE *temp = (NODE*)malloc(sizeof(NODE));
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            A[i][j]=0;
        }
    }
    for (int i=0; i<n; i++)
    {
        temp = graph->adjList[i+1];
        while (temp!=NULL)
        {
            A[i+1][temp->vertex] = 1;
            temp = temp->next;
        }
    }
}

int main()
{
    int n, m, x, y;
    scanf("%d%d", &n, &m);
    int **A = (int**)malloc(sizeof(int)*(n+1));
    for (int i=0; i<=n; i++)
    {
        A[i] = (int*)malloc(sizeof(int)*(n+1));
        for (int j=0; j<=n; j++)
            A[i][j]=0;
    }

    for (int i=0; i<m; i++)
    {
        scanf("%d%d", &x, &y);
        A[x][y] = A[y][x] = 1;
    }

    GRAPH *graph = (GRAPH*)malloc(sizeof(GRAPH));
    graph->adjList = (NODE**)malloc(sizeof(NODE)*(n+1));
    for (int i=1; i<=n; i++)
    {
        graph->adjList[i]=createNode(0);
    }
    MatrixToList(A,graph, n);
    ListToMatrix(A, graph, n);
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
            printf("%d",A[i][j]);
        printf("\n");
    }
    return 0;
}
