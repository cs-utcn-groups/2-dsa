#include "head.h"
Node *first, *last;

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
    for(int i=1; i<=*n; i++)
        for(int j=1; j<=*n; j++)
            matrix[i][j]=0;
}

char **initializeBuffer()
{
    char **buffer=(char **)malloc(sizeof(char *)*MAX_LENGTH);
    for(int i=0; i<MAX_LENGTH; i++)
        buffer[i]=(char *)malloc(sizeof(char)*MAX_LENGTH);
    return buffer;
}

void constructAdjMatrix(int *nodesGraph, int **adjMatrix, int *nrOfNodesGraph, FILE *f)
{
    int i=1,v,w,mx=-1;
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
        adjMatrix[v][w]=1;
        i++;
    }
}

void printAdjMatrix(int **adjMatrix, int *nrOfNodesGraph, FILE *g)
{
    for(int i=1; i<=*nrOfNodesGraph; i++)
    {
        for(int j=1; j<=*nrOfNodesGraph; j++)
            fprintf(g,"%d ",adjMatrix[i][j]);
        fprintf(g,"\n");
    }

    fprintf(g,"\n");
}

Node *createNode(int data)
{
    Node *p=(Node *)malloc(sizeof(Node)*MAX_LENGTH);
    if(p!=NULL)
    {
        p->data=data;
        p->next=NULL;
    }
    return p;
}

void initializeAdjList(int *nrOfNodesGraph, Node *adjList[])
{
    for(int i=1; i<=*nrOfNodesGraph; i++)
        adjList[i]=NULL;
}

void adjMatrixIntoAdjList(int **adjMatrix, int *nrOfNodesGraph, int *adjList[])
{
    for(int i=1; i<=*nrOfNodesGraph; i++)
    {
        adjList[i]=createNode(i);
        for(int j=1; j<=*nrOfNodesGraph; j++)
        {
            if(adjMatrix[i][j]==1)
            {
                Node *ptr=(Node *)malloc(sizeof(Node)*MAX_LENGTH);
                ptr=adjList[i];
                int k=0;
                while(k==0)
                {
                    if(ptr->next==NULL)
                    {
                        ptr->next=createNode(j);
                        k=1;
                    }
                    else
                        ptr=ptr->next;

                }
            }
        }
    }
}

void printAdjList(Node *adjList[], int *nrOfNodesGraph, FILE *g)
{
    Node *p=(Node *)malloc(sizeof(Node)*MAX_LENGTH);

    for(int j=1; j<=*nrOfNodesGraph; j++)
    {
        fprintf(g,"%d: ",j);
        p=adjList[j]->next;

        while(p!=NULL)
        {
            fprintf(g,"%d ",p->data);
            p=p->next;

        }
        fprintf(g,"\n");
    }

    fprintf(g,"\n");
}

void adjListIntoAdjMatrix(Node *adjList[], int **adjMatrix, int *nrOfNodesGraph)
{
    initializeAdjMatrix(adjMatrix,nrOfNodesGraph);

    Node *ptr=(Node *)malloc(sizeof(Node)*MAX_LENGTH);
    for(int i=1; i<=*nrOfNodesGraph; i++)
    {
        ptr=adjList[i]->next;
        for(int j=1; j<=*nrOfNodesGraph; j++)
        {
            if(ptr!=NULL)
                if(ptr->data==j)
                {
                    adjMatrix[i][j]=1;
                    ptr=ptr->next;
                }
        }

    }
}

int findNode(int *nrOfNodesGraph, int *nodesGraph, int node)
{
    for(int i=1; i<=*nrOfNodesGraph; i++)
        if(nodesGraph[i]==node)
            return 1;
    return 0;
}

int readTheSourceNode(int *nrOfNodesGraph, int *nodesGraph, char *algorithm)
{
    int source;
    bool ok=false;
    printf("Enter the source node for %s algorithm: ",algorithm);
    scanf("%d",&source);
    while(ok==false)
    {
        if(findNode(nrOfNodesGraph,nodesGraph,source)==1)
        {
            ok=true;
            return source;
        }
        else
        {
            printf("\nEnter another node: ");
            scanf("%d",&source);
        }
    }
    printf("\n");
}

