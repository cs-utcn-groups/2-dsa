#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define LEFT 1
#define RIGHT 2

typedef struct bst_node
{
    char key;
    struct bst_node *left, *right;
} BSTNodeT;

BSTNodeT *root;

BSTNodeT *recInsert(BSTNodeT*root, char key);
BSTNodeT *find(BSTNodeT *root, char key);
BSTNodeT *delNode (BSTNodeT *root, char key );
void fatalError(const char *msg);
void preorder(BSTNodeT *p,int level);
void inorder(BSTNodeT *p, int level);
void postorder(BSTNodeT *p, int level);
void delTree(BSTNodeT *root);
