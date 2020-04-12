//
// Created by Alex on 11.04.2020.
//

#include "edges.h"

void orderEdge(Edge *edges, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (edges[i].lenght > edges[j].lenght) {
                Edge c = edges[i];
                edges[i] = edges[j];
                edges[j] = c;
            }
        }
    }
}

void Kruskal(Edge *edges, int n, int m, int *visited, int *order) {
    int nredges = 1;
    int curedge = 0;
    for(int i=0;i<n;i++)
        visited[i]=0;
    while (nredges < n && curedge < m) {
        if (visited[edges[curedge].nodeA] == 0) {
            order[nredges - 1] = curedge;
            nredges++;
            if (visited[edges[curedge].nodeB] == 0) {
                visited[edges[curedge].nodeA] = nredges;
                visited[edges[curedge].nodeB] = nredges;
            } else {
                visited[edges[curedge].nodeA] = visited[edges[curedge].nodeB];
            }
        } else {
            if (visited[edges[curedge].nodeB] == 0) {
                order[nredges - 1] = curedge;
                nredges++;
                visited[edges[curedge].nodeB] = visited[edges[curedge].nodeA];
            } else {
                if (visited[edges[curedge].nodeA] != visited[edges[curedge].nodeB]) {
                    order[nredges - 1] = curedge;
                    nredges++;
                    int x = visited[edges[curedge].nodeB];
                    for (int i = 0; i < n; i++) {
                        if (visited[i] == x) {
                            visited[i] = visited[edges[curedge].nodeA];
                        }
                    }
                }
            }
        }
        curedge++;
    }

    printf("\nKruskal:\n");
    for (int i = 0; i < nredges - 1; i++) {
        printf("%d %d %d\n", edges[order[i]].nodeA, edges[order[i]].nodeB, edges[order[i]].lenght);
    }
    printf("\n");
}

void createMatrix(Edge *edges,int n, int m, int **mat) {
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            mat[i][j]=0;
        }
    }
    for (int i = 0; i < m; i++) {
        mat[edges[i].nodeA][edges[i].nodeB] = edges[i].lenght;
        mat[edges[i].nodeB][edges[i].nodeA] = edges[i].lenght;
    }
}

int smallestVal(int **mat, int n, int x, int *visited) {
    int min = 99999, nodeA = x, nodeB = x;
    for (int i = 0; i < n; i++) {
        if (visited[i] != 0 || x == i) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] != 0 && mat[i][j] + visited[i] < min && visited[j] == 0 && j != x) {
                    min = mat[i][j] + visited[i];
                    nodeA = i;
                    nodeB = j;
                }
            }
        }
    }
    if (visited[nodeA] == 0 && nodeA!=x) {
        visited[nodeA] = min;
    } else {
        visited[nodeB] = min;
    }
    if ((visited[nodeA] != 0 || nodeA==x) && (visited[nodeB] != 0 || nodeB==x)) {
        printf("%d %d %d\n", nodeA, nodeB, mat[nodeA][nodeB]);
        return 1;
    } else
        return 0;
}

void BF(int **mat, int n, int x, int *visited) {
    int nredges = 0;
    for(int i=0;i<n;i++)
        visited[i]=0;
    while (nredges < n-1) {
        int a = smallestVal(mat, n, x, visited);
        if (a == 0) {
            printf("Something went wrong");
            return;
        } else
            nredges++;
    }
}