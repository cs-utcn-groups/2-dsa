//
// Created by Bori on 4/2/2020.
//

#include "edge.h"
#include <stdlib.h>

edge *createedge(int endPoint, int length) {
    edge *newedge = (edge *) malloc(sizeof(edge));
    newedge->length = length;
    newedge->endPoint = endPoint;
    newedge->next = NULL;
    return newedge;
}

edge *createedgeWithNext(int endPoint, int length, edge *next) {
    edge *newedge = createedge(endPoint, length);
    newedge->next = next;
    return newedge;
}
