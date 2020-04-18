//
// Created by bindi on 4/7/2020.
//

#ifndef ASSIGNMENT_6_1_GRAPHALGORITHMS_H
#define ASSIGNMENT_6_1_GRAPHALGORITHMS_H
#define INFINITY INT_MAX
#define UNDEFINED (-1)

void doKruskal(graph *myGraph);

void sortEdges(edge **edgeArray, int noOfEdges);

void doBellmanFord(graph *myGraph, int source);

#endif //ASSIGNMENT_6_1_GRAPHALGORITHMS_H
