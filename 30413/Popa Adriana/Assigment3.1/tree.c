#include "tree.h"

void fatalError( const char *msg )
{
    printf ( msg ) ;
    printf ( " \n" ) ;
    exit ( 1 ) ;
}

void initializeList()
{
    first=NULL;
    last=NULL;
}

NodeT *createBinTree( NodeT *parent,FILE *f )
{
    NodeT *p;
    char id ;
    fscanf( f,"%c", &id ) ;
    if ( id == '*' )
        return NULL;
    else
    {
        p = ( NodeT *)malloc(sizeof( NodeT ) ) ;
        if ( p == NULL )
            fatalError( "Out of space in createBinTree " ) ;
        p->id = id ;
        p->left = createBinTree(  p,f ) ;
        p->right = createBinTree(  p,f ) ;
    }
    return p;
}

void prettyPrint( NodeT *p, int level )
{
    int i ;
    if ( p != NULL )
    {
        prettyPrint( p->left, level + 1 ) ;
        for ( i = 0; i < level ; i++ )
            printf ( "     " ) ;
        printf ( "%c\n", p->id ) ;
        prettyPrint( p->right, level + 1 ) ;
    }
}

void addElement(char c)
{
    if(last == NULL)
    {
        first = (NodeL*)malloc(sizeof(NodeL));
        first->id = c;
        first->next = NULL;
        first->previous = NULL;
        last = first;
    }
    else
    {
        NodeL *newNode = (NodeL*)malloc(sizeof(NodeL));
        last->next = newNode;
        newNode->id = c;
        newNode->previous = last;
        newNode->next = NULL;
        last = newNode;
    }
}

NodeL *getListFromTree(NodeT *root)
{
    if(root != NULL)
    {
        addElement(root->id);
        getListFromTree(root->left);
        getListFromTree(root->right);
    }
    else
    {
        addElement('*');
    }
    return first;
}

void traverseList(NodeL *first)
{
    NodeL *newNode = first;
    printf("The list made from that sequence is: ");
    while(newNode!=NULL)
    {
        printf("%c",newNode->id);
        newNode = newNode->next;
    }
    printf("\n");
    current = first;
}

NodeT *getTreeFromList()
{
    if(current->id == '*' || current == NULL)
    {
        current = current->next;
        return NULL;
    }
    else
    {
        NodeT *newNode = (NodeT*)malloc(sizeof(NodeT));
        newNode->id = current->id;
        current = current->next;
        newNode->left = getTreeFromList();
        newNode->right = getTreeFromList();
        return newNode;
    }
}
