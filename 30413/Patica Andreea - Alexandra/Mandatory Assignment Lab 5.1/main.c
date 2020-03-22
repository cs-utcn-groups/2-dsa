#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(int argc, char *argv[])
{
    FILE *f = fopen(argv[1], "r");
    FILE *g = fopen(argv[2], "w");
    TREE *Tree;

    InitializeTree(&Tree);

    char function;
    while (fscanf(f, "%c", &function)>0)
    {
        char letter;
        fscanf(f, "%c", &letter);

        switch(function)
        {
            case 'i': InsertTree(Tree, letter);
                break;
            case 'd': DeleteFromTree(Tree, letter);
                break;
            case 'f': Find(Tree, letter, g);
                break;
            case 't': Transversal(Tree, letter, g);
                break;
            case 'g': fprintf(g, "%c\n", GetExtremum(Tree, letter));
                break;
            default: printf("Invalid call for function!\n");
                break;
        }

        char aux;
        fscanf(f, "%c", &aux);
    }

    fclose(f);
    fclose(g);

    return 0;
}
