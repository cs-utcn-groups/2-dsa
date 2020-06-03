#include "nod.h"

NodeT *createNode(int content) {
    NodeT *newN = (NodeT *) malloc(sizeof(NodeT));
    newN->data = content;
    newN->next = NULL;
    return newN;
}