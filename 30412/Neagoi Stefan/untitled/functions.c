//
// Created by htbc4 on 3/10/2020.
//
#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 100

void initialiseList(doublyLinked *list){
    list->sentinel=NULL;
}

void addFirst(int data,doublyLinked *list){
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

doublyLinked getTime(FILE *file){
    int x;
    doublyLinked time;
    initialiseList(&time);
    char aux[MAX_LINE];
    fgets(aux, MAX_LINE, file);
    char *token = strtok(aux, " ");;
    while (token != NULL){
        x = atoi(token);
        addLast(x, &time);
        token=strtok(NULL, " ");
    }
    return time;
}


void addLast(int data,doublyLinked *list){
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

void deleteFirst(doublyLinked *list){
    if(list->sentinel == NULL)
        return;
    else{
        NodeT *element=list->sentinel->next;
        list->sentinel->next = list->sentinel->next->next;
        list->sentinel->next->prev = list->sentinel;
        free(element);
    }
}

void deleteLast(doublyLinked *list){
    if(list->sentinel == NULL)
        return;
    else{
        NodeT *element=list->sentinel;
        list->sentinel->prev->next = list->sentinel->next;
        list->sentinel = list->sentinel->prev;
        free(element);

    }
}

void doomList(doublyLinked *list) {
    while (list->sentinel != list->sentinel->next)
        deleteFirst(list);
    free(list->sentinel);
    initialiseList(list);
}

void deleteElement(int data,doublyLinked *list){
    NodeT *currentNode = list->sentinel->next;
    NodeT *previousNode = list->sentinel;
    do {
        if (currentNode == list->sentinel->next && currentNode->data == data) {
            deleteFirst(list);
            currentNode = list->sentinel->next;
            previousNode = list->sentinel;
        } else if (currentNode == list->sentinel && currentNode->data == data) {
            deleteLast(list);
            currentNode = list->sentinel->next;
        } else if (currentNode->data == data) {
            NodeT *aux = currentNode;
            previousNode->next = currentNode->next;
            currentNode = currentNode->next;
            currentNode->prev = previousNode;
            free(aux);
            currentNode->prev = previousNode;
        } else {
            previousNode = currentNode;
            currentNode = currentNode->next;
        }

    } while (currentNode != list->sentinel->next);
}

void printAll(doublyLinked *list, FILE *FILE) {
    if (list->sentinel == NULL)
        fprintf(FILE ,"List is empty\n");
    else {
        NodeT *currentNode = list->sentinel->next;
        do {
            fprintf(FILE, "%d ", currentNode->data);
            currentNode = currentNode->next;
        } while (currentNode != list->sentinel->next);
    }
    fprintf(FILE, "\n");
}

void printFirst(int a, doublyLinked *list, FILE *file){
    if (list->sentinel == NULL)
        fprintf(file ,"List is empty\n");
    else {
        NodeT *currentNode = list->sentinel->next;
        do {
            fprintf(file, "%d ", currentNode->data);
            currentNode = currentNode->next;
            a--;
        } while (currentNode != list->sentinel->next && a!=0);
    }
    fprintf(file, "\n");
}

void printLast(int a, doublyLinked *list, FILE *file){
    if (list->sentinel == NULL)
        fprintf(file,"List is empty\n");
    else {
        NodeT *currentNode = list->sentinel;
        do {
            fprintf(file, "%d ", currentNode->data);
            currentNode = currentNode->prev;
            a--;
        } while (currentNode != list->sentinel && a!=0);
    }
    fprintf(file, "\n");
}

doublyLinked getCustomerData(FILE *f){
    doublyLinked customerList;
    initialiseList(&customerList);
    char aux[MAX_LINE];
    while (feof(f) == 0) {
        fscanf(f, "%s", aux);
        int x, y;
        fscanf(f, "%d %d", &x, &y);
        NodeT *newCustomer=(NodeT*)malloc(sizeof(NodeT));
        newCustomer->time=y;
        newCustomer->rubles=x;
        if(customerList.sentinel == NULL){
            customerList.sentinel = newCustomer;
            customerList.sentinel->next = customerList.sentinel;
            customerList.sentinel->prev = customerList.sentinel;
        }
        else{
            newCustomer->prev = customerList.sentinel;
            newCustomer->next = customerList.sentinel->next;
            customerList.sentinel = newCustomer;
            customerList.sentinel->prev->next = customerList.sentinel;
        }
    }
    return customerList;
}
void printCustomerData(doublyLinked *list, FILE *FILE) {
    if (list->sentinel == NULL)
        fprintf(FILE ,"List is empty\n");
    else {
        NodeT *currentNode = list->sentinel->next;
        do {
            fprintf(FILE, "%d %d \n", currentNode->rubles,currentNode->time);
            currentNode = currentNode->next;
        } while (currentNode != list->sentinel->next);
    }
    fprintf(FILE, "\n");
}
