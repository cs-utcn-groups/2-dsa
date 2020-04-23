//
// Created by TheRa on 3/31/2020.
//

#include "node.h"

NodeT *createNode( int content )
{
    NodeT *p = (NodeT*)malloc(sizeof(NodeT));
    p->content = content;
    p->next = NULL;
    return p;
}
