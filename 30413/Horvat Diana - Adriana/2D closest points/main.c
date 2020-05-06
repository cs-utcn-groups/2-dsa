#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>
#define infinity 999999999
#define MAX_LENGTH 100

typedef struct point
{
    int x,y;
} Point;

char **initializeBuffer()
{
    char **buffer=(char **)malloc(sizeof(char *)*MAX_LENGTH);
    for(int i=0; i<MAX_LENGTH; i++)
        buffer[i]=(char *)malloc(sizeof(char)*MAX_LENGTH);

    return buffer;
}

Point *newPoint(int x,int y)
{
    Point *p=(Point *)malloc(sizeof(Point)*MAX_LENGTH);
    if(p!=NULL)
    {

        p->x=x;
        p->y=y;
        return p;
    }
    else
        return;
}

void readFile(int *nrOfPoints, FILE *f,Point *points[])
{
    char **buffer=initializeBuffer();
    char *string=(char *)malloc(sizeof(char)*MAX_LENGTH);
    char *token=(char *)malloc(sizeof(char)*MAX_LENGTH);

    fgets(string,MAX_LENGTH,f);
    string[strlen(string)-1]='\0';

    token=strtok(string," ");

    int i=0,x,y;

    strcpy(buffer[i],token);

    while(token!=NULL)
    {
        i++;
        token=strtok(NULL," ");
        if(token!=NULL)
        {
            strcpy(buffer[i],token);
        }
    }

    *nrOfPoints=i;

    for(int j=0; j<i; j++)
    {
        sscanf(buffer[j],"(%d,%d)",&x,&y);
        points[j]=newPoint(x,y);
    }

}

void mergeX(int *nrOfPoints, int lBound, int mid, int rBound,Point *points[])
{
    int i=lBound,j=mid+1,k=lBound;
    Point *temp[MAX_LENGTH];

    while(i<=mid && j<=rBound)
    {
        if(points[i]->x<points[j]->x)
        {
            temp[k]=points[i];
            i++;
            k++;
        }
        else
        {
            temp[k]=points[j];
            j++;
            k++;
        }
    }

    for(int t=i; t<=mid; t++)
    {
        temp[k]=points[t];
        k++;
    }

    for(int t=j; t<=rBound; t++)
    {
        temp[k]=points[t];
        k++;
    }

    for(int t=lBound; t<=rBound; t++)
    {
        points[t]=temp[t];
    }

}

void sortPointsByX(int *nrOfPoints,int lBound,int rBound,Point *points[])
{
    int mid;

    if(lBound<rBound)
    {
        mid=(lBound+rBound)/2;
        sortPointsByX(nrOfPoints,lBound,mid,points);
        sortPointsByX(nrOfPoints,mid+1,rBound,points);
        mergeX(nrOfPoints,lBound,mid,rBound,points);
    }
}

float dist2Points(Point *P1,Point *P2)
{
    return sqrt((P1->x-P2->x)*(P1->x-P2->x)+(P1->y-P2->y)*(P1->y-P2->y));
}


float smallestDist2Points(Point *points[],int nrOfPoints)
{
    int min=infinity;

    for(int i=0; i<nrOfPoints; i++)
        for(int j=i+1; j<nrOfPoints; j++)
            if(dist2Points(points[i],points[j])<min)
                min=dist2Points(points[i],points[j]);

    return min;
}

float minDist(float x, float y)
{
    if(x<y)
        return x;
    else
        return y;
}

void mergeY(int n, int lBound, int mid, int rBound,Point *strip[])
{
    int i=lBound,j=mid+1,k=lBound;
    Point *temp[n];

    while(i<=mid && j<=rBound)
    {
        if(strip[i]->y<strip[j]->y)
        {
            temp[k]=strip[i];
            i++;
            k++;
        }
        else
        {
            temp[k]=strip[j];
            j++;
            k++;
        }
    }

    for(int t=i; t<=mid; t++)
    {
        temp[k]=strip[t];
        k++;
    }

    for(int t=j; t<=rBound; t++)
    {
        temp[k]=strip[t];
        k++;
    }

    for(int t=lBound; t<=rBound; t++)
    {
        strip[t]=temp[t];
    }

}

void sortPointsByY(int n,int lBound,int rBound,Point *strip[])
{
    int mid;

    if(lBound<rBound)
    {
        mid=(lBound+rBound)/2;
        sortPointsByY(n,lBound,mid,strip);
        sortPointsByY(n,mid+1,rBound,strip);
        mergeY(n,lBound,mid,rBound,strip);
    }
}


float stripClosest(Point *strip[], int n, float d)
{
    int lBound=0,rBound=n-1;
    sortPointsByY(n,lBound,rBound,strip);

    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            if(dist2Points(strip[i],strip[j])<d)
                d=dist2Points(strip[i],strip[j]);

    return d;
}

float closestPoints(Point *points[],int nrOfPoints)
{
    if(nrOfPoints<=3)
        return smallestDist2Points(points,nrOfPoints);

    int mid=nrOfPoints/2;
    Point *midPoint=points[mid];

    Point *temp[nrOfPoints];
    int k=0;
    for(int i=mid; i<nrOfPoints; i++)
    {
        temp[k]=points[i];
        k++;
    }

    float dl=closestPoints(points,mid);
    float dr=closestPoints(temp,k);

    float d=minDist(dl,dr);

    Point *strip[nrOfPoints];
    int j=0;
    for(int i=0; i<nrOfPoints; i++)
        if(abs(points[i]->x-midPoint->x)<d)
        {
            strip[j]=points[i];
            j++;
        }

    return minDist(d,stripClosest(strip,j,d));
}

int main()
{
    FILE *f=fopen("input.in","r");

    Point *points[MAX_LENGTH];
    int nrOfPoints,lBound=0,rBound;
    readFile(&nrOfPoints,f,points);
    rBound=nrOfPoints-1;
    sortPointsByX(&nrOfPoints,lBound,rBound,points);

    printf("The smaller distance between 2 points is: ");
    printf("%f ",closestPoints(points,nrOfPoints));

    return 0;
}
