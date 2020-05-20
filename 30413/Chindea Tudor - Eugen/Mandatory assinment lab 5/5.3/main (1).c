#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h>
typedef struct node_type
{
    char *name,*price,*amount,*dateMan,*dateExp;

    struct node_type *left,*right;

} BSTNodeT;
BSTNodeT *initializeNode()
{
    BSTNodeT *node=(BSTNodeT*)malloc(sizeof(BSTNodeT));
    node->name=(char*)malloc(sizeof(char)*35);
    node->price=(char*)malloc(sizeof(char)*5);
    node->amount=(char*)malloc(sizeof(char)*5);
    node->dateExp=(char*)malloc(sizeof(char)*9);
    node->dateMan=(char*)malloc(sizeof(char)*9);
    node->left=NULL;
    node->right=NULL;
    return node;
}
BSTNodeT *insertNode(BSTNodeT *root,char *data)
{
    if(root==NULL)
    {
        root=initializeNode();
        sscanf(data,"%s,%s,%s,%s,%s",root->name,root->price,root->amount,root->dateMan,root->dateExp);
        strcpy(root->name,root->name+1);

    }
    else
    {
        char *name=(char*)malloc(sizeof(char)*35);
         char *rest=(char*)malloc(sizeof(char)*95);

        sscanf(data,"%s,%s",name,rest);
        strcpy(name,name+1);
        if(strcmp(root->name,name)<0)
        {
            root->right=insertNode(root->right,data);
        }
        else if(strcmp(root->name,name)>0)
        {
            root->left=insertNode(root->left,data);
        }
        else
            printf("medicine %s already exists",name);
    }
    return root;
}
BSTNodeT *find(BSTNodeT *root,char *data)
{
    if(root==NULL)
        return NULL;
    char *name=(char*)malloc(sizeof(char)*35);
    char *rest=(char*)malloc(sizeof(char)*150);
    sscanf(data,"%s,%s",name,rest);
    strcpy(name,name+1);
    for(BSTNodeT *p=root; p!=NULL;)
    {
        if(strcmp(name,p->name)==0)
        {
            char *Newname=(char*)malloc(sizeof(char)*35);
            char *price=(char*)malloc(sizeof(char)*5);
            char *amount=(char*)malloc(sizeof(char)*5);
            char *dateMan=(char*)malloc(sizeof(char)*9);
            char *dateExp=(char*)malloc(sizeof(char)*9);
            sscanf(data,"%s,%s,%s,%s,%s,%s",name,Newname,price,amount,dateMan,dateExp);
            if(strcmp(Newname,"~")!=0)
                strcpy(p->name,Newname);
            if(strcmp(price,"~")!=0)
                strcpy(p->price,price);
            if(strcmp(amount,"~")!=0)
                strcpy(p->amount,amount);
            if(strcmp(dateMan,"~")!=0)
                strcpy(p->dateMan,dateMan);
            if(strcmp(dateExp,"~")!=0)
                strcpy(p->dateExp,dateExp);
        }
        else if(name<p->name)
            p=p->left;
        else
            p=p->right;
    }
    return NULL;
}
BSTNodeT * findMin(BSTNodeT *node)
{
    if(node==NULL)
        return NULL;
    if(node->left)
        return findMin(node->left);
    return node;
}
BSTNodeT *delNode(BSTNodeT *node,char *name)
{
    if(node==NULL)
    {
        printf("No such node exists\n");
    }
    else if(strcmp(name,node->name)<0)
    {
        node->left=delNode(node->left,name);
    }
    else if(strcmp(name,node->name)>0)
    {
        node->right=delNode(node->right,name);
    }
    else
    {
        if(node->right && node->left)
        {
            BSTNodeT *temp=findMin(node->right);
            strcpy(node->name,temp->name);
            strcpy(node->price,temp->price);
            strcpy(node->amount,temp->amount);
            strcpy(node->dateExp,temp->dateExp);
            strcpy(node->dateMan,temp->dateMan);
            node->right=delNode(node->right,temp->name);
        }
        else
        {
            BSTNodeT *temp=node;
            if(node->left==NULL)
                node=node->right;
            else if(node->right==NULL)
                node=node->left;
            free(temp);
        }
    }
    return node;
}
int expiredProd(char *expDate)
{
    int year=0,day=0,month=0;
    year=atoi(expDate);
    day=year%100;
    year/=100;
    month=year%100;
    year/=100;
   if(year<2020)
        return 1;
   if(year== 2020 && month <4)
    return 1;
   if(year==2020 && month==4 && day<2)
    return 1;
   return 0;
}
void preorder (BSTNodeT *root)
{
    if(root !=NULL)
    {
        printf("%s,%s,%s,%s,%s\n",root->name,root->price,root->amount,root->dateExp,root->dateMan);
        preorder(root->left);
        preorder(root->right);
    }
}
void program(FILE *f)
{
    char *data=(char*)malloc(sizeof(char)*100);
    char *newName=(char*)malloc(sizeof(char)*35);
    char *name=(char*)malloc(sizeof(char)*35);
    char *price=(char*)malloc(sizeof(char)*5);
    char *amount=(char*)malloc(sizeof(char)*5);
    char *dateExp=(char*)malloc(sizeof(char)*9);
    char *dateMan=(char*)malloc(sizeof(char)*9);
    BSTNodeT *root=NULL,*ce=NULL,*foundnod;
    foundnod=(BSTNodeT*)malloc(sizeof(BSTNodeT));

    while(fgets(data,100,f))
    {
        if(data[0]=='i')
        {

            root=insertNode(root,data);

            sscanf(data,"%s,%s,%s,%s,%s",name,price,amount,dateMan,dateExp);
            if(expiredProd(dateExp));
               ce=insertNode(ce,data);

        }
        else if(data[0]=='u')
        {
            sscanf(data,"%s,%s,%s,%s,%s,%s",name,newName,price,amount,dateMan,dateExp);
            foundnod=find(root,data);
            if(expiredProd(dateExp));
                foundnod=find(ce,data);
        }
        else if(data[0]=='d')
        {
            strcpy(data,data+1);
            root=delNode(root,data);
            if(expiredProd(dateExp));
            ce=delNode(ce,data);
        }

    }
    preorder(root);

    preorder(ce);
}

int main()
{
    FILE *f=fopen("data.txt","rw+");
    program(f);

    return 0;
}
