#include "node.h"

NodeAVL *createNode(int key)
{
    NodeAVL* node = (NodeAVL*)
            malloc(sizeof(NodeAVL));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return(node);
}