//
// Created by User on 06.04.2020.
//

#include "graphRepresentation.h"
void readFromAdjMatrix(FILE *f)
{
    int n;
    fscanf(f,"%d",&n);
    nrOfVertexes=n;
    int i,j;
    adjM=(int**)malloc(n* sizeof(int *));
    for(i=0;i<n;i++)
    {
        *(adjM+i)=(int*)malloc(n* sizeof(int));

    }
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            fscanf(f, "%d", &adjM[i][j]);
    fclose(f);
}
void printMatrix(int **matrix)
{
    printf("The adjacency matrix is: \n");
    printf("    ");
    for(int i=0;i< nrOfVertexes;i++)
    {
        printf("%c  ", i+'A');
    }
    printf("\n");
    for(int i=0;i<nrOfVertexes;i++)
    {
        printf("%c  ",i+'A');
        for(int j=0;j<nrOfVertexes;j++)
        {
            if(adjM[i][j]>9)
                printf("%d ", matrix[i][j]);
            else
                printf("0%d ",matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int getNumberOfNeighborsOfVertex(int v){
    if(v<nrOfVertexes)
    {
        int nrOfNeighbors=0;
        for(int i=0;i<nrOfVertexes;i++)
        {
            if(adjM[v][i]!=0 && i!=v)
                nrOfNeighbors++;
        }
        return nrOfNeighbors;
    } else{
        return 0;
    }

}

int * getAllNeighborsOfVertex(int v){
    if(v<nrOfVertexes)
    {
        int nrOfNeighbors= getNumberOfNeighborsOfVertex(v);
        int *neighbors=(int*)malloc(nrOfNeighbors* sizeof(int));
        int j=0;
        for(int i=0;i<nrOfVertexes;i++)
        {
            if(adjM[v][i]>0 && i!=v)
            {
                neighbors[j]=i;
                j++;
            }
        }
        return  neighbors;
    } else{
        return NULL;
    }
}
void dfsRec(int v, int *visited, int *path, int index, int destination, int *length, int *lengthMax, int* longestPath) {

    visited[v] = VISITED;
    (*length)++;
    path[index]=v;
    index++;
    int nrOfNeighbors = getNumberOfNeighborsOfVertex(v);
    int *neighbors = getAllNeighborsOfVertex(v);
    if(v==destination){
        if(*length>*lengthMax)
        {
            *lengthMax=*length;
            for(int i=0;i<index;i++)
                longestPath[i]=path[i];
        }

    } else {
        for (int i = 0; i < nrOfNeighbors; i++) {
            int w = neighbors[i];
            if (visited[w] == UNVISITED) {
                dfsRec(w, visited,path,index ,destination,length,lengthMax,longestPath);
            }
        }
    }
    index--;
    visited[v]=UNVISITED;
    (*length)--;

}

void dfsRecurs(int startNode, int destination) {
    int *visited = (int *) malloc(nrOfVertexes * sizeof(int));
    int *path = (int *) malloc(nrOfVertexes * sizeof(int));
    int *longestPath = (int *) malloc(nrOfVertexes * sizeof(int));
    int index=0;
    int length=0;
    int lengthMax=0;
    for (int i = 0; i < nrOfVertexes; i++) {
        visited[i] = UNVISITED;
    }
    dfsRec(startNode, visited,path,index,destination,&length,&lengthMax,longestPath);
    printf("The longest path between the 2 nodes is:\n");
    for(int i=0;i<lengthMax;i++)
    {
        printf("%c ",longestPath[i]+'A');
    }
}