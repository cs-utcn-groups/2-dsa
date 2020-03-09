//
// Created by csatl on 2/27/2020.
//

#include "queue.h"

void InitializeQueue()
{
    queue = NULL;
}
void InitializeTime()
{
    time = NULL;
}
void AddFirstQueue(int rubles, int seconds)
{
    if(queue == NULL)
    {
        queue = (NodeQ*)malloc(sizeof(NodeQ));
        queue->next = NULL;
        queue->seconds = seconds;
        queue->rubles = rubles;
    }
    else
    {
        NodeQ *newElement = (NodeQ*)malloc(sizeof(NodeQ));
        newElement->next = queue;
        newElement->seconds = seconds;
        newElement->rubles = rubles;
        queue = newElement;
    }
}
void AddLastTime(int key)
{
       if(time == NULL)
       {
           time = (NodeT*)malloc(sizeof(NodeT));
           time -> seconds = key;
           time ->next = NULL;
       }
       else
       {
           NodeT * newElement = (NodeT*)malloc(sizeof(NodeT));
           newElement->next = NULL;
           newElement->seconds = key;
           NodeT * q=time;
           while(q->next != NULL)
           {
               q = q->next;
           }
           q->next = newElement;
       }
}
void PrintTime()
{
    NodeT *q = time;
    while(q!=NULL)
    {
        printf("%d ",q->seconds);
        q = q->next;
    }
    printf("\n");
}
void PrintQueue()
{
    NodeQ *q = queue;
    while(q!=NULL)
    {
        printf("%d - %d\n",q->rubles, q->seconds);
        q = q->next;
    }
    printf("\n");
}