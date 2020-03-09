#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE * f;
FILE * g;

typedef struct node
{

    int money;
    int time;
    struct node * next;
    struct node * previous;

} NodeT;

NodeT * first, * last;

void initializeDLL()
{

    first = NULL;
    last = NULL;

}

void addLast(int money, int time)
{
    if(first == NULL)
    {
        first = (NodeT*)malloc(sizeof(NodeT));
        first->next = NULL;
        first->previous = NULL;
        first->money = money;
        first->time = time;
        last = first;
    }
    else
    {
        NodeT * newElement = (NodeT*)malloc(sizeof(NodeT));
        last->next = newElement;
        newElement->previous = last;
        newElement->next = NULL;
        newElement->money = money;
        newElement->time = time;
        last = newElement;
    }
}

void createQueue()
{

    char * line = (char*)malloc(sizeof(char)*150);
    char * tok = (char*)malloc(sizeof(char)*150);
    int money, time;
    while(fgets(line, 150, f) != NULL)
    {
        tok = strtok(line, " \n");
        tok = strtok(NULL, " \n");
        money = atoi(tok);
        tok = strtok(NULL, " \n");
        time = atoi(tok);
        addLast(money, time);
    }

}

void printAll()
{
    if(first == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        NodeT * currentElement = first;
        while(currentElement != NULL)
        {
            printf("%d %d\n", currentElement->money, currentElement->time);
            currentElement = currentElement->next;
        }
        printf("\n");
    }

}

void calculateMoney(int * T, int nrOfT)
{
    int s, timeElapsed, i;
    for(i=0; i<nrOfT; i++)
    {
        NodeT * currentElement = first;
        s=0;
        timeElapsed=0;
        while(currentElement != NULL)
        {
            if(timeElapsed+currentElement->time <= T[i])
            {
                s = s+currentElement->money;
                timeElapsed = timeElapsed+currentElement->time;
            }
            currentElement = currentElement->next;
        }

        fprintf(g, "After %d seconds: %d\n", T[i], s);

    }

}

int main()
{
    f = fopen("input.dat", "r");
    g = fopen("output.dat", "w");
    initializeDLL();
    int nrOfT=0;
    int * T = (int*)malloc(sizeof(int)*150);
    char * line = (char*)malloc(sizeof(char)*150);
    char * tok = (char*)malloc(sizeof(char)*150);
    fgets(line, 150, f);
    tok = strtok(line, " \n");
    while(tok != NULL)
    {
        T[nrOfT] = atoi(tok);
        nrOfT++;
        tok = strtok(NULL, " \n");
    }
    createQueue();
    printAll();
    calculateMoney(T, nrOfT);

    return 0;
}
