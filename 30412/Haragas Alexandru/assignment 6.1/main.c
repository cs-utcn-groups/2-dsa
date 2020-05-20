#include "edges.h"

int main() {
    int n, m;
    printf("Input no of vertices and edges:");
    scanf("%d %d", &n, &m);
    Edge *edges = (Edge *) malloc(m * sizeof(Edge));
    int *visited=(int*)malloc(n* sizeof(int));
    int *order=(int*)malloc((n-1)* sizeof(int));
    printf("Input edges in this order: first vertex, second vertex, length:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].nodeA, &edges[i].nodeB, &edges[i].lenght);
    }
    orderEdge(edges, m);
    Kruskal(edges, n, m,visited,order);

    int **mat=(int**)malloc(n* sizeof(int*));
    for(int i=0;i<n;i++)
        mat[i]=(int*)malloc(n* sizeof(int));
    createMatrix(edges,n,m,mat);
    free(edges);
    free(visited);
    free(order);

    int x;
    printf("Input starting node: ");
    scanf("%d",&x);
    printf("Bellman Froid: \n");
    visited=(int*)malloc(n* sizeof(int));
    BF(mat,n,x,visited);
    free(visited);
    for(int i=0;i<n;i++)
        free(mat[i]);
    free(mat);
    return 0;
}