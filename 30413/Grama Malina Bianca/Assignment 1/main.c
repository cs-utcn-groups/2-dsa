#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *next;
} NodeT;

NodeT *first, *last;

void initializeSll() {
    first = NULL;
    last = NULL;
}

void addLast(int data) {
    if (first == NULL) {
        first = (NodeT *) malloc(sizeof(NodeT));
        first->next = last;
        first->data = data;
        last = first;
    } else {
        NodeT *newElement = (NodeT *) malloc(sizeof(NodeT));
        last->next = newElement;
        newElement->next = NULL;
        newElement->data = data;
        last = newElement;
    }
}

void addFirst(int data) {
    if (first == NULL) {
        first = (NodeT *) malloc(sizeof(NodeT));
        first->next = last;
        first->data = data;
        last = first;
    } else {
        NodeT *newElement = (NodeT *) malloc(sizeof(NodeT));
        newElement->data = data;
        newElement->next = first;
        first = newElement;
    }
}

void removeElement(int data) {
    NodeT *currentElement = (NodeT *) malloc(sizeof(NodeT));
    *currentElement = *first;
    NodeT *previousElement = (NodeT *) malloc(sizeof(NodeT));
    *previousElement = *first;
    while (currentElement != NULL) {
        if (currentElement->data == data) {
            if (currentElement == first) {
                first = first->next;
            } else if (currentElement == last) {
                last = previousElement;
                last->next = NULL;
            } else {
                previousElement->next = currentElement->next;
            }
            previousElement = currentElement;
            currentElement = currentElement->next;
            free(previousElement);
            previousElement = currentElement;
        } else {
            previousElement = currentElement;
            currentElement = currentElement->next;
        }
    }
}

void removeFirst() {
    if (first != NULL) {
        first = first->next;
        free(first);
    }
}

void removeLast() {
    if (first != NULL) {
        NodeT *currentElement = first;
        NodeT *previousElement = first;
        while (currentElement != last) {
            previousElement = currentElement;
            currentElement = currentElement->next;
        }
        last = previousElement;
        last->next = NULL;
    }
}

void printSllData(FILE *g) {
    if (first == NULL) {
        fprintf(g, "List is empty!\n");
    } else {
        NodeT *currentElement = first;
        while (currentElement != NULL) {
            fprintf(g, "%d ", currentElement->data);
            currentElement = currentElement->next;
        }
        fprintf(g, "\n");
    }

}

void printFirst(int data, FILE *g) {
    if (first == NULL) {
        fprintf(g, "List is empty!\n");
    } else {
        NodeT *currentElement = first;
        for (int i = 0; i < data; i++) {
            if (currentElement != NULL) {
                fprintf(g, "%d ", currentElement->data);
                currentElement = currentElement->next;
            }
        }
        fprintf(g, "\n");
    }
}

void printLast(int data, FILE *g) {
    int count = 0;
    if (first == NULL) {
        fprintf(g, "List is empty!\n");
    } else {
        NodeT *currentElement = first;
        while (currentElement != NULL) {
            count++;
            currentElement = currentElement->next;
        }
    }

    NodeT *currentElement1 = first;
    for (int i = 0; i < count - data; i++) {
        if (currentElement1 != NULL) {
            currentElement1 = currentElement1->next;
        }
    }
    for (int i = count - data; i < count; i++) {
        if (currentElement1 != NULL) {
            fprintf(g, "%d ", currentElement1->data);
            currentElement1 = currentElement1->next;
        }
    }
    fprintf(g, "\n");
}

void removeAll() {
    NodeT *currentElement = first;
    while (currentElement != NULL) {
        first = first->next;
        free(currentElement);
        currentElement = first;
    }
}

int main() {

    FILE *f;
    f = fopen("input.dat", "r");
    FILE *g;
    g = fopen("output.dat", "w");
    initializeSll();
    char *strbuf = (char *) malloc(sizeof(char) * 200);
    while (fgets(strbuf, 200, f) != NULL) {
        if (strcmp(strbuf, "DF\n") == 0 || strcmp(strbuf, "DL\n") == 0 || strcmp(strbuf, "DOOM_THE_LIST\n") == 0 ||
            strcmp(strbuf, "PRINT_ALL\n") == 0) {
            if (strcmp(strbuf, "DF\n") == 0) {
                removeFirst();
            }
            if (strcmp(strbuf, "DL\n") == 0) {
                removeLast();
            }
            if (strcmp(strbuf, "DOOM_THE_LIST\n") == 0) {
                removeAll();
            }
            if (strcmp(strbuf, "PRINT_ALL\n") == 0) {
                printSllData(g);
            }
        } else {
            char *pch;
            pch = strtok(strbuf, " ");
            if (strcmp(pch, "AF") == 0) {
                pch = strtok(NULL, "\n");
                int value = atoi(pch);
                addFirst(value);
            }
            if (strcmp(pch, "AL") == 0) {
                pch = strtok(NULL, "\n");
                int value = atoi(pch);
                addLast(value);
            }
            if (strcmp(pch, "DE") == 0) {
                pch = strtok(NULL, "\n");
                int value = atoi(pch);
                removeElement(value);
            }
            if (strcmp(pch, "PRINT_F") == 0) {
                pch = strtok(NULL, "\n");
                int value = atoi(pch);
                printFirst(value, g);
            }
            if (strcmp(pch, "PRINT_L") == 0) {
                pch = strtok(NULL, "\n");
                int value = atoi(pch);
                printLast(value, g);
            }
        }
    }

    fclose(g);
    fclose(f);
    return 0;
}