#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);

int *merge(int m, int *a, unsigned int lena, int *b, unsigned int lenb);

int *split(int *v, unsigned int n);

long unsigned int c = 0, ac = 0, as = 0;

int main() {
    unsigned int n;

    scanf("%d", &n);
    int *v = (int *) malloc(n * sizeof(int));
    for (unsigned int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    v = split(v, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\nComparisons: %ld\n", c);
    printf("Accesses: %ld\n", ac);
    printf("Assignments: %ld", as);
    free(v);
    return 0;
}

int *split(int *v, unsigned int n) {
    if (n > 1) {
        unsigned int mij = n / 2;
        unsigned int lena = 0, lenb = 0;
        int *a = (int *) malloc((n - 1) * sizeof(int));
        int *b = (int *) malloc((n - 1) * sizeof(int));
        for (unsigned int i = 0; i < n; i++) {
            if (i != mij) {
                c++;
                if (v[i] < v[mij]) {
                    a[lena] = v[i];
                    lena++;
                    as++;
                    ac++;
                } else {
                    b[lenb] = v[i];
                    lenb++;
                    as++;
                    ac++;
                }
            }
        }
        ac += n;
        as += n;
        return merge(v[mij],split(a, lena), lena, split(b, lenb), lenb);
    } else
        return v;
}


int *merge(int m, int *a, unsigned int lena, int *b, unsigned int lenb) {
    int *newv = (int *) malloc(sizeof(int) * (lena + lenb+1));
    for (int i = 0; i < lena; i++) {
        newv[i] = a[i];
        as++;
        ac++;
    }
    newv[lena] = m;
    as++;
    for (int i = 0; i < lenb; i++) {
        newv[i + lena + 1] = b[i];
        as++;
        ac++;
    }
    return newv;
}

