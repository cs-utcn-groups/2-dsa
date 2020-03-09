#include "head.h"

int main()
{
    FILE *f=fopen("input.txt","r");
    FILE *g=fopen("output.txt","w");
    initializeSLL();
    readFile(f,g);
    fclose(g);
    fclose(f);
    return 0;
}
