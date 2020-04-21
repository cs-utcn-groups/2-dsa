#include <stdio.h>
#include <stdlib.h>

int nrNodes;
enum {UNVISITED, VISITED};

typedef struct node
{
    int value;
    int distance;
    struct node *next;
} nodeT;

nodeT *queue = NULL;
nodeT *stack = NULL;

int **readFromFile (FILE *f)
{
    fscanf(f,"%d",&nrNodes);
    int **matrix = (int**)malloc(sizeof(int*)*nrNodes);
    int i;
    for(i=0; i<nrNodes; i++)
    {
        matrix[i] = (int*)malloc(sizeof(int)*nrNodes);
    }

    int j;
    for(i=0; i<nrNodes; i++)
    {
        for(j=0; j<nrNodes; j++)
        {
            fscanf(f,"%d",&matrix[i][j]);
        }
    }
    return matrix;
}

void printMatrix( int ** matrix)
{
    printf("The matrix from the list is:\n");
    int i,j;
    for(i=0; i<nrNodes; i++)
    {
        for(j=0; j<nrNodes; j++)
        {
            if(matrix[i][j]<10)printf(" ");
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

void initializeList(nodeT **list)
{
    int i;
    for(i=0; i<nrNodes; i++)
    {
        list[i]->value = i;
        list[i]->distance = 0;
        list[i]->next = NULL;
    }
}

void addLast(nodeT *list,int value, int distance)
{
    nodeT *newNode = (nodeT*)malloc(sizeof(nodeT));
    newNode->next = NULL;
    newNode->distance = distance;
    newNode->value = value;
    if(list)
    {
        nodeT *currentNode = list;
        while(currentNode->next)
        {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
    else
    {

        list = (nodeT*)malloc(sizeof(nodeT));
        list = newNode;
    }
}

nodeT **getList(int **matrix)
{
    nodeT **list = (nodeT**)malloc(sizeof(nodeT*)*nrNodes);
    int i;
    for(i=0; i<nrNodes; i++)
        list[i] = (nodeT*)malloc(sizeof(nodeT));
    initializeList(list);

    for(i=0; i<nrNodes; i++)
    {
        int j;
        for(j=0; j<nrNodes; j++)
        {
            if(j!=i && matrix[i][j]>0)
            {
                int distance = matrix[i][j];
                addLast(list[i],j,distance);
            }
        }
    }
    return list;
}

void printList(nodeT **list)
{
    printf("The adjacency list is:\n");
    int i;
    for(i=0; i<nrNodes; i++)
    {
        printf("%c:  ",'A'+i);
        nodeT *startNode = list[i];
        while(startNode->next)
        {
            startNode = startNode->next;
            printf("%c ",'A'+startNode->value);
        }
        printf("\n");
    }
    printf("\n");
}

int **initializeMatrix()
{
    int i;
    int **matrix = (int**)malloc(sizeof(int*)*nrNodes);
    for(i=0; i<nrNodes; i++)
        matrix[i] = (int*)malloc(sizeof(int)*nrNodes);
    return matrix;
}

int **getMatrix(nodeT **list)
{
    int **matrix = initializeMatrix();
    int i,j;
    for(i=0; i<nrNodes; i++)
    {
        for(j=0; j<nrNodes; j++)
        {
            matrix[i][j] = 0;
        }
    }
    for(i=0; i<nrNodes; i++)
    {
        nodeT *startNode = list[i];
        while(startNode->next)
        {
            startNode = startNode->next;
            matrix[i][startNode->value] = startNode->distance;
        }
    }
    return matrix;
}

void deleteFirstQueue()
{
    if(queue!=NULL)queue = queue->next;
}

void addLastQueue(int value)
{
    if(queue == NULL)
    {
        queue = (nodeT*)malloc(sizeof(nodeT));
        queue->distance = 0;
        queue->value = value;
        queue->next = NULL;
    }
    else
    {
        while(queue->next)
            queue = queue->next;
        nodeT *temp = (nodeT*)malloc(sizeof(nodeT));
        temp->distance = 0;
        temp->next = NULL;
        temp->value = value;
        queue->next = temp;
    }

}

int isEmptyQueue()
{
    return queue == NULL;
}

void bfs(int **matrix, int start)
{
    printf("\nThe BFS graph is:\n");
    int *visited =  (int*)malloc(sizeof(int)*nrNodes);
    int i;
    for(i=0; i<nrNodes; i++)
        visited[i] = UNVISITED;

    addLastQueue(start);
    printf("%c ",'A'+start);
    visited[start] = VISITED;

    while(!isEmptyQueue())
    {
        int current = queue->value;
        deleteFirstQueue();

        for(i=0; i<nrNodes; i++)
        {
            if(visited[i] == UNVISITED && matrix[current][i]>0)
            {
                addLastQueue(i);
                printf("%c ",'A'+i);
                visited[i] = VISITED;
            }
        }
    }
    printf("\n");
}

void deleteFirstStack()
{
    if(stack!=NULL)stack = stack->next;
}

int isEmptyStack()
{
    return stack == NULL;
}

void addFirstStack(int value)
{
    nodeT *newNode = (nodeT*)malloc(sizeof(nodeT));
    newNode->distance = 0;
    newNode->next = stack;
    newNode->value = value;
    stack = newNode;
}

void dfs(int **matrix, int start)
{
    printf("\nThe DFS graph is:\n");
    int *visited =  (int*)malloc(sizeof(int)*nrNodes);
    int i;
    for(i=0; i<nrNodes; i++)
        visited[i] = UNVISITED;

    addFirstStack(start);

    while(!isEmptyStack())
    {
        int current = stack->value;
        deleteFirstStack();

        if(visited[current]==UNVISITED)
        {
            visited[current]=VISITED;
            for(i=nrNodes-1; i>=0; i--)
            {
                if(visited[i] == UNVISITED && matrix[current][i]>0)
                {
                    addFirstStack(i);
                }
            }
            printf("%c ",'A'+current);
        }
    }
    printf("\n");
}

void dfsRec(int **matrix, int v, int *visited)
{
    int i;
    visited[v] = VISITED;
    printf("%c ",v+'A');
    for(i=0; i<nrNodes; i++)
    {
        if(visited[i] == UNVISITED && matrix[v][i]>0)
            dfsRec(matrix,i,visited);
    }
}

void dfsRecursive(int **matrix, int start)
{
    printf("\nDFS Recursive:\n");
    int *visited = (int *) malloc(nrNodes * sizeof(int));
    int i;
    for(i=0; i<nrNodes; i++)
        visited[i] = UNVISITED;
    dfsRec(matrix,start,visited);
}

int main()
{
    FILE *f = fopen("input.txt","r");
    int **matrix = readFromFile(f);

    nodeT **adjacencyList = getList(matrix);
    printList(adjacencyList);

    int **newMatrix = getMatrix(adjacencyList);
    printMatrix(newMatrix);

    bfs(matrix,6);
    dfs(matrix,6);
    dfsRecursive(matrix,6);

    return 0;
}
