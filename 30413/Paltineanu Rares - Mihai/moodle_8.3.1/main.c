#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct knapsack {

    int value;
    int weight;

}knapT;

knapT* array;

void read(FILE* in, int* n, int* weight) {

    fscanf(in, "%d %d", n, weight);

    array = (knapT*)malloc(sizeof(knapT) * (*n));
    for(int i = 0; i < *n; i++) {

        fscanf(in, "%d %d", &array[i].weight, &array[i].value);

    }
}

void sort(int n) {

    bool ready = false;

    while(!ready) {

        ready = true;

        for(int i = 0; i < n - 1; i++) {

            if(1.0 * array[i].value / array[i].weight < 1.0 * array[i + 1].value / array[i + 1].weight) {

                knapT aux;
                aux = array[i];
                array[i]= array[i + 1];
                array[i + 1]= aux;
                ready = false;

            }
        }
    }
}

int findValue(int n, int weight) {

    int biggestValue = 0;
    int biggestWeight = 0;

    for(int i = 0; i < n && biggestWeight < weight; i++) {

        if(biggestWeight + array[i].weight <= weight) {

            biggestWeight += array[i].weight;
            biggestValue += array[i].value;
        }
    }

    return biggestValue;
}

float findFractionalValue(int n, int weight) {

    float biggestValue = 0;
    float valueForEachWeight;
    int biggestWeight = 0;

    for(int i = 0; i < n && biggestWeight < weight; i++) {

        if(biggestWeight + array[i].weight <= weight) {

            biggestWeight += array[i].weight;
            biggestValue += 1.0 *array[i].value;

        } else {

            valueForEachWeight = 1.0 * array[i].value / array[i].weight;
            while(biggestWeight < weight) {

                biggestWeight++;
                biggestValue += valueForEachWeight;

            }
        }
    }

    return biggestValue;

}

int main(int argc, char* argv[]) {

    FILE* in = fopen(argv[1], "r");

    int n;
    int weight;

    read(in, &n, &weight);
    sort(n);

    printf("The biggest value (as a whole) is %d\n", findValue(n ,weight));
    printf("The biggest value is %f", findFractionalValue(n ,weight));
    return 0;
}
