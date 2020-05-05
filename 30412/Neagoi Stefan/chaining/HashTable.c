//
// Created by Stefan on 04/05/2020.
//
#include "header.h"

nodeT * createNode(char * content) {
    nodeT * n = (nodeT*) malloc(sizeof(nodeT));
    n->content = (char*) malloc(sizeof(char) * MAX_STRING_LENGTH);
    strcpy(n->content, content);
    n->next = NULL;
    return n;
}

void addToList(listT *list, char * content)
{

    nodeT *newItem = createNode(content);
    if (list->head == NULL)
    {

        list->head = newItem;
        list->tail = newItem;
        size++;

    }
    else
    {
            list->tail->next = newItem;
            list->tail = newItem;
            list->size++;

    }
}
void initHashTable(int N)
{
    size = N * INITIAL_HT_SIZE_FACTOR;
    hashTable = (listT*)malloc(sizeof(listT)*size);
    for (int i = 0; i < size; i++){
        hashTable[i].head = NULL;
        hashTable[i].tail = NULL;
    }

}

void insertElement(char * element)
{
    int index = hashFunction(element);

    nodeT *list = (nodeT*) hashTable[index].head;

    addToList(&hashTable[index], element);
}

int hashFunction(char * content)
{
   return strlen(content)%size;
}


void computeDistributionsPerBucket()
{


}

void printList(listT *list) {
    if(list->head == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        nodeT * currentElement = list->head;
        while(currentElement != NULL)
        {
            printf("%s ", currentElement->content);
            currentElement = currentElement->next;
        }
        printf("\n");
    }
}

void printHashTable() {
    for (int i = 0; i < size; i++){
        printList(&hashTable[i]);
    }
}


void writeToFile(int N)
{
    srand (time(NULL));
    FILE * f = getFileForInt(N);
    int i;
    for(i=0; i<N; i++)
    {
        fprintf(f,"%s\n",randString());
    }
    fclose(f);
}

char ** readFromFile(int N)
{
    char ** contents = (char**) malloc(sizeof(char*) * N);
    int i;

    for(i=0; i<N; i++)
    {
        *(contents + i) = (char*) malloc(sizeof(char) * (MAX_STRING_LENGTH +1) );
    }

    FILE * f = getFileForInt(N);

    for(i=0; i<N; i++)
    {
        fgets(*(contents+i), (MAX_STRING_LENGTH + 2),f);
    }

    return contents;
}

void printContentToConsole(char ** contents, int N)
{
    int i;
    for(i=0; i<N; i++)
    {
        puts(*(contents+i));
    }
}

char * randString()
{
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()_+{}:<>?|\[];'./,";
    char * str = (char*) malloc(sizeof(char) * (MAX_STRING_LENGTH));
    int i;

    for (i = 0; i < MAX_STRING_LENGTH-1; i++)
    {
        int key = rand() % (int) (sizeof(charset) - 1);
        str[i] = charset[key];
    }
    str[MAX_STRING_LENGTH - 1] = '\0';

    return str;
}

FILE * getFileForInt(int N)
{
    char * filename = (char*) malloc(sizeof(char)*12);
    return fopen(strcat(itoa(N,filename,10),".data"), "rw");
}

