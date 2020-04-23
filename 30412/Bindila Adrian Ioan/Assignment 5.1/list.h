//
// Created by bindi on 4/6/2020.
//

#ifndef ASSIGNMENT_5_1_LIST_H
#define ASSIGNMENT_5_1_LIST_H
typedef struct _list {
    int data;
    struct _list *next;
} list;

list *createListElement(int data);

#endif //ASSIGNMENT_5_1_LIST_H
