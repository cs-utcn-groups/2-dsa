#include "GraphAlgorithms.h"
void formEdgeArray(edgeT *edges)
{
    edgeT aux;
    int e=0;
    for(int i=0; i<nrOfVertexes-1; i++)
    {
        for(int j=i+1; j<nrOfVertexes; j++)
        {
            if(adjMatrix[i][j]>0)
            {
                edges[e].weight=adjMatrix[i][j];
                edges[e].source=i;
                edges[e].destination=j;
                e++;
            }
        }
    }
    for(int i=0; i<nrOfEdges-1; i++)
    {
        for(int j=i+1; j<nrOfEdges; j++)
        {
            if(edges[i].weight>edges[j].weight)
            {
                aux=edges[i];
                edges[i]=edges[j];
                edges[j]=aux;
            }
        }
    }
}
void getAllEdges(edgeT *edges)
{
    int e=0;
    for(int i=0; i<nrOfVertexes; i++)
    {
        for(int j=0; j<nrOfVertexes; j++)
        {
            if(adjMatrix[i][j]>0)
            {
                edges[e].weight=adjMatrix[i][j];
                edges[e].source=i;
                edges[e].destination=j;
                e++;
            }
        }
    }
}
void kruskal()
{
    printf("Kruskal's Algorithm started\n\n");
    edgeT *edges=(edgeT*)malloc(sizeof(edgeT)*nrOfEdges);
    int *visited=(int*)malloc(sizeof(int)*nrOfVertexes);
    int totalWeight=0;
    for(int i=0; i<nrOfVertexes; i++)
    {
        visited[i]=UNVISITED;
    }
    formEdgeArray(edges);

    char **components=(char**)malloc(sizeof(char*)*(nrOfVertexes/2+1));//components=subtrees
    for(int i=0; i<nrOfVertexes/2+1; i++)
        components[i]=(char*)malloc(sizeof(char)*(nrOfVertexes+1));
    int nrOfComponents=0;
    int nrOfAddedEdges=0;
    int i=0;//current edge
    while(nrOfAddedEdges<nrOfVertexes-1)
    {
        char c;
        if(visited[edges[i].source]==UNVISITED && visited[edges[i].destination]==UNVISITED)
        {

            printf("Added edge %c->%c of weight %d\n",edges[i].source+'A',edges[i].destination+'A',edges[i].weight);
            c=edges[i].source+'A';
            strcpy(components[nrOfComponents],&c);
            c=edges[i].destination+'A';
            strcat(components[nrOfComponents],&c);
            nrOfComponents++;
            nrOfAddedEdges++;
            visited[edges[i].source]=VISITED;
            visited[edges[i].destination]=VISITED;
            totalWeight+=edges[i].weight;
        }
        else
        {
            if(visited[edges[i].source]==UNVISITED)
            {

                c=edges[i].destination+'A';
                int found=0,j=0;
                while(!found&&j<nrOfComponents)
                {
                    if(strchr(components[j],c)!=NULL)
                    {
                        found=1;
                        c=edges[i].source+'A';
                        strcat(components[j],&c);
                    }
                    else
                    {
                        j++;
                    }
                }
                printf("Added edge %c->%c of weight %d\n",edges[i].source+'A',edges[i].destination+'A',edges[i].weight);
                visited[edges[i].source]=VISITED;
                nrOfAddedEdges++;
                totalWeight+=edges[i].weight;
            }
            else
            {
                if(visited[edges[i].destination]==UNVISITED)
                {

                    c=edges[i].source+'A';
                    int found=0,j=0;
                    while(!found&&j<nrOfComponents)
                    {
                        if(strchr(components[j],c)!=NULL)
                        {
                            found=1;
                            c=edges[i].destination+'A';
                            strcat(components[j],&c);
                        }
                        else
                        {
                            j++;
                        }
                    }
                    printf("Added edge %c->%c of weight %d\n",edges[i].source+'A',edges[i].destination+'A',edges[i].weight);
                    visited[edges[i].destination]=VISITED;
                    nrOfAddedEdges++;
                    totalWeight+=edges[i].weight;
                }
                else
                {
                    int sourceComponent,destinationComponent;
                    char c1=edges[i].source+'A';
                    char c2=edges[i].destination+'A';
                    for(int j=0;j<nrOfComponents;j++)
                    {
                        if(strchr(components[j],c1))
                            sourceComponent=j;
                        if(strchr(components[j],c2))
                            destinationComponent=j;
                    }
                    if(sourceComponent!=destinationComponent)
                    {
                        printf("Added edge %c->%c of weight %d\n",edges[i].source+'A',edges[i].destination+'A',edges[i].weight);
                        totalWeight+=edges[i].weight;
                        nrOfAddedEdges++;
                        nrOfComponents--;
                        if(sourceComponent<destinationComponent)
                        {
                            strcat(components[sourceComponent],components[destinationComponent]);
                            strcpy(components[destinationComponent],"\0");
                        }
                        else
                        {
                            strcat(components[destinationComponent],components[sourceComponent]);
                            strcpy(components[sourceComponent],"\0");
                        }
                    }


                }
            }
        }

        i++;
    }
    printf("Tree total weight is %d\n\n",totalWeight);
    printf("Kruskal's Algorithm ended\n\n");
}

void belmanford(int startNode)//since the algorithm is technically for directed graphs, i considered every undirected edge as 2 directed edges in each direction, hence the nrofedges*2 everywhere
{
     printf("Belmanford Algorithm started\n\n");
     edgeT *edges=(edgeT*)malloc(sizeof(edgeT)*nrOfEdges*2);
     getAllEdges(edges);//different function from kruskal because the adj matrix is that of an undirected graph
     int *distance=(int*)malloc(sizeof(int)*nrOfVertexes);
     int *previous=(int*)malloc(sizeof(int)*nrOfVertexes);
     for(int i=0;i<nrOfVertexes;i++)
     {
         distance[i]=MAX;
         previous[i]=UNDEFINED;
     }
     distance[startNode]=0;
     int u,v;
    for(int j=0;j<nrOfVertexes-1;j++)
    {
        for(int i=0;i<nrOfEdges*2;i++)
        {
            u=edges[i].source;
            v=edges[i].destination;
            if(distance[u]+edges[i].weight<distance[v])
            {
                distance[v]=distance[u]+edges[i].weight;
                previous[v]=u;
            }
        }
    }
      for(int i=0;i<nrOfEdges*2;i++)
        {
            u=edges[i].source;
            v=edges[i].destination;
            if(distance[u]!=MAX&&distance[u]+edges[i].weight<distance[v])
            {
                printf("Graph contains a negative weight cycle\n");
            }
        }
    for(int i=0;i<nrOfVertexes;i++)
    {
        printf("Minimum distance from %c to %c is %d\n",startNode+'A',i+'A',distance[i]);
        if(i!=startNode)
        printf("The predecessor of vertex %c is %c\n\n",i+'A',previous[i]+'A');
        else printf("No predecessor\n\n");
    }
    printf("Belmanford Algorithm ended\n\n");
}

