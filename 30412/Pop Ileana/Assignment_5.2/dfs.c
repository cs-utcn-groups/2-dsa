//
// Created by ileana on 4/5/2020.
//

#include "dfs.h"

NodeT * longestPathList = NULL;

void addElement(int content);
void savePath();
void dfsRecurs(int a, int b, int *maxLen);
void deletePrevPath();


int longestPath(int *a, int *b)
{
    int maxLen = 0;
    printf("Introduce node a= ");
    scanf("%d",a);
    printf("Introduce node b= ");
    scanf("%d",b);
    dfsRecurs(*a,*b,&maxLen);
    return maxLen;

}
void dfsRec(int v, int *visited, int b, int *maxLen, int *crtLen) {

    if(v==b)
    {
        addElementList(v);
        (*crtLen)++;
        if(*crtLen>*maxLen) {
            *maxLen = *crtLen;
            deletePrevPath();
            savePath();
        }
        *crtLen=0;
        return;
    }
    addElementList(v);
    visited[v] = VISITED;
    (*crtLen)++;
    NodeT *aux = adjList[v];
    while (aux != NULL) {
        int w = aux->content;
        if (visited[w] == UNVISITED) {
            dfsRec(w, visited,b,maxLen,crtLen);
        }
        aux = aux->next;
    }
    visited[v] = UNVISITED;
    deleteLast();
}

void dfsRecurs(int a, int b, int *maxLen) {
    int *visited = (int *) malloc(nbOfNodes * sizeof(int));
    int i;

    for (i = 0; i < nbOfNodes; i++) {
        visited[i] = UNVISITED;
    }
    int crtLen = 0;
    dfsRec(a, visited, b, maxLen, &crtLen);
}

void savePath()
{
    NodeT * aux = auxiliaryList;
    while(aux!=NULL) {
        addElement(aux->content);
        aux = aux->next;
    }
}

void addElement(int content)
{
    if(longestPathList==NULL)
        longestPathList = createNode(content);
    else
    {
        NodeT * aux =longestPathList;
        while(aux->next!=NULL)
            aux=aux->next;
        aux->next=createNode(content);
    }
}
void printPath()
{
    NodeT * aux= longestPathList;
    while(aux!=NULL)
    {
        printf("%d ",aux->content);
        aux=aux->next;
    }
    printf("\n");
}

void deletePrevPath()
{
    if(longestPathList!=NULL)
    {
        NodeT * aux = longestPathList;
        while(longestPathList!=NULL)
        {
            aux=longestPathList;
            longestPathList=longestPathList->next;
            free(aux);
        }
    }
}

