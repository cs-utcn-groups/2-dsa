#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define UNDEFINED -1
#define MAX 9999

typedef struct edgenode
{
    int source;
    int destination;
    int weight;
} edgeT;

edgeT *sortedEdges;

typedef struct node
{
    int value;
    struct node *next;
} nodeT;

nodeT *stack;

int **cycleTable;

int nrVertices,nrEdges = 0;
enum {UNVISITED,VISITED};

int **readDataFromFile (FILE *f)
{
    int **matrix = (int**)malloc(sizeof(int*)*nrVertices);
    int i,j;
    for(i=0; i<nrVertices; i++)
        matrix[i] = (int*)malloc(sizeof(int)*nrVertices);

    for(i=0; i<nrVertices; i++)
    {
        for(j=0; j<nrVertices; j++)
        {
            fscanf(f,"%d",&matrix[i][j]);
        }
    }
    return matrix;
}

edgeT *sortEdges(int **matrix)
{
    edgeT *sortedEdges = (edgeT*)malloc(sizeof(edgeT)*(nrVertices*(nrVertices-1))); ///max possibility
    int i,j,current = 0;
    for(i=0; i<nrVertices-1; i++)
    {
        for(j=i+1; j<nrVertices; j++)
        {
            if(matrix[i][j]>0)
            {
                sortedEdges[current].source = i;
                sortedEdges[current].destination = j;
                sortedEdges[current].weight = matrix[i][j];
                current++;
            }
        }
    }
    nrEdges = current;
    for(i=0; i<nrEdges-1; i++)
    {
        for(j=i+1; j<nrEdges; j++)
        {
            if(sortedEdges[i].weight > sortedEdges[j].weight)
            {
                edgeT aux = sortedEdges[i];
                sortedEdges[i] = sortedEdges[j];
                sortedEdges[j] = aux;
            }
        }
    }
    nrEdges = current;
    ///for(i=0; i<nrEdges;i++)printf("%c %c %d\n",sortedEdges[i].source+'A',sortedEdges[i].destination+'A',sortedEdges[i].weight);
    return sortedEdges;
}

int isCycle(int **cycleTable, edgeT newEdge)
{
    int i,cycle;
    int source = newEdge.source;
    int destination = newEdge.destination;
    int colS,colD;
    for(i=0; i<nrVertices; i++)
    {
        if(cycleTable[source][i] == 1)break;
    }
    colS = i;
    if(cycleTable[destination][colS] == 1)cycle = 1;
    else
    {
        for(i=0; i<nrVertices; i++)
        {
            if(cycleTable[destination][i] == 1)break;
        }
        colD = i;
        for(i=0; i<nrVertices; i++)
        {
            if(cycleTable[i][colD] == 1)
            {
                cycleTable[i][colS] = 1;
                cycleTable[i][colD] = 0;
            }
        }
        cycle = 0;
    }
    return cycle;
}

void kruskal(int **matrix)
{
    printf("The Kruskal Graph is:\n");
    int *visited = (int*)malloc(sizeof(int)*nrVertices);
    int i,j;
    for(i=0; i<nrVertices; i++)visited[i] = UNVISITED;
    int nrVisitedEdges = 0;
    sortedEdges = sortEdges(matrix);
    int current = 0,cost = 0;

    ///dumb stuff to help figure if there is a cycle
    cycleTable = (int**)malloc(sizeof(int*)*nrVertices);
    for(i=0; i<nrVertices; i++)
        cycleTable[i] = (int*)malloc(sizeof(int)*nrVertices);
    for(i=0; i<nrVertices; i++)
    {
        for(j=0; j<nrVertices; j++)
            if(i==j)cycleTable[i][j] = 1;
            else cycleTable[i][j] = 0;
    }

    ///actual algorithm
    while(nrVisitedEdges < nrVertices - 1)
    {
        edgeT newEdge = sortedEdges[current++];
        if(isCycle(cycleTable,newEdge)==0)
        {
            nrVisitedEdges++;
            visited[newEdge.source] = 1;
            visited[newEdge.destination] = 1;
            cost = cost + newEdge.weight;
            printf("%c -> %c\n",newEdge.source+'A',newEdge.destination+'A');
        }
    }
    printf("The cost is: %d\n\n",cost);
}

edgeT findMinimumEdge(int **matrix, int *visited)
{
    int i,j;
    edgeT minEdge;
    minEdge.weight = INT_MAX;
    for(i=0; i<nrVertices; i++)
    {
        for(j=0; j<nrVertices; j++)
        {
            if(visited[i]== VISITED && visited[j] == UNVISITED && matrix[i][j]>0)
            {
                if(matrix[i][j]<minEdge.weight)
                {
                    minEdge.weight = matrix[i][j];
                    minEdge.source = i;
                    minEdge.destination = j;
                }
            }
        }
    }
    return minEdge;
}

