#include <stdio.h>
#include <stdlib.h>

#define MAX_DIFF_TIME 100

int T[MAX_DIFF_TIME];
int totalRubles, totalSeconds;

typedef struct _Customer {
    int rubles;
    int seconds;
    struct _Customer *next;
    struct _Customer *prev;
} Customer;

typedef struct _line {
    Customer *first;
    Customer *last;
} Line;

void addCustomer();

void printAll();

void printResult(int i);

FILE *input, *output;
Line *line;

int main() {
    line = (Line *) malloc(sizeof(Line));
    line->first = NULL;
    line->last = NULL;

    input = fopen("input.dat", "r");
    output = fopen("output.dat", "w+");
    int c, i = 0; // we use i to increment each position in T[]
    do {
        fscanf(input, "%d", &T[i]);
        c = getc(input);
        i++;
    } while (c != '\n');

    while (!feof(input)) {
        addCustomer();
    }
    //printAll();
    printResult(i);
    return 0;
}

void addCustomer() {
    if (line->last == NULL) {
        line->last = (Customer *) malloc(sizeof(Customer));
        line->last->next = NULL;
        line->last->prev = NULL;
        fscanf(input, "%*s %d %d", &line->last->rubles, &line->last->seconds);
        getc(input);
        line->first = line->last;
    } else {
        Customer *newCustomer = (Customer *) malloc(sizeof(Customer));
        newCustomer->next = NULL;
        newCustomer->prev = line->last;
        line->last->next = newCustomer;
        fscanf(input, "%*s %d %d", &newCustomer->rubles, &newCustomer->seconds);
        getc(input);
        line->last = newCustomer;
    }
}

void printAll() {
    Customer *currentCustomer = line->first;
    while (currentCustomer) {
        fprintf(output, "%d %d\n", currentCustomer->rubles, currentCustomer->seconds);
        currentCustomer = currentCustomer->next;
    }
}

void printResult(int i) {
    int j = 0;
    Customer *currentCustomer = line->first;
    totalSeconds = totalRubles = 0;
    while (j < i) {
        while (totalSeconds < T[j] && currentCustomer) {
            totalRubles += currentCustomer->rubles;
            totalSeconds += currentCustomer->seconds;
            currentCustomer = currentCustomer->next;
        }
        if (totalSeconds > T[j]) {
            currentCustomer = currentCustomer->prev;
            totalRubles -= currentCustomer->rubles;
            totalSeconds -= currentCustomer->seconds;
        }
        fprintf(output, "After %d seconds: %d\n", T[j], totalRubles);
        j++;
    }
}
