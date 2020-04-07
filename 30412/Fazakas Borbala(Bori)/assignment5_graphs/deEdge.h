//
// Created by Bori on 4/7/2020.
//

#ifndef ASSIGNMENT5_GRAPHS_DEEDGE_H
#define ASSIGNMENT5_GRAPHS_DEEDGE_H

typedef struct _deEdge {
    int length, endp1, endp2;
    struct _deEdge *next;
} deEdge;

deEdge *createDeEdge(int endp1, int endp2, int length);

deEdge *createDeEdgeWithNext(int endp1, int endp2, int length, deEdge *next);

#endif //ASSIGNMENT5_GRAPHS_DEEDGE_H
