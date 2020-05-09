#include "io.h"
#include "files.h"
#include "hashTable.h"
#include <math.h>


int main() {
    printf("Hashing started!\n");
    FILE *output = fopen("../output.txt", "w");

    for (int t = 0; t < 3; ++t)
    {
        ///using a function pointer to switch between the 3 hash functions

        fprintf(output, "=======================   Hash function %d  ==========================="
                        "\n======================================================================\n", t+1);
        for (int i = 0; i < 3; ++i)
        {
            int N = FILES[i];
            fprintf(output, "\n=======================  File is:  \"%d.data\"  =======================\n", N);
            fprintf(output, "Hash Function ===== ISF  ===== MFF  ===== Max Collisions  ===== Resizes\n");
            for (int j = 0; j < 6; ++j) {
                INITIAL_HT_SIZE_FACTOR = SIZE_FACTORS[j];
                MAX_FILL_FACTOR = FILL_FACTORS[j];
                char **content = readFromFile(N);
                initHashTable(N);
                initialSize=size;
                int maxCollisions = 0;
                for (int k = 0; k < N; ++k) {
                    int aux = insertElement(content[k], t);
                    if (maxCollisions < aux) {
                        maxCollisions = aux;
                    }
                }
                int noOfResizes = log2(size / initialSize)+1;
                fprintf(output, "%7d       ===== %.2lf ===== %.2lf =====      %3d        =====    %d\n", t+1, INITIAL_HT_SIZE_FACTOR, MAX_FILL_FACTOR, maxCollisions,
                        noOfResizes);

            }

        }
        fprintf(output,"\n\n");
    }
    printf("Hashing done!\n");
    return 0;
}
