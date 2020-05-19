#include "list.h"
#include "io.h"
#include<string.h>

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
    nodeT * newNode = createNode(content);

    if(l->head == NULL)
        l->head = newNode;
    else
        l->tail->next = newNode;
    l->tail = newNode;
}

int checkIfExists(listT l, char * content)
{
    if(l.head == NULL)
        return 0;
    nodeT * node=l.head;
    while(strcmp(node->content,content)!=0)
    {
        node = node->next;
        if(node==NULL)
            break;
    }
    if(node==NULL)
        return 0;
    return 1;
}
