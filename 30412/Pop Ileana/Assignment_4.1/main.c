#include "head.h"

#define DATA_PATH "../input.dat"


int main() {
    fin = fopen(DATA_PATH,"r");
    if(fin==NULL)
    {
        perror("File could not be opened");
        exit(EXIT_FAILURE);
    }
    NodeT * root=NULL;

    int key;
    while(!feof(fin))
    {
        fscanf(fin,"%d",&key);
        root = insert(root,key);
    }

    prettyPrint(root,0);
    printf("\n");
    root=insert(root,12);
    prettyPrint(root,0);
    fclose(fin);

    return 0;
}