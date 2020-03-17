#include "header.h"


int main()
{
    FILE * f = fopen("input.dat", "r");
    FILE * g = fopen("output.dat", "w");

    first = last = NULL;

    while(!feof(f))
    {
        char * operation = (char*)malloc(sizeof(char)*15);
        int x;

        fscanf(f,"%s",operation);
        if(strcmp(operation,"AF") == 0)
        {
            fscanf(f,"%d",&x);
            fAF(x);
        }
        else if(strcmp(operation,"AL") == 0)
        {
            fscanf(f,"%d",&x);
            fAL(x);
        }
        else if(strcmp(operation,"DF") == 0)
        {
            fDF();
        }
        else if(strcmp(operation,"DL") == 0)
        {
            fDL();
        }
        else if(strcmp(operation,"DOOM_THE_LIST") == 0)
        {
            fDOOM();
        }
        else if(strcmp(operation,"DE") == 0)
        {
            fscanf(f,"%d",&x);
            fDE(x);
        }
        else if(strcmp(operation,"PRINT_ALL") == 0)
        {
            fPA(g);
        }
        else if(strcmp(operation,"PRINT_F") == 0)
        {
            fscanf(f,"%d",&x);
            fPF(g,x);
        }
        else if(strcmp(operation,"PRINT_L") == 0)
        {
            fscanf(f,"%d",&x);
            fPL(g,x);
        }
    }

    fclose(f);
    fclose(g);

    return 0;
}
