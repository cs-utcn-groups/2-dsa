#include "hash.h"

int main()
{
    FILE *f=fopen("input.dat","r");
    char *name=(char*)malloc(sizeof(char));
    int i;
    for(i=0;i<size;i++)
        StudentsTable[i]=NULL;
    char c;
    fscanf(f,"%c",&c);
    while(c != '0')
    {
        if(c == 'i')
        {
            fgets(name,100,f);
            AddElement(name);
        }
       else if(c == 'f')
        {
            fgets(name,100,f);
            item2=find(name);
            if(item2 != NULL)
                printf("%s found",name);
            else
                printf("%s not found",name);
        }
        else if(c == 'l')
        {
            listing();
        }
        else if(c == 'd')
        {
            fgets(name,100,f);
            del(name);
        }
        fscanf(f,"%c",&c);
    }
    fclose(f);
    return 0;
}
