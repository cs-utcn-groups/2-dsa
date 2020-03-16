#include <stdio.h>
#include <stdlib.h>
typedef struct node_type
{
    int id;

    struct node_type*left,*right;
} NodeT;
void height(NodeT*p,int h,int *max)
{
    if(p!=NULL)
    {  h=h+1;
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
int leaves(NodeT*p)
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
void interChange(NodeT *p,int label)
{
    if(p!=NULL)
    {
      if(p->id==label)
      {
          NodeT* aux=(NodeT*)malloc(sizeof(NodeT));
          aux=p->left;
          p->left=p->right;
          p->right=aux;
      }
      else
      {
          interChange(p->left,label);
          interChange(p->right,label);
      }
    }
}
void fatalError(const char  *msg)
{
    printf(msg);
    printf("\n");
    exit(1);
}
void preOrder(NodeT *p,int level)
{
    if(p!=NULL)
    {
        for(int i=0; i<level; i++) printf(" ");
        printf("%2.2d\n",p->id);
        preOrder(p->left,level+1);
        preOrder(p->right,level+1);


    }
}
void inOrder(NodeT *p,int level)
{
    if(p!=NULL)
    {
        inOrder(p->left,level+1);
        for(int i=0; i<=level; i++)printf(" ");
        printf("%2.2d\n",p->id);
        inOrder(p->right,level+1);

    }
}
void postOrder(NodeT *p,int level)
{
    if(p!=NULL)
    {
        postOrder(p->left,level+1);
        postOrder(p->right,level+1);
        for(int i=0; i<=level; i++) printf(" ");
        printf("%2.2d\n",p->id);

    }
}
NodeT *createBinTree(int branch,NodeT *parent)
{
    NodeT *p;
    int id;
    if(branch==0)
     printf("Root identifier[0 to end]=");
    else
        if(branch==1)
        printf("Left child of %d [0 to end]=",parent->id);
    else
        printf("Right child of %d [0 to end]=",parent->id);
    scanf("%d",&id);
    if(id == 0)
    {
        return NULL;
    }
    else
    {
        p=(NodeT*)malloc(sizeof(NodeT));
        if(p==NULL)
        {
            fatalError("out of space in createBinTree()");
        }
        p->id=id;
        p->left=createBinTree(1,p);
        p->right=createBinTree(2,p);
    }
    return p;
}

int main()
{ int h=0, max=0;
    NodeT*root=createBinTree(0,NULL);
        preOrder(root,0);
        printf("\n");
        inOrder(root,0);
        printf("\n");
        postOrder(root,0);
        printf("\n");
    int label;
    scanf("%d",&label);
    interChange(root,label);
    preOrder(root,0);
      printf("\n");
    inOrder(root,0);
      printf("\n");
    postOrder(root,0);
    printf("\n");
    height(root,h,&max);
    printf("\n%d\n",max);
    printf("\n%d\n",leaves(root));



    return 0;
}
