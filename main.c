#include "head.h"

int main()
{
    FILE * f=fopen("input.dat","r");
    FILE * g=fopen("output.dat","w");
    initializeList();
    readFile(f,g);
    fclose(g);
    fclose(f);
    return 0;
}
