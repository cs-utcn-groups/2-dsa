//
// Created by Alina Mihut on 4/13/20.
//
#include "edge.h"


edgeL *createEdge (){

    edgeL *e=(edgeL*) malloc (MAX* sizeof(edgeL));
    e->n=0;
    e->data=(edgeT*) malloc (MAXN *sizeof(edgeT));
    return e;
}
