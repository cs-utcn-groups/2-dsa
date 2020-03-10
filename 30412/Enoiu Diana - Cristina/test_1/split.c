//
// Created by Diana on 3/10/2020.
//
#include <stdio.h>
#include "stdlib.h"
#include "head.h"
void initializeOrgList () {
    first = NULL;
    last = NULL;
}
void initializeSublist1() {
    first_1 = NULL;
    last_1 = NULL;
}
void initializeSublist2() {
    first_2 = NULL;
    last_2 = NULL;
}
void addFirst (int data) {
    if (first == NULL) {
        first = (originalList *)malloc(sizeof(originalList));
        first->data = data;
        first->next = NULL;
        last = first;
        last->next = NULL;
    }
    else {
        originalList * newElement = (originalList *)malloc(sizeof(originalList));
        newElement->data = data;
        newElement->next = first;
        first = newElement;
    }
}
void addFirstSublist1 (int data) {
    if (first_1 == NULL) {
        first_1 = (sublist_1*)malloc(sizeof(sublist_1));
        first_1->data = data;
        first_1->next = NULL;
        last_1 = first_1;
        last_1->next = NULL;
    }
    else {
        sublist_1 * newElement = (sublist_1 *)malloc(sizeof(sublist_1));
        newElement->data = data;
        newElement->next = first_1;
        first_1 = newElement;
    }
}
void addFirstSublist2 (int data) {
    if (first_2 == NULL) {
        first_2 = (sublist_2*)malloc(sizeof(sublist_2));
        first_2->data = data;
        first_2->next = NULL;
        last_2 = first_2;
        last_2->next = NULL;
    }
    else {
        sublist_2 * newElement = (sublist_2 *)malloc(sizeof(sublist_2));
        newElement->data = data;
        newElement->next = first_2;
        first_2 = newElement;
    }
}

void AlternatingSplit(originalList * source) {
    while(source != NULL) {
        if(source->data % 2 == 1) {
            addFirstSublist1(source->data);
        } else {
            addFirstSublist2(source->data);
        }
        source = source->next;
    }
}
void printAllOrgList(FILE * out) {
    originalList * currentElement;
    currentElement = first;
    if(currentElement == NULL) {
        fprintf(out,"list is empty\n");
        return;
    }
    fprintf(out,"Original list: ");
    while(currentElement != NULL) {
        fprintf(out,"%d ",currentElement->data);
        currentElement = currentElement->next;
    }
    fprintf(out,"\n");
}
void printAllSublist1(FILE * out) {
    sublist_1 * currentElement;
    currentElement = first_1;
    if(currentElement == NULL) {
        fprintf(out,"list is empty\n");
        return;
    }
    fprintf(out,"Sublist_1: ");
    while(currentElement != NULL) {
        fprintf(out,"%d ",currentElement->data);
        currentElement = currentElement->next;
    }
    fprintf(out,"\n");
}

void printAllSublist2(FILE * out) {
    sublist_2 * currentElement;
    currentElement = first_2;
    fprintf(out,"Sublist_2: ");
    if(currentElement == NULL) {
        fprintf(out,"list is empty\n");
        return;
    }
    while(currentElement != NULL) {
        fprintf(out,"%d ",currentElement->data);
        currentElement = currentElement->next;
    }
    fprintf(out,"\n");
}