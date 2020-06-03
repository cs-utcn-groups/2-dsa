#include <stdio.h>
#include <string.h>
#include "queue.h"

void SeparateLine(char line[50], int *rubles, int *seconds);

int main() {
    FILE * inF = fopen(INPUT_FILE_PATH,"r");
    InitializeQueue();
    InitializeTime();
    //Get time
    char s[10];
    int t;
    fscanf(inF,"%s",s);
    while(strtol(s,NULL,10))
    {
        t = strtol(s,NULL,10);
        AddLastTime(t);
        fscanf(inF,"%s",s);
    }
    //Get customers
    char line[100];
    int rubles, seconds;
    fgets(line,100,inF);
    char *p;
    p = strtok(line," \n");
    rubles = strtol(p,NULL,10);
    p = strtok(NULL," \n");
    seconds = strtol(p,NULL,10);
    AddFirstQueue(rubles, seconds);
    while(fgets(line,100,inF))
    {
        SeparateLine(line,&rubles,&seconds);
        AddFirstQueue(queue->rubles + rubles, queue->seconds + seconds);
    }
    fclose(inF);
    FILE *outF = fopen(OUTPUT_FILE_PATH,"w");
    NodeT *currentTime = time;
    NodeQ *queueNode;
    while(currentTime!=NULL)
    {
        queueNode = queue;
        while(queueNode->next != NULL && currentTime->seconds < queueNode->seconds)
        {
            queueNode = queueNode->next;
        }
        fprintf(outF,"After %d seconds: %d\n",currentTime->seconds, queueNode->rubles);
        currentTime = currentTime->next;
    }

    return 0;
}

void SeparateLine(char line[100], int *rubles, int *seconds)
{
    char *p = strtok(line," \n");
    p = strtok(NULL," \n");
    *rubles = strtol(p,NULL,10);
    p = strtok(NULL," \n");
    *seconds = strtol(p,NULL,10);
}