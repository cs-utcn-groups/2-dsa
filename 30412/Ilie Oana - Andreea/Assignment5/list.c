//
// Created by andre on 06.05.2020.
//

#include "list.h"

#define MAX_NO_OF_NEIGHBOURS 30

ListT *createAdjList(int noOfVertices) {
    ListT *adjList = (ListT *) malloc(noOfVertices * sizeof(ListT));
    for (int i = 0; i < noOfVertices; i++) {
        adjList[i].noOfNodes = 0;
        adjList[i].first = adjList[i].last = NULL;
    }
    return adjList;
}

NodeL *createNodeList(int start, int destination, int weight) {
    NodeL *newNode = (NodeL *) malloc(sizeof(NodeL));
    newNode->start = start;
    newNode->destination = destination;
    newNode->weight = weight;
    newNode->neighbours = (int *) malloc(MAX_NO_OF_NEIGHBOURS * sizeof(int));
    newNode->next = NULL;
    return newNode;
}

void addLast(ListT *adjList, int start, int destination, int weight) {
    NodeL *newElement = createNodeList(start, destination, weight);
    if (adjList->last != NULL) {
        adjList->last->next = newElement;
    } else {
        adjList->first = newElement;
    }
    adjList->first->neighbours[adjList->noOfNodes] = newElement->destination;
    adjList->last = newElement;
    adjList->noOfNodes++;
}

void deleteLast(ListT *adjList) {
    if (adjList->last != NULL) {
        NodeL *currentElement = adjList->first;
        NodeL *previousElement = adjList->first;
        if (currentElement) {
            while (currentElement != adjList->last) {
                previousElement = currentElement;
                currentElement = currentElement->next;
            }
            if (currentElement == adjList->first) {
                adjList->first = adjList->last = NULL;
            } else {
                previousElement->next = NULL;
            }
            adjList->last = previousElement;
            free(currentElement);
            adjList->noOfNodes--;
        }
    }
}

void doomTheList(ListT *adjList) {
    NodeL *currentElement = adjList->first;
    while (currentElement != NULL) {
        adjList->first = adjList->first->next;
        free(currentElement);
        currentElement = adjList->first;
    }
    adjList->first = NULL;
    adjList->last = NULL;
}

void printList(FILE *outputFile, ListT adjList) {
    if (adjList.first == NULL) {
        fprintf(outputFile, "This list is empty! \n");
    } else {
        NodeL *currentElement = adjList.first;
        fprintf(outputFile, "%c: ", 'A' + currentElement->start);
        while (currentElement) {
            fprintf(outputFile, "(%c, %d) ", 'A' + currentElement->destination, currentElement->weight);
            currentElement = currentElement->next;
        }
        fprintf(outputFile, "\n");
    }

}

void printAdjList(FILE *outputFile, ListT *adjList, int noOfVertices) {
    fprintf(outputFile, "The adjacency list is:\n");
    for (int i = 0; i < noOfVertices; i++) {
        printList(outputFile, adjList[i]);
    }
    fprintf(outputFile, "\n");
}

void printPath(FILE *outputFile, ListT list) {
    if (list.first == NULL) {
        fprintf(outputFile, "There is no path! \n");
    } else {
        NodeL *currentElement = list.first;
        while (currentElement) {
            fprintf(outputFile, "%c ", 'A' + currentElement->destination);
            currentElement = currentElement->next;
        }
    }
}


