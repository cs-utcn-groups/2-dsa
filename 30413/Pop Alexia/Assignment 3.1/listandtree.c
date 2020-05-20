#include "headerlist.h"

void initializeList()
{
    first=NULL;
    last=NULL;
};

void preorder( NodeT *p, int level)
{
    if(p != NULL)
    {
        for( int i = 0; i <=level; i++ )
            printf(" " );
        printf("%c\n",p->id);
        preorder(p->left,level+1);
        preorder(p->right,level+1);
    }
};

void fatalError( const char *msg )
{
    printf (msg);
    printf (" \n");
    exit (1);
};

NodeT *createBinTree( NodeT *parent,FILE *f )
{
    char id ;
    NodeT *p;
    fscanf( f,"%c", &id);
    if (id == '*') return NULL;
    else
    {
        p = ( NodeT *)malloc(sizeof( NodeT ) ) ;
        if ( p == NULL ) fatalError( "Out of space in createBinTree " ) ;
        p->id =id;
        p->left=createBinTree(p,f) ;
        p->right=createBinTree(p,f) ;
    }
    return p;
}
NodeT *TreeList()
{
    if(currentN->idd== '*')
    {
        currentN = currentN->next;
        return NULL;
    }
    else
    {
        NodeT *newN = (NodeT*)malloc(sizeof(NodeT));
        newN->id = currentN->idd;
        currentN = currentN->next;
        newN->left = TreeList();
        newN->right = TreeList();
        return newN;
    }
};
void createList(char i)
{
    if(last == NULL)
    {
        first = (NdT*)malloc(sizeof(NdT));
        first->previous = NULL;
        first->idd= i;
        first->next = NULL;
        last = first;
    }
    else
    {
        NdT*newN=(NdT*)malloc(sizeof(NdT));
        last->next = newN;
        newN->idd=i;
        newN->next = NULL;
        newN->previous = last;
        last = newN;
    }

}

NdT *ListTree(NodeT *root)
{
    if(root != NULL)
    {
        createList(root->id);
        ListTree(root->left);
        ListTree(root->right);
    }
    else
    {
        createList('*');
    }
    return first;
};
void printList(NdT *first)
{

    NdT *newN=first;
    while(newN!=NULL)
    {
        printf("%c ",newN->idd);
        newN=newN->next;

    }
      currentN=first;
      printf("\n");
};

