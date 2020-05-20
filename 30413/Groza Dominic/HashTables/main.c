//In this problem I used Separate Chaining - each cell of hash table points to a linked list
//of records that have the same hash function value

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define B 100


typedef struct cell {
    char key[60];
    struct cell *next;
} NodeT;

NodeT *BucketTable[B];

NodeT *createNode(char *data,NodeT *p) {
    if (p) {
        strcpy(p->key, data);
        p->next = NULL;
    }

    return p;
}

int f(char *key) {
    int sum, len;
    sum = 0;
    len = strlen(key);
    for (int i = 0; i < len; i++) {
        sum += key[i];
    }
    printf("sum for %s is = %d\n",key,sum);
    return (sum % B);
}

void insert( char *data) {
    NodeT *p=(NodeT*)malloc(sizeof(NodeT));
    p = createNode(data,p);
    int h = f(data);
        if (BucketTable[h] == NULL) {
            //empty slot in HT
            BucketTable[h] = p;
            p->next = NULL;
        } else {//non-empty
            NodeT *ptr = BucketTable[h];
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = p;
            p->next = NULL;
        }
    }


void listHT( FILE *f) {
    NodeT *p = NULL;
    for (int i = 0; i < B; i++) {
        p = BucketTable[i];
        fprintf(f, "%d= ", i);
        while (p != NULL) {
            fprintf(f, "%s ", p->key);
            p = p->next;
        }
        fprintf(f, "\n");
    }
    fprintf(f, "\n");
}

NodeT *find(char *data) {
    int h = f(data);
    NodeT *p;
    p = BucketTable[h];
    while (p != NULL) {
        if (strcmp(data, p->key) == 0)
            return p;
        p = p->next;
    }
    return NULL;
}

void deleteItemFromHT( char *data) {
    NodeT *p=find(data);
    free(p);
}

int main() {
    FILE *f, *g;
    f = fopen("input.txt", "r");
    g = fopen("output.txt", "w");
    NodeT *HTable[B];
    char *instruction=(char*)malloc(sizeof(char)*25);
    while (fgets(instruction,25,f)){
        if (instruction[0]=='i'){
            strcpy(instruction,instruction+1);
            insert(instruction);
        }
        else  if  (instruction[0]=='d'){
                strcpy(instruction,instruction+1);
                deleteItemFromHT(instruction);
        }
        else  if (instruction[0]=='l'){
            listHT(g);
        }
        free(instruction);
    }
    fclose(f);
    fclose(g);
    return 0;
    }
