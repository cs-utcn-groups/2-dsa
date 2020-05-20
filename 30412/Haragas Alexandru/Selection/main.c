#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);

int main() {
    unsigned int n;
    long unsigned int c = 0, ac = 0, as = 0;
    scanf("%d", &n);
    int *v = (int *) malloc(n * sizeof(int));
    for (unsigned int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    for (int i = 0; i < n - 1; i++) {
        int min = v[i];
        ac++;
        as++;
        int loc = i;
        for (int j = i + 1; j < n; j++) {
            c++;
            ac++;
            if (v[j] < min) {
                min = v[j];
                loc = j;
                ac++;
                as++;
            }
        }
        c++;
        if(min!=v[i])
        {
            swap(&v[i],&v[loc]);
            as+=3;
            ac+=3;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\nComparisons: %ld\n", c);
    printf("Accesses: %ld\n", ac);
    printf("Assignments: %ld", as);
    free(v);
    return 0;
}

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}



