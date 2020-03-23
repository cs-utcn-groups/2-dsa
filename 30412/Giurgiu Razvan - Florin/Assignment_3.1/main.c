#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char id;
    struct node *left,*right;
}NodeT;

typedef struct nodetype
{
    char id;
    struct nodetype *prev,*next;
}NodeL;

NodeT *createBinaryTree();
NodeL *getListFromTree(NodeT *root), *first, *last;
void traverseList(NodeL *firstFromList);
NodeT *getTreeFromList(NodeL *firstFromList);
void preorder(NodeT *currentRoot, int level) {
    if (currentRoot != NULL) {
        for (int i = 0; i < level; i++)
            printf(" ");
        printf("%c", currentRoot->id);
        preorder(currentRoot->left, level + 1);
        preorder(currentRoot->right, level + 1);
    }
}
void al(char data);

int main() {
    NodeT *root = createBinaryTree();
    //preorder(root,0);
    NodeL *firstFromList = getListFromTree(root);
    traverseList(firstFromList);
    return 0;
}

void traverseList(NodeL *firstFromList)
{
    NodeL *p = firstFromList;
    while(p!=NULL)
    {
        printf("%c", p->id);
        p=p->next;
    }
}

NodeT *createBinaryTree()
{
    char *c = malloc(sizeof(char));
    scanf("%s",c);
    if(strcmp(c,"*") == 0)
        return NULL;

    NodeT *p = (NodeT *)malloc(sizeof(NodeT));
    p->id = c[0];
    p->left = createBinaryTree();
    p->right = createBinaryTree();
    return p;
}

NodeL *getListFromTree(NodeT *root)
{
    if(root == NULL) return NULL;

    NodeL *p = (NodeL *)malloc(sizeof(NodeL));
    p->id = root->id;
    if(first == NULL)
    {
        last=p;
        last->next = NULL;
        last->prev = NULL;
        first = last;
    }
    else
    {
        last->next = p;
        p->prev = last;
        last = p;
        last->next = NULL;
    }
    first->next = getListFromTree(root->left);
    first->next = getListFromTree(root->right);
    return p;
}

void al(char data)
{
    NodeL *p = (NodeL*)malloc(sizeof(NodeL));
    p->id=data;
    if(first==NULL)
    {
        first=p;
        first->next = NULL;
        first->prev = NULL;
        last = first;
    }
    else
    {
        last->next = p;
        p->prev = last;
        p->next = NULL;
        last = p;
    }

}

NodeT *getTreeFromList(NodeL *firstFromList)
{
    if (firstFromList == NULL) return NULL;

    NodeT *p = (NodeT*)malloc(sizeof(NodeT));
    p->id = firstFromList->id;
    p->left = getTreeFromList(firstFromList->next);
    p->right =  getTreeFromList(firstFromList->next);

    return p;


}
