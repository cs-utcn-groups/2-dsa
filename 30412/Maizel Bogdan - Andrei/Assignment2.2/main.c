#include <stdio.h>
#include <string.h>
#include "sll.h"

#define MAX_LENGHT 300
#define MAX_N 100

void readTime(int *time, FILE *fin, int *n);

int main() {
    FILE *fin, *fout;
    fin = fopen("../input.dat", "r");
    fout = fopen("../output.dat", "w");
    if (fin == NULL)
        perror("Input file can't be opened.");
    if (fout == NULL)
        perror("Output file can't be opened.");
    initList();
    int *time, money, seconds;
    char *name;
    int n, i;
    int sumOfMoney = 0;
    int totalSeconds = 0;
    time = (int *) malloc(MAX_N * sizeof(int));
    readTime(time, fin, &n);
    name = (char *) malloc(MAX_LENGHT * sizeof(char));
    while (!feof(fin)) {
        fscanf(fin, "%s %d %d", name, &money, &seconds);
        AddLastCostumer(money, seconds);
    }
    //printAllElements(fout);
    for (i = 0; i < n; i++) {
        if (first != NULL) {
            if (time[i] >= totalSeconds + first->seconds) {
                {
                    totalSeconds = totalSeconds + first->seconds;
                    sumOfMoney = sumOfMoney + first->money;
                    deleteFirstCustomer();
                }
            }
            fprintf(fout, "After %d seconds: %d \n", time[i], sumOfMoney);
        }
    }
    fclose(fin);
    fclose(fout);
    free(time);
    free(name);
    return 0;
}

void readTime(int *time, FILE *fin, int *n) {
    char *line, *lineCopy, *token;
    int i = 0;
    line = (char *) malloc(MAX_LENGHT * sizeof(char));
    lineCopy = (char *) malloc(MAX_LENGHT * sizeof(char));
    fgets(line, MAX_LENGHT, fin);
    strcpy(lineCopy, line);
    token = strtok(line, " ");
    time[0] = atoi(token);
    while (token != NULL) {
        i++;
        token = strtok(NULL, " ");
        sscanf(token, "%d", &time[i]);
    }
    *n = i;
    free(line);
    free(lineCopy);

}
