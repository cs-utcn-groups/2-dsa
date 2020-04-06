//
// Created by User on 04.04.2020.
//

#include "node.h"

NodeT *createNode(int content) {
    NodeT *newN = (NodeT *) malloc(sizeof(NodeT));
    newN->content = content;
    newN->next = NULL;
    return newN;
}
NodeL * createNodeforList(int key, int weight)
{
    NodeL *newNode=(NodeL*)malloc(sizeof(NodeL));
    newNode->key=(int*)malloc(2* sizeof(int));
    newNode->key[1]=key;
    newNode->key[2]=weight;
    newNode->next=NULL;
    return newNode;
}
void initializeList(ListT *L)
{
    L->first=L->last=NULL;
}
void addToList(int key, int weight,ListT *L)
{
    if(L->first==NULL) {


        L->first = (NodeL *) malloc(sizeof(NodeL));
        L->first->key[1] = key;
        L->first->key[2] = weight;
        L->first->next = L->last;
        L->last = L->first;
    }
    else
    {
        NodeL* newNode=createNodeforList(key,weight);
        L->last->next=newNode;
        L->last=newNode;
    }


}
