#include <stdio.h>
#include <stdlib.h>

typedef struct activityStructure
{
    int start;
    int fin;
} activityStructure;

int nrActivities;

void read(FILE * in);
activityStructure * sort(activityStructure * activity, int nrActivities);
void greedy(activityStructure * activity, int nrActivities);

void read(FILE * in)
{
    fscanf(in,"%d",&nrActivities);
    activityStructure * activity=(activityStructure *) malloc(sizeof(activityStructure) * nrActivities);

    for(int i=0; i<nrActivities; i++)
    {
        fscanf(in,"%d",&activity[i].start);
        fscanf(in,"%d",&activity[i].fin);
    }
    activity=sort(activity,nrActivities);
    greedy(activity,nrActivities);
}

activityStructure * sort(activityStructure * activity, int nrActivities)
{
    for(int i=0; i<nrActivities-1; i++)
    {
        for(int j=i+1; j<nrActivities; j++)
        {
            if(activity[i].fin>activity[i].fin)
            {
                int aux=activity[i].fin;
                activity[i].fin=activity[j].fin;
                activity[j].fin=aux;
            }
        }
    }
    return activity;
}

void greedy(activityStructure * activity, int nrActivities)
{
    int activitiesSelected=0;
    activityStructure preSelectedActivity=activity[0];
    printf("Activity %d: %d -> %d\n",activitiesSelected,activity[0].start,activity[0].fin);

    for(int i=1; i<nrActivities; i++)
    {
        if(activity[i].start>=preSelectedActivity.fin)
        {
            preSelectedActivity=activity[i];
            activitiesSelected++;
            printf("Activity %d: %d -> %d\n",activitiesSelected,activity[i].start,activity[i].fin);
        }
    }
}

int main()
{

    FILE * inFile=fopen("in.txt","r");
    read(inFile);

    return 0;
}
