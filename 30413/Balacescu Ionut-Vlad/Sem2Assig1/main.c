#include "head.h"



int main()
{
    initializeList();
    FILE *f=fopen("input.txt","rw");
    FILE *o=fopen("output.txt","rw");
    char *s1=(char*)malloc(sizeof(char)*100);

    while(fscanf(f,"%s",s1)!=EOF)
    {
        executeInstr(s1);
    }
    return 0;
}
