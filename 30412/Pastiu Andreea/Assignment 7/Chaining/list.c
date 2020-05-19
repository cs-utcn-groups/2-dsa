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

void addToList(listT* l, char * content)
{
    nodeT *element = createNode(content);
    if (l->head == NULL)
    {
        element->next = NULL;
        l->head = element;
        l->tail = element;
    }
    else
    {
        l->tail->next = element;
        l->tail = element;
        l->tail->next = NULL;
    }
    l->size++;
}
