#include <stdio.h>
#include "io.h"
#include "hashTable.h"

int main() {
    FILE* tableFile = fopen("table.txt", "w");
    int noFunctions = 4, noPossibleSizeFactors = 6, noPossibleSizes = 8, N;
    int noStrings[8] = {100, 500, 1000, 5000, 10000, 25000, 50000, 100000};
    float initSizeFactor, maxFillFactor;
    int maxCollisions=0, currentCollisions = 0, totalCollisions=0;
    double avgCollisionForFunctions[5];
    for (int functionNr = 1; functionNr <= noFunctions; functionNr++) {
        avgCollisionForFunctions[functionNr] = 0;
        fprintf(tableFile,
                "-----------------------------------------------------For hashFunction nr %d-------------------------------------------------\n",
                functionNr);
        for (int i = 0; i < noPossibleSizes; i++) {
            N = noStrings[i];
            fprintf(tableFile, "----------------------------For %d strings-----------------------------\n", N);
            char **content = readFromFile(N);
            FILE *inputs = fopen("inputs.txt", "r");
            for (int j = 1; j <= noPossibleSizeFactors; j++) {
                fscanf(inputs, "%f %f", &initSizeFactor, &maxFillFactor);
                setInitialSizeFactor(initSizeFactor);
                setMaxFillFactor(maxFillFactor);
                initHashTable(N, functionNr);
                totalCollisions = 0;
                maxCollisions = 0;
                for (int k = 0; k < N; k++) {
                    currentCollisions = insertElement(content[k]);
                    //printf("finished %d\n", k);
                    totalCollisions += currentCollisions;
                    if (currentCollisions > maxCollisions) {
                        maxCollisions = currentCollisions;
                    }
                }
                fprintf(tableFile,
                        "ISF = %f and MFF = %f --> Max.collisions = %d, Avg.collisions = %.2lf, No. resizes = %d\n",
                        initSizeFactor, maxFillFactor, maxCollisions, (double) totalCollisions / (double) N,
                        noResizes);
                free(hashTable);
                avgCollisionForFunctions[functionNr] += (double) totalCollisions / (double) N;
            }
            fclose(inputs);
        }
    }


    fprintf(tableFile,
            "-----------------------------------------------------Average collisions for functions-------------------------------------------------\n");
    for (int i = 1; i <= noFunctions; i++) {
        avgCollisionForFunctions[i] /= noPossibleSizeFactors * noPossibleSizes;
        fprintf(tableFile, "Avg collision/no inserted elements for hashFunction nr.%d is %.3lf\n", i,
                avgCollisionForFunctions[i]);
    }


    return 0;
}