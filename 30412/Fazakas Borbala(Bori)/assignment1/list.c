//
// Created by Bori on 2/25/2020.
//

#include <stdlib.h>
#include <stdio.h>
#include "list.h"

list createList() {
    list newList;
    newList.first = NULL;
    newList.last = NULL;
    return newList;
}

void addFirst(list *myList, int value) {
    node *newNode = createNodeWithNext(value, myList->first);
    myList->first = newNode;
    if (myList->last == NULL) myList->last = myList->first;
}

void addLast(list *myList, int value) {
    if (myList->first == NULL) addFirst(myList, value);
    else {
        node *newNode = createNode(value);
        myList->last->next = newNode;
        myList->last = newNode;
    }
}

void deleteFirst(list *myList) {
    if (myList->first != NULL) {
        node *prevFirst = myList->first;
        myList->first = myList->first->next;
        free(prevFirst);
        if (myList->first == NULL) myList->last = NULL;
    }
}

void deleteLast(list *myList) {
    if (myList->last != NULL) {
        node *lastButOne = myList->first;
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
    node *curFirst;
    while (myList->first != NULL) {
        curFirst = myList->first;
        myList->first = myList->first->next;
        free(curFirst);
    }
    myList->last = NULL;
}

void deleteValue(list *myList, int value) {
    node *curNode = myList->first;
    node *prevNode = NULL;
    while (curNode != NULL) {
        if (curNode->data ==
            value) //remark that in all of the 3 cases prevNode is constant/it's value doesn't matter anymore
        {
            if (curNode == myList->first) //it remains null
            {
                deleteFirst(myList);
                curNode = myList->first;
            } else if (curNode == myList->last) //it doesn't matter anymore
            {
                deleteLast(myList);
                curNode = NULL;
            } else //it is constant
            {
                curNode = curNode->next;
                free(prevNode->next);
                prevNode->next = curNode;
            }
        } else {
            prevNode = curNode;
            curNode = curNode->next;
        }
    }
}

void printAll(list *myList, FILE *outFile) {
    if (myList->first == NULL) fprintf(outFile, "List is empty\n");
    else {
        node *curNode = myList->first;
        while (curNode != NULL) {
            fprintf(outFile, "%d ", curNode->data);
            curNode = curNode->next;
        }
        fprintf(outFile, "\n");
    }
}

void printFirstX(list *myList, int x, FILE *outFile) {
    if (myList->first == NULL) fprintf(outFile, "List is empty\n");
    else {
        int countPrintedElem = 0;
        node *curNode = myList->first;
        while (countPrintedElem < x && curNode != NULL) {
            fprintf(outFile, "%d ", curNode->data);
            curNode = curNode->next;
            countPrintedElem++;
        }
        fprintf(outFile, "\n");
    }
}

static node *
findLastButXthNode(node *curNode, int *curIndex, int x) //curIndex = index of curNode counted from the end of the list
// returns NULL if current Node is close to the a=end as the x'th, and a pointer to the xth otherwise
{
    if (curNode == NULL) {
        *curIndex = 0;
        return NULL;
    }
    int nextIndex;
    node *lastButXth;
    if ((lastButXth = findLastButXthNode(curNode->next, &nextIndex, x)) != NULL) {
        return lastButXth;
    } else {
        *curIndex = nextIndex + 1;
        if (*curIndex == x) return curNode;
        else return NULL;
    }
}

void printLastX(list *myList, int x, FILE *outFile) {
    if (myList->first == NULL) fprintf(outFile, "List is empty\n");
    else {
        int helper;
        node *startNode = findLastButXthNode(myList->first, &helper, x);
        if (startNode == NULL)
            startNode = myList->first; //if size of myList < x, then startNode is NULL --> all of the elements must be printed
        while (startNode != NULL) {
            fprintf(outFile, "%d ", startNode->data);
            startNode = startNode->next;
        }
        fprintf(outFile, "\n");
    }
}