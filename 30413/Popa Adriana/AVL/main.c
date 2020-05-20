#include "avl.h"

int main()
{
    FILE *f=fopen("input.dat","r");
    NodeT *T;
    initializeTree(&T);

    char key;
    fscanf(f,"%c",&key);
    while(key != '0')
    {
        T=Insert(T,key);
        fscanf(f,"%c",&key);
    }

    prettyPrint(T,0);

    fclose(f);
    return 0;
}
