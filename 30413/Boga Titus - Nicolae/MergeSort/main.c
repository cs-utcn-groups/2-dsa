#include <stdio.h>
int n,x[100001];

void citire()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&x[i]);
}

void afisare()
{
    for(int i=1;i<=n;i++)
        printf("%d ",x[i]);
}

void interclaseaza(int s,int d,int m)
{
    int i=s,j=m+1,k=1,v[100001];
    while(i<=m && j<=d)
    {
        if(x[i]<x[j])
        {
            v[k]=x[i];
            i++;
        }
        else
        {
            v[k]=x[j];
            j++;
        }
        k++;
    }
    if(i<=m)
        while(i<=m)
        {
            v[k]=x[i];
            i++;
            k++;
        }
    else
        while(j<=d)
        {
            v[k]=x[j];
            j++;
            k++;
        }
    for(k=1,i=s;i<=d;k++,i++)
        x[i]=v[k];
}

void mergesort(int s,int d)
{
    int m;
    if(s<d)
    {
        m=(s+d)/2;
        mergesort(s,m);
        mergesort(m+1,d);
        interclaseaza(s,d,m);
    }
}

int main()
{
    citire();
    mergesort(1,n);
    afisare();
    return 0;
}