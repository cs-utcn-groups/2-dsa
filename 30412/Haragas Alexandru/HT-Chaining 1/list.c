#include "list.h"
#include "io.h"
#include <stdlib.h>


nodeT * createNode(char * content)
{
    nodeT * n = (nodeT*) malloc(sizeof(nodeT));
    n->content = (char*) malloc(sizeof(char) * MAX_STRING_LENGTH);
    strcpy(n->content, content);
    n->next = NULL;
    return n;
}

listT addToList(listT l, char * content)
{
    if(l.size==0)
    {
        l.size++;
        l.head=(nodeT*)malloc(sizeof(nodeT));
        l.head->content=content;
        l.head->next=l.tail;
        l.tail=l.head;
    } else{
        nodeT* newNode=(nodeT*)malloc(sizeof(nodeT));
        newNode->next=NULL;
        newNode->content=content;
        l.tail->next=newNode;
        l.tail=newNode;
        l.size++;
    }
    return l;
}
