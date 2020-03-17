#include <stdio.h>
#include <stdlib.h>


typedef struct node_type{
    char id;
    struct node_type *left,*right;
}NodeT;

void fatalError(const char *msg)
{
    printf(msg);
    printf("\n");
    exit(1);
}

void preorder(NodeT *p,int level)
{
    if(p!=NULL)
    {
        for(int i=0;i<=level;i++) printf(" ");
        printf("%2.2d\n",p->id);
        preorder(p->left,level+1);
        preorder(p->right,level+1);
    }
}

void inorder(NodeT *p,int level)
{
    if(p!=NULL)
    {
        inorder(p->left,level+1);
        for(int i=0;i<=level;i++) printf(" ");
        printf("%2.2d\n",p->id);
        inorder(p->right,level+1);

    }
}

void postorder(NodeT *p,int level)
{
    if(p!=NULL)
    {
        postorder(p->left,level+1);
        postorder(p->right,level+1);
        for(int i=0;i<=level;i++) printf(" ");
        printf("%2.2d\n",p->id);
    }
}

void interchange(NodeT *p,int label)
{
    if(p!=NULL)
    {
        if(p->id==label)
        {
            NodeT *auxN=(NodeT*)malloc(sizeof(NodeT));
            auxN=p->left;
            p->left=p->right;
            p->right=auxN;
        }
        else
        {
            interchange(p->left,label);
            interchange(p->right,label);
        }
    }
}

void height(NodeT *p,int h,int *max)
{
    if(p!=NULL)
    {
        h=h+1;
        height(p->left,h,max);
        height(p->right,h,max);
    }
    else
    {
        if(h>*max)
        {
            *max=h;
        }
    }
}

int leaves(NodeT *p)
{
    if(p!=NULL)
    {
        if(leaves(p->right)==0 && leaves(p->left)==0)
            return 1;
        else
            return leaves(p->right)+leaves(p->left);
    }
    else
        return 0;
}

NodeT *createBinTree(int branch,NodeT *parent)
{
    NodeT *p;
    int id;
    if(branch==0)
    {
        printf("Root identifier [0 to end] =");
    }
    else
    if(branch==1)
    {
            printf("Left child of %d [0 to end]=",parent->id);
    }
    else
    {
            printf("Right child of %d [0 to end]=",parent->id);
    }
    scanf("%d",&id);
    if(id==0)
    {
        return NULL;
    }
    else
    {
        p=(NodeT*)malloc(sizeof(NodeT));
        if(p == NULL)
        {
            fatalError("Out of space.");
        }
        p->id=id;
        p->left=createBinTree(1,p);
        p->right=createBinTree(2,p);
    }
    return p;
}

int main()
{
    NodeT *root=createBinTree(0,NULL);
    printf("preorder listing\n");
    preorder(root,0);
    printf("\n");
    printf("inorder listing\n");
    inorder(root,0);
    printf("\n");
    printf("postorder listing\n");
    postorder(root,0);
    printf("\n");
    int label;
    scanf("%d",&label);
    interchange(root,label);
    printf("preorder listing\n");
    preorder(root,0);
    printf("\n");
    printf("inorder listing\n");
    inorder(root,0);
    printf("\n");
    printf("postorder listing\n");
    postorder(root,0);
    printf("\n");
    int h=0,max=0;
    height(root,h,&max);
        printf("%d\n",max);
    printf("%d\n",leaves(root));
        return 0;
}
