#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node_type
{
    char id;
    struct node_Type *left, *right;
} NodeT;
typedef struct list_type
{
    char id;
    struct list_type *previous,*next;
}NodeL;

void prettyPrint(NodeT *p, int level)
{
    if(p!= NULL)
    {
        prettyPrint(p->left,level +1);
        for(int i=0; i<=level; i++)
            printf(" ");
        printf("%2.2c\n",p->id);
        prettyPrint(p->right,level +1);
    }
}
NodeL *first=NULL,*last=NULL;

NodeT *createBinTree ()
{
    NodeT *p;
    char c;
    scanf("%c", &c);
    if(c =='*')
           return NULL;
    else{
        p=(NodeT *)malloc(sizeof(NodeT));
        p->id=c;
        p->left=createBinTree();
        p->right=createBinTree();
    }

    return p;

}
void AL(char data)
{
     NodeL *newNode = (NodeL*)malloc(sizeof(NodeL));
     newNode->id=data;
    if(first == NULL)
    {
       last = newNode;
        first = last;
        newNode->next = NULL;
        newNode->previous = NULL;
    }
    else
    {

        last->next = newNode;
        newNode->next = NULL;

        newNode->previous = last;
        last = newNode;
    }
}
void getListFromTree( NodeT *p)
{
    if ( p == NULL )
    {
        AL("*");

    }
    if( p !=NULL)
    {
        AL(p->id);
        getListFromTree(p->left);
        getListFromTree(p->right);
    }

}
void traverseList()
{
    NodeL *currentNode=first;
    while(currentNode !=NULL)
    {
        printf("%c",currentNode->id);
        currentNode=currentNode->next;
    }
    printf("\n");
}
NodeT * getTreeFromList(NodeL *firstFromList)
{
    NodeT *p;

    if(firstFromList->id =='.')
           return NULL;
    else{
        p=(NodeT *)malloc(sizeof(NodeT));
        p->id=firstFromList->id;

        p->left=getTreeFromList(firstFromList->next);

        p->right=getTreeFromList(firstFromList->next);
    }

    return p;
}
int main()
{
    NodeT * root=createBinTree();
    getListFromTree(root);
    traverseList();
    root=getTreeFromList(first);
    prettyPrint(root,0);
    return 0;
}
