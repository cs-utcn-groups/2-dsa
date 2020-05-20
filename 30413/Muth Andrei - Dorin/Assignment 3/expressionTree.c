#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXX 12
#define COUNT 5

typedef struct nodeTree
{
    char * id;
    struct nodeTree * left, * right;
} nodeT;

int isOperation (char * s)
{
    return strcmp (s, "+") == 0 || strcmp (s, "-") == 0 || strcmp (s, "*") == 0 || strcmp (s, "/") == 0;
}

nodeT * getTree (FILE * fin)
{
    nodeT * newNode = (nodeT*) malloc (sizeof (nodeT));
    newNode->id = (char*) malloc (sizeof (char) * MAXX);
    fscanf (fin, "%s", newNode->id);
    if (!isOperation (newNode->id))
    {
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    newNode->left = getTree (fin);
    newNode->right = getTree (fin);
    return newNode;
}

void printTree (nodeT * p, int space, FILE * fout)
{
    if (p != NULL)
    {
        space += COUNT;
        printTree (p->right, space, fout);
        for (int i = 0; i <= space; i++)
        {
            fprintf (fout, " ");
        }
        fprintf (fout, "%s\n", p->id);
        printTree (p->left, space, fout);
    }
}

int main ()
{
    FILE * fin = fopen ("input.txt", "r");
    FILE * fout = fopen ("output.txt", "w");
    nodeT * root = getTree (fin);
    printTree (root, 0, fout);

    return 0;
}
