#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    struct nodeT *left, *right;
} NodeT;

NodeL List;
const int MAXLENGHTOFEXPRESION=200;

void initial()
{
    List.first=NULL;
    List.last=NULL;
}
void AddListElement (char *x)
{
    ListNode *Element= (ListNode *) malloc (sizeof (ListNode));
    Element->data=(char *) malloc (sizeof(char)*MAXLENGHTOFEXPRESION);
    strcpy(Element->data,x);
    if(List.first==NULL)
    {
        Element->next=List.first;
        Element->previous=NULL;
        List.first = Element;
        List.last=List.first;
    }
    else
    {
        Element->next=NULL;
        Element->previous=List.last;
        List.last->next=Element;
        List.last=Element;

    }
}
void CreateList(FILE *f)
{
    char *strbuf=(char *) malloc (sizeof(char)*MAXLENGHTOFEXPRESION);
    char *p;
    initial();
    fgets(strbuf,MAXLENGHTOFEXPRESION,f);
    p=strtok(strbuf," \n");

    while(p!=NULL)
    {
        AddListElement (p);
        p=strtok(NULL," \n");

    }
}
int isSign(char *c)
{
    if(strcmp(c,"*")==0)
        return 1;
    if(strcmp(c,"+")==0)
        return 1;
    if(strcmp(c,"-")==0)
        return 1;
    if(strcmp(c,"/")==0)
        return 1;
    return 0;
}
NodeT *CreateNode (ListNode *Element)
{

    if(Element == NULL)
        return  NULL;

    if(!isSign(Element->data))
    {
        NodeT *Node=(NodeT*)malloc(sizeof(NodeT));
        Node->label=malloc(sizeof(char)*MAXLENGHTOFEXPRESION);
        strcpy(Node->label,Element->data);
        Node->right=NULL;
        Node->left=NULL;

        return Node;
    }
    NodeT *Node=(NodeT*)malloc(sizeof(NodeT));
    Node->label=malloc(sizeof(char)*MAXLENGHTOFEXPRESION);
    strcpy(Node->label,Element->data);
    Node->left=CreateNode(List.first=List.first->next);
    Node->right=CreateNode(List.first=List.first->next);
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
void PrintTree(NodeT *root,int level)
{
    if(root!=NULL)
    {
        PrintTree( root->left, level + 1 );
        int i;
        for ( i = 0; i <= level; i++ )
            printf( " " );
        printf("%s\n",root->label);
        PrintTree( root->right, level + 1 );
    }
}
int main()
{
    FILE *f=fopen("input.txt","r+");
    CreateList(f);
    NodeT *root=getTreeFromList(List);
    PrintTree(root,0);
    return 0;
}
