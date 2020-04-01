//
// Created by csatl on 3/21/2020.
//

#include "binary_tree.h"

tree *CreateBinaryTree()
{
    tree *p = (tree*)malloc(sizeof(tree));
    char *c = malloc(sizeof(char));
    scanf("%s",c);
    if(strcmp(c, "*") == 0){
        p->id = '*';
        p->left = NULL;
        p->right = NULL;
        return p;
    }
    p->id = c[0];
    p->left = CreateBinaryTree();
    p->right = CreateBinaryTree();
    return p;
}

dll_tree *GetListFromTree(tree * root, dll_tree * ant)
{
    dll_tree *p = (dll_tree*)malloc(sizeof(dll_tree));
    p->id = root->id;
    p->previous = ant;
    p->n_right = NULL;
    p->n_left = NULL;

    if(root->left != NULL)
        p->n_left = GetListFromTree(root->left, p);

    if(root->right != NULL)
        p->n_right = GetListFromTree(root->right, p);
    return p;
}

void PrettyPrint(tree *currentRoot, int level)
{
    if(currentRoot != NULL)
    {
        PrettyPrint(currentRoot->right,level+1);
        for(int i=0; i<level;i++)
            printf("     ");
        printf("%c\n",currentRoot->id);
        PrettyPrint(currentRoot->left,level+1);
    }
}
void PrettyPrintDLL(dll_tree *currentRoot, int level)
{
    if(currentRoot != NULL)
    {
        PrettyPrintDLL(currentRoot->n_right,level+1);
        for(int i=0; i<level;i++)
            printf("     ");
        printf("%c\n",currentRoot->id);
        PrettyPrintDLL(currentRoot->n_left,level+1);
    }
}


/*
1
2
3
*
*
4
*
*
5
6
*
*
7
*
*
 */