#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned int n;
    long unsigned int c = 0, ac = 0, as = 0;
    scanf("%d", &n);
    int *v = (int *) malloc(n * sizeof(int));
    for (unsigned int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && v[j] < v[j - 1]) {
            int cop = v[j - 1];
            v[j - 1] = v[j];
            v[j] = cop;
            j--;
            as += 3;//there are 3 assignments in the loop. I count only assignments that work with the array.
            ac += 4;//there are 3 acceses of the vector in the loop
        }
        c = c + (i - j + 1);//i-j+1 is equal with the nr of loops, with one comparison per loop.
        // I don't count j>0 since I want to count only the nr of comparisons with the elements from the array.
        ac = ac + 2 * (i - j +
                       1);//same idea, this is to count the nr of acceses in the while statement. It is *2 because we access both v[j] and v[j-1].
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