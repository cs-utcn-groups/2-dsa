//
// Created by q on 3/5/2020.
//


#include "node.h"

NodeT * createNode(int data) {
    NodeT * newNode = (NodeT *)malloc(sizeof(NodeT));
    if(newNode) {
    newNode->key = data;
    newNode->prev = newNode->next = NULL;
    }
    return newNode;
}
NodeT * findNodeByKey(NodeT * curr, int x) {
    NodeT * temp = curr;
    while(temp && temp->key != x) {
        temp = temp->next;
    }
    return temp;
}
void printLastRec(FILE * fp, NodeT * curr, int x) {
    if(curr && x) {
        printLastRec(fp,curr->prev,x-1);
        fprintf(fp,"%d ",curr->key);
    }
}