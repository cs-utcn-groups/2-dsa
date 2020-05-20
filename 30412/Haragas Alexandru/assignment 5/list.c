//
// Created by Alex on 04.04.2020.
//

#include "list.h"


List *createList(int n, int *m) {
    List *firstElem = NULL, *lastElem = NULL;
    for (int i = 0; i < n; i++) {
        if (m[i] != 0) {
            if (firstElem == NULL) {
                firstElem = (List *) malloc(sizeof(List));
                firstElem->label = i;
                firstElem->val = m[i];
                firstElem->next = lastElem;
                lastElem = firstElem;
            } else {
                List *newElem = (List *) malloc(sizeof(List));
                newElem->next = NULL;
                newElem->label = i;
                newElem->val = m[i];
                lastElem->next = newElem;
                lastElem = newElem;
            }
        }
    }
    return firstElem;
}

void printList(int n, List **l) {
    printf("\nThe list is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        List *curElem = l[i];
        while (curElem != NULL) {
            printf("%d ", curElem->label);
            curElem = curElem->next;
        }
        printf("\n");
    }
    printf("\n");
}

void DFSList(int x, List **l, int *v) {
    v[x] = 1;
    printf("%d ", x);
    List *curElem = l[x];
    while (curElem != NULL) {
        if (v[curElem->label] == 0) {
            DFSList(curElem->label, l, v);
        }
        curElem = curElem->next;
    }
}

void BFSList(int x, List **l, int *v) {
    initializeStack();
    push(x);
    v[x] = 1;
    printf("BFS for list:\n");
    while (first != NULL) {
        int curNode = pop();
        List *curElem = l[curNode];
        printf("%d ", curNode);
        while (curElem != NULL) {
            if (v[curElem->label] == 0) {
                v[curElem->label] = 1;
                push(curElem->label);
            }
            curElem = curElem->next;
        }
    }
    printf("\n");
}


int **backMatrix(int n, List **l) {
    int **m = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        List *curElem = l[i];
        m[i] = (int *) malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            m[i][j] = 0;
            if (curElem != NULL) {
                if (curElem->label == j) {
                    m[i][j] = curElem->val;
                    curElem = curElem->next;
                }
            }
        }
    }
    return m;
}