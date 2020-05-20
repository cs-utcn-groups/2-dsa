#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE{
    char Key;
    struct _NODE *Left,*Right;
}NODE;

NODE * insert(char Key, NODE *parent);
NODE *gm(NODE *parent);
NODE *gM(NODE *parent);
NODE * delete(char Key,NODE *parent);
NODE *find(char Key,NODE * parent);
void preorder(NODE *parent);
void inorder(NODE *parent);
void postorder(NODE *parent);