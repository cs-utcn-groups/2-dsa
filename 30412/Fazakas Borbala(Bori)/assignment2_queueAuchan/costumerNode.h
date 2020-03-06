//
// Created by Bori on 3/6/2020.
//

#ifndef ASSIGNMENT2_QUEUEAUCHAN_COSTUMERNODE_H
#define ASSIGNMENT2_QUEUEAUCHAN_COSTUMERNODE_H

typedef struct {
    int time, amount;
} costumer;

typedef struct _costumerNode {
    costumer thisCostumer;
    struct _costumerNode *next;
} costumerNode;

costumerNode *createCostumerNode(costumer *c);

costumerNode *createCostumerNodeWithNext(costumer *c, costumerNode *next);

#endif //ASSIGNMENT2_QUEUEAUCHAN_COSTUMERNODE_H
