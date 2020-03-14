#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE{
    char id;
    struct _NODE *left,*right;
}NODE;

typedef  struct _LIST{
    char data;
    struct _LIST *next;
}LIST;

LIST *lastL=NULL,*firstL=NULL;

NODE * createBinTree( )
{
    NODE *p;
    char id;
    scanf(" %c",&id);
    if(id=='*')
    {
        return  NULL;
    } else
    {
        p=(NODE *)malloc(sizeof(NODE));
        p->id=id;
        p->left=createBinTree(p->left);
        p->right=createBinTree(p->right);
    }
    return p;

}

void AddToList( char Value)
{
    if(firstL == NULL){
        firstL=(LIST *)malloc(sizeof(LIST));
        firstL->data=Value;
        firstL->next=NULL;
        lastL=firstL;
    } else
    {
        LIST *NewNode=(LIST*)malloc(sizeof(LIST));
        NewNode->data=Value;
        NewNode->next=NULL;
        lastL->next=NewNode;
        lastL=NewNode;
    }


}

LIST * getListFromTree(NODE *parent)
{

    if(parent==NULL)
    {
        AddToList('*');
    } else
    {
        AddToList(parent->id);
        getListFromTree(parent->left);
        getListFromTree(parent->right);
    }
    return firstL;

}

void traverseList(LIST *first)
{
    LIST *p=first;
    while(p)
    {
        printf("%c ",p->data);
        p=p->next;
    }
    printf("\n");
}

NODE * CreateBinaryTree(LIST *CurrentEl)
{
    if(CurrentEl == NULL)
        return  NULL;

    if(CurrentEl->data=='*')
    {
        return NULL;
    }
    NODE *Node=(NODE*)malloc(sizeof(NODE));
    Node->id=CurrentEl->data;
    Node->left=CreateBinaryTree(firstL=firstL->next);
    Node->right=CreateBinaryTree(firstL=firstL->next);
    return Node;

}

NODE * getTreeFromTheList(LIST * first)
{
   if(first==NULL)
   {
       return NULL;
   }
     NODE *root=CreateBinaryTree(first);
    return  root;
}

void prettyPrint(NODE *parent,int level)
{
    if(parent==NULL)
        return;
    printf("%c is on the level %d\n",parent->id,level);
    prettyPrint(parent->left,level+1);
    prettyPrint(parent->right,level+1);

}

int main() {
    NODE *root= createBinTree();
    LIST *prim= getListFromTree(root);
    traverseList(prim);
    root=getTreeFromTheList(prim);
    prettyPrint(root, 0);
    return 0;
}
