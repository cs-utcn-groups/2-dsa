#include <stdio.h>
#include <stdlib.h>

enum {VISITED, UNVISITED};
typedef struct Queue
{
    int nod;
    struct Queue *next;
}QueueT;

typedef struct Stack
{
    int nod;
    struct Stack *next;
}StackT;

void GetArcs(char *buf, int **a)
{
    int x, y;
    char letter;
    char *aux = (char*)malloc(sizeof(char)*10);

    int n;
    sscanf(buf, "%c %s %n", &letter, aux, &n);
    buf += n;
    while (sscanf(buf, "(%d %d) %n", &x, &y, &n)!=0 && x!=13 && y!=13)
    {
        a[x][y] = a[y][x] = 1;
        buf += n;
    }
}

void GetNodes(char *buf, int **a, int *nodes, int *MaxNode)
{
    int x;
    char letter;
    char *aux = (char*)malloc(sizeof(char)*10);

    int n;
    sscanf(buf, "%s %s %n", &letter, aux, &n);
    buf += n;
    while (sscanf(buf, "%d %n", &x, &n)!=0 && x!=13)
    {
        nodes[*MaxNode] = x;
        (*MaxNode)++;
        buf += n;
    }

}

void BFS(int MaxNode, int **a, int *nodes)
{
    int *mark = (int*)malloc(sizeof(int)*100);

    QueueT *queue = (QueueT*)malloc(sizeof(QueueT));
    queue->nod = nodes[0];
    printf("%d ", nodes[0]);
    queue->next = NULL;
    QueueT *first;
    first = queue;

    for (int i=0; i<=nodes[MaxNode-1]; i++)
        mark[i] = UNVISITED;

    mark[nodes[0]] = VISITED;

    while (first!=NULL)
    {
        int v = first->nod;

        for (int i=0; i<=nodes[MaxNode-1]; i++)
        {
            if (a[v][i] == 1 && mark[i]==UNVISITED)
            {
                mark[i] = VISITED;

                QueueT *node = (QueueT*)malloc(sizeof(QueueT));
                node->next = NULL;
                node->nod = i;
                queue->next = node;
                queue = node;
                printf("%d ", i);
            }
        }

        QueueT *aux = first;
        first = first->next;
        free(aux);
    }
    printf("\n");
}


void DFS(int MaxNode, int **a, int *nodes)
{
    int *mark = (int*)malloc(sizeof(int)*100);

    StackT *stack = (StackT*)malloc(sizeof(StackT));
    stack->next = NULL;
    stack->nod = nodes[0];
    printf("%d ", nodes[0]);


    for (int i=0; i<=nodes[MaxNode-1]; i++)
    {
        mark[i]=UNVISITED;
    }
    mark[nodes[0]]=VISITED;

    while (stack!=NULL)
    {
        int v = stack->nod;
        int ok =0;

        for (int i=0; i<=nodes[MaxNode-1]; i++)
        {
            if (a[v][i] == 1 && mark[i] == UNVISITED)
            {
                mark[i] = VISITED;
                StackT *node = (StackT*)malloc(sizeof(StackT));
                node->next = stack;
                node->nod = i;
                stack = node;

                printf("%d ", i);

                ok = 1;
                break;
            }
        }
        if (!ok)
        {
            StackT *aux = stack;
            stack = stack->next;
            free(aux);
        }
    }
    printf("\n");
}


int main()
{
    int *nodes = (int*)malloc(sizeof(int)*100);
    int MaxNode = 0;
    int **a = (int**)malloc(sizeof(int)*100);
    for (int i=0; i<100; i++)
    {
        nodes[i]=0;
        a[i] = (int*)malloc(sizeof(int)*100);
    }

    char **buf = (char**)malloc(sizeof(char)*3);
    for (int i=0; i<2; i++)
    {
        buf[i] = (char*)malloc(sizeof(char)*100);
        fgets(buf[i], 100, stdin);
        if (i==0)
        {
            GetNodes(buf[i], a, nodes, &MaxNode);
        }
        if (i==1)
        {
            GetArcs(buf[i], a);
        }
    }

    BFS(MaxNode, a, nodes);
    DFS(MaxNode, a, nodes);


    return 0;
}
