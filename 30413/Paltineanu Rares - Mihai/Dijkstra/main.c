#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define maxValue 999999

int maxim = -1;;
int minim = 10000;
int** initializeMatrix() {

    int** matrix = (int**)malloc(sizeof(int*) * 20);

    for(int i = 0; i < 20; i++) {

        matrix[i] = (int*)malloc(sizeof(int) * 20);
        memset(matrix[i], 0, 80);

    }

    return matrix;
}

int* initializeArray(int value) {

    int* vect = (int*)malloc(sizeof(int) * (maxim + 1));

    for(int i = 0; i <= maxim; i++)
        vect[i] = value;

    return vect;

}

void readInput(FILE* in, int** matrix) {

    char* input = (char*)malloc(10);
    char* tok = (char*)malloc(10);
    int node1, node2;
    while(fgets(input, 10, in) != NULL) {

        tok = strtok(input, ",");
        node1 = atoi(tok);

        tok = strtok(NULL, "=");
        node2 = atoi(tok);

        if(node1 > maxim)
            maxim = node1;

        if(node2 > maxim)
            maxim = node2;

        if(node1 < minim)
            minim = node1;

        if(node2 < minim)
            minim = node2;

        tok = strtok(NULL, "\0\n");
        matrix[node1][node2] = atoi(tok);
        matrix[node2][node1] = atoi(tok);

    }
}

int findNewNode(int** matrix, int* cost, int* visited) {

    int node = -1;
    int minCost = maxValue;

    for(int i = minim; i <= maxim; i++) {
        if(visited[i] == 0) {
            if(cost[i] > 0 && minCost > cost[i]) {

                node = i;
                minCost = cost[i];

            }
        }
    }

    return node;
}

void print(int* cost, int* visited) {

    for(int i = minim; i <= maxim; i++)
        printf("%d ", cost[i]);

}

void Dijkstra(int** matrix, int sourceNode,int* cost,int* visited) {

    visited[sourceNode] = 1;

    for(int i = 1; i <= maxim; i++) {

        if(visited[i] == 0) {
            if(matrix[i][sourceNode] != 0) {
                if(cost[sourceNode] + matrix[i][sourceNode] < cost[i]) {

                    cost[i] = cost[sourceNode] + matrix[i][sourceNode];

                }
            }
        }
    }

    int newNode = findNewNode(matrix, cost, visited);

    if(newNode != -1)
        Dijkstra(matrix, newNode, cost, visited);

}

int readNode() {

    int node;
    scanf("%d", &node);
    if(node < minim || node > maxim) {

        printf("Read a valid node.\n");
        readNode();

    } else {

        return node;

    }

}

int main(int argc, char* argv[]) {
    int** matrix = initializeMatrix();

    FILE* in = fopen(argv[1], "r");
    readInput(in, matrix);

    int* cost = initializeArray(maxValue);
    int* visited = initializeArray(0);

    int sourceNode = readNode();
    cost[sourceNode] = 0;
    Dijkstra(matrix, sourceNode, cost, visited);
    print(cost, visited);

    return 0;
}
