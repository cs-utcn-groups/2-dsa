#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    struct node *left, *right;
    int height;
} NodeT;

int height(NodeT *n){
    if (n==NULL){
        return 0;
    }
    return n->height;
}

int max(int a, int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}

NodeT *rotateRight(NodeT *n){
    NodeT *temp=n->left;
    NodeT *T2=temp->right;
    temp->right=n;
    n->left=T2;
    n->height=max(height(n->left),height(n->right))+1;
    temp->height=max(height(temp->left),height(temp->right))+1;
    return temp;
}

NodeT *rotateLeft(NodeT *n){
    NodeT *temp=n->right;
    NodeT *T2=temp->left;
    n->right=T2;
    temp->left=n;
    n->height=max(height(n->left),height(n->right))+1;
    temp->height=max(height(temp->left),height(temp->right))+1;
    return temp;
}

int getBalance(NodeT *n) {
    if (n==NULL){
        return 0;
    }
    return height(n->left)-height(n->right);
}

NodeT *createNode(int key) {
    NodeT *n=(NodeT *)malloc(sizeof(NodeT));
    if (n!=NULL){
        n->key=key;
        n->right=NULL;
        n->left=NULL;
        n->height=1;
    }
    return n;
}

NodeT *insertNode(NodeT *n, int key) {
    if (n==NULL){
        return (createNode(key));
    }
    if (key<n->key){
        n->left=insertNode(n->left,key);
    }
    else if (key>n->key){
        n->right=insertNode(n->right,key);
    }
    else{
            return n;
    }
    n->height=max(height(n->left),height(n->right))+1;
    int balance=getBalance(n);

    if (balance>1 && key<n->left->key){
        return rotateRight(n);
    }

    if (balance<-1 && key>n->right->key){
        return rotateLeft(n);
    }

    if (balance>1 && key>n->left->key){
        n->left=rotateLeft(n->left);
        return rotateRight(n);
    }

    if (balance<-1 && key<n->right->key){
        n->right=rotateRight(n->right);
        return rotateLeft(n);
    }
    return n;
}

void prettyPrint(NodeT *n,int level)
{
    if(n!=NULL)
    {
    prettyPrint(n->right,level+1);
    for(int i=0;i<=level;i++)
    {
        printf("    ");
    }
    printf("%d\n",n->key);
    prettyPrint(n->left,level+1);
    }
}

int main (){
    NodeT *root=NULL;
    int x;
    printf("Enter the number of elements in the tree: ");
    scanf ("%d",&x);
    int y;
    for (int i=0;i<x;i++){
        printf("\nElement nr. %d= ",i+1);
        scanf("%d",&y);
        root=insertNode(root,y);
    }
    printf("\n");
    prettyPrint(root,0);
return 0;
}
