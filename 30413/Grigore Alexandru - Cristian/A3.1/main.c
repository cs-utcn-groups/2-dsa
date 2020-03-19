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

void AL(char key)
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
    char c;
    scanf("%c",&c);
    if(c == '*')
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
            p->id=c;
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
        AL(p->id);
        getListFromTree(p->left);
        getListFromTree(p->right);
    }
    else
    {
        AL('*');
    }
}

void traverseList()
{
    if(first==NULL)
    {
        printf("Nothing\n");
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
    NodeT *t=getTree(&currentNode);
    free(aux);
    return t;
}

void prettyPrint(NodeT *p,int level)
{
    if(p==NULL)
    {
        return;
    }
    prettyPrint(p->right,level+1);
    for(int i=0;i<=level;i++)
    {
        printf("  ");
    }
    printf("%c\n",p->id);
    prettyPrint(p->left,level+1);
}

int main()
{
    NodeT *root = createBinTree();
    getListFromTree(root);
    traverseList();
    root = getTreeFromList(first);
    prettyPrint(root, 0);
    return 0;
}
