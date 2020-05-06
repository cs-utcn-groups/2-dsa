#include "head.h"

int main()
{
    FILE *f=fopen("input.in","r");
    FILE *g=fopen("output.out","w");

    int nrOfActivities;
    Activity *act[MAX_LENGTH];

    readFile(f,&nrOfActivities,act);
    sortAccToFinishT(&nrOfActivities,act);
    selectActivities(&nrOfActivities,act,g);

    return 0;
}
