//
// Created by Bori on 3/6/2020.
//

#include "intNode.h"
#include <stdlib.h>

intNode *createIntNode(int data) {
    intNode *newintNode = (intNode *) malloc(sizeof(intNode));
    newintNode->data = data;
    newintNode->next = NULL;
    return newintNode;
}

intNode *createIntNodeWithNext(int data, intNode *next) {
    intNode *newintNode = createIntNode(data);
    newintNode->next = next;
    return newintNode;
}
