//
// Created by ileana on 3/1/2020.
//

#ifndef E1_SLL_H
#define E1_SLL_H

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int capacity;
    struct node * next;
}NodeT;

typedef struct node1{
    char country[100];
    struct node1 * next;
}NodeT1;

NodeT *firstSentinel, *lastSentinel;
NodeT1 *firstCountry, *lastCountry;
NodeT **firstNodes, **lastNodes;             //array of first nodes from lists for the capacities of waves of each country

void initialize(NodeT * first, NodeT * last);
void addElement(int key);
void deleteFirstSentinel();
NodeT ** createArrayOfNodes(int n);
void addElementCountry(char name[]);
void printSll(NodeT * first, NodeT *last);
void printSll1(NodeT1 * first, NodeT1 *last);
void addWaves(int key, int i);
void removeCountry(char name[]);
void deleteWave(int i);

#endif //E1_SLL_H
