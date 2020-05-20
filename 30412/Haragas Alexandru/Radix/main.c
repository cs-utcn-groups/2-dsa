#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long unsigned int c = 0, ac = 0, as = 0;

int *CSort(int *v, unsigned int n, int e);

int main() {
    unsigned int n;
    int max = 0;
    scanf("%d", &n);
    int *v = (int *) malloc(n * sizeof(int));
    for (unsigned int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        c++;
        if (max < log10(v[i])) {
            max = log10(v[i]);
        }
    }
    int e = 1;
    for (int i = 0; i <= max; i++) {
        v = CSort(v, n, e);
        e *= 10;
    }
    for (unsigned int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\nComparisons: %ld\n", c);
    printf("Accesses: %ld\n", ac);
    printf("Assignments: %ld", as);
    free(v);
    return 0;
}

int *CSort(int *v, unsigned int n, int e) {
    int *count = (int *) malloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++) {
        count[i] = 0;
    }
    int *new = (int *) malloc(n * sizeof(int));
    for (unsigned int i = 0; i < n; i++) {
        count[(v[i] / e) % 10]++;
        as++;
        ac++;
    }
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        new[count[(v[i] / e) % 10] - 1] = v[i];
        count[(v[i] / e) % 10]--;
        as += 1;
        ac += 3;
    }
    free(count);
    return new;
}