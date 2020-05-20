#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    int start;
    int finish;
}ACTIVITY;

void swap (ACTIVITY *a, ACTIVITY*b)
{
    ACTIVITY *aux = a;
    a=b;
    b=aux;
}

void sort(ACTIVITY *activity, int n)
{
    int ok;
    do
    {
        ok=0;
        for (int i=0; i<n-1; i++)
        {
            if ((activity[i].start<activity[i+1].start) || (activity[i].start == activity[i+1].start && activity[i].finish>activity[i+1].finish))
            {
                swap(activity+i,activity+i+1);
                ok=1;
            }
        }
    }while(!ok);
}


void Greedy(ACTIVITY *activity, int n)
{
    printf("%d ", activity[0].id);
    int lastFinish = activity[0].finish;
    for (int i=1; i<n; i++)
    {
        if (activity[i].start>=lastFinish)
        {
            printf("%d ", activity[i].id);
            lastFinish = activity[i].finish;
        }
    }
}


int main()
{
    int n;
    scanf("%d", &n);
    ACTIVITY *activity = (ACTIVITY*)malloc(sizeof(ACTIVITY)*n);
    for (int i=0; i<n; i++)
    {
        int x,y;
        scanf("%d%d", &x, &y);
        activity[i].start = x;
        activity[i].finish = y;
        activity[i].id = i+1;
    }

    sort(activity,n);
    Greedy(activity,n);

    return 0;
}
