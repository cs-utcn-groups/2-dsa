#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct _LIST{
    int data;
    struct  _LIST * next;
}LIST;

LIST *prim=NULL,*last=NULL;

void AF(int data)
{
    if( prim == NULL)
    {
        prim=(LIST *) malloc(sizeof(LIST));
        prim->data=data;
        prim->next=NULL;
        last=prim;
    } else
    {
        LIST * NewEl= malloc(sizeof(LIST));
        NewEl->next=prim;
        NewEl->data=data;
        prim=NewEl;

    }
}

void AL( int data)
{
    if( prim == NULL)
    {
        prim=(LIST *) malloc(sizeof(LIST));
        prim->data=data;
        prim->next=NULL;
        last=prim;
    } else
    {
        LIST * NewEl= malloc(sizeof(LIST));
        NewEl->data=data;
        NewEl->next=NULL;
        last->next=NewEl;
        last=NewEl;

    }
}

void DF(void)
{
    if(prim==NULL)
    {
        return;
    } else{
        LIST *NewEl=prim;
        prim=prim->next;
        if(prim == NULL)
        {
            last=prim;
        }
        free(NewEl);
    }
}

void DL(void)
{
    if(last==NULL)
    {
        return;
    }
    else
    {
        if(prim==last)
        {
            free(prim);
            prim=last=NULL;
            return;
        }
        LIST *p=prim;
        while(p->next->next)
        {
            p=p->next;
        }
        last=p;
        p=p->next;
        last->next=NULL;
        free(p);
    }
}

void  DOOM_THE_LIST (void)
{
    if(prim == NULL)
    {
        return;
    } else
    {
        LIST *p=prim;
        while (p)
        {
            prim=prim->next;
            free(p);
            p=prim;
        }
    }
    last=NULL;
}

void DE (int value)
{
    if(prim == NULL)
    {
        return;
    } else
    {
        LIST * p=prim;
        while(prim&&prim->data==value)
        {
            p=prim;
            prim=prim->next;
            free(p);
        }
        p=prim;
        if(!p)
        {
            last=prim;
        }
        else
        while(p->next)
        {
            if(p->next->data==value)
            {
                LIST *q=p->next;
                p->next=q->next;
                free(q);
            } else
                p=p->next;


        }
    }
}

void PRINT_ALL()
{
    LIST * p=prim;
    while (p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

void PRINT_F(int data)
{
    LIST *p=prim;
    while (p && data--)
    {
       printf("%d ",p->data);
       p=p->next;
    }
    printf("\n");
}

int ElCount()
{
    LIST *p=prim;
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
        LIST *p=prim;
        for(int i=0;i<nr-data;++i)
        {
            p=p->next;
        }
        while(p)
        {
            printf("%d ",p->data);
            p=p->next;

        }
    }
    printf("\n");

}

int main() {

    FILE *f=fopen("input.dat","r");

    char *s1=(char*)malloc(sizeof(char)*256);
    char *s2=(char*)malloc(sizeof(char)*256);
    while(fscanf(f,"%s",s1)!=EOF)
    {
        if(!strcmp(s1,"AF"))
        {
            fscanf(f,"%s",s2);
            AF(atoi(s2));
          //  PRINT_ALL();
            continue;
        }
        if(!strcmp(s1,"AL"))
        {
            fscanf(f,"%s",s2);
            AL(atoi(s2));
        //    PRINT_ALL();
            continue;
        }
        if(!strcmp(s1,"DF"))
        {
            DF();
         //   PRINT_ALL();
            continue;
        }
        if(!strcmp(s1,"DL"))
        {
            DL();
         //   PRINT_ALL();
            continue;
        }
        if(!strcmp(s1,"DE"))
        {
            fscanf(f,"%s",s2);
            DE(atoi(s2));
         //   PRINT_ALL();
            continue;
        }
        if(!strcmp(s1,"PRINT_ALL"))
        {
            PRINT_ALL();
            continue;
        }
        if(!strcmp(s1,"PRINT_F"))
        {
            fscanf(f,"%s",s2);
            PRINT_F(atoi(s2));

            continue;
        }
        if(!strcmp(s1,"PRINT_L"))
        {
            fscanf(f,"%s",s2);
            PRINT_L(atoi(s2));
            continue;
        }
        if(!strcmp(s1,"DOOM_THE_LIST"))
        {
            DOOM_THE_LIST();
        //    PRINT_ALL();
            continue;
        }
    }
    return 0;
}
