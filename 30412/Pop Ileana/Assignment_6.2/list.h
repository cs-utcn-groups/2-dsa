//
// Created by ileana on 4/14/2020.
//

#ifndef ASSIGNMENT_6_2_LIST_H

typedef struct node{
    int content;
    struct node * next;
}NodeT;

NodeT * coverSet;

void makeEmpty();
void addNewNode(int content);

#define ASSIGNMENT_6_2_LIST_H

#endif //ASSIGNMENT_6_2_LIST_H
