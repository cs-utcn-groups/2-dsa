//
// Created by bindi on 3/19/2020.
//

#ifndef ASSIGNMENT_3_LIST_H
#define ASSIGNMENT_3_LIST_H
typedef struct _dLList {
    char data;
    struct _dLList *next;
    struct _dLList *prev;
} list;
list *firstElement, *lastElement;

void initList(void);

void addElementLast(char data);

void traverseList(list *firstOfList);

#endif //ASSIGNMENT_3_LIST_H
