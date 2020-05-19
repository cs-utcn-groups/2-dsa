#include "io.h"
#include "files.h"
#include "hashTable.h"

int main() {
    FILE *output=fopen("../output.txt","w");
    for (int t = 0; t < 4; ++t) {
        fprintf(output,"______________________ Hash function   %d______________________"
                       "\n======================                  ======================\n",t);
        for (int i = 0; i < 8; ++i) {
            int N = FILES[i];
            fprintf(output,"======================File is:\"%d.data\"======================\n", N);
            for (int j = 0; j < 5; ++j) {
                INITIAL_HT_SIZE_FACTOR=SIZE_FACTORS[j];
                fprintf(output,"Current size factor is:%.2lf -----",INITIAL_HT_SIZE_FACTOR);
                char **content = readFromFile(N);
                initHashTable(N);
                for (int k = 0; k < N; ++k) {
                    insertElement(content[k],t);
                }
                getStandardDeviation(output);
            }
        }
    }

    return 0;
}
