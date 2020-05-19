//
// Created by Bori on 4/29/2020.
//

#include "list.h"
#include "io.h"

nodeT * createNode(char * content)
{
    nodeT * n = (nodeT*) malloc(sizeof(nodeT));
    n->content = (char*) malloc(sizeof(char) * (MAX_STRING_LENGTH+1));
    strcpy(n->content, content);
    n->next = NULL;
    return n;
}

listT createList(){
    listT l;
    l.size=0;
    l.head=NULL;
    l.tail=NULL;
    return l;
}

void addToList(listT* l, char * content)
{
    nodeT *newNode = createNode(content);
    if(l->size>1) {
        l->tail->next = newNode;
        l->tail = newNode;
    }
    else{
        l->tail = newNode;
        l->head = newNode;
    }
    l->size++;
}
