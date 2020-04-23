#include <stdio.h>
#include <stdlib.h>
#include "graphTraversals.h"

void readMatrix(FILE *ifptr, int ***adjMatrix, int *nodesNo)
{
    fscanf(ifptr, "%d", nodesNo);
    (*adjMatrix) = (int **) malloc((*nodesNo) * sizeof(int*));
    for(int i = 0; i < (*nodesNo); i++)
    {
        ((*adjMatrix)[i]) = (int *) malloc((*nodesNo) * sizeof(int));
        for(int j = 0; j < (*nodesNo); j++)
        {
            fscanf(ifptr, "%d", &((*adjMatrix)[i][j]));
        }
    }
}
nodeT* addLast(int key, nodeT *last, nodeT **arrayOfList)
{
    nodeT *element = (nodeT *) malloc(sizeof(nodeT));
    element->key = key;
    if (*arrayOfList == NULL)
    {
        element->next = NULL;
        (*arrayOfList) = element;
        last = element;
    }
    else
    {
        last->next = element;
        last = element;
        last->next = NULL;
    }
    return last;
}
nodeT** matrixToList(int **adjMatrix, int nodesNo)
{
    nodeT **arrayOfLists, *last;
    arrayOfLists = (nodeT**) malloc(nodesNo * sizeof(nodeT*));
    for(int i = 0; i < nodesNo; i++)
    {
        arrayOfLists[i] = NULL;
        last = NULL;
        for(int j = 0; j < nodesNo; j++)
        {
            if(adjMatrix[i][j] == 1)
            {
                last = addLast(j, last, &(arrayOfLists[i]));
            }
        }
    }
    return arrayOfLists;
}
void printArrayOfLists(nodeT **arrayOfLists, int nodesNo)
{
    printf("The array of lists is:\n");
    for(int i = 0; i < nodesNo; i++)
    {
        printf("List %d: ", i);
        nodeT *currentNode = arrayOfLists[i];
        while (currentNode != NULL)
        {
            printf("%d ", currentNode->key);
            currentNode = currentNode->next;
        }
        printf("\n");
    }
}
int** listToMatrix(nodeT **arrayOfLists, int nodesNo)
{
    int **adjMatrixFromList;
    adjMatrixFromList = (int**) malloc(nodesNo * sizeof(int*));
    for(int i = 0; i < nodesNo; i++)
    {
        adjMatrixFromList[i] = (int*) malloc(nodesNo * sizeof(int));
        for(int j = 0; j < nodesNo; j++)
        {
            adjMatrixFromList[i][j] = 0;
        }
    }
    for(int i = 0; i < nodesNo; i++)
    {
        nodeT *currentNode = arrayOfLists[i];
        while (currentNode != NULL)
        {
            adjMatrixFromList[i][currentNode->key]++;
            currentNode = currentNode->next;
        }
    }
    return adjMatrixFromList;
}
void printMatrix(int **matrix, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    FILE *ifptr = fopen("input.dat", "r");
    if(ifptr == NULL)
    {
        perror("ifptr");
    }
    else
    {
        int **adjMatrix, nodesNo, **adjMatrixfromList;
        readMatrix(ifptr, &adjMatrix, &nodesNo);
        printf("The read matrix is:\n");
        printMatrix(adjMatrix, nodesNo);
        nodeT **arrayOfListsCopy;
        nodeT **arrayOfLists = matrixToList(adjMatrix, nodesNo);
        printArrayOfLists(arrayOfLists, nodesNo);
        adjMatrixfromList = listToMatrix(arrayOfLists, nodesNo);
        printf("The adjacency matrix from the array of lists is:\n");
        printMatrix(adjMatrixfromList, nodesNo);
        bfs(0, nodesNo, adjMatrix);
        dfsRecurs(0, nodesNo, adjMatrix);
        arrayOfListsCopy = (nodeT**) malloc(nodesNo * sizeof(nodeT*));
        for(int i = 0; i< nodesNo; i++)
        {
            arrayOfListsCopy[i] = arrayOfLists[i];
        }
        bfsList(0, nodesNo, arrayOfLists);
        dfsRecursList(0, nodesNo, arrayOfListsCopy);
        int a = 0;
    }

    return 0;
}