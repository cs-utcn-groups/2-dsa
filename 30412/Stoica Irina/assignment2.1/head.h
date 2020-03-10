//
// Created by Irina on 08/03/2020.
//

#ifndef ASSIGNMENT2_HEAD_H
#define ASSIGNMENT2_HEAD_H

typedef struct node{
    int value;
    struct node * next;
    struct node * previous;
}node;
node * first, * last;

#endif //ASSIGNMENT2_HEAD_H
