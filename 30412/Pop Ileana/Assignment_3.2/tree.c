//
// Created by ileana on 3/21/2020.
//

#include "tree.h"


void printElement(NodeT * node);


NodeT * createExpressionTree()
{
    if(first->operator=='#') {
        first=first->next;
        return NULL;
    }
    NodeT * p = (NodeT*)malloc(sizeof(NodeT));
    if(first->type==0)
        p->operator=first->operator;
    else
        p->operand=first->operand;
    p->type=first->type;
    first=first->next;
    p->left=createExpressionTree(first);
    p->right=createExpressionTree(first);
    return p;
}

void printTree(NodeT * root, int level)
{
    if(root!=NULL)
    {
        printTree(root->right,level+1);
        for(int i=0;i< 5*level;i++)
            printf(" ");
        printElement(root);
        printf("\n");
        printTree(root->left,level+1);
        printf("\n");
    }
}

void printElement(NodeT * node)
{
    if(node->type==0)
        printf("%c",node->operator);
    else
        printf("%0.2lf",node->operand);

}
void preOrder(NodeT * currentRoot, int level)
{
    int i;
    if(currentRoot!=NULL)
    {
        for(i=0;i<level;i++)
            printf(" ");
        printElement(currentRoot);
        preOrder(currentRoot->left,level+1);
        preOrder(currentRoot->right,level + 1);
    }
}