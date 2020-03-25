#include "head.h"

int main()
{
    FILE *f=fopen("input.txt","r");
    FILE *g=fopen("output.txt","w");

    createPBBST(f,g);
    deleteNodesInPBBST(g);

    return 0;
}
