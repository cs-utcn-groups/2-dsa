//
// Created by Bori on 3/6/2020.
//

#ifndef ASSIGNMENT2_QUEUEAUCHAN_INTNODE_H
#define ASSIGNMENT2_QUEUEAUCHAN_INTNODE_H

typedef struct _intNode {
    int data;
    struct _intNode *next;
} intNode;

intNode *createIntNode(int data);

intNode *createIntNodeWithNext(int data, intNode *next);

#endif //ASSIGNMENT2_QUEUEAUCHAN_INTNODE_H
