#include "list.h"
#include "io.h"

nodeT *createNode(char *content) {
    nodeT *newElement = (nodeT *) malloc(sizeof(nodeT));
    newElement->content = (char *) malloc(sizeof(char) * MAX_STRING_LENGTH);
    strcpy(newElement->content, content);
    newElement->next = NULL;
    return newElement;
}

void addToList(listT *l, char *content) {
    nodeT *newElement = createNode(content);
    if (l->head == NULL) {
        l->head = newElement;
        l->tail = newElement;
        l->size = 1;
    } else {
        l->tail->next = newElement;
        l->tail = newElement;
        l->size++;
    }
}
