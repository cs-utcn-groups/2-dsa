#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    struct node * next;
} NodeT;

typedef struct queue
{
    NodeT * qFirst;
    NodeT * qLast;
} QueueT;

typedef struct stack
{
    NodeT * sFirst;
} StackT;

int ** readFromAdjMat(FILE * f,int nrOfNodes)
{
    int n=nrOfNodes;
    int i,j;
    int ** adjMat=(int**)malloc(n*sizeof(int*));
    for (i=0; i<n; i++)
    {
        *(adjMat+i)=(int*)malloc(n*sizeof(int));
    }

    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            fscanf(f,"%d",&adjMat[i][j]);
        }
    }
    return adjMat;
}


NodeT * createNode(int data)
{
    NodeT * p;
    p = (NodeT*)malloc(sizeof(NodeT));
    p->key = data;
    p->next = NULL;
    return p;
}

QueueT *createEmptyQueue()
{
    QueueT *pL = (QueueT*)malloc(sizeof(QueueT));
    if(pL != NULL)
    {
        pL->qFirst = NULL;
        pL->qLast = NULL;
    }
    return pL;
}

void enqueue(QueueT* q, int data)
{
    NodeT * p;
    p = createNode(data);
    if(q->qLast != NULL)
    {
        q->qLast->next = p;
    }
    if(q->qFirst == NULL)
    {
        q->qFirst = p;
    }
    q->qLast = p;
}

int dequeue(QueueT *q)
{
    NodeT *p = q->qFirst;
    int a = q->qFirst->key;
    q->qFirst = p->next;
    free(p);
    if(q->qFirst == NULL)
    {
        q->qLast = NULL;
    }
    return a;
}

void bfsMat (int nrOfNodes, int srcNode, int **adjMat)
{

    int mark[nrOfNodes], i, j, k;
    QueueT *Q = (QueueT*)malloc(sizeof(QueueT));
    Q = createEmptyQueue();
    for (i = 0; i < nrOfNodes; i++)
    {
        mark[i] = 0;
    }
    mark[srcNode] = 1;
    enqueue(Q, srcNode);
    while (Q->qFirst != NULL)
    {
        j = dequeue(Q);
        printf("%d ", j);
        for (k = 0; k < nrOfNodes; k++)
        {
            if(adjMat[j][k] == 1 && mark[k] == 0)
            {
                mark[k] = 1;
                enqueue(Q,k);
            }
        }
    }
}

StackT * createEmptyStack()
{

    StackT *pL = (StackT*)malloc(sizeof(StackT));
    if(pL != NULL)
    {
        pL->sFirst = NULL;
    }
    return pL;

}

void push(StackT * stack, int data)
{
    NodeT * newNode = createNode(data);
    newNode->next = stack->sFirst;
    stack->sFirst = newNode;
}

void pop(StackT * stack)
{
    if(stack->sFirst != NULL)
    {
        NodeT * p = stack->sFirst;
        stack->sFirst = stack->sFirst->next;
        free(p);
    }
    return;
}

void dfsMat (int nrOfNodes, int srcNode, int **adjMat)
{
    int mark[nrOfNodes], i, j;
    StackT * stack = (StackT*)malloc(sizeof(StackT));
    stack = createEmptyStack();
    for(i = 0; i < nrOfNodes; i++)
    {
        mark[i] = 0;
    }
    mark[srcNode] = 1;
    printf("%d ", srcNode);
    push(stack, srcNode);
    while (stack->sFirst != NULL)
    {
        int top = stack->sFirst->key;
        for(j = 0; j < nrOfNodes; j++)
        {
            if(adjMat[top][j] == 1)
            {
                if(mark[j] == 0)
                {
                    mark[j] = 1;
                    printf("%d ", j);
                    push(stack, j);
                }
                else
                    pop(stack);
            }
        }
    }
    printf("\n");
}

NodeT ** matToList(int ** adjMat, int nrOfNodes)
{
    int i, j;
    NodeT ** adjList = (NodeT**)malloc(sizeof(NodeT*)* nrOfNodes);
    for(i=0; i<nrOfNodes; i++)
    {
        adjList[i] = createNode(i);
        for(j=0; j<nrOfNodes; j++)
        {
            if(adjMat[i][j] == 1)
            {
                NodeT * p = adjList[i];
                while(p->next != NULL)
                {
                    p = p->next;
                }
                p->next = createNode(j);
            }
        }
    }
    return adjList;
}

int ** listToMat(NodeT ** adjList, int nrOfNodes)
{
    int i;
    int ** adjMat = (int**)malloc(nrOfNodes * sizeof(int));
    for(i=0; i<nrOfNodes; i++)
    {
        adjMat[i] = (int*)calloc(nrOfNodes, sizeof(int));
    }
    for(i=0; i<nrOfNodes; i++)
    {
        NodeT *p = adjList[i];
        while(p->next != NULL)
        {
            p = p->next;
            adjMat[i][p->key] = 1;
        }
    }
    return adjMat;
}

void bfsList (int nrOfNodes, int srcNode, NodeT **adjList)
{
    int mark[nrOfNodes], i, j;
    QueueT *Q = (QueueT*)malloc(sizeof(QueueT));
    Q = createEmptyQueue();
    for (i = 0; i < nrOfNodes; i++)
    {
        mark[i] = 0;
    }
    mark[srcNode] = 1;
    enqueue(Q, srcNode);
    while (Q->qFirst != NULL)
    {
        j = dequeue(Q);
        printf("%d ", j);
        NodeT * p = adjList[j];
        while(p->next != NULL)
        {
            p = p->next;
            if(mark[p->key] == 0)
            {
                mark[p->key] = 1;
                enqueue(Q, p->key);
            }
        }
    }
    printf("\n");
}

void dfsList (int nrOfNodes, int srcNode, NodeT **adjList)
{
    int mark[nrOfNodes], i;
    StackT * stack = (StackT*)malloc(sizeof(StackT));
    stack = createEmptyStack();
    for(i = 0; i < nrOfNodes; i++)
    {
        mark[i] = 0;
    }
    mark[srcNode] = 1;
    printf("%d ", srcNode);
    push(stack, srcNode);
    while (stack->sFirst != NULL)
    {
        int top = stack->sFirst->key;
        NodeT * p = adjList[top];
        while(p->next != NULL)
        {
            p = p->next;
            if(mark[p->key] == 0)
            {
                mark[p->key] = 1;
                printf("%d ", p->key);
                push(stack, p->key);
            }
            else
            {
                pop(stack);
            }
        }
    }
    printf("\n");
}

int main()
{

    FILE * f = fopen("input5.txt", "r");
    int nrOfNodes;
    fscanf(f,"%d",&nrOfNodes);
    int ** adjMat;
    adjMat = readFromAdjMat(f,nrOfNodes);
    printf("BFS for adjMat: ");
    bfsMat(nrOfNodes, 0, adjMat);
    printf("\nDFS for adjMat: ");
    dfsMat(nrOfNodes, 0, adjMat);
    NodeT ** adjList = matToList(adjMat, nrOfNodes);
    printf("\nBFS for list: ");
    bfsList(nrOfNodes, 0, adjList);
    printf("DFS for list: ");
    dfsList(nrOfNodes, 0, adjList);
    adjMat = listToMat(adjList, nrOfNodes);
    printf("\nBFS for adjMat: ");
    bfsMat(nrOfNodes, 0, adjMat);
    printf("\nDFS for adjMat: ");
    dfsMat(nrOfNodes, 0, adjMat);
    fclose(f);
    return 0;
}
