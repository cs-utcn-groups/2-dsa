//
// Created by Alina Mihut on 4/5/20.
//

#include "list.h"
#include "graph.h"
#include "node.h"
void initializeList()
{
    adjList=(List*) malloc (sizeof(List));
    adjList->first=(NodeT*) malloc (sizeof(NodeT));
    adjList->last=(NodeT*) malloc (sizeof(NodeT));
    adjList->first=NULL;
    adjList->last=NULL;
}

void addLast (List *l, int v) {
   // NodeT *newElement = (NodeT *) malloc(sizeof(NodeT));
   /* newElement->vertex=v;
    if (l->first == NULL) {
        l->first =newElement;
        l->first->next= NULL;
        l->last = l->first;
    }
    else if (l->last != NULL) {
        l->last->next = newElement;
        newElement->next = NULL;
        l->last = newElement;
    }
    */
    if (l->first == NULL)
        l->first=createNode(v);
    else {
        NodeT *currentElement = l->first;
        while(currentElement->next!=NULL)
        {
            currentElement=currentElement->next;
        }
        currentElement->next=createNode(v);
    }

}

List *createListFromMatrix ()
{
    initializeList();
    for(int i=0;i<nrOfVertexes;i++)
        for(int j=0;j<nrOfVertexes;j++)
        {
            if(adjMatrix[i][j]!=0)
                addLast(&adjList[i],j);
        }
    return adjList;
}
void printList (List *l)
{
    for (int i=0;i<nrOfVertexes;i++)
    {
        printf("%c", 'A'+ i );
        NodeT *temp = l[i].first;
        while (temp) {
            printf("-> %c", 'A'+temp->vertex);
            temp=temp->next;
        }
        printf("\n");
    }
    printf(" \n ");

}
