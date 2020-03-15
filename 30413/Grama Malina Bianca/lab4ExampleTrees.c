#include <stdio.h>
#include <stdlib.h>

typedef struct node_type {
    int id;
    struct node_type *left, *right;
} NodeT;

void fatalError(const char *msg) {
    printf("%s", msg);
    printf("\n");
    exit(1);
}

void preorder(NodeT *p, int level) {
    if (p != NULL) {
        for (int i = 0; i <= level; i++)
            printf(" "); /* for nice listing */
        printf("%2.2d\n", p->id);
        preorder(p->left, level + 1);
        preorder(p->right, level + 1);
    }
}

void inorder(NodeT *p, int level) {
    if (p != NULL) {
        inorder(p->left, level + 1);
        for (int i = 0; i <= level; i++)
            printf(" "); /* for nice listing */
        printf("%2.2d\n", p->id);
        inorder(p->right, level + 1);
    }
}

void postorder(NodeT *p, int level) {
    if (p != NULL) {
        postorder(p->left, level + 1);
        postorder(p->right, level + 1);
        for (int i = 0; i <= level; i++)
            printf(" "); /* for nice listing */
        printf("%2.2d\n", p->id);
    }
}

NodeT *createBinTree(int branch, NodeT *parent) {
    NodeT *p;
    int id;
    /* read node id */
    if (branch == 0)
        printf("Root identifier [0 to end] =");
    else if (branch == 1)
        printf("Left child of %d [0 to end] =",
               parent->id);
    else
        printf("Right child of %d [0 to end] =",
               parent->id);
    scanf("%d", &id);
    if (id == 0)
        return NULL;
    else {
        p = (NodeT *) malloc(sizeof(NodeT));
        if (p == NULL)
            fatalError("Out of space in createBinTree"); /* fill in node */
        p->id = id;
        p->left = createBinTree(1, p);
        p->right = createBinTree(2, p);
    }
    return p;
}

void Swap( NodeT **a , NodeT **b)
{
    NodeT * temp = *a;
    *a = *b;
    *b = temp;
}

void swapEveryKLevelUtil( NodeT *root, int level, int k)
{
    if (root== NULL ||
        (root->left==NULL && root->right==NULL) )
        return ;

    if ( (level + 1) % k == 0)
        Swap(&root->left, &root->right);
    
    swapEveryKLevelUtil(root->left, level+1, k);
    swapEveryKLevelUtil(root->right, level+1, k);
}

void swapEveryKLevel(NodeT *root, int k) {
    swapEveryKLevelUtil(root, 1, k);
}

int maxHeight(NodeT* node)
{
    if (node==NULL)
        return 0;
    else
    {
        int lHeight = maxHeight(node->left);
        int rHeight = maxHeight(node->right);

        if (lHeight > rHeight)
            return(lHeight+1);
        else return(rHeight+1);
    }
}

int getLeafCount(NodeT* node)
{
    if(node == NULL)
        return 0;
    if(node->left == NULL && node->right==NULL)
        return 1;
    else
        return getLeafCount(node->left)+
               getLeafCount(node->right);
}

int main() {
    NodeT *root = createBinTree(0, NULL);
    swapEveryKLevel(root,1);

    printf("\n Preorder listing\n");
    preorder(root, 0);
    printf("\nInorder listing\n");
    inorder(root, 0);
    printf("\nPostorder listing\n");
    postorder(root, 0);
    printf("The height of the tree is %d.\n", maxHeight(root)-1);
    printf("The number of leaves in the tree is %d.\n", getLeafCount(root));
    return 0;
}