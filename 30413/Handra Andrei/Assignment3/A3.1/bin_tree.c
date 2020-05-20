#include "head.h"

void FatalError(const char *msg)
{

    printf(msg);
    printf(" \n");
    exit(1);
}

void Initialize_DLL()
{
    first=NULL;
    last=NULL;
}

NodeT *createBinTree()
{
    NodeT *p;
    char c;

    scanf("%c", &c);
    if(c=='*')
    {
        return NULL;
    }
    else
    {
        p=(NodeT*)malloc(sizeof(NodeT));
        if(p==NULL)
        {
            FatalError("Out of space");
        }
        p->id=c;
        p->left=createBinTree();
        p->right=createBinTree();
    }
    return p;
}

void prettyPrint(NodeT *root,int level)
{
    int i;
    if(root!=NULL)
    {
        prettyPrint(root->left,level+1);
        for(i=0;i<level;i++)
        {
            printf("   ");
        }
        printf("%c\n",root->id);
        prettyPrint(root->right,level+1);
    }
}

void AddtoNode(char ch)
{
    if(first==NULL)
    {
        first=(NodeL*)malloc(sizeof(NodeL));
        first->id=ch;
        first->next=last;
        first->prev=NULL;
        last=first;
    }
    else
    {
        NodeL *newel=(NodeL*)malloc(sizeof(NodeL));
        newel->id=ch;
        last->next=newel;
        newel->next=NULL;
        newel->prev=last;
        last=newel;
    }
}

NodeL *ListFromTree(NodeT *root)
{
    if(root!=NULL)
    {
        AddtoNode(root->id);
        ListFromTree(root->left);
        ListFromTree(root->right);
    }
    else
    {
        AddtoNode('*');
    }
    return first;
}

void TraverseList(NodeL *first)
{
    NodeL *newel=(NodeL*)malloc(sizeof(NodeL));
    newel=first;
    while(newel!=NULL)
    {
        printf("%c",newel->id);
        newel=newel->next;
    }
    printf(" \n");
    current=first;
}

NodeT *TreeFromList()
{
    if(current->id == '*' || current == NULL)
    {
        current = current->next;
        return NULL;
    }
    else
    {
        NodeT *Node = (NodeT*)malloc(sizeof(NodeT));
        Node->id = current->id;
        current = current->next;
        Node->left =TreeFromList();
        Node->right =TreeFromList();
        return Node;
    }
}
