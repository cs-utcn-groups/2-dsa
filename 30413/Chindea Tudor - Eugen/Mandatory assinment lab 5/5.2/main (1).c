#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node_type
{
    char key;
    struct node_type *left,*right;
} BSTNodeT;
BSTNodeT *createNode(char key)
{
    BSTNodeT *p=(BSTNodeT*)malloc(sizeof(BSTNodeT));
    p->key = key;
    p->left = p->right = NULL;
    return p;
}
BSTNodeT *insertNode(BSTNodeT *root,char key)
{
    if(root == NULL)
    {
        root=createNode(key);
    }
    else
    {
        if(key<root->key)
            root->left=insertNode(root->left,key);
        else if(key > root->key)
        {
            root->right = insertNode(root->right, key);
        }
        else
            printf("\nNode with key = %c already exists \n", key);
    }
    return root;
}
BSTNodeT * findMin(BSTNodeT *node)
{
    if(node==NULL)
        return NULL;
    if(node->left)
        return findMin(node->left);
    return node;
}
BSTNodeT *delNode(BSTNodeT * node,char key)
{
    if(node == NULL)
    {
        printf("no element\n");
    }
    else if(key < node->key)
    {
        node->left=delNode(node->left,key);
    }
    else if(key> node->key)
    {
        node->right=delNode(node->right,key);
    }
    else
    {
        if(node->right && node->left)
        {
            BSTNodeT * temp= findMin(node->right);
            node->key=temp->key;
            node->right=delNode(node->right,temp->key);
        }
        else
        {
            BSTNodeT *temp=node;
            if(node->left==NULL)
                node=node->right;
            else if(node->right == NULL)
                node=node->left;
            free(temp);
        }
    }
    return node;
}
BSTNodeT *find(BSTNodeT *root, char key)
{
    if(root==NULL)
        return NULL;
    for(BSTNodeT *p=root; p!=NULL;)
    {
        if(key==p->key)
            return p;
        if(key<p->key)
            p=p->left;
        else
            p=p->right;
    }
    return NULL;
}
void preorder (BSTNodeT *p,int level,FILE *g)
{
    if(p!=NULL)
    {
        for(int i=0; i<=level; i++)
            fprintf(g," ");
        fprintf(g,"%c\n",p->key);
        preorder(p->left,level +1,g);
        preorder(p->right,level +1,g);
    }
}
void inorder(BSTNodeT  *p,int level,FILE *g)
{
    if(p!=NULL)
    {
        inorder(p->left,level+1,g);
        for(int i=0; i<=level; i++)
            fprintf(g," ");
        fprintf(g,"%c\n",p->key);
        inorder(p->right,level+1,g);
    }
}
void postorder(BSTNodeT *p,int level,FILE *g)
{
    if(p!=NULL)
    { 
		postorder(p->left,level+1,g);
        postorder(p->right,level+1,g);
        for(int i=0; i<=level; i++)
            fprintf(g," ");
        fprintf(g,"%c\n",p->key);
       
    }
}
BSTNodeT *findMax(BSTNodeT *node)
{
    if(node ==NULL)
    {
        return NULL;
    }
    if(node->right)
        return findMax(node->right);
    return node;
}
void program(FILE *f,FILE *g)
{
    BSTNodeT *root=NULL;
    BSTNodeT *newNode=(BSTNodeT*)malloc(sizeof(BSTNodeT));
    char *c=(char*)malloc(sizeof(char)*3);
    while(fgets(c,3,f)
    {
        if(c[0]=='i')
            root=insertNode(root,c[1]);
        else if(c[0]=='d')
            root=delNode(root,c[1]);
        else if(c[0]=='f')
            newNode=find(root,c[1]);
        else
            if(strcmp(c,"tp")==0)
                preorder(root,0,g);
            else if(strcmp(c,"tP")==0)
                postorder(root,0,g);
            else if(strcmp(c,"ti")==0)
                inorder(root,0,g);

            else if(strcmp(c,"gm")==0)
                newNode=findMin(root);
            else if(strcmp(c,"gM")==0)
                newNode=findMax(root);

    }
}
int main()
{
    FILE *f=fopen("data.txt","rw+");
    FILE *g=fopen("output.txt","rw+");
    program(f,g);
    return 0;
}
