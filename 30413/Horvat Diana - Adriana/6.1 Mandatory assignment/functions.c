#include "head.h"

void initializeBucket(CellT *bucketTable[B])
{
    for(int i=0; i<B; i++)
        bucketTable[i]=NULL;
}

int f(char *key)
{
    int sum=0;
    for(int i=0; i<strlen(key); i++)
        sum=sum+key[i];
    return (sum%A);
}

CellT *create(char *key)
{
    CellT *p=(CellT *)malloc(sizeof(CellT)*MAX_LENGTH);
    if(p!=NULL)
    {
        strcpy(p->key,key);
        p->next=NULL;
    }
    return p;
}

void insertKey(char *key)
{
    int h;
    CellT *p=create(key);
    h=f(key);

    if(bucketTable[h]==NULL)
    {
        bucketTable[h]=p;
    }
    else
    {
        CellT *ptr=bucketTable[h];
        int k=0;
        while(k==0)
        {
            if(ptr->next==NULL)
            {
                ptr->next=p;
                k=1;
            }
            else
                ptr=ptr->next;
        }
    }
}

void listTable(FILE *g)
{
    CellT *p=(CellT *)malloc(sizeof(CellT)*MAX_LENGTH);

    for(int j=0; j<B; j++)
    {
        if(bucketTable[j]!=NULL)
        {
            fprintf(g,"Bucket for hash value %d :",j);
            p=bucketTable[j];

            while(p!=NULL)
            {
                fprintf(g,"%s\n",p->key);
                p=p->next;

            }

        }
    }
    fprintf(g,"\n");
}

char *findKey(char *key)
{
    int h=f(key);
    CellT *p=bucketTable[h];

    while(p!=NULL)
    {
        if(strcmp(key,p->key)==0)
            {
                return "Yes";
            }
        p=p->next;
    }

  return "No";
}

void deleteKey(char *key, FILE *g)
{
    int h=f(key);
    int k=0;
    CellT *p=(CellT *)malloc(sizeof(CellT)*MAX_LENGTH);
    p=bucketTable[h];

    if(strcmp(key,p->key)==0)
    {
        bucketTable[h]=p->next;
        k=1;
    }
    else
    {
        CellT *temp=NULL;
        while(p!=NULL)
        {
            if(strcmp(key,p->key)==0)
            {
                temp->next=p->next;
                k=1;
            }

            temp=p;
            p=p->next;
        }
    }

    if(k==0)
        fprintf(g,"Element not found\n");

}

void processCommandsFromInputData(char **buffer,int *n,FILE *g)
{
    char *token=(char *)malloc(sizeof(char)*MAX_LENGTH);
    initializeBucket(bucketTable);

      for(int i=0;i<*n;i++)
    {
       token=strtok(buffer[i],",");

       if(strcmp(token,"i")==0)
        {
            token=strtok(NULL,",");
            insertKey(token);
        }
        else if(strcmp(token,"d")==0)
        {
            token=strtok(NULL,",");
            deleteKey(token,g);
        }
        else if(strcmp(token,"f")==0)
        {
            token=strtok(NULL,",");
           fprintf(g,"%s\n",findKey(token));
        }
        else if(strcmp(token,"l")==0)
        {
            listTable(g);
        }

    }
}

char **initializeBuffer()
{
    char **buffer=(char **)malloc(sizeof(char*)*MAX_LENGTH);

    for(int i=0;i<MAX_LENGTH;i++)
        buffer[i]=(char *)malloc(sizeof(char)*MAX_LENGTH);

    return buffer;
}


char  **readFile(FILE *f,int *n)
{
    char **buffer=initializeBuffer();
    *n=0;
    while(fgets(buffer[*n],MAX_LENGTH,f))
    {
        buffer[*n][strlen(buffer[*n])-1]='\0';
        *n=*n+1;
    }

    return buffer;
}

