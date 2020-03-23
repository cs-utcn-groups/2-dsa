#include "head.h"
MAX_LENGTH=200;
NodeT *rootExp=NULL,*root=NULL;


NodeT *newNode(char *s)
{
    char *token=(char *)malloc(sizeof(char)*MAX_LENGTH);
    NodeT *node=(NodeT *)malloc(sizeof(NodeT));
    token=strtok(s,",");
    node->name=token;
    int i=1;

    while(token!=NULL)
    {
        token=strtok(NULL,",");
        if(i==1)
            node->price=atoi(token);
        else if(i==2)
            node->amount=atoi(token);
        else if(i==3)
            node->dateOfManufacturing=atoi(token);
        else if(i==4)
            node->dateOfExpiration=atoi(token);
        i++;
    }

    node->left=NULL;
    node->right=NULL;

    return node;
}

NodeT *insertNode(NodeT *node, char *s)
{
    if(node==NULL)
    {
        char *cpy=(char *)malloc(sizeof(char)*MAX_LENGTH);
        strcpy(cpy,s);
        node=newNode(cpy);
    }
    else
    {
        if(strcmp(s,node->name)<0)
            node->left=insertNode(node->left,s);
        else if(strcmp(s,node->name)>0)
            node->right=insertNode(node->right,s);
    }

    return node;
}

NodeT *getMin(NodeT *node)
{
    if(node==NULL)
        return;
    else if(node->left)
        return getMin(node->left);
    else
        return node;
}

NodeT *deleteNode(NodeT *node,char *s)
{
    if(node==NULL)
        printf("Element not found\n");
    else if(strcmp(s,node->name)<0)
        node->left=deleteNode(node->left,s);
    else if(strcmp(s,node->name)>0)
        node->right=deleteNode(node->right,s);
    else
    {
        if(node->left && node->right)
        {
            NodeT *temp=getMin(node->right);

            node->name=temp->name;
            node->price=temp->price;
            node->amount=temp->amount;
            node->dateOfExpiration=temp->dateOfExpiration;
            node->dateOfManufacturing=temp->dateOfManufacturing;

            node->right=deleteNode(node->right,temp->name);
        }
        else
        {
            NodeT *temp=node;
            if(node->left==NULL)
                node=node->right;
            else if(node->right==NULL)
                node=node->left;
            free(temp);
        }
    }

    return node;
}


NodeT *updateNode(NodeT *node,char *s)
{
    char *name=strtok(s,",");
    s=strtok(NULL,"");
    deleteNode(node,name);
    insertNode(node,s);
}

NodeT *preorder(NodeT *node, int level,FILE *g)
{
    if(node!=NULL)
    {
        for(int i=0; i<level; i++)
            fprintf(g,"    ");
        fprintf(g,"%s\n",node->name);
        node->left=preorder(node->left,level+1,g);
        node->right=preorder(node->right,level+1,g);
    }

}

NodeT *newNode2(NodeT *nodeFirstTree)
{
    NodeT *node=(NodeT *)malloc(sizeof(NodeT));
    node->name=nodeFirstTree->name;
    node->price=nodeFirstTree->price;
    node->amount=nodeFirstTree->amount;
    node->dateOfManufacturing=nodeFirstTree->dateOfManufacturing;
    node->dateOfExpiration=nodeFirstTree->dateOfExpiration;
    node->left=NULL;
    node->right=NULL;

    return node;
}


NodeT *insertNode2(NodeT *node, NodeT *nodeFirstTree)
{
    if(node==NULL)
    {
        node=newNode2(nodeFirstTree);
    }
    else
    {
        if(strcmp(nodeFirstTree->name,node->name)<0)
            node->left=insertNode2(node->left,nodeFirstTree);
        else if(strcmp(nodeFirstTree->name,node->name)>0)
            node->right=insertNode2(node->right,nodeFirstTree);
    }

    return node;
}

NodeT *expiredProducts(NodeT *node,int level)
{
    if(node==NULL)
        return;
    int day,month,year;
    time_t now=time(&now);
    struct tm *local=localtime(&now);
    day=local->tm_mday;
    month=local->tm_mon+1;
    year=local->tm_year+1900;
    int currDate=0;

    currDate=year;
    currDate=currDate*100+month;
    currDate=currDate*100+day;

    if(currDate>node->dateOfExpiration)
    {
        if(rootExp==NULL)
        {
            rootExp=insertNode2(rootExp,node);
        }
        else
            insertNode2(rootExp,node);
    }

    node->left=expiredProducts(node->left,level+1);
    node->right=expiredProducts(node->right,level+1);
}

void readFile(FILE *f, FILE *g)
{
    char *s=(char *)malloc(sizeof(char)*MAX_LENGTH);
    char letter;
    while(fgets(s,MAX_LENGTH,f))
    {
        s[strlen(s)-1]='\0';
        letter=s[0];
        strtok(s," ");
        s=strtok(NULL,"");

        if(letter=='i')
        {
            if(root==NULL)
                root=insertNode(root,s);
            else
                insertNode(root,s);
        }
        else if(letter=='u')
            updateNode(root,s);
        else if(letter=='d')
            deleteNode(root,s);
        else if(letter=='e')
        {
            preorder(root,0,g);
            expiredProducts(root,0);
            fprintf(g,"\n");
            preorder(rootExp,0,g);
        }
    }
}
