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
        nodeT *newNode = createNode(content);
        l->size++;
        if (l->head == NULL) {
            l->head = newNode;
            l->tail = l->head;
        } else {
            l->tail->next = newNode;
        }
        l->tail = newNode;
}

void printList(listT l) {
    if (l.head == NULL) {
        printf("Empty bucket \n");
    } else {
        nodeT *current = l.head;
        while(current) {
            printf("%s ", current->content);
            current = current->next;
        }
    }
    printf("\n");
}
