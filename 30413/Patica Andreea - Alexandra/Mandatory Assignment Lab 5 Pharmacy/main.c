#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(int argc, char *argv[])
{
    FILE *f = fopen(argv[1], "r");
    FILE *g = fopen(argv[2], "w");
    TREE *Tree;
    TREE *TreeExpired;

    InitializeTree(&Tree);
    InitializeTree(&TreeExpired);

    char function;
    while (fscanf(f, "%c", &function)>0)
    {
        switch(function)
        {
            case 'i': InsertTree(Tree, f);
                PrintTree(Tree,g);
                fprintf(g, "\n");
                break;
            case 'd': DeleteFromTree(Tree, f);
                PrintTree(Tree,g);
                fprintf(g, "\n");
                break;
            case 'u': FindAndReplace(Tree, f, g);
                PrintTree(Tree,g);
                fprintf(g, "\n");
                break;
            case 'c': CreateExpired(TreeExpired, Tree, f);
                PrintTree(TreeExpired,g);
                fprintf(g, "\n");
                break;
            default: printf("Invalid call for function!\n");
                break;
        }

    }

    fclose(f);
    fclose(g);

    return 0;
}
