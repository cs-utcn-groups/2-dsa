#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int label;
    struct node *left, *right;
} NodeTree;


void initial(NodeTree *T)
{
    T->left=NULL;
    T->right=NULL;
    T->label=0;
}

NodeTree *createBinTree( int direction, NodeTree *T )
{
    NodeTree *p;
    int id;
    if ( direction == 0 )
        printf( "Root identifier  =" );
    else if ( direction == 1 )
        printf( "Left child of %d  =",T->label );
    else
        printf( "Right child of %d  =",T->label );
    scanf("%d", &id);
    if ( id == 0 )
        return NULL;
    else
    {
        p = ( NodeTree *)malloc(sizeof( NodeTree ));
        p->label = id;
        p->left = createBinTree( 1, p );
        p->right = createBinTree( 2, p );
    }
    return p;
}


void preorder(NodeTree *T,int level)
{
    if(T!=NULL)
    {
        int i;
        for ( i = 0; i <= level; i++ )
            printf( " " );
        printf("%2.2d\n",T->label);
        preorder( T->left, level + 1 );
        preorder( T->right, level + 1 );
    }
}
void inorder(NodeTree *T,int level)
{
    if(T!=NULL)
    {
        inorder( T->left, level + 1 );
        int i;
        for ( i = 0; i <= level; i++ )
            printf( " " );
        printf("%2.d\n",T->label);
        inorder( T->right, level + 1 );
    }
}
void postorder(NodeTree *T,int level)
{
    if(T!=NULL)
    {

        postorder( T->left, level + 1 );
        postorder( T->right, level + 1 );
        int i;
        for ( i = 0; i <= level; i++ )
            printf( " " );
        printf("%2.d\n",T->label);
    }
}
NodeTree *Interchange(NodeTree *T)
{
    if(T!=NULL)
    {
        NodeTree *Copy = ( NodeTree *)malloc(sizeof( NodeTree ));
        Copy=T->left;
        T->left=T->right;
        T->right=Copy;
    }
    return T;
}

int height(NodeTree *T,int level)
{
    if(T!=NULL)
    {
        if(T->left==NULL&&T->right==NULL)
            return level+1;
        else
        {
            int l=height(T->left,level+1);
            int r=height(T->right,level+1);
            if(r>l)
                return r;
            else
                return l;
        }
    }
}
int leafs(NodeTree *T,int leaf)
{
    int r,l;
    if(T!=NULL)
    {
        if(T->left==NULL&&T->right==NULL)
            return 1;
        else
        {
            l=leaf+leafs(T->left,leaf);
            r=leaf+leafs(T->right,leaf);

            return r+l;
        }
    }
}
int main()
{
    NodeTree *root = createBinTree( 0, NULL );
    while ('\n' != getc(stdin));
    {
        printf( "\nPreorder listing\n" );
        preorder( root, 0 );
        printf( "Press Enter to continue." );
    }
    while ('\n' != getc(stdin));
    {
        printf( "\nInorder listing\n" );
        inorder( root, 0 );
        printf( "Press Enter to continue." );
    }
    while ('\n' != getc(stdin));
    {
        printf( "\nPostorder listing\n" );
        postorder( root, 0 );
        printf( "Press Enter to continue." );
    }
    printf ("\n");
    printf("%d \n",height(root,0));
    printf ("\n");
    printf("%d \n",leafs(root,0));
    return 0;
}
