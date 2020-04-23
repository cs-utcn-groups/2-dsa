//
// Created by ileana on 4/14/2020.
//

#include "vertexCover.h"
void printEdges(edgeT * edges, int nrEdges);

void vertexCover()
{
    makeEmpty();            // coverSet is initialized
    edgeT * edges = getEdges();
    int nrEdges = getNrOfEdges();
    printf("Edge list is\n");
    printEdges(edges,nrEdges);
    while(nrEdges!=0)
    {
        edgeT chosenEdge = edges[0];
        addNewNode(chosenEdge.source);
        addNewNode(chosenEdge.destination);

        printf("Chosen Edge: %d %d\n",chosenEdge.source,chosenEdge.destination);
        deleteIncidentEdges(edges,chosenEdge.source,&nrEdges);
        printf("remove incident on %d\n",chosenEdge.source);
        printEdges(edges,nrEdges);
        printf("remove incident on %d\n",chosenEdge.destination);
        deleteIncidentEdges(edges,chosenEdge.destination,&nrEdges);
        printEdges(edges,nrEdges);
    }

}

void printCoverSet()
{
    printf("\nThe vertex cover is:\n");

    NodeT * node = coverSet;
    while(node!=NULL)
    {
        printf("%c ",node->content + 'A');
        node=node->next;
    }
}
void printEdges(edgeT * edges, int nrEdges)
{
    for(int i=0;i<nrEdges;i++)
        printf("%d %d\n",edges[i].source, edges[i].destination);
}
