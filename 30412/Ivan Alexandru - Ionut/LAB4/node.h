//
// Created by Ivan on 4/1/2020.
//

#ifndef LAB4_NODE_H
#define LAB4_NODE_H

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

void preord(struct Node *root);
struct Node* insert(struct Node* node, int key);
struct Node *rotateL(struct Node *x);
#endif //LAB4_NODE_H
