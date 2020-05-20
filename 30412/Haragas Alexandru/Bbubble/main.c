#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned int n;
    long unsigned int c = 0, ac = 0, as = 0;
    scanf("%d", &n);
    int *v = (int *) malloc(n * sizeof(int));
    for (unsigned int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    for (unsigned int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            c++;// one comparison for each if
            ac += 2;//2 accesses for each if
            if (v[i] > v[j]) {
                int cop = v[i];
                v[i] = v[j];
                v[j] = cop;
                as += 3;
                ac += 4;
            }
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