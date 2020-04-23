//
// Created by TheRa on 3/31/2020.
//

#include "list.h"
#include "graphRepresentation.h"

NodeT **adjToList() {
    NodeT **p = (NodeT**)malloc(nrOfVertexes * sizeof(NodeT*));
    NodeT *new,*temp;
    for(int i = 0 ; i<nrOfVertexes ;i++)
    {
     p[i]=(NodeT*)malloc(sizeof(NodeT));
     p[i]->content = i;
     p[i]->next = NULL;
    }
    for( int i = 0 ; i<nrOfVertexes ;i++)
        for(int j=0 ; j < nrOfVertexes ; j++)
            if(adjMatrix[i][j] == VISITED)
            {
                temp=p[i];
                new = createNode(j);
                while(p[i]->next != NULL) p[i] = p[i]->next;
                p[i]->next = new;
                p[i]=temp;
            }
    return p;
}

void printList(NodeT **list)
{
    for(int i = 0 ; i < nrOfVertexes ; i++)
    {
        while(list[i]!= NULL)
        {
            printf("%d -> ", list[i]->content);
            list[i] = list[i] ->next;
        }
        printf("\n");
    }
}

int **listToAdj(NodeT **list)
{
    int **adj = (int**)malloc(nrOfVertexes * sizeof(int*));
    for(int i = 0 ; i< nrOfVertexes ; i++)
    {
        adj[i] = (int*)malloc(nrOfVertexes * sizeof(int));
        for(int j= 0 ; j<nrOfVertexes ; j++)
            adj[i][j]=0;

        NodeT *temp=list[i]->next;
        while(temp != NULL)
        {
            adj[list[i]->content][temp->content] = 1;
            temp = temp ->next;
            //printf("%d",temp->content);
        }
    }
    return adj;
}

void printMatrix(int **a)
{
    for(int i = 0 ; i< nrOfVertexes  ; i++,printf("\n"))
        for(int j = 0 ; j< nrOfVertexes  ; j++)
            printf("%d ",a[i][j]);
}
