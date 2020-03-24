#include "head.h"

NodeT *createBinaryTree(){
    char *c = malloc(sizeof(char));
    fscanf(fin,"%s",c);
    if(strcmp(c,"*")==0){
        return NULL;
    }
    NodeT *p = (NodeT*) malloc (sizeof(NodeT));
    p->id = c[0];
    p->left = createBinaryTree();
    p->right = createBinaryTree();
    return p;
}

void initializeDLL(NodeL **head, NodeL **last){
    *head = (NodeL*) malloc (sizeof(NodeL));
    *last = (NodeL*) malloc (sizeof(NodeL));
    *head = NULL;
    *last = NULL;
}

void addElementToTheList(NodeL **head, NodeL **last, char newData){
    NodeL *newElement = (NodeL*) malloc (sizeof(NodeL));
    newElement->data = newData;
    if(*last == NULL){
        *head = *last = newElement;
        newElement->prev = newElement->next = NULL;
    }
    else{
        (*last)->next = newElement;
        newElement->prev = *last;
        newElement->next = NULL;
        *last = newElement;
    }
}

void preorder(NodeL **head, NodeL **last, NodeT *currentRoot){
    if(currentRoot != NULL){
        addElementToTheList(head,last,currentRoot->id);

        if(currentRoot->left == NULL){
            addElementToTheList(head,last,'*');
        }
        preorder(head,last,currentRoot->left);

        if(currentRoot->right == NULL){
            addElementToTheList(head,last,'*');
        }
        preorder(head,last,currentRoot->right);
    }
}

NodeL *getListFromTree(NodeT *root){
    NodeL *head, *last;
    initializeDLL(&head,&last);
    preorder(&head,&last,root);
    return head;
}

void traverseList(NodeL *head){
    NodeL *p;
    p = head;
    if(head == NULL){
        printf("The list is empty!");
    }
    while(p != NULL){
        printf("%c ", p->data);
        p = p->next;
    }
    printf("\n");
}

NodeT *getTreeFromList(NodeL **currentNode){
    NodeT *currentRoot = (NodeT*)malloc(sizeof(NodeT));
    if((*currentNode)->data == '*'){
        *currentNode = (*currentNode)->next;
        return NULL;
    }
    currentRoot->id = (*currentNode)->data;

    *currentNode = (*currentNode)->next;

    currentRoot->left = getTreeFromList(currentNode);
    currentRoot->right = getTreeFromList(currentNode);

    return currentRoot;
}

void prettyPrint(NodeT *currentRoot, int level){
    if(currentRoot != NULL){
        prettyPrint(currentRoot->right, level+1);
        for(int i=0;i<level;i++){
            printf("\t");
        }
        printf("%c", currentRoot->id);
        printf("\n");
        prettyPrint(currentRoot->left, level+1);
    }
}

//
// Created by Anca on 3/22/2020.
//

