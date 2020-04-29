#include "io.h"
#include "files.h"
#include "hashTable.h"
#include <stdio.h>


int main()
{
    int noStrings[8]={100, 500, 100, 5000, 10000, 25000, 50000, 100000};
    int functionNr, N;
    float sizeFactor;
    for(int i=0; i<8; i++){
        N = noStrings[i];
        char** content = readFromFile(N);
        FILE* inputs = fopen("inputs.txt", "r");
        for(int j=1; j<=24; j++){
            fscanf(inputs, "%d %f", &functionNr, &sizeFactor);
            setInitialSizeFactor(sizeFactor);
            initHashTable(N, functionNr);
            for(int k=1; k<=N; k++) {
                insertElement(content[i]);
            }
            printf("SD for hash function %d with %d data rows, and initial size factor %f is: %lf\n", functionNr, N, sizeFactor, standartDeviationOfBucketLengths());
        }
        fclose(inputs);
    }



    return 0;
}