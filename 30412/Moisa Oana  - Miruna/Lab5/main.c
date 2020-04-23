#include <stdio.h>
#include "graphRepresentation.h"
#include "graphTraversals.h"
#define FILE_PATH "../matrix.txt"

int main() {
    FILE *f = fopen(FILE_PATH, "r");
    readFromAdjMatrix(f);
    printMatrix(adjM);
    bfs('G' - 'A');
    dfs('G' - 'A');
    dfsRecurs('G' - 'A');
    adjList=(ListT*)malloc(nrOfVertexes* sizeof(ListT));
    for(int i=0;i<nrOfVertexes;i++)
    {
        initializeList(&adjList[i]);
    }
    matrixToList();
    printf("Adjacency list is: \n");
    for(int i=0;i<nrOfVertexes;i++)
    {
        NodeL *currentNode;
        if(adjList[i].first==NULL)
        {
            printf("The list is empty!\n");

        }
        else {
            printf("%c: ",i+'A');
            currentNode = adjList[i].first;
            while (currentNode != NULL) {
                printf("(%c,%d) ", currentNode->key[1]+'A',currentNode->key[2]);
                currentNode = currentNode->next;
            }
            printf("\n");
        }
    }
    listToMatrix();
    printMatrix(newAdjM);
    bfsList('G' - 'A');
    dfsList('G' - 'A');
    dfsRecursList('G' - 'A');
    return 0;
}