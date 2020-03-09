#include <stdio.h>
#include <stdlib.h>

typedef struct nodetype {
    int money;
    int seconds;
    struct nodetype *next;
    struct nodetype *prev;
} nodeT;

nodeT *first, *last, *sentinel;

void init_queue() {
    first = NULL;
    last = NULL;
}

void queue_push(int money, int seconds) {
    if (first == NULL) {
        first = last = (nodeT *) malloc(sizeof(nodeT));
        first->money = money;
        first->seconds = seconds;
        first->next = last;
        last->next = NULL;
        first->prev = NULL;
        last->prev = first;
    } else {
        nodeT *newLast = (nodeT *) malloc(sizeof(nodeT));
        newLast->prev = last;
        newLast->money = money;
        newLast->seconds = seconds;
        newLast->next = NULL;
        last->next = newLast;
        last = newLast;
    }
}

void queue_pop() {
    nodeT *newFirst = first->next;
    free(first);
    first = newFirst;
}

int main() {
    FILE *input = fopen("..\\input.dat", "r");
    int i = 0;
    int *time = (int *) malloc(sizeof(int)*6);
    for (i = 0; i < 6; ++i) {
        fscanf(input, "%d", &time[i]);
    }
    init_queue();
    for (i=0;i<5;++i) {
        char * name = (char*)malloc(sizeof(char)*20);
        int money, seconds;
        fscanf(input, "%s %d %d", name, &money, &seconds);
        queue_push(money, seconds);
    }
    FILE *output = fopen("..\\output.dat", "w");
    int timeTotal=0, moneyTotal=0;
    for (int i=0;i<5;++i) {
        if (time[i]>=timeTotal+first->seconds) {
            timeTotal+=first->seconds;
            moneyTotal+=first->money;
            fprintf(output, "After %d seconds: %d\n", time[i], moneyTotal);
            queue_pop();
        }
        else {
            timeTotal+=first->seconds;
            fprintf(output, "after %d seconds: %d\n", time[i], moneyTotal);
            moneyTotal+=first->money;
            queue_pop();
        }
    }
    return 0;
}
