#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct activities {

    int startHour;
    int startMinute;
    int finishHour;
    int finishMinute;
    int id;

}activitiesT;

activitiesT* array;

void read(int* n, FILE* in) {

    fscanf(in, "%d", n);
    array = (activitiesT*)malloc(sizeof(activitiesT) * (*n));

    for(int i = 0; i < (*n); i++) {

        fscanf(in, "%d %d %d %d", &array[i].startHour, &array[i].startMinute, &array[i].finishHour, &array[i].finishMinute);
        array[i].id = i + 1;

    }
}

void sort(int n) {

    bool ready = false;

    while(!ready) {

        ready = true;

        for(int i = 0; i < n - 1; i++) {

            if(array[i].finishHour > array[i + 1].finishHour) {

                activitiesT aux;
                aux = array[i];
                array[i] = array[i + 1];
                array[i + 1] = aux;
                ready = false;

            } else if(array[i].finishHour == array[i + 1].finishHour && array[i].finishMinute > array[i + 1].finishMinute) {

                activitiesT aux;
                aux = array[i];
                array[i] = array[i + 1];
                array[i + 1] = aux;
                ready = false;

            }
        }
    }
}

void printfActivities(int n) {

    int finishHour = array[0].finishHour;
    int finishMinute = array[0].finishMinute;
    printf("%d ", array[0].id);

    for(int i = 1; i < n; i++) {

        if(array[i].startHour > finishHour || (array[i].startHour == finishHour && array[i].startMinute >= finishMinute)) {

            printf("%d ", array[i].id);
            finishHour = array[i].finishHour;
            finishMinute = array[i].finishMinute;

        }
    }
}

int main(int argc, char* argv[]){

    FILE* in = fopen(argv[1], "r");
    int n;

    read(&n, in);
    sort(n);
    printfActivities(n);
    return 0;
}
