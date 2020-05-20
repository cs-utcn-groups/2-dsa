#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
typedef struct _POINT
{
    int x;
    int y;
}POINT;

int CompareX(const void* a, const void* b)
{
    POINT *p1 = (POINT *)a,  *p2 = (POINT *)b;
    return (p1->x - p2->x);
}

int CompareY(const void* a, const void* b)
{
    POINT *p1 = (POINT *)a,   *p2 = (POINT *)b;
    return (p1->y - p2->y);
}

float Dist(POINT p1, POINT p2)
{
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

float Min(float x, float y)
{
    return ((x<y)? x:y);
}

float ClosestStrip(POINT strip[], int size, float d)
{
    float min = d;
    qsort(strip, size, sizeof(POINT), CompareY);

    for (int i=0; i<size; i++)
    {
        for (int j=i+1; j<size&& (strip[j].y - strip[i].y)<min; j++)
        {
            if (Dist(strip[i], strip[j])<min)
            {
                min = Dist(strip[i], strip[j]);
            }
        }
    }

    return min;
}

float FindClosest( POINT *point, int n)
{
    if(n <= 3)
    {
        float min = FLT_MAX;
        for (int i=0; i<n; i++)
        {
            for (int j=i+1; j<n; j++)
            {
                if (Dist(point[i], point[j])<min)
                {
                    min = Dist(point[i], point[j]);
                }
            }
        }
        return min;
    }

    int mid = n/2;
    POINT midPoint = point[mid];

    float dl = FindClosest(point, mid);
    float dr = FindClosest(point+mid, n-mid);

    float d = Min(dl, dr);

    POINT *strip = (POINT*)malloc(sizeof(POINT)*n);
    int j=0;
    for (int i=0; i<n; i++)
    {
        if (abs(point[i].x - midPoint.x)<d)
        {
            strip[j]=point[i];
            j++;
        }
    }

    return Min(d, ClosestStrip(strip, j, d));
}


float Closest(POINT point[], int n)
{
    qsort(point, n, sizeof(POINT), CompareX);

    return FindClosest(point, n);
}

int main(int argc, char *argv[])
{
    FILE *f = fopen(argv[1], "r");
    FILE *g = fopen(argv[2], "w");

    int n;
    fscanf(f, "%d", &n);
    POINT *point = (POINT*)malloc(sizeof(POINT*)*n);
    for (int i=0; i<n; i++)
    {
        fscanf(f, "%d%d", &(point+i)->x, &(point+i)->y);
    }

    float dist = Closest(point, n);

    fprintf(g, "%f", dist);

    return 0;
}
