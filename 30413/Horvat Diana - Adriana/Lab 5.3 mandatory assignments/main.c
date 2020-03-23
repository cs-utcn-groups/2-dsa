#include "head.h"

int main(int argc, char *argv[])
{
    int i=0;
    printf("argc=%d\n",argc);
    if(argc!=0)
    {
        for(i=0; i<argc; i++)
            printf("argv[%d]=%s\n",i,argv[i]);
    }
    else
        printf("Not enough arguments\n");

    FILE *f=fopen(argv[1],"r");
    FILE *g=fopen(argv[2],"w");

    readFile(f,g);

    return 0;
}
