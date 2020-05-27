#ifndef ASSIGNMENT__3_1__TREE_H
#define ASSIGNMENT__3_1__TREE_H

#include "node.h"

#define PADDING_STEP 7

NodeT *createBinTree();

NodeT *getTreeFromList(NodeL **first);

void prettyPrint(NodeT *root, int padding);


#endif //ASSIGNMENT__3_1__TREE_H
