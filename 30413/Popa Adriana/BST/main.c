#include "BST.h"

int main()
{
    FILE *f=fopen("input.txt","r");
    BSTNodeT *p;
    int n, key, i;
    fscanf(f,"%d",&n);
    root= NULL;
    for(i = 0; i < n ; i++)
    {
        fscanf(f,"%c",&key);
        root = recInsert(root, key);

    }
    printf( "\nPreorder listing\n");
    preorder(root, 0);
    printf(" \nInorder listing\n");
    inorder(root, 0);
    printf("\nPostorder listing\n");
    postorder(root, 0);
    printf("Key of node to found");
    scanf("%c",&key);
    p= find(root, key);
    if(p != NULL)
        printf("Node found\n");
    else
        printf("Node NOT found\n ");
    printf("Key of node to delete");
    scanf("%c",&key);
    root = delNode (root, key);
    inorder(root, 0);
    delTree(root);
    root= NULL;
    printf("Tree completely removed\n");
    return 0;
}
