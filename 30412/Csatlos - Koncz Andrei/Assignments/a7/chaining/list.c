//
// Created by csatl on 5/4/2020.
//


#include "list.h"
#include "io.h"
#include <stdlib.h>

nodeT * createNode(char * content)
{
    nodeT * n = (nodeT*) malloc(sizeof(nodeT));
    n->content = (char*) malloc(sizeof(char) * strlen(content) );
    strcpy(n->content, content);
    n->next = NULL;
    return n;
}

void addToList(listT l, char * content)
{
    //! add last
    nodeT * newElement = createNode(content);
    if(l.head == NULL)
    {
        l.head = newElement;
        l.tail = l.head;
    }
    else
    {
        l.tail->next = newElement;
        l.tail = newElement;
    }
}
