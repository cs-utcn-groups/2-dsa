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

void addToList(listT *l, char * content)
{
    //! add last

    if(l->head == NULL){
        l->head = createNode(content);
        l->tail = l->head;
        l->size = 1;
    }else{
        nodeT * newNode = createNode(content);
        l->tail->next = newNode;
        l->tail = newNode;
        l->size++;
    }
}
