//
// Created by Bori on 2/25/2020.
//

#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include <string.h>

dlList createDLList() {
    dlList newdlList;
    newdlList.sentinel = createNodeWithSelfReference("");
    return newdlList;
}

void addFirst(dlList *mydlList, char *value) {
    node *newNode = createNode(value, mydlList->sentinel, mydlList->sentinel->next);
    mydlList->sentinel->next->prev = newNode;
    mydlList->sentinel->next = newNode;
}

void addLast(dlList *mydlList, char *value) {
    node *newNode = createNode(value, mydlList->sentinel->prev, mydlList->sentinel);
    mydlList->sentinel->prev->next = newNode;
    mydlList->sentinel->prev = newNode;
}

void deleteFirst(dlList *mydlList) {
    if (mydlList->sentinel->next != mydlList->sentinel) {
        node *curFirst = mydlList->sentinel->next;
        mydlList->sentinel->next = mydlList->sentinel->next->next;
        mydlList->sentinel->next->prev = mydlList->sentinel;
        free(curFirst);
    }
}

char *popFirst(dlList *mydlList) {
    if (mydlList->sentinel->next != mydlList->sentinel) {
        node *curFirst = mydlList->sentinel->next;
        mydlList->sentinel->next = mydlList->sentinel->next->next;
        mydlList->sentinel->next->prev = mydlList->sentinel;
        return curFirst->data;
    } else return NULL;
}

void deleteLast(dlList *mydlList) {
    if (mydlList->sentinel->prev != mydlList->sentinel) {
        node *curLast = mydlList->sentinel->prev;
        mydlList->sentinel->prev = mydlList->sentinel->prev->prev;
        mydlList->sentinel->prev->next = mydlList->sentinel;
        free(curLast);
    }
}

void deleteAll(dlList *mydlList) {
    node *curFirst;
    while (mydlList->sentinel->next != mydlList->sentinel) {
        curFirst = mydlList->sentinel->next;
        mydlList->sentinel->next = mydlList->sentinel->next->next;
        free(curFirst);
    }
    mydlList->sentinel->prev = mydlList->sentinel;
}

void deleteValue(dlList *mydlList, char *value) {
    node *curNode = mydlList->sentinel->next;
    node *prevNode = mydlList->sentinel;
    while (curNode != mydlList->sentinel) {
        if (strcmp(curNode->data,
                   value)) //remark that in all of the 3 cases prevNode is constant/it's value doesn't matter anymore
        {
            prevNode->next = curNode->next;
            curNode->next->prev = prevNode;
            free(curNode);
            curNode = prevNode->next;
        } else {
            prevNode = curNode;
            curNode = curNode->next;
        }
    }
}

void printAll(dlList *mydlList, FILE *outFile) {
    if (mydlList->sentinel->next == mydlList->sentinel) fprintf(outFile, "List is empty\n");
    else {
        node *curNode = mydlList->sentinel->next;
        while (curNode != mydlList->sentinel) {
            fprintf(outFile, "%s ", curNode->data);
            curNode = curNode->next;
        }
        fprintf(outFile, "\n");
    }
}

void printFirstX(dlList *mydlList, int x, FILE *outFile) {
    if (mydlList->sentinel->next == mydlList->sentinel) fprintf(outFile, "List is empty\n");
    else {
        int countPrintedElem = 0;
        node *curNode = mydlList->sentinel->next;
        while (countPrintedElem < x && curNode != mydlList->sentinel) {
            fprintf(outFile, "%s ", curNode->data);
            curNode = curNode->next;
            countPrintedElem++;
        }
        fprintf(outFile, "\n");
    }
}


static void printLastX_recusive(node *curNode, node *sentinel, int x, FILE *outfile) {
    if (curNode != sentinel) {
        if (x == 1) {
            fprintf(outfile, "%s ", curNode->data);
        } else {
            printLastX_recusive(curNode->prev, sentinel, x - 1, outfile);
            fprintf(outfile, "%s ", curNode->data);
        }
    }
}

void printLastX(dlList *mydlList, int x, FILE *outFile) {
    if (mydlList->sentinel->prev == mydlList->sentinel) {
        fprintf(outFile, "List is empty\n");
    } else {
        printLastX_recusive(mydlList->sentinel->prev, mydlList->sentinel, x, outFile);
        fprintf(outFile, "\n");
    }
}