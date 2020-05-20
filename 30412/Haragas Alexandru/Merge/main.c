#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);
int *merge(int *a,unsigned int lena,int *b,unsigned int lenb);
int *split(int *v,unsigned int n);
long unsigned int c = 0, ac = 0, as = 0;
int main() {
    unsigned int n;

    scanf("%d", &n);
    int *v = (int *) malloc(n * sizeof(int));
    for (unsigned int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    v=split(v,n);
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\nComparisons: %ld\n", c);
    printf("Accesses: %ld\n", ac);
    printf("Assignments: %ld", as);
    free(v);
    return 0;
}

int *split(int *v,unsigned int n)
{
    if(n>1) {
        unsigned int mij = n / 2;
        int *a = (int *) malloc(mij * sizeof(int));
        for(unsigned int i=0;i<mij;i++)
            a[i]=v[i];
        int *b = (int *) malloc((n - mij) * sizeof(int));
        for(unsigned int i=mij;i<n;i++)
            b[i-mij]=v[i];
        ac+=n;
        as+=n;
        return merge(split(a,mij),mij,split(b,n-mij),n-mij);
    }
    else
        return v;
}


int *merge(int *a,unsigned int lena,int *b,unsigned int lenb)
{
    int *newv=(int *)malloc(sizeof(int)*(lena+lenb));
    unsigned int x=0,y=0;
    while(x<lena && y<lenb)
    {
        if(a[x]>b[y])
        {
            newv[x+y]=b[y];
            y++;
        } else{
            newv[x+y]=a[x];
            x++;
        }
        c++;
        as+=1;
        ac+=2;
    }
    while(x<lena)
    {
        newv[x+y]=a[x];
        x++;
        c++;
        as++;
        ac++;
    }
    while(y<lenb)
    {
        newv[x+y]=b[y];
        y++;
        c++;
        as++;
        ac++;
    }
    return newv;
}

