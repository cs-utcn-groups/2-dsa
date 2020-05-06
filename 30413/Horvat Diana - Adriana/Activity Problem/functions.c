#include "head.h"

Activity *createAct(int activity, int startT, int finishT)
{
     Activity *p=(Activity *)malloc(sizeof(Activity)*MAX_LENGTH);
     if(p!=NULL)
     {
         p->activity=activity;
         p->startT=startT;
         p->finishT=finishT;
         return p;
     }
     else return;
}

void readFile(FILE *f, int *nrOfActivities, Activity *act[])
{
    fscanf(f,"%d",nrOfActivities);

    int i=1,x,y;

    while(i<=*nrOfActivities)
    {
        fscanf(f,"%d %d",&x,&y);
        act[i]=createAct(i,x,y);
        i++;
    }

}

void sortAccToFinishT(int *nrOfActivities, Activity *act[])
{
    bool ok=false;
    Activity *temp;

    while(ok==false)
    {
        ok=true;
        for(int i=1; i<*nrOfActivities; i++)
        {
            if(act[i]->finishT>act[i+1]->finishT)
            {
                temp=act[i];
                act[i]=act[i+1];
                act[i+1]=temp;
                ok=false;
            }
        }
    }
}

void selectActivities(int *nrOfActivities, Activity *act[], FILE *g)
{
    fprintf(g,"%d ",act[1]->activity);
    int finishT=act[1]->finishT;

    for(int i=2;i<=*nrOfActivities;i++)
    {
        if(finishT<=act[i]->startT)
        {
            fprintf(g,"%d ",act[i]->activity);
            finishT=act[i]->finishT;
        }
    }

}