int deleteEl()
{
    Node * currentElement = first;
    Node * previousElement= first;
    while(currentElement != last)
    {
        previousElement = currentElement;
        currentElement = currentElement->next;
    }

    if(first==last)
        last=NULL;
    else
    {
        previousElement->next =NULL;
        last=previousElement;
        free(currentElement);
    }
}


int takeEl()
{
    if(last!=NULL)
        return last->data;
    else
        return -1;
}

void addQueue(int data)
{
    if(first==NULL)
    {
        first=(Node*)malloc(sizeof(Node));
        first->data=data;
        first->next=NULL;
        last=first;
    }
    else
    {
        Node *newEl=(Node *)malloc(sizeof(Node));
        newEl->next=first;
        newEl->data=data;
        first=newEl;
    }
}

void addStack(int data)
{
    if(first==NULL)
    {
        first=(Node*)malloc(sizeof(Node));
        first->next=NULL;
        first->data=data;
        last=first;
    }
    else
    {
        Node *newEl=(Node *)malloc(sizeof(Node));
        newEl->next=NULL;
        newEl->data=data;
        last->next=newEl;
        last=newEl;
    }
}

void BFSAdjList(Node *adjList[], int *nrOfNodesGraph, FILE *g, int *nodesGraph)
{
    char *algorithm=(char *)malloc(sizeof(char)*10);
    strcpy(algorithm,"BFS");
    int source=readTheSourceNode(nrOfNodesGraph,nodesGraph,algorithm);

    int *visited=(int *)malloc(sizeof(int)*MAX_LENGTH);

    int i=1;
    for(i=1; i<=*nrOfNodesGraph; i++)
        visited[i]=0;

    visited[source]=1;
    fprintf(g,"BFS: %d ",source);

    Node *ptr=(Node *)malloc(sizeof(Node)*MAX_LENGTH);
    ptr=adjList[source]->next;
    while(ptr!=NULL)
    {
        addQueue(ptr->data);
        visited[ptr->data]=1;
        ptr=ptr->next;
    }

    i=takeEl();
    deleteEl();

    while(i!=-1)
    {
        fprintf(g,"%d ",i);
        ptr=adjList[i]->next;
        for(int j=1; j<=*nrOfNodesGraph; j++)
        {
            if(ptr!=NULL)
                if(ptr->data==j && visited[j]==0)
                {
                    addQueue(j);
                    visited[j]=1;
                    ptr=ptr->next;
                }
        }
        i=takeEl();
        deleteEl();
    }

}

void DFSAdjList(Node *adjList[], int *nrOfNodesGraph, FILE *g, int *nodesGraph)
{
    char *algorithm=(char *)malloc(sizeof(char)*10);
    strcpy(algorithm,"DFS");
    int source=readTheSourceNode(nrOfNodesGraph,nodesGraph,algorithm);

    int *visited=(int *)malloc(sizeof(int)*MAX_LENGTH);

    int i=1;
    for(i=1; i<=*nrOfNodesGraph; i++)
        visited[i]=0;

    visited[source]=1;
    fprintf(g,"\nDFS: %d ",source);

    Node *ptr=(Node *)malloc(sizeof(Node)*MAX_LENGTH);
    i=source;
    addStack(source);
    bool ok;

    while(i!=-1)
    {
        ok=false;
        ptr=adjList[i]->next;
        for(int j=1; j<=*nrOfNodesGraph; j++)
        {
            if(ptr!=NULL)
            {
                if(ptr->data==j && visited[j]==0)
                {
                    addStack(j);
                    fprintf(g,"%d ",j);
                    visited[j]=1;
                    i=j;
                    ok=true;
                    ptr=ptr->next;
                    break;
                }
                else if(ptr->data<=j)
                    ptr=ptr->next;
            }
        }
        if(ok==false)
        {
            deleteEl();
            i=takeEl();
        }
    }



}
