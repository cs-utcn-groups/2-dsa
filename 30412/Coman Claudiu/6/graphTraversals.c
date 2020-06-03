#include "graphTraversals.h"
#include "graphTraversals.h"
#include "graphRepresentation.h"

void bfs(int startNode )
{
    printf("BFS STARTED \n");
    int *visited = (int *)malloc(nrOfVertexes * sizeof(int));
    int i, v, w;

    for(i=0 ; i < nrOfVertexes ; i++)
        visited[i] = UNVISITED;

    enqueue(startNode);
    visited[startNode] = VISITED;
    printf("%c ", startNode + 'A');

    while(!isEmptyQueue())
    {
        v = peekQueue()->content;
        dequeue();

        int nrOfNeighbors = getNumberOfNeighborsOfVertex(v);
        int *neighbors = getAllNeighborsOfVertex(v);
        for(i =0 ;i<nrOfVertexes ; i++)
        {
            w=neighbors[i];
            if(visited[w] == UNVISITED)
            {
                printf("%c ", w + 'A');
                enqueue(w);
                visited[w] = VISITED;
            }
        }
    }
    printf("\nEND\n");

}

void dfs(int startNode)
{
    printf("DFS started\n");
    int *visited = (int *) malloc(nrOfVertexes * sizeof(int));
    int i, v, w;

    for (i = 0; i < nrOfVertexes; i++) {
        visited[i] = UNVISITED;
    }

    push(startNode);

    while(!isEmptyStack())
    {
        v=peekStack()->content;
        if(visited[v] == UNVISITED)
        {
            visited[v] = VISITED;
            int nrOfNeighbors = getNumberOfNeighborsOfVertex(v);
            int *neighbors = getAllNeighborsOfVertex(v);
            for( i = nrOfNeighbors -1 ; i>=0 ;i--)
            {
                w=neighbors[i];
                if(visited[w] == UNVISITED)
                    push(w);
            }
            printf("%c ", v + 'A');
        }
    }
    printf("\nDFS ended\n\n");
}
