#include "trees.h"

int main()
{
    NodeT *root ;
    int x;
    FILE *f=fopen("input.txt","r");
    root = createBinTree( 0, NULL ,f) ;
    printf ( " \nInorder listing \n" ) ;
    inorder( root, 0 ) ;

    printf("Give a node for interchange x=");
    scanf("%d",&x);
    interchange(root,x);

    printf("\nThe high of the tree is: %d",determineHigh(root));
    printf("\nThe number of leaves is: %d",determineNumberLeaves(root));

    printf ( " \nPreorder listing \n" ) ;
    preorder( root, 0 ) ;
    printf ( " \nInorder listing \n" ) ;
    inorder( root, 0 ) ;
    printf ( " \nPostorder listing \n" ) ;
    postorder( root, 0 ) ;
    return 0;
}
