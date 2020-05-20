#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    FILE *f = fopen("input.in", "r");
    FILE *g = fopen("output.out", "w");
    TREE *Tree;

    InitializeTree(&Tree);

    char function;
    while (fscanf(f, "%c", &function)>0)
    {
        char letter;
        fscanf(f, "%c", &letter);

        switch(function)
        {
            case 'i': InsertTree(&Tree, letter);
                break;
            case 'p' : Preorder(Tree, g);
                fprintf(g, "\n");
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
