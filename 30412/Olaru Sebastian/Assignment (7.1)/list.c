#include "list.h"
#include "io.h"

NodeT * createNode(char * content)
{
    NodeT * n = (NodeT*) malloc(sizeof(NodeT));
    n->content = (char*) malloc(sizeof(char) * MAX_STRING_LENGTH);
    strcpy(n->content, content);
    n->next = NULL;
    return n;
}

void addToList(ListT *l, char * content)
{   NodeT *newNode=createNode(content);
    if(l->head==NULL){
        l->head=newNode;
        l->tail=newNode;
    }
    else {
        l->tail->next = newNode;
        l->tail = newNode;
    }
}

void initList(ListT *l){
    l->head=l->tail=NULL;
}