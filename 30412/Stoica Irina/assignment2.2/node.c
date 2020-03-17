//
// Created by Irina on 10/03/2020.
//
#include "node.h"
#include "stdio.h"
#include "stdlib.h"

void initializeList(){
    first = NULL;
    last = NULL;
}
node * getNewNode(int ruble, int seconds){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->rubles = ruble;
    newNode->seconds = seconds;
    newNode->next = NULL;
    newNode->previous = NULL;
    return newNode;
}
node * getSentinel(){
    node * sentinel = getNewNode(0, 0);
    sentinel->rubles = 0;
    sentinel->seconds = 0;
    sentinel->previous = NULL;
    sentinel->next = first = last;
    return sentinel;
}