#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define B 11
const int MAX_LENGTH=200;
typedef struct cell
{
    char key[60];
    struct cell *next;
} NodeT;
NodeT *BucketTable[B];
void initializeHash()
{
    for(int i=0; i<B; i++)
        BucketTable[i]=NULL;
}
int f(char * key)
{
    int sum, len;
    sum = 0;
    len = strlen(key);
    for (int i = 0; i < len; i++)
        sum += key[ i ];
    return(sum % B);
}
void insert(char * key)
{
    int h=f(key);
    NodeT * newElement = malloc(sizeof(NodeT));
    if(newElement==NULL)
    {
        return;
    }
    strcpy(newElement->key,key);
    newElement->next=NULL;
    if (BucketTable[h]==NULL)
    {
        BucketTable[h]=newElement;
    }
    else
    {
        NodeT * previous=BucketTable[h];
        while(previous)
        {
            if(previous->next==NULL)
            {
                previous->next=newElement;
                break;
            }
            previous=previous->next;
        }
    }
}
void find(char * key)
{
    int value=f(key);
    int ok=0;
    NodeT * p=(NodeT*)malloc(sizeof(NodeT));
    p=BucketTable[value];
    while(p!=NULL)
    {
        if(strcmp(p->key,key)==0)
            ok=1;
        p=p->next;
    }
    if(ok==1)
        printf("Element %s was found on position %d.\n",key,value);
    else
        printf("Element %s was not found.\n",key);

}
void deleteElement(char * key)
{
    int h=f(key);
    int k=0;
    NodeT * p=(NodeT*)malloc(sizeof(NodeT)*MAX_LENGTH);
    p=BucketTable[h];
    if(strcmp(key,p->key)==0)
    {
        BucketTable[h]=p->next;
        k=1;
    }
    else
    {
        NodeT *aux=NULL;
        while(p!=NULL)
        {
            if(strcmp(p->key,key)==0)
            {
                aux->next=p->next;
                k=1;
            }

            aux=p;
            p=p->next;

        }
    }
    if(k==1)
    {
        printf("Element %s was found on position %d and was deleted.\n",key,h);
    }
    else printf("Element %s was not found.\n",key);
}
void print()
{
    NodeT * p;
    for (int i = 0; i < B; i++)
        if (BucketTable[ i ] != NULL)
        {
            printf("Bucket for hash value %d ", i);
            p =BucketTable[ i ];
            if(p->key!=NULL)
                while(p!=NULL)
                {
                    printf("%s ",p->key);
                    p = p->next;
                }
            else
                printf("no value");
            printf("\n");
        }

}
void readFile(FILE * f)
{
    char * array=(char*)malloc(sizeof(char)*MAX_LENGTH);
    char letter;
    while(fgets(array,MAX_LENGTH,f))
    {
        array[strlen(array)-1]='\0';
        letter=array[0];
        strtok(array,",");
        array=strtok(NULL," ");
        if(letter=='i')
            insert(array);
        if(letter=='f')
            find(array);
        if(letter=='d')
            deleteElement(array);
    }
}
int main()
{
    FILE * f=fopen("input.dat","r");
    initializeHash();
    readFile(f);
    print();
}
