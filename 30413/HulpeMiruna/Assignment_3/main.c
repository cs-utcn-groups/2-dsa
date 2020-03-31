#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int MAXLENGHTOFNR=200;
typedef struct node
{
    char *data;
    struct node *next, *previous;
} ListNode;

typedef struct
{
    ListNode *first, *last;
} NodeL;

typedef struct nodeT
{
    char *label;
    int list;
    struct nodeT *left, *right;
} NodeT;

NodeL firstFromList;

void initial()
{
    firstFromList.first=NULL;
    firstFromList.last=NULL;
}

NodeT *CreateBinTree( int direction,NodeT *T)
{
    NodeT *p;
    char *id=(char *) malloc (sizeof(char)*MAXLENGHTOFNR);
    if ( direction == 0 )
        printf( "Root identifier  =" );
    else if ( direction == 1 )
        printf( "Left child of %s  =",T->label );
    else
        printf( "Right child of %s  =",T->label );
    scanf("%s",id);
    if ( strcmp(id,"*")==0 )
    {
        return NULL;
    }
    else
    {
        p = ( NodeT *)malloc(sizeof( NodeT ));
        p->label = (char *) malloc (sizeof(char)*MAXLENGHTOFNR);
        strcpy(p->label,id);
        p->list=0;
        p->left = CreateBinTree( 1, p );
        p->right = CreateBinTree( 2, p );
    }
    return p;
}
void AddListElement (char *x)
{
    ListNode *Element= (ListNode *) malloc (sizeof (ListNode));
    Element->data=(char *) malloc (sizeof(char)*MAXLENGHTOFNR);
    strcpy(Element->data,x);
    if(firstFromList.first==NULL)
    {
        Element->next=firstFromList.first;
        Element->previous=NULL;
        firstFromList.first = Element;
        firstFromList.last=firstFromList.first;
    }
    else
    {
        Element->next=NULL;
        Element->previous=firstFromList.last;
        firstFromList.last->next=Element;
        firstFromList.last=Element;

    }

}
void getListFromTree(NodeT *root,int level)
{
    if(level==0)
    {
        initial();

    }
    if(root!=NULL)
    {
        if(root->list==0)
        {
            AddListElement(root->label);
            root->list=1;
        }
        if(root->left==NULL)
            AddListElement("*");
        getListFromTree(root->left,level+1);
        getListFromTree(root->right,level+1);
        if(root->right==NULL)
            AddListElement("*");
    }
}
void TraverseList()
{
    if (firstFromList.first==NULL)
        printf("The list is empty \n");
    else
    {
        ListNode *CurrentElement;
        CurrentElement=firstFromList.first;
        while(CurrentElement != NULL)
        {
            printf("%s ",CurrentElement->data);
            CurrentElement=CurrentElement->next;
        }
    }
    printf("\n");
}

NodeT *CreateNode (ListNode *Element)
{
    if(Element == NULL)
        return  NULL;

    if(!strcmp(Element->data,"*"))
    {
        return NULL;
    }
    NodeT *Node=(NodeT*)malloc(sizeof(NodeT));
    Node->label=malloc(256);
    strcpy(Node->label,Element->data);
    Node->left=CreateNode(firstFromList.first=firstFromList.first->next);
    Node->right=CreateNode(firstFromList.first=firstFromList.first->next);
    return Node;
}
NodeT *getTreeFromList(NodeL Element)
{
    if(Element.first==NULL)
    {
        return NULL;
    }
    NodeT *root=CreateNode(Element.first);
    return  root;
}
void preorder(NodeT *T,int level)
{
    if(T!=NULL)
    {
        int i;
        for ( i = 0; i <= level; i++ )
            printf( " " );
        printf("%s\n",T->label);
        preorder( T->left, level + 1 );
        preorder( T->right, level + 1 );
    }
}
void inorder(NodeT *T,int level)
{
    if(T!=NULL)
    {
        inorder( T->left, level + 1 );
        int i;
        for ( i = 0; i <= level; i++ )
            printf( " " );
        printf("%s\n",T->label);
        inorder( T->right, level + 1 );
    }
}
void postorder(NodeT *T,int level)
{
    if(T!=NULL)
    {

        postorder( T->left, level + 1 );
        postorder( T->right, level + 1 );
        int i;
        for ( i = 0; i <= level; i++ )
            printf( " " );
        printf("%s\n",T->label);
    }
}

void prettyPrint(NodeT *root,int level)
{

    printf( "\nPreorder listing\n" );
    preorder( root, 0 );
    printf( "\n" );
    printf( "\nInorder listing\n" );
    inorder( root, 0 );
    printf( "\n" );
    printf( "\nPostorder listing\n" );
    postorder( root, 0 );
    printf( "\n" );

}
int main()
{
    NodeT *root=CreateBinTree(0,NULL);
    getListFromTree(root,0);
    TraverseList(firstFromList);
    root=getTreeFromList (firstFromList);
    prettyPrint(root,0);
    return 0;
}
