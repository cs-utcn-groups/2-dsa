//
// Created by 0rezz on 3/22/2020.
//
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void initialiseList(doublyLinked *list) {
    list->sentinel = NULL;
}
void addFirst(char data, doublyLinked *list){
    NodeT *newNode = (NodeT *) malloc(sizeof(NodeT));
    newNode->data = data;
    if (list->sentinel == NULL) {
        list->sentinel = newNode;
        list->sentinel->next = list->sentinel;
        list->sentinel->prev = list->sentinel;
    } else {
        newNode->next = list->sentinel->next;
        list->sentinel->next = newNode;
        list->sentinel->next->prev = list->sentinel;
    }
}
void addLast(char data, doublyLinked *list){
    NodeT *newNode = (NodeT *) malloc(sizeof(NodeT));
    newNode->data = data;
    if(list->sentinel == NULL){
        addFirst(data, list);
    }
    else{
        newNode->prev = list->sentinel;
        newNode->next = list->sentinel->next;
        list->sentinel = newNode;
        list->sentinel->prev->next = list->sentinel;
    }
}
void printAll(doublyLinked *list, FILE *FILE) {
    if (list->sentinel == NULL)
        fprintf(FILE ,"List is empty\n");
    else {
        NodeT *currentNode = list->sentinel->next;
        do {
            fprintf(FILE, "%c ", currentNode->data);
            currentNode = currentNode->next;
        } while (currentNode != list->sentinel->next);
    }
    fprintf(FILE, "\n");
}
NodeS *createBinaryTree(){
    char *c = malloc(sizeof(char));
    scanf("%s",c);
    if (strcmp(c, "*") == 0){
        return NULL;
    }
    NodeS *p = (NodeS*)malloc(sizeof(NodeS));
    p->id = c[0];
    p->left = createBinaryTree();
    p->right = createBinaryTree();
    return p;
}
void preorder(NodeS *currentRoot, int lv){
    if (currentRoot != NULL) {
        for (int i = 0; i < lv; i++) {
            printf("*");
        }
        printf("%c", currentRoot->id);
        preorder(currentRoot->left, lv + 1);
        preorder(currentRoot->right, lv + 1);
    }
}
void getListFromTree(NodeS *currentRoot, int lv, doublyLinked *list){
    if (currentRoot != NULL) {
        for (int i = 0; i < lv; i++) {
           addLast('*', list);
        }
        addLast(currentRoot->id, list);
        getListFromTree(currentRoot->left, lv + 1, list);
        getListFromTree(currentRoot->right, lv + 1, list);
    }
}
NodeS *traverseList (NodeT **currentNode){
    char c = (*currentNode)->data;
    (*currentNode) = (*currentNode)->next;
    if (c != '*') {
        NodeS *p = (NodeS *) malloc(sizeof(NodeS));
        p->id = c;
        p->left = traverseList(currentNode);
        p->right = traverseList(currentNode);
        return p;
    } else {
        return NULL;
    }
}
