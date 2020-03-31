#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_HASH 10000

typedef struct _LNODE
{
    char name[30];
    struct _LNODE *next;
}LNODE;

typedef struct _EL
{
    LNODE *first,*last;
}TABLE;

int getHASH(char *s)
{
    int sum=0;
    for(int i=0;i<strlen(s);++i)
        sum+=s[i];
    return sum%MAX_HASH;
}

void insertList(LNODE **first,LNODE **last,char *name) {
    if (*first == NULL)
    {
        (*first)=(LNODE*)malloc(sizeof(LNODE));
        strcpy((*first)->name,name);
        (*first)->next=NULL;
        *last=*first;
    } else
    {
        LNODE *newEl=(LNODE*)malloc(sizeof(LNODE));
        strcpy(newEl->name,name);
        newEl->next=NULL;
        (*last)->next=newEl;
        *last=newEl;
    }
}

void INSERT(char * s,TABLE *Hash_table){insertList(&Hash_table[getHASH(s)].first,&Hash_table[getHASH(s)].last,s);}

void printList(LNODE *first)
{
    LNODE *p=first;
    while (p)
    {
        printf("%s ",p->name);
        p=p->next;
    }
    printf("\n");
}

bool find ( char *name , TABLE * Hash)
{
    int index=getHASH(name);
    if(Hash[index].first)
    {
        LNODE *p=Hash[index].first;
        while (p) {
            if (!strcmp(p->name, name))
                return true;
            p=p->next;
        }
    }
    return false;
}

void DELETE (char *name,TABLE *Hash)/// covering all the cases
{
    int index=getHASH(name);
    if(Hash[index].first)
    {

        LNODE *p;
        while (Hash[index].first&&!strcmp(Hash[index].first->name,name))
        {
            p=Hash[index].first;
            Hash[index].first=Hash[index].first->next;
            free(p);
        }
        if(!Hash[index].first)
        {
            Hash[index].last=NULL;
            return;
        }
        p=Hash[index].first;
        while(p->next)
            if(!strcmp(p->next->name,name))
            {
                LNODE *q=p->next;
                p->next=p->next->next;
                free(q);
            }
        if(!p->next)
        {
            Hash[index].last=p;
            return;
        }
    }
}

void list(TABLE *Hash)
{
    printf("PRINTING THE ELEMENTS:\n");
    for(int i=0;i<MAX_HASH;++i)
        if(Hash[i].first)
            printList(Hash[i].first);
    printf("\n");
}

int main() {
    TABLE *Hash_table=(TABLE*)malloc(sizeof(TABLE)*MAX_HASH);
    for(int i=0;i<MAX_HASH;++i)Hash_table[i].first=Hash_table[i].last=NULL;
    FILE * f=fopen("input.dat","r");
    char *s=(char*)malloc(sizeof(char)*31);
    while (fscanf(f,"%s",s)!=EOF)
        switch (s[0]){
        case 'i': INSERT(s+1,Hash_table); break;
        case 'f':printf("%s\n",find(s+1,Hash_table)?"yes":"no");break;
        case 'd':DELETE(s+1,Hash_table);break;
        case 'l':list(Hash_table);break;
        default:printf("WRONG INPUT LINE!!\n");
    }

    return 0;
}