void prim(int **matrix,int startNode)
{
    printf("The Prim Graph is:\n");
    int *visited = (int*)malloc(sizeof(int)*nrVertices);
    int i,cost = 0;
    for(i=0; i<nrVertices; i++)visited[i] = UNVISITED;
    int nrVisitedEdges = 0;
    visited[startNode] = 1;

    while(nrVisitedEdges < nrVertices - 1)
    {
        edgeT minimumEdge = findMinimumEdge(matrix,visited);
        cost = cost + minimumEdge.weight;
        visited[minimumEdge.source] = 1;
        visited[minimumEdge.destination] = 1;
        nrVisitedEdges++;
        printf("%c -> %c\n",minimumEdge.source+'A',minimumEdge.destination+'A');
    }
    printf("The cost is: %d\n\n",cost);
}

int getMinDistanceVisited(int *distance, int *visited)
{
    int min = INT_MAX,i;
    int minV = 0;
    for(i=0; i<nrVertices; i++)
    {
        if(distance[i] < min && visited[i] == UNVISITED)
        {
            minV = i;
        }
    }
    return minV;
}

void pop()
{
    if(stack!=NULL)stack = stack->next;
}

int isEmptyStack()
{
    return stack == NULL;
}

void push(int value)
{
    nodeT *newNode = (nodeT*)malloc(sizeof(nodeT));
    newNode->next = stack;
    newNode->value = value;
    stack = newNode;
}

void dijkstra(int **matrix, int startNode)
{
    int *visited = (int*)malloc(sizeof(int)*nrVertices);
    int *previous = (int*)malloc(sizeof(int)*nrVertices);
    int *distance = (int*)malloc(sizeof(int)*nrVertices);
    int i;
    for(i=0; i<nrVertices; i++)
    {
        visited[i] = UNVISITED;
        previous[i] = UNDEFINED;
        distance[i] = INT_MAX;
    }
    int nrVisitedVertices = 0;
    distance[startNode] = 0;

    while(nrVisitedVertices < nrVertices)
    {
        int nextMin = getMinDistanceVisited(distance,visited);
        visited[nextMin] = VISITED;

        for(i=0; i<nrVertices; i++)
        {
            if(matrix[nextMin][i] > 0)
            {
                int alt = distance[nextMin] + matrix[nextMin][i];
                if(alt < distance[i])
                {
                    distance[i] = alt;
                    previous[i] = nextMin;
                }
            }
        }
        nrVisitedVertices++;
    }

    printf("\nDijkstra's paths are:\n");
    for(i=0; i<nrVertices; i++)
    {
        int temp = i;
        if(i!=startNode)
        {
            while(previous[temp]!=UNDEFINED)
            {
                push(temp);
                temp = previous[temp];
            }
            printf("Path from %c to %c is (distance %d) : %c ", startNode + 'A', i + 'A',distance[i],startNode + 'A');
        }
        while (!isEmptyStack())
        {
            printf(" -> %c ", stack->value + 'A');
            pop();
        }
        printf("\n");
    }
}

void bellmanford(int **matrix, int startNode)
{
    int *previous = (int*)malloc(sizeof(int)*nrVertices);
    int *distance = (int*)malloc(sizeof(int)*nrVertices);
    int i;
    for(i=0; i<nrVertices; i++)
    {
        previous[i] = UNDEFINED;
        distance[i] = MAX;
    }
    distance[startNode] = 0;

    int j;
    for(i=0; i<nrVertices; i++)
    {
        for(j=0; j<nrVertices; j++)
        {
            if(matrix[i][j]>0) ///if there is edge
            {
                int tempDistance = distance[i]+matrix[i][j];
                if(tempDistance < distance[j])
                {
                    distance[j] = tempDistance;
                    previous[j] = i;
                }
            }
        }
    }
    printf("\nBellmanford's paths are:\n");
    for(i=0; i<nrVertices; i++)
    {
        int temp = i;
        if(i!=startNode)
        {
            while(previous[temp]!=UNDEFINED)
            {
                push(temp);
                temp = previous[temp];
            }
            printf("Path from %c to %c is (distance %d) : %c ", startNode + 'A', i + 'A',distance[i],startNode + 'A');
        }
        while (!isEmptyStack())
        {
            printf(" -> %c ", stack->value + 'A');
            pop();
        }
        printf("\n");
    }
}

int main()
{
    FILE *f = fopen("input.txt","r");
    fscanf(f,"%d",&nrVertices);
    int **matrix = readDataFromFile(f);
    prim(matrix,0); ///start from node A
    kruskal(matrix);
    dijkstra(matrix,0);
    bellmanford(matrix,0);
    return 0;
}
