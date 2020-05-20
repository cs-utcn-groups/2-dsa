#include <stdio.h>
#include <stdlib.h>
typedef struct node_type
{
    struct node_type *left,*right;
    int key;

} BSTNodeT;
int level(BSTNodeT *p)
{
    if(p==NULL)
        return 0;
    else
        return level(p->left)+level(p->right)+1;
}
BSTNodeT * findMin(BSTNodeT *node)
{
    if(node==NULL)
        return NULL;
    if(node->left)
        return findMin(node->left);
    return node;
}
BSTNodeT * findMax(BSTNodeT *node)
{
    if(node==NULL)
        return NULL;
    if(node->right)
        return findMin(node->right);
    return node;

}
void pointMaxNUL(BSTNodeT *node,BSTNodeT *maxi)
{
    if(node->right==maxi)
        node->right=NULL;
    else
        pointMaxNUL(node->right,maxi);
}
void pointMinNUL(BSTNodeT *node,BSTNodeT *mini)
{
    if(node->left==mini)
        node->left=NULL;
    else
        pointMinNUL(node->left,mini);
}

BSTNodeT *createNode(int key)
{
    BSTNodeT *p=(BSTNodeT*)malloc(sizeof(BSTNodeT));
    p->key = key;
    p->left = p->right = NULL;
    return p;
}
BSTNodeT *insertAVL(BSTNodeT *root,int data)
{
    BSTNodeT *maxNode=(BSTNodeT*)malloc(sizeof(BSTNodeT));
    BSTNodeT *minNode=(BSTNodeT*)malloc(sizeof(BSTNodeT));




    if(root==NULL)
    {
        root=createNode(data);
    }
    else
    {
        int left=level(root->left);
        int right=level(root->right);
        if(data < root->key  )
        {
            if(left>right)
            {
                maxNode=findMax(root->left );
                if(root->left==maxNode)
                {
                    root->left=NULL;

                }
                else
                {
                    pointMaxNUL(root->left,maxNode);
                }

                maxNode->left=root->left;
                maxNode->right=root;
                root=maxNode;
            }
            root->left=insertAVL(root->left,data);
        }
        else if(data > root->key)
        {

            if(right>left)
            {
                minNode=findMin(root->right);
                if(root->right==minNode)
                {
                    root->right=NULL;
                }
                else
                {
                    pointMinNUL(root->right,minNode);
                }

                minNode->left=root;
                minNode->right=root->right;
                root=minNode;
            }
            root->right=insertAVL(root->right,data);
        }

        else
            printf("key exists\n");
    }
    return root;
}
void preorder (BSTNodeT *p,int level)
{

    if(p!=NULL)
    {
        for(int i=0; i<=level; i++)
            printf(" ");
        printf("%d\n",p->key);
        preorder(p->left,level +1);
        preorder(p->right,level +1);
    }

}
int main()
{
    BSTNodeT *root=NULL;
    root=insertAVL(root,7);

    root=insertAVL(root,8);
    root=insertAVL(root,9);

    root=insertAVL(root,10);
    root=insertAVL(root,12);
    root=insertAVL(root,13);
    root=insertAVL(root,15);
    preorder(root,0);
    return 0;
}
