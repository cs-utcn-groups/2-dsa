#include "head.h"

Node *first, *last;

char **initializeBuffer()
{
    char **buffer=(char **)malloc(sizeof(char *)*MAX_LENGTH);
    for(int i=0; i<MAX_LENGTH; i++)
        buffer[i]=(char *)malloc(sizeof(char)*MAX_LENGTH);
    return buffer;
}

Edge *createNode(int source, int dest, int weight)
{
    Edge *p=(Edge *)malloc(sizeof(Edge)*N);

    if(p!=NULL)
    {
        p->source=source;
        p->dest=dest;
        p->weight=weight;
        return p;
    }
    else
        return;
}

void constructGraph(FILE *f, int *nrOfNodes, Edge *edges[], int *nrOfEdges)
{
    char **buffer=initializeBuffer();
    char *string=(char *)malloc(sizeof(char)*MAX_LENGTH);
    char *token=(char *)malloc(sizeof(char)*MAX_LENGTH);

    fgets(string,MAX_LENGTH,f);
    string[strlen(string)-1]='\0';
    *nrOfNodes=atoi(string);

    int i=1,v,w,c;

    fgets(string,MAX_LENGTH,f);
    string[strlen(string)-1]='\0';
    token=strtok(string," ");
    strcpy(buffer[i],token);

    while(token!=NULL)
    {
        i++;
        token=strtok(NULL," ");
        if(token!=NULL)
            strcpy(buffer[i],token);
    }

    int j=1;
    while(j<i)
    {
        sscanf(buffer[j],"(%d,%d,%d)",&v,&w,&c);
        edges[j]=createNode(v,w,c);
        j++;
    }
    *nrOfEdges=i-1;
}

void sortAccToWeight(int *nrOfEdges, Edge *edges[])
{
    bool ok=false;
    Edge *temp;

    while(ok==false)
    {
        ok=true;
        for(int i=1; i<*nrOfEdges; i++)
            if(edges[i]->weight>edges[i+1]->weight)
            {
                temp=edges[i];
                edges[i]=edges[i+1];
                edges[i+1]=temp;
                ok=false;
            }
    }

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
    {
        last=NULL;
        first=NULL;
    }
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

void initializeStack()
{
    first=NULL;
    last=NULL;
}

int isCycle(int source, int dest, int *visited,int *nrOfNodes,int **adjMatrix)
{
    if(visited[source]==1 && visited[dest]==1)
    {
        int k=source;

        int *visitedCycle=(int *)malloc(sizeof(int)*MAX_LENGTH);
        for(int i=1; i<=*nrOfNodes; i++)
            visitedCycle[i]=0;
        initializeStack();

        visitedCycle[k]=1;

        int nrOfVisited=1,temp;

        if(source>dest)
        {
            temp=source;
            source=dest;
            dest=temp;

        }

        while(k!=-1)
        {
            for(int i=1; i<=*nrOfNodes; i++)
            {
                if(k<i)
                {
                    if(visitedCycle[k]==1 && adjMatrix[k][i]==1)
                        return 0;
                    else if(visitedCycle[i]==0 && adjMatrix[k][i]==1)
                    {
                        addStack(i);
                        visitedCycle[i]=1;
                        nrOfVisited++;
                    }
                }
            }

            k=takeEl();
            deleteEl();
        }
    }

    return 1;
}

void Kruskal(int *nrOfEdges, Edge *edges[],int *nrOfNodes,FILE *g)
{
    sortAccToWeight(nrOfEdges,edges);
    int **adjMatrix=initializeMatrix();
    initializeAdjMatrix(adjMatrix,nrOfNodes);

    int i=1,x,y,j=1;

    int *visited=(int *)malloc(sizeof(int)*MAX_LENGTH);
    for(int i=1; i<=*nrOfNodes; i++)
        visited[i]=0;

    fprintf(g,"Kruskal:\n");

    while(i<=(*nrOfNodes)-1)
    {
        x=edges[j]->source;
        y=edges[j]->dest;
        adjMatrix[x][y]=1;
        adjMatrix[y][x]=1;

        if(isCycle(x,y,visited,nrOfNodes,adjMatrix)==1)
        {
            visited[x]=1;
            visited[y]=1;
            fprintf(g,"%d %d\n",x,y);
            i++;
        }
        else
        {
            adjMatrix[x][y]=0;
            adjMatrix[y][x]=0;
        }

        j++;
    }
}

int readSource(int *nrOfNodes)
{
    int source;
    bool ok=false;
    printf("Enter the source node for Bellman Ford Algorithm: ");
    scanf("%d",&source);
    while(ok==false)
        if(source<=*nrOfNodes && source>=1)
        {
            ok=true;
            return source;
        }
        else
        {
            printf("Enter another node, the previous one doesn't belong to the initial graph: ");
            scanf("%d",&source);
        }
}

void BellmanFord(int *nrOfNodes, int *nrOfEdges, Edge *edges[], FILE *g)
{
    int *dist=(int *)malloc(sizeof(int)*MAX_LENGTH);
    for(int i=1; i<=*nrOfNodes; i++)
        dist[i]=infinity;

    int src=readSource(nrOfNodes);
    dist[src]=0;

    int source,dest,weight,i=1;
    while(i<*nrOfNodes)
    {
        for(int j=1;j<=*nrOfEdges;j++)
        {
            source=edges[j]->source;
            dest=edges[j]->dest;
            weight=edges[j]->weight;
            if(dist[source]+weight<dist[dest])
                dist[dest]=dist[source]+weight;
        }
        i++;
    }

    fprintf(g,"Bellman Ford:\n");
    for(int i=1;i<=*nrOfNodes;i++)
        fprintf(g,"%d ",dist[i]);
}
