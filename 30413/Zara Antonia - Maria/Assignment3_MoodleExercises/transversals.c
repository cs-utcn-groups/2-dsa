#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int id;
    struct node *left, *right;
} nodeT;

void preorder( nodeT *p, int level )
{
    int i;
    if ( p != NULL )
    {
        for (i = 0; i <= level; i++ )
        {
            printf( "   " );
        }
        printf( "%2.2d\n", p->id );
        preorder( p->left, level + 1 );
        preorder( p->right, level + 1 );
    }
}

void inorder( nodeT *p, int level )
{
    int i;
    if ( p != NULL )
    {
        inorder( p->left, level + 1 );
        for (i = 0; i <= level; i++ )
        {
            printf( "   " );
        }
        printf( "%2.2d\n", p->id );
        inorder( p->right, level + 1 );
    }
}

void postorder( nodeT *p, int level )
{
    int i;
    if ( p != NULL )
    {
        postorder( p->left, level + 1 );
        postorder( p->right, level + 1 );
        for (i = 0; i <= level; i++ )
        {
            printf( "   " );
        }
        printf( "%2.2d\n", p->id );
    }
}
