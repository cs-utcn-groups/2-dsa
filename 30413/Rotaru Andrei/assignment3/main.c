#include <stdio.h>
#include <stdlib.h>

typedef struct node_type{
    char id;
    struct node_type *left, *right;
}NodeT;

typedef struct node{
    char id;
    struct node *next, *prev;
}NodeL;

NodeL *first, *last;

void fatalError(const char *msg)
{
    printf("%s",msg);
    printf("\n");
    exit(1);
}

void addNode(char key)
{
    if(first == NULL)
    {
        first=(NodeL*)malloc(sizeof(NodeL));
        first->next=NULL;
        first->prev=NULL;
        first->id=key;
        last=first;
    }
    else
    {
        NodeL *newNode=(NodeL*)malloc(sizeof(NodeL));
        last->next=newNode;
        newNode->prev=last;
        newNode->next=NULL;
        newNode->id=key;
        last=newNode;
    }
}

NodeT *createBinTree()
{
    NodeT *p;
    char ch;
    scanf("%c",&ch);
    if(ch == '*')
    {
        return NULL;
    }
    else
    {
        p=(NodeT*)malloc(sizeof(NodeT));
        if(p==NULL)
        {
            fatalError("NO SPACE");
        }
        else
        {
            p->id=ch;
            p->left=createBinTree();
            p->right=createBinTree();
        }
    }
    return p;
}

void getListFromTree(NodeT *p)
{
    if(p!=NULL)
    {
        addNode(p->id);
        getListFromTree(p->left);
        getListFromTree(p->right);
    }
    else
    {
        addNode('*');
    }
}

void traverseList()
{
    if(first==NULL)
    {
        printf("NULL\n");
    }
    else
    {
        NodeL *currentNode=first;
        while(currentNode!=NULL)
        {
            printf("%c ",currentNode->id);
            currentNode=currentNode->next;
        }
        printf("\n");
    }
}

NodeT *getTree(NodeL **list)
{
    NodeT *p;
    *list=(*list)->next;
    if((*list)->id=='*')
    {
        return NULL;
    }
    else
    {
        p=(NodeT*)malloc(sizeof(NodeT));
        if(p==NULL)
        {
            fatalError("NO SPACE");
        }
        else
        {
            p->id=(*list)->id;
            p->left=getTree(list);
            p->right=getTree(list);
        }
    }
    return p;
}

NodeT *getTreeFromList(NodeL *first)
{
    NodeL *currentNode=(NodeL*)malloc(sizeof(NodeL));
    currentNode->id=first->id;
    currentNode->prev=NULL;
    currentNode->next=first;
    NodeL *aux=currentNode;
    NodeT *T=getTree(&currentNode);
    free(aux);
    return T;
}

void prettyPrint(NodeT *p,int level)
{
    if(p!=NULL)
    {
    prettyPrint(p->right,level+1);
    for(int i=0;i<=level;i++)
    {
        printf("    ");
    }
    printf("%c\n",p->id);
    prettyPrint(p->left,level+1);
    }
}
int main()
{
    printf("Please enter the tree: ");
    NodeT *root = createBinTree();
    getListFromTree(root);
    traverseList();
    root = getTreeFromList(first);
    prettyPrint(root, 0);
    return 0;
}
