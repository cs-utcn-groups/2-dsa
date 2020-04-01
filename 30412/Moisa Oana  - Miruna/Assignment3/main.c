#include <stdio.h>
#include<string.h>
#include<stdlib.h>
typedef  struct nodeTree{
    char id;
    struct nodeTree *left,*right;
}NodeT;
typedef struct nodeList{
    char id;
    struct nodeList *next, *prev;
}NodeL;
NodeL*last,*firstNodeList;
NodeT *createBinaryTree();
void preOrder(NodeT *currentRoot, int level);
void getListFromTree(NodeT * currentRoot);
void addLast( char x);
void printList();
void initializeList();
NodeT *getTreeFromList();
int main() {

    NodeT *root=createBinaryTree();
    initializeList();
    getListFromTree(root);
    printList();
    root=getTreeFromList();
    preOrder(root,0);
    return 0;
}

NodeT *createBinaryTree() {
    char *c;
    c=(char*)malloc(sizeof(char));
    scanf("%s",c);
    if(strcmp(c,"*")==0)
    {
        return NULL;
    }
    NodeT *newNode;
    newNode=(NodeT*)malloc(sizeof(NodeT));
    newNode->id=c[0];
    newNode->left=createBinaryTree();
    newNode->right=createBinaryTree();
    return newNode;
}
void preOrder(NodeT *currentRoot, int level)
{
    if(currentRoot!=NULL)
    {
        for(int i=0;i<level;i++)
            printf(" ");
        printf("%c",currentRoot->id);
        preOrder(currentRoot->left,level+1);
        preOrder(currentRoot->right,level+1);
    }
}
void getListFromTree(NodeT * currentRoot)
{
    if(currentRoot!=NULL) {
        addLast(currentRoot->id);
        if(currentRoot->left==NULL)
        {
            addLast('*');
        }
        getListFromTree(currentRoot->left);
        if(currentRoot->right==NULL)
        {
            addLast('*');
        }
        getListFromTree(currentRoot->right);
    }

}
void printList() {
    if (firstNodeList == NULL) {
        printf("List is empty!\n");
    } else {
        NodeL *currentNode;
        currentNode = firstNodeList;
        while (currentNode != NULL) {
            printf("%c ", currentNode->id);
            currentNode = currentNode->next;
        }
        printf("\n");

    }
}
void addLast( char x)
{
    if((firstNodeList)==NULL)
    {
        (firstNodeList)=(NodeL*)malloc(sizeof(NodeL));
        (firstNodeList)->id=x;
        (firstNodeList)->next=last;
        (firstNodeList)->prev=NULL;
        last=firstNodeList;

    } else
    {
        NodeL *newNode;
        newNode=(NodeL*)malloc(sizeof(NodeL));
        newNode->next=NULL;
        newNode->prev=last;
        newNode->id=x;
        last->next=newNode;
        last=newNode;
    }
}
NodeT *getTreeFromList()
{
    if(firstNodeList->id=='*')
    {
        return NULL;
    }
    NodeT *newNode;
    newNode=(NodeT*)malloc(sizeof(NodeT));
    newNode->id=firstNodeList->id;
    firstNodeList=firstNodeList->next;
    newNode->left=getTreeFromList();
    firstNodeList=firstNodeList->next;
    newNode->right=getTreeFromList();
    return newNode;
}
void initializeList()
{
    firstNodeList=NULL;
    last=NULL;
}
