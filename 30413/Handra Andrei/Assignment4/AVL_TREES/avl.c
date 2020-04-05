#include "head.h"

void PrettyPrint(NodeT *root,int space)
{
    if(root == NULL)
    {
        return;
    }
    space+=COUNT;
    PrettyPrint(root->right,space);
    printf("\n");
    for(int i=COUNT;i<space;i++)
    {
        printf(" ");
    }
    printf("%d",root->key);
    PrettyPrint(root->left,space);
}
