#ifndef ASSIGNMENT__4_1__TREEAVL_H
#define ASSIGNMENT__4_1__TREEAVL_H

#include "node.h"

#define PADDING_STEP 7

NodeAVL *insert(NodeAVL *node, int key);

void prettyPrint(NodeAVL *root, int padding);

#endif //ASSIGNMENT__4_1__TREEAVL_H
