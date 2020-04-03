//
// Created by Bori on 2/25/2020.
//

#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "edge.h"

list createList() {
    list newList;
    newList.first = NULL;
    newList.last = NULL;
    return newList;
}

void addFirst(list *myList, int endPoint, int length) {
    edge *newedge = createedgeWithNext(endPoint, length, myList->first);
    myList->first = newedge;
    if (myList->last == NULL) myList->last = myList->first;
}

void addLast(list *myList, int endPoint, int length) {
    if (myList->first == NULL) addFirst(myList, endPoint, length);
    else {
        edge *newedge = createedge(endPoint, length);
        myList->last->next = newedge;
        myList->last = newedge;
    }
}

void deleteFirst(list *myList) {
    if (myList->first != NULL) {
        edge *prevFirst = myList->first;
        myList->first = myList->first->next;
        free(prevFirst);
        if (myList->first == NULL) myList->last = NULL;
    }
}

void deleteLast(list *myList) {
    if (myList->last != NULL) {
        edge *lastButOne = myList->first;
        if (myList->first != myList->last) {
            while (lastButOne->next->next != NULL) lastButOne = lastButOne->next;
            free(myList->last);
            myList->last = lastButOne;
            lastButOne->next = NULL;
        } else {
            free(myList->last);
            myList->last = NULL;
            myList->first = NULL;
        }
    }
}

void deleteAll(list *myList) {
    edge *curFirst;
    while (myList->first != NULL) {
        curFirst = myList->first;
        myList->first = myList->first->next;
        free(curFirst);
    }
    myList->last = NULL;
}

void deleteValue(list *myList, int endPoint) {
    edge *curedge = myList->first;
    edge *prevedge = NULL;
    while (curedge != NULL) {
        if (curedge->endPoint ==
            endPoint)  //remark that in all of the 3 cases prevedge is constant/it's value doesn't matter anymore
        {
            if (curedge == myList->first) //it remains null
            {
                deleteFirst(myList);
                curedge = myList->first;
            } else if (curedge == myList->last) //it doesn't matter anymore
            {
                deleteLast(myList);
                curedge = NULL;
            } else //it is constant
            {
                curedge = curedge->next;
                free(prevedge->next);
                prevedge->next = curedge;
            }
        } else {
            prevedge = curedge;
            curedge = curedge->next;
        }
    }
}

void printAllList(list *myList, FILE *outFile) {
    if (myList->first == NULL) fprintf(outFile, "List is empty\n");
    else {
        edge *curedge = myList->first;
        while (curedge != NULL) {
            fprintf(outFile, "(%d, %d)", curedge->endPoint, curedge->length);
            curedge = curedge->next;
        }
        fprintf(outFile, "\n");
    }
}

void printFirstX(list *myList, int x, FILE *outFile) {
    if (myList->first == NULL) fprintf(outFile, "List is empty\n");
    else {
        int countPrintedElem = 0;
        edge *curedge = myList->first;
        while (countPrintedElem < x && curedge != NULL) {
            fprintf(outFile, "(%d, %d)", curedge->endPoint, curedge->length);
            curedge = curedge->next;
            countPrintedElem++;
        }
        fprintf(outFile, "\n");
    }
}

static edge *
findLastButXthedge(edge *curedge, int *curIndex, int x) //curIndex = index of curedge counted from the end of the list
// returns NULL if current edge is close to the a=end as the x'th, and a pointer to the xth otherwise
{
    if (curedge == NULL) {
        *curIndex = 0;
        return NULL;
    }
    int nextIndex;
    edge *lastButXth;
    if ((lastButXth = findLastButXthedge(curedge->next, &nextIndex, x)) != NULL) {
        return lastButXth;
    } else {
        *curIndex = nextIndex + 1;
        if (*curIndex == x) return curedge;
        else return NULL;
    }
}

void printLastX(list *myList, int x, FILE *outFile) {
    if (myList->first == NULL) fprintf(outFile, "List is empty\n");
    else {
        int helper;
        edge *startedge = findLastButXthedge(myList->first, &helper, x);
        if (startedge == NULL)
            startedge = myList->first; //if size of myList < x, then startedge is NULL --> all of the elements must be printed
        while (startedge != NULL) {
            fprintf(outFile, "(%d, %d)", startedge->endPoint, startedge->length);
            startedge = startedge->next;
        }
        fprintf(outFile, "\n");
    }
}