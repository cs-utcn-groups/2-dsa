
#include "header.h"

void addElementToEnd(int data)
{
    if(first==NULL)
    {
        first=(Node *) malloc(sizeof(Node));
        first->id=data;
        first->next=last;
        last=first;
    }

    else
    {
        Node * element=(Node *) malloc(sizeof(Node));
        element->next = NULL;
        element->id = data;
        last->next = element;
        last = element;
    }
}

void addToEnd(NodeL ** sentinel, char data)
{
    Node * element = (Node *) malloc(sizeof(Node));
    element->id =data;
    element->next = NULL;
    element->previous = NULL;

    if ((*sentinel)->first == NULL)
    {
        (*sentinel)->first = element;
        (*sentinel)->last = element;
    }

    else
    {
        (*sentinel)->last->next = element;
        element->previous = (*sentinel)->last;
        (*sentinel)->last = element;
    }
}

NodeT * createBinTree()
{
    NodeT *p;
    char c;

    scanf("%c",&c);
    addElementToEnd(c);

    if(c== '*')
    {
        return NULL;
    }

    else
    {
        p=(NodeT *) malloc(sizeof(NodeT));
        p->parent=NULL;
        if(p==NULL)
        {
            printf("Out of space\n");
            exit(1);
        }

        p->id=c;
        p->left=createBinTree();
        p->right=createBinTree();
    }
    return p;
}


NodeT * addParentsToBinaryTree(NodeT * element, NodeT * parent, NodeL ** sentinel)
{
    if(!element->visited)
    {
        addToEnd(&(*sentinel),element->id);
    }

    if(!element->left)
    {
        addToEnd(&(*sentinel),'*');
    }

    if(!element->right)
    {
        addToEnd(&(*sentinel),'*');
    }

    element->parent=parent;
    element->visited=true;

    if(element->left && !element->left->visited)
    {
        parent=element;
        return  addParentsToBinaryTree(element->left,parent,sentinel);
    }

    if(element->right && !element->right->visited)
    {
        parent=element;
        return  addParentsToBinaryTree(element->right,parent,sentinel);
    }

    if(!element->parent)
    {
        return element;
    }

    else
    {
        return addParentsToBinaryTree(element->parent,element->parent->parent,sentinel);
    }
}

NodeL * getListFromTree(NodeT * root)
{
    NodeL * sentinel=(NodeL *) malloc(sizeof(NodeL));
    sentinel->first=sentinel->last=NULL;

    root=addParentsToBinaryTree(root,NULL,&sentinel);

    return sentinel;
}

void traverseList(NodeL * sentinel)
{
    Node * element=sentinel->first;

    while(element!=NULL)
    {
        printf("%c",element->id);
        element=element->next;
    }
    printf("\n");
}

///123**4**56**7**
NodeT * createBinTreeFromList()
{
    if(element!=NULL)
    {
        NodeT *p;

        char c=element->id;
        element=element->next;

        if(c=='*')
        {
            return NULL;
        }

        else
        {
            p=(NodeT *) malloc(sizeof(NodeT));
            p->parent=NULL;

            if(p==NULL)
            {
                printf("Out of space\n");
                exit(1);
            }

            p->id=c;
            p->left=createBinTreeFromList();
            p->right=createBinTreeFromList();
        }
        return p;
    }

    return NULL;
}

NodeT * getTreeFromList(NodeL * sentinel)
{
    element=first;
    return createBinTreeFromList();
}

void prettyPrint(NodeT *p,int level)
{
    if(p!=NULL)
    {
        prettyPrint(p->left,level+1);

        for(int i=0; i<=level; i++)
        {
            printf(" ");
        }

        printf("%c\n",p->id);

        prettyPrint(p->right,level+1);
    }
}

int main()
{
    NodeT * root=createBinTree();
    NodeL * firstFromList=getListFromTree(root);
    traverseList(firstFromList);
    root=getTreeFromList(firstFromList);
    prettyPrint(root,0);

    return 0;
}
