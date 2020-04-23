//
// Created by q on 4/1/2020.
//

#include "list.h"

ListT * createAdjList(int N) {
    ListT * AL = (ListT *)malloc(N * sizeof(ListT));
    if (AL == NULL) {
        errMessage();
    }
    else {
        // initialize the empty lists
        for (int i = 0; i < N; i++) {
            AL[i].count = 0;
            AL[i].head = AL[i].tail = NULL;
        }
    }
    return AL;
}

void insertNode(ListT * list, int data) {
    // add new adjacent node to the end of the list
    NodeT * new = createNode(data);
    if(list->count == 0) {
        list->head = new;
    }
    else {
        list->tail->next = new;
    }
    list->tail = new;
    list->count++;
}

void deleteLastNode(ListT * list) {
    // delete last node
    if(list->count) {
        // list is not empty
        NodeT * temp = list->head;
        NodeT * prev = NULL;
        while(temp != list->tail) {
            prev = temp;
            temp = temp->next;
        }
        if(temp == list->head) {
            // delete the only node
            list->head = NULL;
        }
        else {
            prev->next = NULL;
        }
        list->tail = prev;
        free(temp);
        list->count --;
    }
}
void deleteList(ListT * list) {
    // delete all elements of the list
    while(list->tail) {
        deleteLastNode(list);
    }
}
void printAdjList(int N, ListT * AL) {
    // print adjacency lists
    printf("Adjacency list:\n");
    for(int i=0; i<N; i++) {
        printList(AL[i]);
    }
    new_line;
}
void printList(ListT list) {
    // print list
    NodeT * temp = list.head;
    while(temp) {
        printf("%c ",'A' + temp->data);
        temp = temp->next;
    }
    new_line;
}
