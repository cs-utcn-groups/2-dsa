#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef  struct _LIST {
    int data;
    struct _LIST *next,*prev;
}LIST;

typedef struct  _SENTINEL{
    LIST *first,*last;
}SENTINEl;

FILE *g;

SENTINEl *Sentinel=NULL;

void AL(int Value){
    if(Sentinel == NULL)
    {
        return;;
    }
    if(Sentinel->first == NULL)
    {
        Sentinel->first=malloc(sizeof(LIST));
        Sentinel->first->data=Value;
        Sentinel->first->next=NULL;
        Sentinel->first->prev=NULL;
        Sentinel->last=Sentinel->first;
    } else
    {
        LIST * Node=malloc(sizeof(LIST));
        Sentinel->last->next=Node;
        Node->data=Value;
        Node->next=NULL;
        Node->prev=Sentinel->last;
        Sentinel->last=Node;
    }
}


void AF(int Value)
{
    if(Sentinel == NULL)
    {
        return;
    }
    if(Sentinel->first == NULL)
    {
        Sentinel->first=(LIST*)malloc(sizeof(LIST));
        Sentinel->first->data=Value;
        Sentinel->first->next=NULL;
        Sentinel->first->prev=NULL;
        Sentinel->last=Sentinel->first;
    } else
    {
        LIST * Node= malloc(sizeof(LIST));
        Node->data=Value;
        Node->prev=NULL;
        Node->next=Sentinel->first;
        Sentinel->first->prev=Node;
        Sentinel->first=Node;
    }
}

void DF(){
    if(Sentinel == NULL || Sentinel->first == NULL)
    {
        return;
    }
    if(Sentinel->first->next == NULL)
    {
        free(Sentinel->first);
        Sentinel->first=Sentinel->last=NULL;
    } else
    {
        LIST *Node=Sentinel->first;
        Sentinel->first=Sentinel->first->next;
        free(Node);
        Sentinel->first->prev=NULL;
    }
}


void DL(){
    if(Sentinel == NULL || Sentinel->first == NULL)
    {
        return;
    }
    if(Sentinel->first->next == NULL)
    {
        free(Sentinel->first);
        Sentinel->first=Sentinel->last=NULL;
    } else{
        LIST *Node= Sentinel->last;
        Sentinel->last=Node->prev;
        free(Node);
        Sentinel->last->next=NULL;
    }
}

void DE(int Value){
    if(Sentinel == NULL || Sentinel->first == NULL)
    {
        return;
    }
    if(Sentinel->first->next == NULL)
    {
        free(Sentinel->first);
        Sentinel->first=Sentinel->last=NULL;
    } else {
        LIST *p=Sentinel->first;
        while(p && p->data==Value)
        {
            DF();
            p=Sentinel->first;
        }
        p=p->next;
        if(Sentinel->first == NULL)
        {
            Sentinel->last=NULL;
        }

        while(p)
        {

            if(p->data==Value)
            {

                LIST *q=p;
                p->prev->next=p->next;
                p->next->prev=p->prev;
                p=p->next;
                if(q==Sentinel->last)
                    Sentinel->last=q->prev;
                free(q);
            }
            if(p)
                p=p->next;
        }


    }
}

void PRINT_ALL(){
    LIST *p=Sentinel->first;
    while(p)
    {
        fprintf(g,"%d ",p->data);
        p=p->next;
    }
    fprintf(g,"\n");

}

void PRINT_F(int Value){
    LIST *p=Sentinel->first;
    for(int i=0;p && i<Value;++i)
    {
        fprintf(g,"%d ",p->data);
        p=p->next;
    }
    fprintf(g,"\n");
}

int ElCount()
{
    LIST *p=Sentinel->first;
    int i=0;
    while (p)
    {
        p=p->next;
        ++i;
    }
    return i;
}

void PRINT_L(int data)
{
    int nr=ElCount();
    if(data>nr)
    {
        PRINT_ALL();
    } else
    {
        LIST *p=Sentinel->first;
        for(int i=0;i<nr-data;++i)
        {
            p=p->next;
        }
        while(p)
        {
            fprintf(g,"%d ",p->data);
            p=p->next;

        }
    }
    fprintf(g,"\n");

}

void DOOM_THE_LIST( ){
    LIST *Node=Sentinel->first;
    while(Node)
    {
        Sentinel->first=Sentinel->first->next;
        free(Node);
        Node=Sentinel->first;
    }

}



int main() {
    Sentinel = malloc(sizeof(SENTINEl));
    Sentinel->first = NULL;
    Sentinel->first = NULL;
    FILE *f = fopen("input.dat", "r");
    g = fopen("output.dat", "w");
    char *s1 = (char *) malloc(sizeof(char) * 256);
    char *s2 = (char *) malloc(sizeof(char) * 256);
    while (fscanf(f, "%s", s1) != EOF) {
        if (!strcmp(s1, "AF")) {
            fscanf(f, "%s", s2);
            AF(atoi(s2));
            //  PRINT_ALL();
            continue;
        }
        if (!strcmp(s1, "AL")) {
            fscanf(f, "%s", s2);
            AL(atoi(s2));
            //    PRINT_ALL();
            continue;
        }
        if (!strcmp(s1, "DF")) {
            DF();
            //   PRINT_ALL();
            continue;
        }
        if (!strcmp(s1, "DL")) {
            DL();
            //   PRINT_ALL();
            continue;
        }
        if (!strcmp(s1, "DE")) {
            fscanf(f, "%s", s2);
            DE(atoi(s2));
            //   PRINT_ALL();
            continue;
        }
        if (!strcmp(s1, "PRINT_ALL")) {
            PRINT_ALL();
            continue;
        }
        if (!strcmp(s1, "PRINT_F")) {
            fscanf(f, "%s", s2);
            PRINT_F(atoi(s2));

            continue;
        }
        if (!strcmp(s1, "PRINT_L")) {
            fscanf(f, "%s", s2);
            PRINT_L(atoi(s2));
            continue;
        }
        if (!strcmp(s1, "DOOM_THE_LIST")) {
            DOOM_THE_LIST();
            //    PRINT_ALL();
            continue;
        }

    }
    return 0;
}