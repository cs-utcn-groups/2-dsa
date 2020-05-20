#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int main()
{
     FILE *f=fopen("input.txt","r");
     char name[30];
     Table=(MapT*)malloc(sizeof(MapT)*B);
     initialize();
     while(fscanf(f,"%s",name)!=EOF)
     {
        switch(name[0]){
            case 'i':insertT(name+1); break;
            case 'd':deleteT(name+1); break;
            case 'f':findT(name+1); break;
            case 'l':listData(); break;
            default: printf("\n Wrong input.\n");
        }
     }
    return 0;
}
