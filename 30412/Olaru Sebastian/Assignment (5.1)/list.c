//
// Created by acer on 4/5/2020.
//

#include "list.h"

void addLastList(List *list, int value) {
    if(list->first == NULL){
        list->first = (Node *)malloc(sizeof(Node));
        list->first->data = value;
        list->first->next = NULL;
        list->last = list->first;
    }else {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = value;
        newNode->next = NULL;
        list->last->next = newNode;
        list->last = newNode;
    }
}

List *getListFromMatrix(int **matrix, int noOfVertices) {
    List *adjList = (List *)malloc(noOfVertices * sizeof(List));
    for(int i=0; i<noOfVertices; i++){
        adjList[i].first = NULL;
        adjList[i].last = NULL;
        for (int j = 0; j <noOfVertices ; ++j)
            if(matrix[i][j])
                addLastList(&adjList[i], j + 1);
    }
    return adjList;
}

void printAdjList(List *pList, int noOfVertices) {
    Node *currNode;
    for(int i=0; i<noOfVertices; i++){
        printf("%c: ", i+'A');
        currNode = pList[i].first;
        while(currNode != NULL){
            printf("%c ", currNode->data + 'A');
            currNode = currNode->next;
        }
        printf("\n");
    }
}

void enqueue(List *list, int value) {
    if(list->first == NULL){
        list->first = (Node *)malloc(sizeof(Node));
        list->first->data = value;
        list->first->next = NULL;
        list->last = list->first;
    } else {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = value;
        newNode->next = NULL;
        list->last->next = newNode;
        list->last = newNode;
    }
}

int dequeue(List *list) {
    int data;
    if(list->first) {
        data = list->first->data;
        list->first = list->first->next;
    }
    if(list->first == NULL)
        list->last = NULL;
    return data;
}