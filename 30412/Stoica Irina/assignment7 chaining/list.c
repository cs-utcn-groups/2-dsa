#include "list.h"
#include "io.h"
#include "hashTable.h"

nodeT * createNode(char * content)
{
    nodeT * newNode = (nodeT*)malloc(sizeof(nodeT));
    newNode->content = (char*)malloc((MAX_STRING_LENGTH+1) * sizeof(char));
    strcpy(newNode->content, content);
    newNode->next = NULL;
    return newNode;
}

void addToList(listT * l, char * content)
{
    //! add last
    nodeT * newNode = createNode(content);
    l->sizeList++;
    if(l->head == NULL){
        l->head = newNode;
        l->tail = l->head;
    }
    else {
        l->tail->next = newNode;
        l->tail = newNode;
        newNode = l->tail;
    }
}