//
// Created by q on 3/27/2020.
//

#ifndef ASSIGNMENT4_DELETE_H
#define ASSIGNMENT4_DELETE_H

#endif //ASSIGNMENT4_DELETE_H

#include "insert.h"

/*
 * deleting a node from tree
 */
// function that deletes a node given by key
BSTNodeT * deleteNode(BSTNodeT * root, int key);
// function that returns successor of node
BSTNodeT * getSuccessor(BSTNodeT * node);