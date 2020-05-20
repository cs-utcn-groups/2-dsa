
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node_type
{
    int id;
    struct node_type *left, *right;
} NodeT;

int findHeight(NodeT *p)
{
    int rightH,leftH,height;

    if(p->left != NULL && p->right != NULL)
    {
        rightH = 1 + findHeight(p->right);
        leftH = 1 + findHeight(p->left);
        if(rightH > leftH)
        {
            height = rightH;
        }
        else
        {
            height = leftH;
        }
    }
    else if(p->right == NULL && p->left != NULL)
    {
        height = 1 + findHeight(p->left);
    }
    else if(p->right != NULL && p->left == NULL)
    {
        height = 1 + findHeight(p->right);
    }
    else
    {
        height = 1;
    }
    return height;
}
    int nrLeaves(NodeT*p,int leaves)
    {
        if(p!=NULL)
        {
            if (p->left==NULL&&p->right==NULL)
            {
               return 1;
            }
            leaves = leaves + nrLeaves(p->left,leaves) + nrLeaves(p->right, leaves);
        }
        return leaves;
    }

    void interChange(NodeT *p,int id)
    {
        if(p != NULL)
        {
            if(p->id==id)
            {
                if(p->left != NULL && p->right != NULL)
                {
                    NodeT *aux;
                    aux = p->right;
                    p->right = p->left;
                    p->left = aux;
                }
                else if(p->left == NULL)
                {
                    p->left = p->right;
                    p->right = NULL;
                }
                else if(p->right == NULL)
                {
                    p->right = p->left;
                    p->left = NULL;
                }
            }
            else
            {
               interChange(p->left, id);
               interChange(p->right, id);
            }
        }
    }
    void fatalError( const char *msg)
    {
        printf( msg );
        printf("\n" );
        exit ( 1 );
    }
    void preorder( NodeT *p, int level)
    {
        if(p != NULL)
        {
            for( int i = 0; i <= level; i++ )
                printf(" " );
            printf("%2.2d\n",p->id );
            preorder(p->left, level + 1 );
            preorder(p->right, level + 1 );
        }
    }
    void inorder( NodeT*p, int level)
    {
        if(p != NULL)
        {
            inorder(p->left, level + 1 );
            for( int i = 0; i <= level; i++ )
                printf(" " );
            printf("%2.2d\n",p->id );
            inorder(p->right, level + 1 );
        }
    }
    void postorder( NodeT*p, int level)
    {
        if(p != NULL)
        {
            postorder(p->left, level + 1 );
            postorder(p->right, level + 1 );
            for( int i = 0; i <= level; i++ )
                printf(" " );
            printf("%2.2d\n",p->id );
        }
    }
    NodeT*createBinTree( int branch, NodeT*parent)
    {
        NodeT*p;
        int id;
        if( branch == 0 )
            printf("Root identifier [0 to end]=" );
        else if ( branch == 1 )
            printf("Left child of%d [0 to end]=",parent->id );
        else printf("Right child of%d [0 to end]=",parent->id );
        scanf("%d", &id);
        if( id == 0 ) return NULL;
        else
        {
            p = ( NodeT*)malloc(sizeof( NodeT ));
            if(p == NULL) fatalError("Out of space in createBinTree" );
            p->id= id;
            p->left= createBinTree( 1,p );
            p->right= createBinTree( 2,p );
        }
        return p;
    }
    int main()
    {
        int id;
        int leaves;
        NodeT*root= createBinTree( 0, NULL );
        printf("Choose a node for interchange\n");
        scanf("%d", &id);
        interChange(root,id);
        while('\n' != getc(stdin));
        printf("\nPreorder listing\n" );
        preorder( root, 0 );
        printf("Press Enter to continue." );
        while('\n' != getc(stdin));
        printf("\nInorder listing\n" );
        inorder( root, 0 );
        printf("Press Enter to continue." );
        while('\n' != getc(stdin));
        printf("\nPostorder listing\n" );
        postorder( root, 0 );
        printf("Press Enter to continue." );
        while('\n' != getc(stdin));
        leaves=nrLeaves(root,0);
        printf(" Nr of leaves %d",leaves);
        printf("\n");
        int height = findHeight(root);
        printf(" Height %d", height);
        return 0;
    }
