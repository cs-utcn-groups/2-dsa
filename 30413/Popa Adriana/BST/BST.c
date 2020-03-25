#include "BST.h"

void fatalError(const char *msg)
{
    printf(msg);
    printf("\n");
    exit (1);
}

void preorder(BSTNodeT *p,int level)
{
    int i;
    if(p != NULL)
    {
        for
        (i=0; i<=level; i++)
            printf(" ");
        printf("%c\n", p->key);
        preorder(p->left, level + 1);
        preorder(p->right, level + 1);
    }
}

void inorder(BSTNodeT *p, int level)
{
    int i;
    if(p != NULL)
    {
        inorder(p->left, level + 1);
        for(i = 0; i <= level; i++)
            printf("    ");
        printf("%c\n", p->key);
        inorder(p->right, level + 1);
    }
}

void postorder(BSTNodeT *p, int level)
{
    int i;
    if(p != NULL)
    {
        postorder(p->left, level + 1);
        postorder( p->right, level + 1);
        for (i = 0; i <= level; i++)
            printf(" ");
        printf("%c\n",p->key);
    }
}

BSTNodeT *recInsert(BSTNodeT*root,char key)
{
    BSTNodeT *p;
    if(root == NULL)
    {
        p = (BSTNodeT*) malloc(sizeof(BSTNodeT));
        p->key= key;
        p->left= p->right= NULL;
        root=p;
        return root;
    }
    else
    {
        if(key < root->key)
            root->left= recInsert(root ->left, key);
        else if(key > root->key)
            root->right= recInsert(root ->right, key);
        else
            printf("\nNode of key=%d already exists\n",key);
    }
return root;
}

BSTNodeT *find(BSTNodeT *root, char key)
{
    BSTNodeT *p;
    if(root == NULL)
        return NULL;
    p = root;
    while(p != NULL)
    {
        if(p -> key == key)
            return p ;
        else if(key<p->key)
            p=p->left;
        else
            p=p->right;
    }
    return NULL;
}

BSTNodeT *delNode (BSTNodeT *root, char key )
{
    BSTNodeT *p;
    BSTNodeT *pParent;
    BSTNodeT *pRepl;
    BSTNodeT *pReplParent;
    int direction;
    if(root == NULL)
        return NULL;
    p= root;
    pParent = NULL;
    while(p != NULL && p->key != key)
    {
        if(key < p->key)
        {
            pParent = p ;
            p = p->left ;
            direction  = LEFT ;
        }
        else
        {
            pParent = p ;
            p  = p->right ;
            direction = RIGHT ;
        }
    }
    if ( p == NULL )
    {
        printf
        ("\nNo node of key value=%d\n", key);
        return root;
    }
    if(p->left == NULL)
        pRepl = p->right ;
    else if ( p->right == NULL )
        pRepl = p->left ;
    else
    {
        pReplParent = p ;
        pRepl = p->right ;
        while(pRepl->left != NULL)
        {
            pReplParent= pRepl;
            pRepl= pRepl->left;
        }
        if(pReplParent != p)
        {
            pReplParent->left = pRepl->right;
            pRepl->right =  p->right  ;
        }
        pRepl->left = p->left ;
    }
    free(p);
    printf("\nDeletion of node%d completed\n ", key);
    if(pParent == NULL)
        return pRepl;
    else
    {
        if(direction == LEFT)
            pParent->left = pRepl;
        else
            pParent->right = pRepl;
        return root ;
    }
}

void delTree(BSTNodeT *root)
{
    if(root != NULL)
    {
        delTree(root->left);
        delTree(root->right);
        free(root);
    }
}
