#include <stdio.h>
#include <stdlib.h>
#include <String.h>

typedef struct list {

    int node;
    struct list* next;

}listT;

listT* first,* last;

int visited[100];

void initialize() {

    first = NULL;
    last = NULL;

}

int** initializeMatrix() {

    int** matrix = (int**)malloc(sizeof(int) * 100);

    for(int i = 0; i < 100; i++) {

        matrix[i]= (int*)malloc(sizeof(int) * 100);
        memset(matrix[i], 0, 400);

    }

    return matrix;

}

void read(int** matrix, FILE* in) {

    int node1, node2, weight;

    while(fscanf(in, "%d %d %d", &node1, &node2, &weight) != EOF) {

        matrix[node1][node2] = weight;
        matrix[node2][node1] = weight;

    }

}

void addNode(int node) {

    if(first == NULL) {

        first = (listT*)malloc(sizeof(listT));
        first->node = node;
        first->next = last;
        last = first;

    } else {

        listT* current = (listT*)malloc(sizeof(listT));
        current->node = node;
        last->next = current;
        current->next = NULL;
        last = current;

    }

}

int minEdge(int** matrix, int* position1, int* position2) {

    listT* current = first;
    int minim = 1000;

    while(current != NULL) {

        for(int i = 0; i < 100; i++) {

            if(matrix[i][current->node] != 0 && visited[i] == 0) {
                if(matrix[current->node][i] < minim) {

                    minim = matrix[current->node][i];
                    (*position1) = i;
                    (*position2) = current->node;

                }
            }
        }

        current = current->next;

    }

    return minim;
}

void primAlg(int** matrix, int startNode) {

    addNode(startNode);
    visited[startNode] = 1;
    int position1 = -1;
    int position2 = -1;
    int minim;
    while(minEdge(matrix, &position1, &position2) != 1000) {

        minim = minEdge(matrix, &position1, &position2);
        visited[position1] = 1;
        visited[position2] = 1;
        printf("%d %d - %d\n", position1, position2, minim);
        addNode(position1);

    }
}

int main(int argc, char* argv[])
{
    FILE* in = fopen(argv[1], "r");

    int** matrix = initializeMatrix();
    initialize();

    read(matrix, in);
    primAlg(matrix, 1);
    return 0;
}
