#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE{
    int Key,height;
    struct _NODE * left,*right;
}NODE;

int max(int a,int b){ return a>b?a:b;}

int getHeight(NODE *parent)
{
    if(parent==NULL)
        return 0;
    else
        return max(getHeight(parent->left),getHeight(parent->right))+1;
}

NODE * createTree(NODE * newNode,NODE *parent)
{
    if(parent==NULL)
        return  newNode;
    else
        {
        if (newNode->Key > parent->Key)
        {
            parent->right = createTree(newNode, parent->right);
            parent->height=getHeight(parent);
        }
         else
        {
             parent->left = createTree(newNode, parent->left);
             parent->height=getHeight(parent);
        }
         //parent->height=getHeight(parent);
         if((!parent->left&&parent->right&&parent->right->height>1)||(!parent->right&&parent->left&&parent->left->height>1)||(parent->right&&parent->left&&parent->right->height-parent->left->height>1)||(parent->right&&parent->left&&parent->right->height-parent->left->height<-1)) // unbalanced
         {
             if(newNode->Key>parent->Key)//right
             {
                 if(newNode->Key>parent->right->Key)//right so we have the "right right" case
                 {
                    NODE *y=parent->right;
                    parent->right=y->left;
                    y->left=parent;
                    return  y;
                 } else //"right left" case
                 {
                    NODE *y=parent->right,*x=parent->right->left;
                    parent->right=x->left;
                    y->left=x->right;
                    x->left=parent;
                    x->right=y;
                    return x;
                 }
             } else ///left
             {
                 if(newNode->Key>parent->left->Key) /// right so we have the "left right" case
                 {
                    NODE *x=parent->left->right,*y=parent->left;
                    y->right=x->left;
                    parent->left=x->right;
                    x->left=y;
                    x->right=parent;
                    return x;

                 } else///"left left" case
                 {
                    NODE *y=parent->left;
                    parent->left=parent->left->right;
                    y->right=parent;
                    return  y;
                 }
             }
         }
    }
    return  parent;

}

void preorder(NODE *parent)
{
    if(!parent)
        return;
    printf("%d ",parent->Key);
    preorder(parent->left);
    preorder(parent->right);
}

NODE * createNode(int Value)
{
    NODE *newNode=(NODE*)malloc(sizeof(NODE));
    newNode->left=newNode->right=NULL;
    newNode->Key=Value;
    newNode->height=1;
    return newNode;
}

int main() {
    NODE * root=NULL;
    FILE *f=fopen("date.in","r");
    int Key;
    while(fscanf(f,"%d",&Key)!=EOF)
    {
        root=createTree(createNode(Key),root);
    }
    preorder(root);
    return 0;
}

