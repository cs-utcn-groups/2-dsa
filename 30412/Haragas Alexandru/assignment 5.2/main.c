#include <stdio.h>
#include <stdlib.h>

int maxlen(int a,int b,int n,int **m,int *v,int *p,int l);

int main() {
    int n;
    printf("Input size of matrix and its elements:\n");
    scanf("%d", &n);
    int **m = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        m[i] = (int *) malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            scanf("%d", &m[i][j]);
        }
    }
    int a, b;
    printf("Input starting node: ");
    scanf("%d", &a);
    printf("Input final node: ");
    scanf("%d", &b);

    int *v = (int *) malloc(n * sizeof(int));
    for(int i=0;i<n;i++)
        v[i]=0;
    int *path=(int *)malloc(n* sizeof(int));
    int ml=maxlen(a,b,n,m,v,path,0);
    if(ml!=0) {
        printf("The longest path from %d to %d has the length %d and is:\n", a, b, ml);
        for (int i = 0; i <= ml; i++)
            printf("%d ", path[i]);
    }
    else
        printf("Impossible to find a path");
    free(v);
    free(path);
    for(int i=0;i<n;i++)
        free(m[i]);
    free(m);
    return 0;
}
int maxlen(int a,int b,int n,int **m,int *v,int *p,int l)
{
    v[a]=1;
    int ml=l;
    if(a==b)
        return l;
    for(int i=0;i<n;i++)
    {
        if(m[a][i]!=0 && v[i]==0)
        {
            int nl=maxlen(i,b,n,m,v,p,l+1);
            if(ml<nl)
            {
                ml=nl;
                p[l]=a;
                if(i==b)
                    p[l+1]=b;
            }
        }
    }
    v[a]=0;
    return ml;
}