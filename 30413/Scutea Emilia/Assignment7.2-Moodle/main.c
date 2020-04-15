#include <stdio.h>
#include <stdlib.h>
typedef struct time
{
    int start,finish;
} Time;
Time * activity;
int nrOfActivities;
Time * readFile(FILE * f)
{
    int i,n;
    fscanf(f,"%d",&n);
    nrOfActivities=n;
    activity=(Time*)malloc(sizeof(Time)*n);
    for(i=0; i<n; i++)
    {
        fscanf(f,"%d",&activity[i].start);
        fscanf(f,"%d",&activity[i].finish);
    }
    return activity;
}

void print(Time * activity)
{
    for(int i=0; i<nrOfActivities; i++)
        printf("Activity nr %d start time: %d, finish time: %d.\n",i+1,activity[i].start,activity[i].finish);
    printf("\n");
}

void ascendingOrderFinishTime(Time * activity)
{
    int i,done=0;
    Time * aux=(Time*)malloc(sizeof(Time));
    while(done!=1)
    {
        done=1;
        for(i=0; i<nrOfActivities-1; i++)
            if(activity[i].finish>activity[i+1].finish)
            {
                *aux=activity[i];
                activity[i]=activity[i+1];
                activity[i+1]=*aux;
                done=0;
            }
    }
}
void compatibleActivities(Time * activity)
{
    printf("The compatible activities are:\n");
    int i,finishTime=0;
    for(i=0;i<nrOfActivities;i++)
    {
        if(activity[i].start>=finishTime)
        {
            printf("Start time: %d, finish time: %d\n",activity[i].start,activity[i].finish);
            finishTime=activity[i].finish;
        }
    }
}
int main()
{
    FILE * f=fopen("input.dat","r");
    Time * activity=readFile(f);
    print(activity);
    ascendingOrderFinishTime(activity);
    compatibleActivities(activity);
}
