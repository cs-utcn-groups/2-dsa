#include "header.h"
int main()
{
    FILE * in=fopen("in.txt","r");
    read(in);
    sortByX(0,nrPoints-1);

    for(int i=0;i<nrPoints;i++)
    {
        printf("%d %d\n",point[i].x,point[i].y);
    }


    return 0;
}
