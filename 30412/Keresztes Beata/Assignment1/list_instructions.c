//
// Created by q on 3/1/2020.
//

#include "list_instructions.h"
void initializeList() {
    head = NULL;
    tail = NULL;
}
void addFirst(int x) {
    NodeT * newNode = (NodeT *) malloc (sizeof(NodeT));
    newNode->data = x;
    if(head == NULL) {
        head = newNode;
        tail = head;
        newNode->next = NULL;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
}
void addLast(int x) {
    NodeT * newNode = (NodeT *) malloc(sizeof(NodeT));
    newNode->data = x;
    newNode->next = NULL;
    if(tail == NULL) {
        tail = newNode;
        head = tail;
        newNode->next = NULL;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}
void deleteFirst() {
    if(head != NULL) {
        NodeT *temp = head;
        head = temp->next;
        if(head == NULL) {
            tail = head;
        }
        free(temp);
    }
}
void deleteLast() {
    if(head != NULL) {
        if(head == tail) {
            free(head);
            head = NULL;
            tail = NULL;
        }
        else {
            NodeT *temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            temp->next = NULL;
            free(tail);
            tail = temp;
        }
    }
}
void removeAllElements() {
    NodeT * temp = head;
    while(temp != NULL) {
        head = head->next;
        free(temp);
        temp = head;
    }
    tail = NULL;
}
void delete(int x) {
    NodeT *currentNode = head;
    NodeT *previousNode = head;

    while (currentNode != NULL) {

        if (currentNode->data == x) {
            if(currentNode == head) {
                deleteFirst();
                currentNode = head;
            }
            else {
                if (currentNode == tail) {
                    deleteLast();
                    currentNode = tail;
                } else {
                    previousNode->next = currentNode->next;
                    free(currentNode);
                    currentNode = previousNode->next;
                }
            }
        } else {
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
    }
}

FILE * openFile(char * fileName, char * openMode) {
    FILE *fp = fopen(fileName, openMode);
    if (fp == NULL) {
        fprintf(stderr, "File %s was not found.\n",fileName);
        exit(EXIT_FAILURE);
    }
    return fp;
}

void printAll(FILE * fp) {
    NodeT * temp = head;
    if(head == NULL) {
        fprintf(fp,"Empty list.\n");
        return;
    }
    while(temp != NULL) {
        fprintf(fp,"%d ",temp->data);
        temp = temp->next;
    }
    fprintf(fp,"\n");
}
void printFirst(FILE *fp, int x) {
    NodeT * temp = head;
    if(head == NULL) {
        fprintf(fp,"Empty list.\n");
        return;
    }
    while(temp != NULL && x) {
        fprintf(fp,"%d ",temp->data);
        x--;
        temp = temp->next;
    }
    fprintf(fp,"\n");
}
void printLast(FILE * fp, int x) {
    NodeT * temp = head;
    if(head == NULL) {
        fprintf(fp,"Empty list.\n");
        return;
    }
//traverse list and count the number of nodes
    int noOfNodes = 0;
    while(temp != NULL) {
        noOfNodes++;
        temp = temp->next;
    }
    temp = head;
    while(temp != NULL && noOfNodes > x) {
        temp = temp->next;
        noOfNodes--;
    }
    //prints the remaining x nodes, or all of them if noOfNodes <= x
    while(temp != NULL && noOfNodes) {
        fprintf(fp,"%d ",temp->data);
        temp = temp->next;
        noOfNodes--;
    }
    fprintf(fp,"\n");
}