#ifndef HASH_TABLES_LIST_H

typedef struct node
{
    char * content;
    struct node * next;
} nodeT;

typedef struct list
{
    nodeT * head;
    nodeT * tail;
    int size;
} listT;

void addToList(listT *l, char * content);

#define HASH_TABLES_LIST_H

#endif //HASH_TABLES_LIST_H
