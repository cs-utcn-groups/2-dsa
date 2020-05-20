#include "header.h"

void read(FILE * in)
{
    fscanf(in,"%d",&nrPoints);
    point=(pointStructure *) malloc(sizeof(pointStructure) * nrPoints);

    for(int i=0; i<nrPoints; i++)
    {
        fscanf(in,"%d %d",&point[i].x,&point[i].y);
    }
}

void sortByX(int left, int right)
{
    if(left<right)
    {
        int mid=(left+right)/2;
        sortByX(left,mid);
        sortByX(mid+1,right);

//            for(int i=0;i<nrPoints;i++)
//    {
//        printf("%d %d  ,   ",point[i].x,point[i].y);
//    }printf("\n");
//
        sortt(left,mid,right);
    }
}

void sortt(int left, int mid, int right)
{
    printf("asta o face de 3 ori  right-left+1 este %d deci nu <0 \n",right-left+1);
    pointStructure * auxArray=(pointStructure *) malloc(sizeof(pointStructure) * (right-left+1));
    printf("asta o face de 2 ori  right-left+1 este %d deci nu <0\n",right-left+1);

    int auxArrayIndex=left;
    int leftArrayIndex=left,rightArrayIndex=mid+1;

    while(leftArrayIndex<=mid && rightArrayIndex<=right)
    {
        /// printf("point[leftArrayIndex].x:%d  point[rightArrayIndex].x:%d\n",point[leftArrayIndex].x,point[rightArrayIndex].x);
        if(point[leftArrayIndex].x<=point[rightArrayIndex].x)
        {
            ///printf("1:%d  %d\n",point[rightArrayIndex].x,point[rightArrayIndex].y);
            /// printf("leftArrayIndex:%d\n",leftArrayIndex);
            auxArray[auxArrayIndex]=point[leftArrayIndex];
            leftArrayIndex++;
        }

        else
        {
            ///printf("2:%d  %d\n",point[rightArrayIndex].x,point[rightArrayIndex].y);
            /// printf("rightArrayIndex:%d\n",rightArrayIndex);
            auxArray[auxArrayIndex]=point[rightArrayIndex];
            rightArrayIndex++;
        }
        auxArrayIndex++;
    }

    for(int i=leftArrayIndex; i<=mid; i++)
    {
        ///printf("3:%d  %d\n",point[i].x,point[i].y);
        /// printf("leftArrayIndex:%d  mid:%d",leftArrayIndex,mid);
        auxArray[auxArrayIndex++]=point[i];
    }

    for(int i=rightArrayIndex; i<=right; i++)
    {
        ///printf("4:%d  %d\n",point[i].x,point[i].y);
        ///  printf("rightArrayIndex:%d right:%d\n",rightArrayIndex,right);
        auxArray[auxArrayIndex++]=point[i];
    }

    for(int i=left; i<=right; i++)
    {
        point[i]=auxArray[i];
    }
    free(auxArray);
}

double distance(pointStructure p0, pointStructure p1)
{
    return ((double) sqrt((p0.x-p1.x)*(p0.x-p1.x)+(p0.y-p1.y)*(p0.y-p1.y)));
}
