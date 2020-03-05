//
// Created by Bori on 2/26/2020.
//

#include "bunker.h"

Bunker createBunker() {
    Bunker newBunker;
    newBunker.sentinels = createList();
    newBunker.jimKongNuPower = 1;
    return newBunker;
}

void readDataOfBunker(Bunker *myBunker, FILE *inFile) {
    int noSentinels;
    fscanf(inFile, "%d", &noSentinels);
    int nextSentinelPower;
    for (int i = 1; i <= noSentinels; i++) {
        fscanf(inFile, "%d", &nextSentinelPower);
        addLast(&myBunker->sentinels, nextSentinelPower);
    }
    addLast(&myBunker->sentinels, myBunker->jimKongNuPower); //logically he's viewed as a sentinel himself
}

int isDefeated(Bunker *thisBunker) {
    if (isEmpty(&thisBunker->sentinels)) return 1;
    return 0;
}