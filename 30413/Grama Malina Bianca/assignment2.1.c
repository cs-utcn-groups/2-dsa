#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    struct node *next;
    struct node *prev;
    int val;
} NodeDll;

NodeDll *initializeSentinel() {
    NodeDll *sentinel = (NodeDll *) malloc(sizeof(NodeDll));
    sentinel->next = sentinel;
    sentinel->prev = sentinel;
    return sentinel;
}

void addFirst(NodeDll *sentinel, int data) {
    NodeDll *newNode;
    newNode = (NodeDll *) malloc(sizeof(NodeDll));
    if (newNode == NULL)
        return;
    newNode->next = sentinel->next;
    newNode->prev = sentinel;
    newNode->val = data;
    sentinel->next->prev = newNode;
    sentinel->next = newNode;
}

void addLast(NodeDll *sentinel, int data) {
    NodeDll *newNode;
    newNode = (NodeDll *) malloc(sizeof(NodeDll));
    if (newNode == NULL)
        return;
    newNode->prev = sentinel->prev;
    newNode->next = sentinel;
    newNode->val = data;
    sentinel->prev->next = newNode;
    sentinel->prev = newNode;
}

void printDllist(FILE *g, NodeDll *sentinel) {
    NodeDll *node;
    if (sentinel == NULL || sentinel->next == sentinel)
        return;
    node = sentinel->next;
    do {
        fprintf(g, "%d ", node->val);
        node = node->next;
    } while (node != sentinel);
    fprintf(g,"\n");
}

void removeAll(NodeDll *sentinel) {
    NodeDll *currentElement = sentinel->next;
    while (currentElement != sentinel) {
        sentinel->next = sentinel->next->next;
        currentElement->next->prev = sentinel;
        free(currentElement);
        currentElement = sentinel->next;
    }
}

void deleteFirst(NodeDll *sentinel) {
    NodeDll *currentNode = sentinel->next;

    if (currentNode != sentinel) {
        sentinel->next = sentinel->next->next;
        free(currentNode);
        currentNode = sentinel->next;
        currentNode->prev = sentinel;
    }
}

void deleteLast(NodeDll *sentinel) {
    struct node *NodeToDel;
        NodeToDel = sentinel->prev;
        sentinel->prev = sentinel->prev->prev;
        sentinel->prev->next = sentinel;
        free(NodeToDel);

}

void deleteNode(NodeDll *sentinel, int data) {
    NodeDll *currentNode = sentinel->next;
    while (currentNode != sentinel) {
        if (currentNode->val == data) {
            if (currentNode == sentinel->next) {
                sentinel->next = sentinel->next->next;
                free(currentNode);
                currentNode = sentinel->next;
                currentNode->prev = sentinel;
            } else if (currentNode == sentinel->prev) {
                sentinel->prev = currentNode->prev;
                currentNode->prev->next = sentinel;
                free(currentNode);
                currentNode = sentinel;
            } else {
                currentNode->prev->next = currentNode->next;
                currentNode->next->prev = currentNode->prev;
                free(currentNode);
                currentNode = currentNode->prev->next;
            }
        } else {
            currentNode = currentNode->next;
        }
    }
}

void printFirst(FILE *g, NodeDll *sentinel, int data) {
    NodeDll *node;
    if (sentinel == NULL || sentinel->next == sentinel)
        return;
    node = sentinel->next;
    for (int i = 0; i < data && node != sentinel; i++) {
        fprintf(g, "%d ", node->val);
        node = node->next;
    }
    fprintf(g, "\n");
}

int countElements(NodeDll *sentinel) {
    int count = 0;
    NodeDll *currentNode = sentinel->next;
    while (currentNode != sentinel) {
        count++;
        currentNode = currentNode->next;
    }
    return count;
}

void printLast(FILE *g, NodeDll *sentinel, int data) {
    NodeDll *node;
    if (sentinel->prev == sentinel) {
        fprintf(g, "List is empty!");
    }
    if (data <= countElements(sentinel)) {
        node = sentinel->prev;
        for (int i = 0; i < data - 1 && node != sentinel; i++) {
            node = node->prev;
        }
        for (int j = 0; j < data; j++) {
            fprintf(g, "%d ", node->val);
            node = node->next;
        }
        fprintf(g, "\n");
    } else {
        node = sentinel->next;
        for (int j = 0; j < countElements(sentinel); j++) {
            fprintf(g, "%d ", node->val);
            node = node->next;
        }
        fprintf(g, "\n");
    }

}

int main() {
    NodeDll *sentinel = initializeSentinel();
    FILE *f;
    f = fopen("input.dat", "r");
    FILE *g;
    g = fopen("output.dat", "w");
    char *strbuf = (char *) malloc(sizeof(char) * 200);
    while (fgets(strbuf, 200, f) != NULL) {
        if (strcmp(strbuf, "DF\n") == 0 || strcmp(strbuf, "DL\n") == 0 || strcmp(strbuf, "DOOM_THE_LIST\n") == 0 ||
            strcmp(strbuf, "PRINT_ALL\n") == 0) {
            if (strcmp(strbuf, "DF\n") == 0) {
                deleteFirst(sentinel);
            }
            if (strcmp(strbuf, "DL\n") == 0) {
                deleteLast(sentinel);
            }
            if (strcmp(strbuf, "DOOM_THE_LIST\n") == 0) {
                removeAll(sentinel);
            }
            if (strcmp(strbuf, "PRINT_ALL\n") == 0) {
                printDllist(g,sentinel);
            }
        } else {
            char *pch;
            pch = strtok(strbuf, " ");
            if (strcmp(pch, "AF") == 0) {
                pch = strtok(NULL, "\n");
                int value = atoi(pch);
                addFirst(sentinel, value);
            }
            if (strcmp(pch, "AL") == 0) {
                pch = strtok(NULL, "\n");
                int value = atoi(pch);
                addLast(sentinel, value);
            }
            if (strcmp(pch, "DE") == 0) {
                pch = strtok(NULL, "\n");
                int value = atoi(pch);
                deleteNode(sentinel,value);
            }
            if (strcmp(pch, "PRINT_F") == 0) {
                pch = strtok(NULL, "\n");
                int value = atoi(pch);
                printFirst(g,sentinel,value);
            }
            if (strcmp(pch, "PRINT_L") == 0) {
                pch = strtok(NULL, "\n");
                int value = atoi(pch);
                printLast(g,sentinel,value);
            }
        }
    }

    fclose(g);
    fclose(f);
    return 0;
}