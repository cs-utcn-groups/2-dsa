#include "head.h"
Node *first=NULL, *last=NULL;

void addElQueue(int data)
{
    if(first==NULL)
    {
        first=(Node*)malloc(sizeof(Node));
        first->prev=NULL;
        first->data=data;
        first->next=NULL;
        last=first;
    }
    else
    {
        Node *newEl=(Node *)malloc(sizeof(Node));
        newEl->next=first;
        newEl->prev=NULL;
        newEl->data=data;
        first->prev=newEl;
        first=newEl;
    }
}

void addElStack(int data)
{
    if(first==NULL)
    {
        first=(Node*)malloc(sizeof(Node));
        first->prev=NULL;
        first->next=NULL;
        first->data=data;
        last=first;
    }
    else
    {
        Node *newEl=(Node *)malloc(sizeof(Node));
        newEl->next=NULL;
        newEl->prev=last;
        newEl->data=data;
        last->next=newEl;
        last=newEl;
    }
}

int deleteEl()
{
    Node *currentEl=last;
    int data;
    if(last==NULL)
    {
        first=NULL;
        return -1;
    }
    else
    {
        data=last->data;
        if(last!=first)
        {
            last=last->prev;
            last->next=NULL;
            free(currentEl);
        }
        else
            last=NULL;
        return data;
    }
}

int takeEl()
{
    if(last!=NULL)
        return last->data;
    else return -1;
}


int *initializeArray()
{
    int *array=(int *)malloc(sizeof(int)*MAX_LENGTH);
    return array;
}

int **initializeMatrix()
{
    int **matrix=(int **)malloc(sizeof(int *)*MAX_LENGTH);
    for(int i=0; i<MAX_LENGTH; i++)
        matrix[i]=(int *)malloc(sizeof(int)*MAX_LENGTH);
    return matrix;
}

void initializeAdjMatrix(int **matrix, int *n)
{
    for(int i=0; i<*n; i++)
        for(int j=0; j<*n; j++)
            matrix[i][j]=0;
}

char **initializeBuffer()
{
    char **buffer=(char **)malloc(sizeof(char *)*MAX_LENGTH);
    for(int i=0; i<MAX_LENGTH; i++)
        buffer[i]=(char *)malloc(sizeof(char)*MAX_LENGTH);
    return buffer;
}

void constructGraph(int *nodesGraph, int **adjMatrix, int *nrOfNodesGraph, FILE *f)
{
    int i=0,v,w,mx=-1;
    while(fscanf(f,"%d",&nodesGraph[i]))
    {
        if(nodesGraph[i]>mx)
            mx=nodesGraph[i];
        i++;
    }
    *nrOfNodesGraph=mx;

    char **buffer=initializeBuffer();
    initializeAdjMatrix(adjMatrix,nrOfNodesGraph);
    char *string=(char *)malloc(sizeof(char)*MAX_LENGTH);
    char *token=(char *)malloc(sizeof(char)*MAX_LENGTH);

    fgets(string,MAX_LENGTH,f);
    string[strlen(string)-1]='\0';
    token=strtok(string," ");
    i=0;
    //printf("%s ",token);
    strcpy(buffer[i],token);
    while(token!=NULL)
    {
        i++;
        token=strtok(NULL," ");
        if(token!=NULL)
            strcpy(buffer[i],token);
    }

    i=0;
    while(sscanf(buffer[i],"(%d,%d)",&v,&w))
    {
        adjMatrix[v-1][w-1]=1;
        i++;
    }

}

int findNode(int node,int *nodesGraph, int *nrOfNodesGraph)
{
    for(int i=0; i<*nrOfNodesGraph; i++)
        if(nodesGraph[i]==node)
            return 1;
    return 0;
}

void BFS(int **adjMatrix, int *nrOfNodesGraph, FILE *g, int *nodesGraph)
{
    bool ok=false;
    int nodeBFS;
    printf("Enter a node from which we will start the BFS Algorithm: ");
    scanf("%d",&nodeBFS);
    while(ok==false)
    {
        if(findNode(nodeBFS,nodesGraph,&nrOfNodesGraph)==1)
        {
            ok=true;
        }
        else
        {
            printf("\nEnter another node because the previous one doesn't belong to the graph.\n");
            scanf("%d",&nodeBFS);
        }
    }

    int *visited=(int *)malloc(sizeof(int)*MAX_LENGTH);
    for(int i=0; i<*nrOfNodesGraph; i++)
        visited[i]=0;
    visited[nodeBFS-1]=1;
    fprintf(g,"BFS: %d ",nodeBFS);

    int i=nodeBFS-1;
    for(int j=0; j<*nrOfNodesGraph; j++)
    {
        if(adjMatrix[i][j]==1)
        {
            addElQueue(j+1);
            visited[j]=1;
        }
    }

    i=deleteEl();
    while(i!=-1)
    {
        fprintf(g,"%d ",i);
        for(int j=0; j<*nrOfNodesGraph; j++)
        {
            if(adjMatrix[i-1][j]==1 && visited[j]==0)
            {
                addElQueue(j+1);
                visited[j]=1;
            }
        }
        i=deleteEl();
    }

}

void DFS(int **adjMatrix, int *nrOfNodesGraph, FILE *g, int *nodesGraph)
{
    bool ok=false;
    int nodeDFS;
    printf("\nEnter a node from which we will start the DFS Algorithm: ");
    scanf("%d",&nodeDFS);
    while(ok==false)
    {
        if(findNode(nodeDFS,nodesGraph,&nrOfNodesGraph)==1)
        {
            ok=true;
        }
        else
        {
            printf("\nEnter another node because the previous one doesn't belong to the graph.\n");
            scanf("%d",&nodeDFS);
        }
    }

    int *visited=(int *)malloc(sizeof(int)*MAX_LENGTH);
    for(int i=0; i<*nrOfNodesGraph; i++)
        visited[i]=0;
    visited[nodeDFS-1]=1;
    fprintf(g,"\nDFS: %d ",nodeDFS);

    int i=nodeDFS;
    addElStack(nodeDFS);

    while(i!=-1)
    {
        ok=false;
        for(int j=0; j<*nrOfNodesGraph; j++)
        {
            if(adjMatrix[i-1][j]==1 && visited[j]==0)
            {
                addElStack(j+1);
                fprintf(g,"%d ",j+1);
                visited[j]=1;
                i=j+1;
                ok=true;
                break;
            }
        }
        if(ok==false)
        {
            deleteEl();
            i=takeEl();
        }
    }

}
