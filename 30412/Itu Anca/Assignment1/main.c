#include "head.h"

int main() {
    fptrout = fopen("D:\\Facultate\\DSA\\Assignment1\\output.dat", "w");
    if (fptrout == NULL)
    {
        printf("Could not open file");
        return 0;
    }

    first = NULL;
    last = NULL;

    char c[100];
    int n;

    FILE * fptr;
    fptr = fopen("D:\\Facultate\\DSA\\Assignment1\\input.dat", "r");
    if(fptr == NULL){
        printf("ERROR");
        exit(1);
    }

    for(int i=1;i<=21;i++)
    {
        fscanf(fptr,"%s", c);
        if(strcmp("AL",c)==0)
        {
            fscanf(fptr, "%d", &n);
            AddLast(n);
        }
        if(strcmp("AF",c)==0)
        {
            fscanf(fptr, "%d", &n);
            AddFirst(n);
        }
        if(strcmp("DF",c)==0)
        {
            fscanf(fptr, "%d", &n);
            DeleteFirst();
        }
        if(strcmp("DL",c)==0)
        {
            fscanf(fptr, "%d", &n);
            DeleteLast();
        }
        if(strcmp("DE",c)==0)
        {
            fscanf(fptr, "%d", &n);
            Delete(n);
        }
        if(strcmp("PRINT_ALL",c)==0)
        {
            printSllData();
        }
        if(strcmp("PRINT_F",c)==0)
        {
            fscanf(fptr, "%d", &n);
            PrintFirstXElements(n);
        }
        if(strcmp("PRINT_L",c)==0)
        {
            fscanf(fptr, "%d", &n);
            PrintLastXElements(n);
        }
        if(strcmp("DOOM_THE_LIST",c)==0)
        {
            DeleteAll();
        }
    }
    fclose(fptr);
    fclose(fptrout);
    return 0;
}


