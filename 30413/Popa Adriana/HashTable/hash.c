#include "hash.h"

int f(char *key)
{
    int i, sum;
    sum = 0;
    for (i = 0; i < strlen (key); i++)
        sum += key[ i ];
    return(sum % size);
}

void AddElement(char key[size])
{
    item=(NodeT *) malloc(sizeof(NodeT));
    if(item)
    {
        strcpy(item->key,key);
        int h=f(item->key);
        if(StudentsTable[h]==NULL)
        {
            StudentsTable[h]=item;
            item->next=NULL;
        }
        else
        {
            printf("\nStudentsTable[%d] already ocupied\n",h);
            item2=find(item->key);
            if(item2==NULL)
            {
                item->next=StudentsTable[h];
                StudentsTable[h]=item;
            }
        }
    }
}

NodeT *find(char key[size])
{
    int h=f(key);
    item=StudentsTable[h];
    while(item!=NULL)
    {
        if(strcmp(item->key,key)==0)
            return item;
        item=item->next;
    }
    return NULL;
}

void listing()
{
    int i;
    for (i = 0; i < size; i++)
    {
         if (StudentsTable[ i ] != NULL)
        {
            printf("StudentsTable for hash value %d: ", i);
            item =StudentsTable[ i ];
            while (item != NULL)
            {
                printf("%s",item->key);
                item = item->next;
            }
        }
    }
}

void del(char key[size])
{
    int h=f(key);
    item=StudentsTable[h];
    if(item->next!= NULL)
    {
        StudentsTable[h]=item->next;
    }
    else
    {
        StudentsTable[h]=NULL;
    }
}
