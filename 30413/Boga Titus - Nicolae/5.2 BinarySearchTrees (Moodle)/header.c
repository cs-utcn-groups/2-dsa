#include "header.h"

NODE * insert(char Key, NODE *parent)
{
    if(parent== NULL)
    {
        parent=(NODE*)malloc(sizeof(NODE));
        parent->Key=Key;
        parent->Left=NULL;
        parent->Right=NULL;
        return parent;
    } else
    {
        if(Key==parent->Key)
            printf("\n The Key %c already exists in the tree\n",Key);
        else
        if(Key>parent->Key)
            parent->Right=insert(Key,parent->Right);
        else
            parent->Left=insert(Key,parent->Left);
    }
    return parent;

}

NODE *gm(NODE *parent)
{
    if(parent==NULL)
        return NULL;
    if(!parent->Left)
        return parent;
    else
        return  gm(parent->Left);
}

NODE *gM(NODE *parent)
{
    if(parent==NULL)
        return  NULL;
    if(!parent->Right)
        return parent;
    else
        return gm(parent->Right);

}

NODE * delete(char Key,NODE *parent)
{
    if(parent==NULL)
    {
        //  printf("Key %d not found!\n",Key);
        return NULL;
    } else
    {
        if(parent->Key==Key)
        {
            NODE *p;
            if(parent->Left == NULL && parent->Right== NULL)
            {
                free(parent);
                return  NULL;
            } else
            if((parent->Left == NULL && parent->Right !=NULL) || (parent->Right == NULL && parent->Left !=NULL))
            {
                p=parent->Left?parent->Left:parent->Right;
                free(parent);
                return p;
            } else{
                p=gM(parent->Left);
                parent->Key=p->Key;
                parent->Left=delete(p->Key,parent->Left);
                return parent;
            }
        } else
        {
            parent->Left=delete(Key,parent->Left);
            parent->Right=delete(Key,parent->Right);
        }

    }
    return parent;
}

NODE *find(char Key,NODE * parent)
{
    if(parent==NULL)
    {
        //printf("Key %d not found!",Key);
        return NULL;
    }
    if(parent->Key==Key)
        return parent;
    return find(Key,parent->Left)?find(Key,parent->Left):find(Key,parent->Right);
}

void preorder(NODE *parent)
{
    if(!parent)
        return;
    printf("%c ",parent->Key);
    preorder(parent->Left);
    preorder(parent->Right);
}

void inorder(NODE *parent)
{
    if(!parent)
        return;
    inorder(parent->Left);
    printf("%c ",parent->Key);
    inorder(parent->Right);
}

void postorder(NODE *parent)
{
    if(!parent)
        return;
    postorder(parent->Left);
    postorder(parent->Right);
    printf("%c ",parent->Key);
}