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

void interchange(NodeT *p, int x)
{
    if(p != NULL)
    {
        if(p->id == x)
        {
            NodeT *aux = (NodeT*)malloc(sizeof(NodeT));
            aux = p->left;
            p->left = p->right;
            p->right = aux;
        }
        else
        {
            interchange(p->left,x);
            interchange(p->right,x);
        }
    }
}

void height(NodeT *p, int s, int *maxim)
{
    if(p != NULL)
    {
        s = s+1;
        height(p->left,s,maxim);
        height(p->right,s,maxim);
    }
    else
    {
        if(s > *maxim)
        {
            *maxim = s;
        }
    }
}

int leaves(NodeT *p)
{
    if(p != NULL)
    {
        if(leaves(p->left) == 0 && leaves(p->right) == 0)
            return 1;
        else
            return leaves(p->left) + leaves(p->right);
    }
    else
        return 0;
}

int main()
{
    NodeT *root = createBinTree( 0, NULL );
    /*while ('\n' != getc(stdin))
    {
        printf( "\nPreorder listing\n" );
        preorder( root, 0 );
        printf( "Press Enter to continue." );
    }
    while ('\n' != getc(stdin))
    {
        printf( "\nInorder listing\n" );
        inorder( root, 0 );
        printf( "Press Enter to continue." );
    }
    while ('\n' != getc(stdin))
    {
        printf( "\nPostorder listing\n" );
        postorder( root, 0 );
        printf( "Press Enter to continue." );
    }*/
    while ('\n' != getc(stdin));
    int x;
    scanf("%d",&x);
    interchange(root,x);
    preorder(root, 0);

    int s=0,maxim=0;
    height(root,s,&maxim);
    printf("%d\n",maxim);

    printf("%d",leaves(root));
    return 0;
}
