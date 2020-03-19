#include "header.h"

treeStruct * insertKey(treeStruct * root,char key)
{
    if(root==NULL)
    {
        root=createNode(key);
    }

    else
    {
        if(key<root->key)
        {
            root->left=insertKey(root->left,key);
        }

        else
        {
            if(key>root->key)
            {
                root->right=insertKey(root->right,key);
            }
        }
    }

    return root;
}

treeStruct * createNode(char key)
{
    treeStruct * p=(treeStruct *) malloc(sizeof(treeStruct));

    p->key=key;
    p->left=p->right=NULL;

    return p;
}

void preOrder(treeStruct * node)
{
    if(node!=NULL)
    {
        printf("%c ",node->key);
        preOrder(node->left);
        preOrder(node->right);
    }
    printf("\n");
}

void inOrder(treeStruct * node)
{
    if(node!=NULL)
    {
        preOrder(node->left);
        printf("%c ",node->key);
        preOrder(node->right);
    }
    printf("\n");
}

void postOrder(treeStruct * node)
{
    if(node!=NULL)
    {
        preOrder(node->left);
        preOrder(node->right);
        printf("%c ",node->key);
    }
    printf("\n");
}

treeStruct * deleteNode(treeStruct * node, char key)
{
    if(node == NULL)
    {
        printf("Element not found\n");
    }

    else
    {
        if(key<node->key)
        {
            node->left=deleteNode(node->left,key);
        }

        else
        {
            if(key>node->key)
            {
                node->right=deleteNode(node->right,key);
            }

            else
            {
                if(node->right && node->left)
                {
                    treeStruct * temp=findMin(node->right);
                    node->key=temp->key;
                    node->right=deleteNode(node->right,temp->key);
                }
            }
        }
    }
    return node;
}

treeStruct * findMin(treeStruct * node)
{
    if(node == NULL)
    {
        return NULL;
    }

    if(node->left)
    {
        return findMin(node->left);
    }

    return node;
}

treeStruct * findd(treeStruct * root,char key)
{
    treeStruct * p=(treeStruct *) malloc(sizeof(treeStruct));

    if(root==NULL)
    {
        p=root;
    }

    while(p!=NULL)
    {
        if(p->key==key)
        {
            printf("%c found\n",key);
            return p;
        }

        else
        {
            if(key<p->key)
            {
                p=p->left;
            }

            else
            {
                p=p->right;
            }
        }
    }
    printf("%c not found\n",key);
    return NULL;
}

treeStruct * findMax(treeStruct * node)
{
    if(node == NULL)
    {
        return NULL;
    }

    if(node->right)
    {
        return findMax(node->right);
    }

    return node;
}

void read(FILE * f)
{
    char * s=(char *) malloc(sizeof(char) * 5);

    while(fgets(s,5,f))
    {
        char command=s[0],key=s[1];

        if(command=='i')
        {
            root=insertKey(root,key);
            continue;
        }

        if(command=='d')
        {
            root=deleteNode(root,key);
            continue;
        }

        if(command=='f')
        {
            findd(root,key);
            continue;
        }

        if(command=='t')
        {
            if(key=='p')
            {
                preOrder(root);
                continue;
            }

            if(key=='P')
            {
                postOrder(root);
                continue;
            }

            if(key=='i')
            {
                inOrder(root);
                continue;
            }
            continue;
        }

        if(command=='g')
        {
            if(key=='m')
            {
                treeStruct * p=findMin(root);
                printf("%c\n",p->key);
            }

            if(key=='M')
            {
                treeStruct * p=findMax(root);
                printf("%c\n",p->key);
            }
        }
    }
}
