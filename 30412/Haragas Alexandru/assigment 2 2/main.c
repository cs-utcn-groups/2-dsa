#include <stdio.h>
#include <string.h>
#include "queue.h"

int main() {
    Initialize();
    FILE *f = fopen("D:\\DSA\\2-dsa\\30412\\Haragas Alexandru\\assigment 2 2\\input.dat", "r");
    char *s = (char *) malloc(255 * sizeof(char));
    char *copy;
    int money = 0;
    int time = 0;
    fgets(s, 255, f);
    copy = strtok(s, " ");
    while (copy != NULL) {
        AddLast(atoi(copy));
        copy = strtok(NULL, " ");
    }
    while (first != NULL) {
        if (!feof(f)) {
            int m, t;
            fscanf(f, "%s %d %d", s, &m, &t);
            while (t + time > first->val && first!=NULL) {
                printf("After %d seconds: %d\n", first->val, money);
                DeleteFirst();
            }
            money = money + m;
            time = time + t;
        } else {
            printf("After %d seconds: %d\n", first->val, money);
            DeleteFirst();
        }
    }
    free(s);
    free(copy);
    fclose(f);
    return 0;
}