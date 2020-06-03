//
// Created by diana on 10/05/2020.
//

#include "longest-path.h"

void findPath(Graph *graph, int source, int destination, AdjList *path, AdjList *longestPath);

int countElements(AdjList *list);

void findLongestPath(Graph *graph, int source, int destination, struct _iobuf *buffer) {
    fprintf(buffer, "\nLongest simple path between %d and %d:\n", source, destination);
    fillVisited(graph->nrOfVertices);
    AdjList *path = createAdjListArray(1);
    AdjList *longestPath = createAdjListArray(1);

    findPath(graph, source, destination, path, longestPath);

    ListNode *crawl = longestPath->head;
    while (crawl != NULL) {
        fprintf(buffer, "%d ", crawl->key);
        crawl = crawl->next;
    }
}

void findPath(Graph *graph, int source, int destination, AdjList *path, AdjList *longestPath) {
    static int maxCurrentLength = 0;
    visited[source] = true;
    addEdgeToEndOfList(path, source, 1);
    if (source == destination) {
        if (countElements(path) > maxCurrentLength) {
            deleteList(&longestPath);
            longestPath->head = path->head; // copy path to longestPath
            maxCurrentLength = countElements(longestPath);
            path->head = NULL; // clear path
        }
    } else {
        // DFS order of trying to add neighbours
        ListNode *crawl = graph->nodesArray[source].head;
        while (crawl != NULL) {
            if (visited[crawl->key] == false) {
                findPath(graph, crawl->key, destination, path, longestPath);
            }
            crawl = crawl->next;
        }
    }
}

int countElements(AdjList *list) {
    if (list->head == NULL)
        return 0;
    ListNode *crawl = list->head;
    int nrOfElements = 0;
    while (crawl != NULL) {
        nrOfElements++;
        crawl = crawl->next;
    }
    return nrOfElements;
}


