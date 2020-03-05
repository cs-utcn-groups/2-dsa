//
// Created by diana on 01/03/2020.
//

#include "sentinel.h"
#include <stdlib.h>

void initializeSentinelList() {
    firstSentinel = NULL;
    lastSentinel = NULL;
}

void addSentinel(int data) {
    if (firstSentinel == NULL) {
        firstSentinel = (Sentinel *) malloc(sizeof(Sentinel));
        firstSentinel->hitPoints = data;
        firstSentinel->next = lastSentinel;
        lastSentinel = firstSentinel;
    } else {
        Sentinel *newSentinel = (Sentinel *) malloc(sizeof(Sentinel));
        newSentinel->hitPoints = data;
        newSentinel->next = NULL;
        lastSentinel->next = newSentinel;
        lastSentinel = newSentinel;
    }
}
