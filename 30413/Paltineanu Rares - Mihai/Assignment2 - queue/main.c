#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct costumers {

    char* name;
    int time;
    int rubles;
    struct costumers * next;
} costumersT;

costumersT* first,* last;

typedef struct time {

    int time;
    struct time* next;

} timeT;

timeT* firstT,* lastT;
void initialize() {

    first = NULL;
    last = NULL;
    firstT = NULL;
    lastT = NULL;
}

int time = 0, money = 0;

void initializeName(costumersT* current) {

    current->name = (char*)malloc(60);
}

int takingNumber(char* array) {

    int i = 0;
    int nr = 0;

    while(array[i] >= '0' && array[i] <= '9') {

        nr = nr * 10 + (array[i] - '0');
        i++;
    }

    i++;
    return nr;
}

void addCostumer(char* name, int time, int rubles) {

    if(first == NULL) {

        first = (costumersT*)malloc(sizeof(costumersT));
        initializeName(first);
        strcpy(first->name, name);
        first->rubles = rubles;
        first->time = time;
        first->next = last;
        last = first;
    } else {

        costumersT* current = (costumersT*)malloc(sizeof(costumersT));
        initializeName(current);
        strcpy(current->name, name);
        current->rubles = rubles;
        current->time = time;
        last->next = current;
        current->next = NULL;
        last = current;
    }
}

void addTime(int timeP) {

    if(firstT == NULL) {

        firstT = (timeT*)malloc(sizeof(timeT));
        firstT->time = timeP;
        firstT->next = NULL;
        lastT = firstT;
    } else {

        timeT* current = (timeT*)malloc(sizeof(timeT));
        current->time = timeP;
        current->next = NULL;
        lastT->next = current;
        lastT = current;

    }
}

void readTime(FILE* in) {

    int time;
    while(fscanf(in, "%d\n", &time) != EOF) {

        printf("%d\n", time);
        addTime(time);
    }
}

void printMoney(int time, int money) {

    printf("After %d seconds:%d\n", time, money);

}

void calculateMoney() {

    costumersT* currentC = first;
    timeT* currentT = firstT;

    while(currentT != NULL && currentC != NULL) {

        while(currentC != NULL && time + currentC->time <= currentT->time ) {

            time += currentC->time;
            money += currentC->rubles;
            currentC = currentC->next;
        }

        printMoney(currentT->time, money);
        currentT = currentT->next;
    }
    printMoney(lastT->time, money);
}
void readCostumers(FILE* in) {

    char* command = (char*)malloc(60);
    char* name = (char*)malloc(60);

    while(fgets(command, 60, in) != NULL) {

        name = strtok(command, " ");
        addCostumer(name, takingNumber(strtok(NULL," ")), takingNumber(strtok(NULL, " \n")));
    }
}

void printAll() {

    if(first == NULL)
        return;

    costumersT* current = first;

    while(current != NULL) {

        printf("%s %d %d\n\n", current->name, current->rubles, current->time);
        current = current->next;
    }
}

int main() {

    FILE* in = fopen("input.data", "r");
    FILE* in2 = fopen("in.data", "r");
    if(in == NULL || in2 == NULL)
        return -1;

    initialize();
    readTime(in2);
    readCostumers(in);
    calculateMoney();
    return 0;
}
