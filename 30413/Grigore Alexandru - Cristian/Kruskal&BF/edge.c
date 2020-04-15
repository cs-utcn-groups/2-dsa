#include "edge.h"

edgeList *createEdge()
{
    edgeList *edge=(edgeList*)malloc(sizeof(edgeList)*MAX);
    edge->n=0;
    edge->data=(Edge*)malloc(sizeof(Edge)*MAX);
    return edge;
}
