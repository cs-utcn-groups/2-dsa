#include "head.h"
MAX_LENGTH=200;
NodeT *root=NULL;

NodeT *newNode(char c)
{
    NodeT *node=(NodeT *)malloc(sizeof(NodeT));

    node->data=c;
    node->left=NULL;
    node->right=NULL;

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

NodeT *deleteNode(NodeT *node, char c)
{
    if(node==NULL)
        printf("Element not found/n");
    else
    {
        if(c<node->data)
            node->left=deleteNode(node->left,c);
        else
        {
            if(c>node->data)
                node->right=deleteNode(node->right,c);
            else
            {
                if(node->left && node->right)
                {
                    NodeT *temp=getMin(node->right);
                    node->data=temp->data;
                    node->right=deleteNode(node->right,temp->data);
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
        }
    }

    return node;
}

NodeT *findNode(NodeT *node, char c)
{
    if(node==NULL)
        return;

    NodeT *p=node;

    while(p!=NULL)
    {
        if(c<p->data)
            p=p->left;
        else if(c>p->data)
            p=p->right;
        else
            return p;
    }
    return;
}

NodeT *preorder(NodeT *node, int level)
{
    if(node!=NULL)
    {
        for(int i=0; i<level; i++)
            printf(" ");
        printf("%c\n",node->data);
        node->left=preorder(node->left,level+1);
        node->right=preorder(node->right,level+1);
    }
}

NodeT *inorder(NodeT *node, int level)
{
    if(node!=NULL)
    {
        node->left=inorder(node->left,level+1);
        for(int i=0; i<level; i++)
            printf(" ");
        printf("%c\n",node->data);
        node->right=inorder(node->right,level+1);
    }
}

NodeT *postorder(NodeT *node, int level)
{
    if(node!=NULL)
    {
        node->left=postorder(node->left,level+1);
        node->right=postorder(node->right,level+1);
        for(int i=0; i<level; i++)
            printf(" ");
        printf("%c\n",node->data);
    }
}

NodeT *getMax(NodeT *node)
{
    if(node==NULL)
        return;
    else if(node->right)
        return getMax(node->right);
    else
        return node;
}


NodeT *insertNode(NodeT *node, char c)
{
    if(node==NULL)
        node=newNode(c);
    else
    {
        if(c<node->data)
            node->left=insertNode(node->left,c);
        else
        {
            if(c>node->data)
                node->right=insertNode(node->right,c);
        }
    }
    return node;
}

void readFile(FILE *f)
{
    char *s=(char *)malloc(sizeof(char));
    while(fgets(s,MAX_LENGTH,f))
    {
        s[strlen(s)-1]='\0';

        if(s[0]=='i')
        {
            if(root==NULL)
                root=insertNode(root,s[1]);
            else
                insertNode(root,s[1]);
        }
        else
        {
            if(s[0]=='d')
                deleteNode(root,s[1]);
            else
            {
                if(s[0]=='f')
                    printf("\n%c\n",findNode(root,s[1])->data);
                else
                {
                    if(s[0]=='t')
                    {
                        if(s[1]=='p')
                            preorder(root,0);
                        else
                        {
                            if(s[1]=='P')
                                postorder(root,0);
                            else
                                inorder(root,0);
                        }
                    }
                    else if(s[0]=='g')
                    {
                        if(s[1]=='m')
                            printf("\n%c\n",getMin(root)->data);
                        else
                            printf("\n%c\n",getMax(root)->data);
                    }
                }
            }
        }
    }
}
