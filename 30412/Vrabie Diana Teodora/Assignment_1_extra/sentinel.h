//
// Created by diana on 01/03/2020.
//

#ifndef ASSIGNMENT_1_EXTRA_SENTINEL_H
#define ASSIGNMENT_1_EXTRA_SENTINEL_H

typedef struct _Sentinel {
    int hitPoints;
    struct _Sentinel *next;
} Sentinel;

Sentinel *firstSentinel, *lastSentinel;

void initializeSentinelList();

void addSentinel(int data);


#endif //ASSIGNMENT_1_EXTRA_SENTINEL_H
