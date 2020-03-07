//
// Created by Bori on 3/6/2020.
//

#include "costumerNode.h"
#include <stdlib.h>

costumerNode *createCostumerNode(costumer *c) {
    costumerNode *newcostumerNode = (costumerNode *) malloc(sizeof(costumerNode));
    newcostumerNode->thisCostumer.time = c->time;
    newcostumerNode->thisCostumer.amount = c->amount;
    newcostumerNode->next = NULL;
    return newcostumerNode;
}

costumerNode *createCostumerNodeWithNext(costumer *c, costumerNode *next) {
    costumerNode *newcostumerNode = createCostumerNode(c);
    newcostumerNode->next = next;
    return newcostumerNode;
}
