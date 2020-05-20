#include <stdio.h>
#include <stdlib.h>

typedef struct bst_node
{
    char key;
    int height;
    struct bst_node*left,*right;
} BSTNodeT;

BSTNodeT*root;

int max(int a, int b)
{
    if (a>b) return a;
    return b;
}
int height(BSTNodeT *p)
{
    if (p==NULL)return 0;
    return p->height;
}
int Balance(BSTNodeT *p)
{
    if (p==NULL)
        return 0;
    return height(p->left)-height(p->right);
}
BSTNodeT* Right(BSTNodeT *l)
{
    BSTNodeT *p=l->left;
    BSTNodeT *t=p->right;

    p->right=l;
    l->left=t;

    l->height=max(height(l->left),height(l->right))+1;
    p->height=max(height(p->left),height(p->right))+1;

    return p;
}

BSTNodeT* Left(BSTNodeT *p)
{
    BSTNodeT *l=p->right;
    BSTNodeT *t=l->left;

    l->left=p;
    p->right=t;
    p->height=max(height(p->left),height(p->right))+1;
    l->height=max(height(l->left),height(l->right))+1;

    return l;
}

void fatalError(const char *msg)
{
    printf(msg);
    printf("\n");
    exit (1);
}
void preorder(BSTNodeT*p, int level)
{
    int i;

    if(p != NULL)
    {
        for(i = 0; i <= level; i++) printf(" ");
        printf("%c\n",p->key);
        preorder(p->left, level + 1);
        preorder(p->right, level + 1);
    }
}
BSTNodeT*recInsert(BSTNodeT*nod, char key)
{
    BSTNodeT*p;
    if(nod == NULL)
    {
        p = (BSTNodeT*) malloc(sizeof(BSTNodeT));
        p->key= key;
        p->left=NULL;
        p->right= NULL;
        nod=p;
        return nod;
    }
    else
    {
        if(key< nod->key) nod->left= recInsert(nod ->left, key);
        else if(key> nod->key) nod->right= recInsert(nod ->right, key);
        else printf("\nNode of key=%c already exists\n",key);
    }
    return nod;
    nod->height=1+max(height(nod->left),height(nod->right));

    int balance=Balance(nod);

    if (balance>1&&key<nod->left->key)
    {
        return Right(nod);
    }
    if (balance<-1&&key>nod->right->key)
    {
        return Left(nod);
    }
    if (balance>1&&key>nod->left->key)
    {
        nod->left=Left(nod->left);
        return Right(nod);
    }
    if (balance<-1&&key<nod->right->key)
    {
        nod->right=Right(nod->right);
        return Left(nod);
    }

    return nod;
}
char getCh(const char*message)
{
    fflush(stdin);
    char val;
    printf(message);
    scanf("%c", &val);
    fflush(stdin);
    return val;
}
int main()
{
    BSTNodeT *p;
    int n;
    printf("Number of nodes to insert=");
    scanf("%d", &n);
    char key;
    root= NULL;
    for(int i=0; i<n; i++)
    {
        key=getCh("\nKey=");
        root= recInsert(root, key);
    }
    printf("Preorder listing\n");
    preorder(root,0);

    return 0;

}
