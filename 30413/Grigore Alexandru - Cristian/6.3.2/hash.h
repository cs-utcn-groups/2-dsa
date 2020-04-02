#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define B 10


typedef struct node{
    char name[30];
}NodeT;

typedef struct mapH{
    int flag;// flag=0 no data flag=1 data exists flag =2 data existed//
    NodeT *data;
}MapT;

MapT *Table;
void initialize();
int f(char *data);
void insertT(char *name);
void deleteT(char *name);
void findT(char *name);
void listData();
