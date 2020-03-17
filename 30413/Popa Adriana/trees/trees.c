#include "trees.h"

void fatalError( const char *msg )
{
    printf ( msg ) ;
    printf ( " \n" ) ;
    exit ( 1 ) ;
}

void preorder( NodeT *p, int level )
{
    int i ;
    if ( p != NULL )
    {
        for ( i = 0; i <= level ; i++ )
            printf ( "  " ) ;
        printf ( "%d\n", p->id ) ;
        preorder( p->left, level + 1 ) ;
        preorder( p->right, level + 1 ) ;
    }
}

void inorder( NodeT *p, int level )
{
    int i ;
    if ( p != NULL )
    {
        inorder( p->left, level + 1 ) ;
        for ( i = 0; i <= level ; i++ )
            printf ( "  " ) ;
        printf ( "%d\n", p->id ) ;
        inorder( p->right, level + 1 ) ;
    }
}

void postorder( NodeT *p, int level )
{
    int i ;
    if ( p != NULL )
    {
        postorder( p->left, level + 1 ) ;
        postorder( p->right, level + 1 ) ;
        for ( i = 0; i <= level ; i++ )
            printf ( "  " ) ;
        printf ( "%d\n", p->id ) ;
    }
}

NodeT *createBinTree( int branch, NodeT *parent,FILE *f )
{
    NodeT *p;
    int id ;
    if ( branch == 0 )
        printf ( "Root identifier =" ) ;
    else if ( branch == 1 )
        printf ( "Left child of %d =",parent->id ) ;
    else
        printf ( "Right child of %d=",parent->id ) ;
    fscanf( f,"%d", &id ) ;
    printf("%d\n",id);
    if ( id == 0 )
        return NULL;
    else
    {
        p = ( NodeT *)malloc(sizeof( NodeT ) ) ;
        if ( p == NULL )
            fatalError( "Out of space in createBinTree " ) ;
        p->id = id ;
        p->left = createBinTree( 1, p,f ) ;
        p->right = createBinTree( 2, p,f ) ;
    }
    return p;
}

void interchange(NodeT *p,int x)
{
    if ( p != NULL )
    {
        if(p->id==x)
        {
            NodeT *aux=(NodeT*)malloc(sizeof(NodeT));
            aux=p->left;
            p->left=p->right;
            p->right=aux;
        }
        else
        {
            interchange( p->left,x) ;
            interchange( p->right, x) ;
        }
    }
}

int determineHigh(NodeT *p)
{
    int a,b;
    if(p != NULL)
    {
        a=determineHigh(p->left);
        b=determineHigh(p->right);
        if(a>b)
            return a+1;
        else
            return b+1;
    }
    return 0;
}

int determineNumberLeaves(NodeT *p)
{
    if(p != NULL)
    {
        if(p->left == NULL && p->right == NULL)
            return 1;
        else
            return determineNumberLeaves(p->left)+determineNumberLeaves(p->right);
    }
    return 0;
}
