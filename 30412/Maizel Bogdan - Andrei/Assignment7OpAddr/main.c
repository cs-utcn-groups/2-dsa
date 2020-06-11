#include "io.h"
#include "files.h"
#include "hashTable.h"

int main() {
    int N = _500;
    char **content = readFromFile(N);
    int maxCollisions = 0, resizes = 0;
    float fillFactor = getFillFactor();
    initializeHT(N);
    for (int i = 0; i < N; ++i) {
        if (fillFactor > MAX_FILL_FACTOR) {
            resizeHT();
            resizes++;
        }
        int currentCollisions = insert(content[i]);
        if (currentCollisions > maxCollisions)
            maxCollisions = currentCollisions;
        fillFactor = getFillFactor();
    }
    printf("Max Collisions: %d\nResizes: %d\n", maxCollisions, resizes);
    return 0;
}
