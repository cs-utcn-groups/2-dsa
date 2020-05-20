#include "list.h"
#include "graphRepresentation.h"
void initializeAdjList(listT *l)
{
    l->first=NULL;
    l->last=NULL;
}
void matrixToList()
{
    adjList=(listT*)malloc(sizeof(listT)*nrOfVertexes);
    for(int i=0;i<nrOfVertexes;i++)
    {
        initializeAdjList(&adjList[i]);
    }
    for(int i=0; i<nrOfVertexes; i++)
    {

        for(int j=0; j<nrOfVertexes; j++)
        {
            if(adjMatrix[i][j]!=0)
            {

                if(adjList[i].first==NULL)
                {

                    adjList[i].first=(nodeL*)malloc(sizeof(nodeL));
                    adjList[i].first->letter='A'+j;

                    adjList[i].first->content=adjMatrix[i][j];

                    adjList[i].first->next=adjList[i].last;
                    adjList[i].last=adjList[i].first;

                }
                else
                {
                    nodeL *currentNode=(nodeL*)malloc(sizeof(nodeL));
                    currentNode->letter='A'+j;
                    currentNode->content=adjMatrix[i][j];
                    currentNode->next=NULL;
                    adjList[i].last->next=currentNode;
                    adjList[i].last=currentNode;
                }
            }
        }
    }

}
void listToMatrix()
{
    initializeMatrix();
    nodeL *currentNode=(nodeL*)malloc(sizeof(nodeL));
    for(int i=0; i<nrOfVertexes; i++)
    {
        currentNode=adjList[i].first;
        while(currentNode!=NULL)
        {
            adjMatrix[i][currentNode->letter-'A']=currentNode->content;
            currentNode=currentNode->next;
        }
    }
}
void printAdjList()
{
    printf("The list is:\n");
    for(int i=0;i<nrOfVertexes;i++)
    {
        printf("Vertex %c neighbors: ",'A'+i);
        {
            nodeL *currentNode=(nodeL*)malloc(sizeof(nodeL));
            currentNode=adjList[i].first;
            while(currentNode!=NULL)
            {
                printf("%c ",currentNode->letter);
                currentNode=currentNode->next;
            }
        }
        printf("\n");
    }
}
