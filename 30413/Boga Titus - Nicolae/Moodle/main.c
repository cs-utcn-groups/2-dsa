#include <stdio.h>
#include <stdlib.h>
typedef struct node_type
{
    char id; /* node name */
    /* ... other useful info */
    struct node_type *left, *right;
} NodeT;
void fatalError( const char *msg )
{
    printf( msg );
    printf( "\n" );
    exit ( 1 );
}
void preorder( NodeT *p, int level )
{
    if ( p != NULL )
    {
        for ( int i = 0; i <= level; i++ ) printf( " " ); /* for nice listing */
        printf( "%2.2d\n", p->id );
        preorder( p->left, level + 1 );
        preorder( p->right, level + 1 );
    }
}
void inorder( NodeT *p, int level )
{
    if ( p != NULL )
    {
        inorder( p->left, level + 1 );
        for ( int i = 0; i <= level; i++ ) printf( " " ); /* for nice listing */
        printf( "%2.2d\n", p->id );
        inorder( p->right, level + 1 );
    }
}

void postorder( NodeT *p, int level )
{
    if ( p != NULL )
    {
        postorder( p->left, level + 1 );
        postorder( p->right, level + 1 );
        for ( int i = 0; i <= level; i++ ) printf( " " ); /* for nice listing */
        printf( "%2.2d\n", p->id );
    }
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

int max(int a,int b)
{
    if(a>b)
        return a;
    return b;
}

void InterchangeBranches(NodeT *parent)
{
    if(parent == NULL)
        return;
    NodeT *aux=parent->left;
    parent->left=parent->right;
    parent->right=aux;
}

int HeightOfTheTree(NodeT * parent)
{
    if(parent == NULL)
        return 0;
    return max(HeightOfTheTree(parent->left),HeightOfTheTree(parent->right))+1;
}

int NrOfLeaves(NodeT * parent )
{
    if(parent == NULL)
        return 0;
    int n=0;
    if(parent->left == NULL && parent->right == NULL)
        return 1;
    if(parent->left)
         n+=NrOfLeaves(parent->left);
    if(parent->right)
        n+=NrOfLeaves(parent->right);
    return n;

}


int main()
{
    NodeT *root = createBinTree( 0, NULL );
    while ('\n' != getc(stdin));
    printf( "\nPreorder listing\n" );
    preorder( root, 0 );
    printf( "Press Enter to continue." );
    while ('\n' != getc(stdin));
    printf( "\nInorder listing\n" );
    inorder( root, 0 );
    printf( "Press Enter to continue." );
    while ('\n' != getc(stdin));
    printf( "\nPostorder listing\n" );
    postorder( root, 0 );
    printf( "Press Enter to continue." );
    while ('\n' != getc(stdin));

    printf("\nHeight Of the Tree: %d",HeightOfTheTree(root));
    printf("\nNumber of Leaves : %d",NrOfLeaves(root));

    InterchangeBranches(root);



    printf( "\nPreorder listing\n" );
    preorder( root, 0 );
    printf( "Press Enter to continue." );
    while ('\n' != getc(stdin));
    printf( "\nInorder listing\n" );
    inorder( root, 0 );
    printf( "Press Enter to continue." );
    while ('\n' != getc(stdin));
    printf( "\nPostorder listing\n" );
    postorder( root, 0 );
    printf( "Press Enter to continue." );
    while ('\n' != getc(stdin));


    return 0;
}
