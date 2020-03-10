//
// Created by Irina on 10/03/2020.
//

#ifndef ASSIGNMENT2_2_NODE_H
#define ASSIGNMENT2_2_NODE_H

typedef struct node{
    int rubles;
    int seconds;
    struct node * next;
    struct node * previous;
}node;

node *first, *last;

node * getNewNode(int ruble, int seconds);

node * getSentinel();

void initializeList();

#endif //ASSIGNMENT2_2_NODE_H
