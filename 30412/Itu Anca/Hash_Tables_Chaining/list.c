//
// Created by Anca on 5/2/2020.
//

#include "list.h"
#include "io.h"

nodeT * createNode(char * content)
{
    nodeT * n = (nodeT*) malloc(sizeof(nodeT));
    n->content = (char*) malloc(sizeof(char) * MAX_STRING_LENGTH);
    strcpy(n->content, content);
    n->next = NULL;
    return n;
}

void addToList(listT * l, char * content)
{
    if(l->head == NULL){
        l->head = createNode(content);
        l->tail = l->head;
        l->size = 1;
    }
    else{
        nodeT * newElement = createNode(content);
        l->tail->next = newElement;
        l->tail = newElement;
        l->size = l->size + 1;
    }
    //! add last
}

void printListData(listT l){
    if(l.head == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        nodeT * currentElement = l.head;
        while(currentElement != NULL)
        {
            printf("%s ", currentElement->content);
            currentElement = currentElement->next;
        }
        printf("\n");
    }
}

