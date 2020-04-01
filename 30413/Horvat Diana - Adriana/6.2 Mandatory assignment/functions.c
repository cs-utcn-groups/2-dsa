#include "head.h"

int f(char *key)
{
    int sum=0;
    for(int i=0; i<strlen(key); i++)
        sum=sum+key[i];
    return (sum%A);
}

void initializeHash(CellT *HashTable[B])
{
    for(int i=0; i<B; i++)
        HashTable[i]=NULL;
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
    int h=f(key);
    CellT *p=create(key);

    if(HashTable[h]==NULL)
    {
        HashTable[h]=p;
    }
    else
    {
        int x=1;
        while(HashTable[h]!=NULL)
        {
            h=h+x*x;
            x++;
        }

        HashTable[h]=p;
    }
}

char *findKey(char *key)
{
    CellT *p;

    for(int i=0;i<B;i++)
    {
        if(HashTable[i]!=NULL)
        {
            p=HashTable[i];

            while(p!=NULL)
            {
                if(strcmp(key,p->key)==0) return "Yes";
                p=p->next;
            }
        }
    }

    return "No";
}

void deleteKey(char *key, FILE *g)
{
    if(findKey(key)=="Yes")
    {
        int h=f(key);
        CellT *p=HashTable[h];

        if(strcmp(key,p->key)==0)
        {
            HashTable[h]=NULL;
        }
        else
        {
            int x=1;
            while(p!=NULL)
            {
                if(strcmp(key,p->key)==0)
                {
                    HashTable[h]=NULL;
                }
                else
                {
                    h=h+x*x;
                    p=HashTable[h];
                    x++;
                }
            }
        }


    }
    else
        fprintf(g,"This key doesn't exist in the hash table\n");
}

void listTable(FILE *g)
{
    CellT *p;

    for(int i=0; i<B; i++)
    {
        if(HashTable[i]!=NULL)
        {
            fprintf(g,"Bucket for hash value %d :",i);
            p=HashTable[i];

            while(p!=NULL)
            {
                fprintf(g,"%s\n",p->key);
                p=p->next;

            }

        }
    }
    fprintf(g,"\n");
}

void processCommandsFromInputData(char **buffer,int *n,FILE *g)
{
    char *token=(char *)malloc(sizeof(char)*MAX_LENGTH);
    initializeHash(HashTable);

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
