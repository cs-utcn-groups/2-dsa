#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_LENGTH 100

typedef struct activity
{
    int activity, startT, finishT;
} Activity;

Activity *createAct(int activity, int startT, int finishT);
void readFile(FILE *f, int *nrOfActivities, Activity *act[]);
void sortAccToFinishT(int *nrOfActivities, Activity *act[]);
void selectActivities(int *nrOfActivities, Activity *act[], FILE *g);
