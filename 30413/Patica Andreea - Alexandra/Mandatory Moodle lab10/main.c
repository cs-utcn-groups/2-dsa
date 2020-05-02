#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min (int a, int b, int c)
{
    if (a<=b && a<=c)return a;
    if (b<=a && b<=c) return b;
    return c;
}

int FindMinOperations(char *a, char *b)
{
    int n = strlen(a);
    int m = strlen(b);

    int **operations = (int**)malloc(sizeof(int*)*(n+1));
    for (int i=0; i<=n; i++)
    {
        operations[i]=(int*)malloc(sizeof(int)*(m+1));
        for (int j=0; j<=m; j++)
        {
            if (i==0)
            {
                operations[i][j]=j;
            }
            else if (j==0)
            {
                operations[i][j]=i;
            }
            else if (a[i-1]==b[j-1])
            {
                operations[i][j] = operations[i-1][j-1];
            }
            else
            {
                operations[i][j] = 1 + min(operations[i-1][j-1], operations[i][j-1], operations[i-1][j]);
            }
        }
    }


    return operations[n][m];
}

int main()
{
    FILE *f = fopen("input.in", "r");
    FILE *g = fopen("output.out", "w");

    int t;
    fscanf(f, "%d", &t);
    for (int i=0; i<t; i++)
    {
        char *string1 = (char*)malloc(sizeof(char*)*2000);
        char *string2 = (char*)malloc(sizeof(char*)*2000);

        fscanf(f, "%s", string1);
        fscanf(f, "%s", string2);

        int MinOp = FindMinOperations(string1, string2);

        fprintf(g, "%d\n", MinOp);

        free(string1);
        free(string2);
    }
    return 0;
}
