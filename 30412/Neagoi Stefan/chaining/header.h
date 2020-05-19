//
// Created by Stefan on 04/05/2020.
//

#ifndef CHAINING_HEADER_H
#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include <time.h>

#define MAX_STRING_LENGTH 64

static const float INITIAL_HT_SIZE_FACTOR = .33;

enum FILE
{
    _100 = 100,
    _500 = 500,
    _1000= 1000,
    _5000= 5000,
    _10000=10000,
    _25000=25000,
    _50000=50000,
    _100000=100000
};

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

listT * hashTable;
int size;

void addToList(listT *list, char * content);
int hashFunction(char * content);
void initHashTable(int N);
void insertElement(char * element);
void computeDistributionsPerBucket();
void printList(listT *list);
void printHash();
void printHashTable();
FILE * getFileForInt(int N);
char ** readFromFile(int N);
char * randString();
void printContentToConsole(char ** contents, int N);
void writeToFile(int N);

#define CHAINING_HEADER_H
#endif //CHAINING_HEADER_H
