#include "stack.h"
#include "list.h"

int *createVect(int n);

void DFS(int x, int n, int **m, int *v);

void BFS(int x, int n, int **m);

int main() {
    int n;
    scanf("%d", &n);
    int **m = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        m[i] = (int *) malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
            scanf("%d", &m[i][j]);
    }
    BFS(0, n, m);
    int *v = createVect(n);
    printf("DFS:\n");
    DFS(0, n, m, v);
    free(v);
    printf("\n");

    List **l = (List **) malloc(n * sizeof(List));
    for (int i = 0; i < n; i++) {
        l[i] = createList(n, m[i]);
    }
    for (int i = 0; i < n; i++) {
        free(m[i]);
    }
    free(m);

    printList(n,l);

    v=createVect(n);
    printf("DFS for list:\n");
    DFSList(0,l,v);
    printf("\n");
    free(v);

    v=createVect(n);
    BFSList(0,l,v);
    free(v);

    m=backMatrix(n,l);
    printf("\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int *createVect(int n) {
    int *v = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        v[i] = 0;
    return v;
}

void DFS(int x, int n, int **m, int *v) {
    v[x] = 1;
    printf("%d ", x);
    for (int i = 0; i < n; i++) {
        if (m[x][i] != 0 && v[i] == 0) {
            DFS(i, n, m, v);
        }
    }
}

void BFS(int x, int n, int **m) {
    int *v = createVect(n);
    initializeStack();
    int curNode;
    push(x);
    v[x] = 1;
    printf("BFS:\n");
    while (first != NULL) {
        curNode = pop();
        printf("%d ", curNode);

        for (int i = n - 1; i >= 0; i--) {
            if (m[curNode][i] != 0 && v[i] == 0) {
                push(i);
                v[i] = 1;
            }
        }
    }
    printf("\n");
    free(v);
}
