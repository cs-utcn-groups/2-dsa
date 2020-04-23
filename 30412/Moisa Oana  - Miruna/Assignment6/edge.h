//
// Created by User on 11.04.2020.
//

#ifndef ASSIGNMENT6_EDGE_H
typedef struct edge{
    int weight;
    int source;
    int destination;
    struct edge *next;
}EdgeT;
typedef struct edgeList{
    struct edge * first;
    struct edge *last;
    int n;
}EdgeList;
EdgeList list;
EdgeT * createEdge(int source, int destination, int weight);
#define ASSIGNMENT6_EDGE_H

#endif //ASSIGNMENT6_EDGE_H
