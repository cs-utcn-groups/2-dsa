#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COUNT 10

typedef struct node{
    char id;
    struct node *left, *right;
} NodeT;

typedef struct nodeList{
    char id;
    struct nodeList *next, *prev;
} NodeL;

NodeT *createBinaryTree();
NodeL *getListFromTree(NodeT *root);
void addLeaves(NodeT *root);
void printList(NodeL*);
NodeT *getTreeFromList(NodeL *currentElement);
void print2D(NodeT *root, int);

NodeL *first;
NodeL *last;

int main() {
    NodeT *root = createBinaryTree();
    NodeL *firstFromList = getListFromTree(root);
    printList(firstFromList);
    root = getTreeFromList(firstFromList);
    print2D(root,0);
    return 0;
}

NodeT *createBinaryTree(){
    char *c= malloc(sizeof(char));
    scanf("%s",c);

    if(strcmp(c,"*") == 0){
        return  NULL;
    }

    NodeT *p = (NodeT *)malloc(sizeof(NodeT));
    p->id = c[0];
    p->left = createBinaryTree();
    p->right = createBinaryTree();
    return p;
}


void printList(NodeL *currentElement)
{
    if(currentElement == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        while(currentElement != NULL)
        {
            printf("%c ", currentElement->id);
            currentElement = currentElement->next;
        }
        printf("\n");
    }

}

void print2D(NodeT *root, int space)
{
    if (root != NULL){
        space += COUNT;

        print2D(root->right, space);

        printf("\n");
        for (int i = COUNT; i < space; i++)
            printf(" ");
        printf("%c\n", root->id);

        print2D(root->left, space);
    } else {
        return;
    }
}

void addNodeToList(NodeT *root){
    if (first == NULL) {
        first = (NodeL *) malloc(sizeof(NodeL));
        first->id = root->id;
        first->next = last;
        first->prev = NULL;
        last = first;
    } else
    {
        NodeL *addedNode = (NodeL*)malloc(sizeof(NodeL));
        addedNode->id = root->id;
        last->next = addedNode;
        addedNode->prev = last;
        addedNode->next = NULL;
        last = addedNode;
        addLeaves(root);

    }
}

void addLeaves(NodeT *root){
    if (root->right == NULL){
        NodeL *addedLeaf = (NodeL*)malloc(sizeof(NodeL));
        addedLeaf->id = '*';
        last->next = addedLeaf;
        addedLeaf->prev = last;
        addedLeaf->next = NULL;
        last = addedLeaf;
    }
    if (root->left == NULL){
        NodeL *addedLeaf = (NodeL*)malloc(sizeof(NodeL));
        addedLeaf->id = '*';
        last->next = addedLeaf;
        addedLeaf->prev = last;
        addedLeaf->next = NULL;
        last = addedLeaf;
    }
}

NodeL *getListFromTree(NodeT *root){
    if (root != NULL){
        addNodeToList(root);
        getListFromTree(root->left);
        getListFromTree(root->right);
    }
    return first;
}

NodeT *getTreeFromList(NodeL *currentElement){
    if(currentElement == NULL)
    {
        printf("List is empty!\n");
        return NULL;
    }
    else
    {
        while(currentElement != NULL)
        {
            if (currentElement->id == '*'){
                return  NULL;
            }
            NodeT *p = (NodeT *)malloc(sizeof(NodeT));
            p->id = currentElement->id;
            p->left = getTreeFromList(currentElement->next);
            p->right = getTreeFromList(currentElement->next);
            return p;
        }
    }
}