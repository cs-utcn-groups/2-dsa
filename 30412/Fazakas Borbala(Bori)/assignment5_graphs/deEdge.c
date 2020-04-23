//
// Created by Bori on 4/7/2020.
//

#include "deEdge.h"
#include <stdlib.h>

deEdge *createDeEdge(int endp1, int endp2, int length) {
    deEdge *newdeEdge = (deEdge *) malloc(sizeof(deEdge));
    newdeEdge->length = length;
    newdeEdge->endp1 = endp1;
    newdeEdge->endp2 = endp2;
    newdeEdge->next = NULL;
    return newdeEdge;
}

deEdge *createDedeEdgeWithNext(int endp1, int endp2, int length, deEdge *next) {
    deEdge *newdeEdge = createDeEdge(endp1, endp2, length);
    newdeEdge->next = next;
    return newdeEdge;
}