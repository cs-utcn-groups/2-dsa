#include "head.h"
int main()
{
    initializeList();
    FILE * f=fopen("input.dat","r");
    FILE * g=fopen("output.dat","w");
    readFile(f,g);
    fclose(f);
    fclose(g);
}
