#include "io.h"
#include "files.h"
#include "hashTable.h"
#include <stdio.h>

#define MAX_FUNCTIONS 5

int main()
{
    FILE *tableFile = fopen("table.txt", "w");
    int noFunctions = 5, noPossibleSizeFactors = 6, noPossibleSizes = 8, N;
    int noStrings[8] = {100, 500, 1000, 5000, 10000, 25000, 50000, 100000};
    float sizeFactor;
    double avgSD[MAX_FUNCTIONS + 1] = {0}, SD;
    for (int functionNr = 0; functionNr < noFunctions; functionNr++) {
        fprintf(tableFile,
                "-----------------------------------------------------For hashFunction nr %d-------------------------------------------------\n",
                functionNr);
        for (int i = 0; i < noPossibleSizes; i++) {
            N = noStrings[i];
            fprintf(tableFile, "------------------------------For %d strings-------------------------------\n", N);
            char **content = readFromFile(N);
            FILE *inputs = fopen("inputs.txt", "r");
            for (int j = 1; j <= noPossibleSizeFactors; j++) {
                fscanf(inputs, "%f", &sizeFactor);
                setInitialSizeFactor(sizeFactor);
                initHashTable(N, functionNr);
                for (int k = 0; k < N; k++) {
                    insertElement(content[k]);
                }
                SD = standartDeviationOfBucketLengths();
                avgSD[functionNr] += SD;
                fprintf(tableFile, "ISF = %.2f --> standard deviation of buckets sizes = %lf\n",
                        sizeFactor, SD);
            }
            fclose(inputs);
        }
    }

    fprintf(tableFile, "-----------------------------------Average SDs--------------------------------------\n", N);
    for (int i = 0; i < noFunctions; i++) {
        avgSD[i]/=noPossibleSizeFactors*noPossibleSizes;
        fprintf(tableFile, "Average standard deviation for hash function nr. %d is %.3lf\n", i, avgSD[i]);
    }



    return 0;
}