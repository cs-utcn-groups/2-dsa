//
// Created by andre on 06.05.2020.
//

#include "longestPath.h"

void longestPath(FILE *outputFile, ListT *adjList, int noOfVertices, int startNode, int destinationNode) {
    fprintf(outputFile, "The longest simple path between %c and %c:\n", 'A' + startNode, 'A' + destinationNode);
    int *visited = initializeArray(noOfVertices, UNVISITED);
    ListT *longestPath = createAdjList(1);
    ListT *currentPath = createAdjList(1);

    addLast(currentPath, startNode, startNode, 0);
    longestPathRec(adjList, longestPath, currentPath, startNode, destinationNode, visited);

    printPath(outputFile, *longestPath);
    fprintf(outputFile, "\nThe longest simple path between %c and %c ended.\n\n", 'A' + startNode,
            'A' + destinationNode);
}

void longestPathRec(ListT *adjList, ListT *longestPath, ListT *currentPath, int startNode, int destinationNode,
                    int *visited) {
    if (startNode == destinationNode) {
        if (currentPath->noOfNodes > longestPath->noOfNodes) {
            doomTheList(longestPath);
            NodeL *currentElement = currentPath->first;
            while (currentElement != NULL) {
                addLast(longestPath, currentElement->start, currentElement->destination, 0);
                currentElement = currentElement->next;
            }
            longestPath->noOfNodes = currentPath->noOfNodes;
        }
    } else {
        visited[startNode] = VISITED;
        int *neighbours = adjList[startNode].first->neighbours;
        int noOfNeighbours = adjList[startNode].noOfNodes;
        for (int i = 0; i < noOfNeighbours; i++) {
            int w = neighbours[i];
            if (visited[w] == UNVISITED) {
                addLast(currentPath, startNode, w, 0);
                longestPathRec(adjList, longestPath, currentPath, w, destinationNode, visited);
                deleteLast(currentPath);
            }
        }
        visited[startNode] = UNVISITED;
    }
}
