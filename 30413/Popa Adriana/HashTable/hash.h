#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define size 50

typedef struct cell
{
    char key[size];
    struct cell *next;
}NodeT;

NodeT *StudentsTable[size];
NodeT *item;
NodeT *item2;

NodeT *find(char key[size]);
void AddElement(char key[size]);
void del(char key[size]);
void listing();
