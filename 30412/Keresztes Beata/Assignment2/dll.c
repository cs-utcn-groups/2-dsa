//
// Created by q on 3/5/2020.
//

#include "dll.h"

DLListT * createEmptyList() {
    DLListT * newList = (DLListT *)malloc(sizeof(DLListT));
    if(newList) {
        newList->count = 0;
        newList->head = newList->tail = NULL;
    }
    return newList;
}

void freeList(DLListT * listPtr) {
    NodeT * temp = listPtr->head;
    while(temp) {
        listPtr->head = listPtr->head->next;
        free(temp);
        temp = listPtr->head;
    }
}

void addFirst(DLListT * listPtr, int x) {
    NodeT * newNode = createNode(x);
    if(listPtr->head == NULL) {
        //empty list
        listPtr->tail = newNode;
    }
    else {
        listPtr->head->prev = newNode;
    }
    newNode->next = listPtr->head;
    listPtr->head = newNode;
    listPtr->count++;
}

void addLast(DLListT * listPtr, int x) {
    NodeT * newNode = createNode(x);
    if(listPtr->tail == NULL) {
        //empty list
        listPtr->head = newNode;
    }
    else {
        listPtr->tail->next = newNode;
    }
    newNode->prev = listPtr->tail;
    listPtr->tail = newNode;
    listPtr->count++;
}

void deleteFirst(DLListT * listPtr) {
    NodeT * temp = listPtr->head;
    if(listPtr->head) {
        if(listPtr->count == 1) {
            //deleting the last node
            listPtr->tail = NULL;
        }
        else {
            temp->next->prev = NULL;
        }
        listPtr->head = temp->next;
        listPtr->count--;
        free(temp);
    }
}

void deleteLast(DLListT * listPtr) {
    NodeT * temp = listPtr->tail;
    if(listPtr->tail) {
        if(listPtr->count == 1) {
            //deleting the last node
            listPtr->head = NULL;
        }
        else {
            temp->prev->next = NULL;
        }
        listPtr->tail = temp->prev;
        free(temp);
        listPtr->count--;
    }
}

void doomTheList(DLListT * listPtr) {
    while(listPtr->head) {
       deleteFirst(listPtr);
    }
    listPtr->count = 0;
}

void deleteByKey(DLListT * listPtr, int x) {
    NodeT * temp = findNodeByKey(listPtr->head, x);
   //delete all occurrences of x
    while(temp) {
        if(temp == listPtr->head) {
            deleteFirst(listPtr);
        }
        else {
            if (temp == listPtr->tail) {
                deleteLast(listPtr);
            } else {
                temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
                free(temp);
                listPtr->count--;
            }
        }
        temp = findNodeByKey(temp->next,x);
    }
}

void printList(FILE * fp, DLListT * listPtr) {
    NodeT * temp = listPtr->head;
    while(temp) {
        fprintf(fp,"%d ",temp->key);
        temp = temp->next;
    }
    fprintf(fp,"\n");
}
void printFirst(FILE * fp, DLListT * listPtr, int x) {
    if(listPtr->head) {
        NodeT *temp = listPtr->head;
        while (temp && x) {
            fprintf(fp, "%d ", temp->key);
            temp = temp->next;
            x--;
        }
        fprintf(fp, "\n");
    }
    else {
        fprintf(fp," empty list\n");
    }
}

void printLast(FILE * fp, DLListT * listPtr, int x) {
    if(listPtr->tail) {
        printLastRec(fp, listPtr->tail,x);
        fprintf(fp,"\n");
    }
    else {
        fprintf(fp," empty list\n");
    }
}