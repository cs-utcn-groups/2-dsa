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

void printList(listT l) {
    if(l.size) {
        nodeT *temp = l.head;
        while (temp) {
            printf("%s ", temp->content);
            temp = temp->next;
        }
        printf("\n");
    }
    else {
        printf("empty\n");
    }
}

void addToList(listT * l, char * content)
{
    nodeT * newNode = createNode(content);
    if(l->tail == NULL) {
        l->head = newNode;
    }
    else {
        if(find(l,content) != -1) {
            l->tail->next = newNode;
        }
    }
    l->tail = newNode;
    l->size++;
}

int find(listT * l, char * data) {
    int value = 0;
    nodeT * temp = l->head;
    while (temp) {
        if (strcmp(temp->content,data) == 0) {
            return value;
        }
        temp = temp->next;
        value++;
    }
    return -1;
}