#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int father[1000];

typedef struct nodesCost {

    int cost;
    int father;
    int son;
    struct nodesCost* next;
}nodeT;

nodeT* first,* last;

void initialize() {

    first = last = NULL;

}

void addNode(int father, int son, int cost) {

    if(first == NULL) {

        first = (nodeT*)malloc(sizeof(nodeT));
        first->cost = cost;
        first->father = father;
        first->son = son;
        first->next = last;
        last = first;

    } else {

        nodeT* current = (nodeT*)malloc(sizeof(nodeT));
        current->father = father;
        current->son= son;
        current->cost = cost;
        current->next = NULL;
        last->next = current;
        last = current;

    }
}


int find(int node) {

    if(father[node] == node)
        return node;

    return find(father[node]);

}

void unite(int node1, int node2) {

    father[find(node1)] = find(node2);

}

void read(FILE* in, int* edges, int* nodes) {

    int node1, node2, cost;

    fscanf(in, "%d %d", nodes, edges);
    for(int i = 0; i < (*edges); i++) {

        fscanf(in, "%d %d %d", &node1, &node2, &cost);
        addNode(node1, node2, cost);

    }
}

void swap(nodeT* a, nodeT* b) {

    int aux1 = a->father;
    int aux2 = a->son;
    int aux3 = a->cost;
    a->father = b->father;
    a->son = b->son;
    a->cost = b->cost;
    b->father = aux1;
    b->son = aux2;
    b->cost = aux3;
}

void sort(int n) {

    bool ready = false;

    while(!ready) {

        ready = true;
        nodeT* current = first;

        while(current->next != NULL) {

            if(current->cost > current->next->cost) {

                swap(current, current->next);
                ready = false;

            }
            current = current->next;
        }
    }
}

void kruskal(int edges) {

    int minimumCost = 0;
    int allEdges = 0;
    int node1, node2, cost;
    nodeT* current = first;
    for(int i = 0; i < edges && allEdges != edges; i++) {

        node1 = current->father;
        node2 = current->son;
        cost = current->cost;

        if(find(node1) != find(node2)) {

            unite(node1, node2);
            minimumCost += cost;
            printf("%d %d %d\n", node1, node2, cost);
            allEdges++;

        }
        current = current->next;
    }

    printf("\nMinimum cost is:%d", minimumCost);
}

int main(int argc, char* argv[]) {

    FILE* in = fopen(argv[1], "r");
    int edges, nodes;

    read(in, &edges, &nodes);

    for(int i = 0; i < 1000; i++)
        father[i] = i;

    sort(edges);
    kruskal(edges);

    return 0;
}
