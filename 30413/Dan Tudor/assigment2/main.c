#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int money;
    int time;
    struct node *next;
} NodeT;

NodeT *first,*last;

void initialize()
{
    first = NULL;
    last = NULL;
}

void addElement(int m, int t)
{
    if(first == NULL)
    {
        first = (NodeT*)malloc(sizeof(NodeT));
        first->next = last;
        first->money = m;
        first->time = t;
        last = first;
    }
    else
    {
        NodeT * newE1 = (NodeT*)malloc(sizeof(NodeT));
        last->next = newE1;
        newE1->next = NULL;
        newE1->money = m;
        newE1->time = t;
        last = newE1;
    }
}

void print(int *x, int *y, int *z, int n)
{
    int s1=0,i=0,j=0,s2=0;
    while(i < n)
    {
        if(s1+z[j] > x[i])
        {
            printf("%d %d\n",x[i],s2);
            i++;
        }
        else
        {
            s1 = s1+z[j];
            s2 = s2+y[j];
            j++;
        }
    }

}

int main()
{
    initialize();
    int n,i;
    int *x = (int)malloc(sizeof(int)*100);
    int *y = (int)malloc(sizeof(int)*100);
    int *z = (int)malloc(sizeof(int)*100);
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&x[i]);
    }
    for(i=0; i<n; i++)
    {
        scanf("%d",&y[i]);
        scanf("%d",&z[i]);
    }
    print(x,y,z,n);
    return 0;
}
