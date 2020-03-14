#include "head.h"

int main()
{

    FILE *f=fopen("input.dat","r");

    NodeT *root=createBinTree(0,NULL,f);

    printf("\nPreorder listing\n");
    preorder(root,0);
    printf("\n");

    printf("\nInorder listing\n");
    inorder(root,0);
    printf("\n");

    printf("\nPostorder listing\n");
    postorder(root,0);
    printf("\n");

    int node,k=0;
    while(k==0)
    {
        printf("Enter a node to interchange its subtree: ");
        scanf("%d",&node);
        if(ifNodeExists(root,node)==false)
            printf("Enter another node that appears in the initial tree: ");
        else
            k=1;
    }

    searchNodeForAddress(root,node);

    printf("Preorder listing after the interchange:\n");
    preorder(root,0);
    printf("\n");

    printf("Inorder listing after the interchange:\n");
    inorder(root,0);
    printf("\n");

    printf("Postorder listing after the interchange:\n");
    postorder(root,0);
    printf("\n");

    printf("The height of the tree is: %d",findHeight(root));

    printf("\nThe nr of leaves is: %d",nrOfLeaves(root));

    return 0;
}
