#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define size 100

int minNode = 101, maxNode = -1;
int visited[size];

typedef struct listTransversal {

    int node;
    struct listTransversal* next;


}listTransversalT;

listTransversalT* first,* last;

typedef struct list {

    int node;
    struct list* next;

}listT;

listT* array[size];

void initTrans() {

    first = last = NULL;

}

void initializeArray() {

    for(int i = 0; i < size; i++)
        array[i] = NULL;

}

listT* initialize(int node2) {

    listT* p = (listT*)malloc(sizeof(listT));
    p->next = NULL;
    p->node = node2;
    return p;

}

int** initializeMatrix() {

    int** matrix = (int**)malloc(sizeof(int) * size);

    for(int i = 0; i < size; i++) {

        matrix[i] = (int*)malloc(sizeof(int) * size);
        memset(matrix[i], 0, sizeof(int) * size);

    }

    return matrix;

}

int min(int node) {

    return (node < minNode) ? node : minNode;

}

int max(int node) {

    return (node > maxNode) ? node : maxNode;

}

void read(FILE* in, int** matrix) {

    int node1, node2;
    while(fscanf(in, "%d %d", &node1, &node2) != EOF) {

        matrix[node1][node2] = 1;
        matrix[node2][node1] = 1;

        minNode = min(node1);
        minNode = min(node2);

        maxNode = max(node1);
        maxNode = max(node2);

    }

}

void addNode(int node1, int node2) {

    if(array[node1] == NULL) {

        array[node1] = initialize(node2);

    } else {

        listT* p = array[node1];

        while(p->next != NULL) {

            p = p->next;

        }

        p->next = initialize(node2);
    }

    if(array[node2] == NULL) {

        array[node2] = initialize(node1);

    } else {

        listT* p = array[node2];

        while(p->next != NULL) {

            p = p->next;

        }

        p->next = initialize(node1);
    }
}

void matrixToList(int** matrix) {

    for(int i = minNode; i <= maxNode - 1; i++) {
        for(int j = i + 1; j <= maxNode; j++) {

            if(matrix[i][j] == 1) {

                addNode(i, j);

            }
        }
    }
}

int** listToMatrix() {

    int** mat = initializeMatrix();

    for(int i = minNode; i<= maxNode; i++) {

        if(array[i] != NULL) {

            listT* p = array[i];
            while(p != NULL) {

                mat[i][p->node] = mat[p->node][i] = 1;
                p = p->next;

            }
        }
    }

    return mat;
}

void add(int node) {

    if(first == NULL) {

        first = (listTransversalT*)malloc(sizeof(listTransversalT));
        first->node = node;
        first->next = last;
        last = first;

    } else {

        listTransversalT* p = (listTransversalT*)malloc(sizeof(listTransversalT));
        p->node = node;
        p->next = NULL;
        last->next = p;
        last = p;

    }
}

void deleteFirst() {

    if(first == NULL)
        return;

    if(first->next == NULL) {

        free(first);
        initTrans();

    } else {

        listTransversalT* current = first;
        first = first->next;
        free(current);

    }
}

void deleteLast() {

    if(first->next == last) {

        listTransversalT* current = last;
        free(current);
        last = first;
        first->next = last->next = NULL;
        return;

    }

    if(first->next == NULL) {

        free(first);
        initTrans();

    }

    if(last == NULL)
        return;

    listTransversalT* current = first;

    while(current->next != last)
        current = current->next;

    last = current;
    current = last->next;
    last->next = NULL;
    free(current);

}

void BFS(int node) {

    add(node);
    visited[node] = 1;

    while(first != NULL) {

        node = first->node;
        printf("%d ", node);
        deleteFirst();

        listT* p = array[node];

        while(p != NULL) {

            if(visited[p->node] == 0){

                add(p->node);
                visited[p->node] = 1;

            }

            p = p->next;

        }
    }
}

void DFS(int node) {

    int find = 0;
    add(node);
    visited[node] = 1;
    printf("%d ", node);

    while(first != NULL) {

        node = last->node;
        find = 0;

        listT* p = array[node];
        while(p != NULL && find == 0) {

            if(visited[p->node] == 0) {

                find = 1;
                visited[p->node] = 1;
                printf("%d ", p->node);
                add(p->node);

            }

            p = p->next;

        }

        if(!find) {

            deleteLast();

        }
    }
}

void printMatrix(int** matrix) {

    for(int i = 0; i <= maxNode; i++) {

        for(int j = 0; j <= maxNode; j++)
            printf("%d ", matrix[i][j]);

        printf("\n");
    }

    printf("\n");
}

int main(int argc, char* argv[]){

    FILE* in = fopen(argv[1], "r");
    int** matrix = initializeMatrix();

    initTrans();
    initializeArray();

    read(in, matrix);
    matrixToList(matrix);

    printf("BFS: ");
    BFS(1);
    printf("\n\n");

    memset(visited, 0, size * 4);

    printf("DFS: ");
    DFS(1);
    printf("\n\n");

    int** newMatrix = listToMatrix();

    printMatrix(matrix);
    printMatrix(newMatrix);
    return 0;
}
