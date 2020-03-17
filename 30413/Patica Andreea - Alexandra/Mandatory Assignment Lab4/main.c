#include <stdio.h>
#include <stdlib.h>

typedef struct node_type
{
    int id; /* node name */
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
        for ( int i = 0; i <= level; i++ )
            printf( " " ); /* for nice listing */
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
        for ( int i = 0; i <= level; i++ )
            printf( " " ); /* for nice listing */
        printf( "%2.2d\n", p->id );
        inorder( p->right, level + 1 );
    }
}
//-----  --- Code part 04 ----------------------
// Construction and traversals of binary trees (continued)}
void postorder( NodeT *p, int level )
{
    if ( p != NULL )
    {
        postorder( p->left, level + 1 );
        postorder( p->right, level + 1 );
        for ( int i = 0; i <= level; i++ )
            printf( " " ); /* for nice listing */
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

NodeT* searchNode(NodeT *p, int val)
{
    if (p == NULL)
    {
        return NULL;
    }
    if (p->id == val)
    {
        return p;
    }
    NodeT *node;
    node = searchNode(p->left, val);
    if (node == NULL)
    {
        node = searchNode(p->right, val);
    }
    return node;
}

void Interchange (NodeT *p, int val)
{
    NodeT *node = searchNode(p, val);
    if (node == NULL)
    {
        printf("Node not found!\n");
    }
    else
    {
        NodeT *temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}

int heightOfTree(NodeT *p)
{
    if (p == NULL)
    {
        return 0;
    }
    int valLeft = 1 + heightOfTree(p->left);
    int valRight = 1 + heightOfTree(p->right);
    if (valLeft>valRight)
    {
        return valLeft;
    }
    else
    {
        return valRight;
    }
}

int noOfLeaves(NodeT *p)
{
    if (p == NULL)
    {
        return 0;
    }
    if (p->left == NULL && p->right == NULL)
    {
        return 1;
    }
    else
    {
        return noOfLeaves(p->left) + noOfLeaves(p->right);
    }
}

int main()
{
    NodeT *root;

    root = createBinTree( 0, NULL );
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

    ///interchange
    int val;
    printf("\nNode whose subtrees you want to interchange= ");
    scanf("%d", &val);
    Interchange(root, val);
    ///

    printf("After the ghange:\n");
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

    printf("\nHeight of the tree = %d\n", heightOfTree(root));
    printf( "Press Enter to continue." );
    while ('\n' != getc(stdin));

    printf("\nNumber of leaves = %d\n", noOfLeaves(root));
    printf( "Press Enter to continue." );
    while ('\n' != getc(stdin));

    return 0;
}
