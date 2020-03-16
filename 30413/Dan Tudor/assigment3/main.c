#include <stdio.h>
#include <stdlib.h>

typedef struct node_type
{
    char id;
    struct node_type *left, *right;
} NodeT;

void fatalError( const char *msg )
{
    printf( msg );
    printf( "\n" );
    exit ( 1 );
}

NodeT *createBinTree( int branch, NodeT *parent )
{
    NodeT *p;
    int id;
    /* read node id */
    if ( branch == 0 )
        printf( "Root identifier [0 to end] =" );
    else if ( branch == 1 )
        printf( "Left child of %d [0 to end] =",
                parent->id );
    else
        printf( "Right child of %d [0 to end] =",
                parent->id );
    scanf("%d", &id);
    if ( id == 0 )
        return NULL;
    else
    {
        /* build node pointed to by p */
        p = ( NodeT *)malloc(sizeof( NodeT ));
        if ( p == NULL )
            fatalError( "Out of space in createBinTree" );
        /* fill in node */
        p->id = id;
        p->left = createBinTree( 1, p );
        p->right = createBinTree( 2, p );
    }
    return p;
}

void preorder( NodeT *p, int level )
{
    if ( p != NULL )
    {
        for ( int i = 0; i <= level; i++ )
            printf( " " ); /* for nice listing */
        printf( "%2.2d\n", p->id );
        preorder( p->left, level + 1 );
        preorder( p->right, level + 1 );
    }
}

void printarray(NodeT *p)
{
    if(p != NULL)
    {
        printf("%d",p->id);
        printarray(p->left);
        printarray(p->right);
    }
    else
        printf("0");
}

int main()
{
    NodeT *root = createBinTree(0,NULL);
    printarray(root);
    printf("\n");
    preorder(root,0);
    return 0;
}
