#include <stdio.h>
#include <stdlib.h>

const int SIZE_V=1000;



int main() {
    unsigned int n;
    int *countVect=(int*)malloc(SIZE_V* sizeof(int));
    for(int i=0;i<SIZE_V;i++)
        countVect[i]=0;
    long unsigned int c = 0, ac = 0, as = 0;
    int max=0;
    scanf("%d", &n);
    int *v = (int *) malloc(n * sizeof(int));
    for (unsigned int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
        countVect[v[i]]++;
        ac++;
    }
    int poz=0;
    for(int i=0;i<SIZE_V;i++)
    {
        c++;
        if(countVect[i]!=0)
        {
            c+=countVect[i];
            while(countVect[i]!=0)
            {
                v[poz]=i;
                countVect[i]--;
                poz++;
                as++;
                ac++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\nComparisons: %ld\n", c);
    printf("Accesses: %ld\n", ac);
    printf("Assignments: %ld", as);
    free(countVect);
    free(v);
    return 0;
}

