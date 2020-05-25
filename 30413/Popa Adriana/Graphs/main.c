#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void GetArcs(char *buf, int **a)
{
    int x, y;
    char letter;
    char *aux = (char*)malloc(sizeof(char)*10);

    int n;
    printf("give letter string n:");
    sscanf(buf, "%c %s %n", &letter, aux, &n);
    buf += n;
    while (sscanf(buf, "(%d %d) %n", &x, &y, &n)!=0 && x!=13 && y!=13)
    {
        a[x][y]=1;
        buf += n;
    }
}

void PrintArcs(char *buf, int **a)
{
    int x;
    char *letter = (char*)malloc(sizeof(char)*10);
    char *aux = (char*)malloc(sizeof(char)*10);
    int *nodes = (int*)malloc(sizeof(int)*100);
    int MaxNode = 0;

    int n;
    printf("give letter string n:");
    sscanf(buf, "%s %s %n", letter, aux, &n);
    buf += n;
    while (sscanf(buf, "%d %n", &x, &n)!=0 && x!=13)
    {
        nodes[x] = 1;
        if (x>MaxNode)
        {
            MaxNode = x;
        }
        buf += n;
    }

    printf("V' arcs: ");
    int i,j;
    for ( i=1; i<=MaxNode; i++)
    {
        if (nodes[i]==1)
        {
            for ( j=1; j<=MaxNode; j++)
            {
                if (a[i][j]==1 && nodes[j]==1)
                {
                    printf("(%d %d) ", i, j);
                }
            }
        }
    }
}

int main()
{
    int **a = (int**)malloc(sizeof(int)*100);
    int i;
    for ( i=0; i<100; i++)
    {
        a[i] = (int*)malloc(sizeof(int)*100);
    }

    char **buf = (char**)malloc(sizeof(char)*3);
    for ( i=0; i<3; i++)
    {
        buf[i] = (char*)malloc(sizeof(char)*100);
        fgets(buf[i], 100, stdin);
        if (i==1)
        {
            GetArcs(buf[i], a);
        }
        if (i==2)
        {
            PrintArcs(buf[i], a);
        }
    }
    return 0;
}
