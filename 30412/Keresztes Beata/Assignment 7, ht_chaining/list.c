//
// Created by q on 5/1/2020.
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
    //! add last
    nodeT * newNode = createNode(content);
    if(l->tail == NULL) {
        // empty slot
        l->head = newNode;
    }
    else {
        if(find(l,content) != -1) {
            // check if element is already present in the list
            l->tail->next = newNode;
        }
    }
    l->tail = newNode;
    l->size++;
}

int find(listT * l, char * data) {
    // find element in list
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